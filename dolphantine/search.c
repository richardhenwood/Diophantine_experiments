#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/*
 * An IFDEF complier switch
 * to include the correct GMP header.
 * The correct mkl header depends on the
 * target (i.e. desktop linux or HPC cluster with intel MKL)
 */
#ifdef __GNUC__
    #include <gmp.h>
#else
    #include "mkl_gmp.h"
#endif
#include "uthash.h"
#include "utlist.h"
#include <mpi.h>

void usage (char * progname);
void usage (char * progname) {
    printf(" \n");
    printf("This is an code to solve: ax^3+by^3+cu^3+dv^3=0 \n");
    printf(" \n");
    printf("Dependencies on mpi and gmp. \n");
    printf(" \n");
    printf("Alternative codes: \n");
    printf("http://cr.yp.to/papers.html#sortedsums \n");
    printf(" \n");
    printf("command line arguments\n");
    printf("%s a b c d height_upper height_lower heap_knob /dir/for/logfiles\n\n", progname);
    printf("example: %s 2 3 -5 -7 1000 0 2500000 /tmp/dsearchlogs\n\n", progname);
    printf(" \n");
    printf("Emperical evidence suggests that a suitable value  \n");
    printf("for the 'heap_knob' is 10000000 - assuming a single process on a 64bit\n");
    printf("machine with 4GB of memory. \n");
    printf(" \n");
}

typedef struct value_pair
{
    long long int u;
    long long int v;
    struct value_pair *next;
} value_pair; 

struct uv_struct {
    char *uv_str;
    value_pair *uv_list_head;
    UT_hash_handle hh;
};

void test_against_ab (long int coeff_a, 
        long int coeff_b, 
        long int h_height, 
        long int l_height, 
        struct uv_struct * uv_hash, 
        int rank, 
        FILE * logpath);
int process_range( int coeff_a, int coeff_b, int coeff_c, int coeff_d,
        long long int height, long long int lower,
        long int hash_chunk_size,
        int rank,
        int numproc,
        char * logdir);
char * format_solution (long int a, long int b, long int u, long int v);
long int get_max (long int a, long int b, long int u, long int v);
void dump_hash(struct uv_struct * uv_hash);

int DO_LOGGING = 1;


void print_intemediary(long long int count, long long int u, long long int v, mpz_t mp_sum) {
    mpz_out_str (stdout, 10, mp_sum);
    printf("\n");
}


/*
 * process_range
 *
 * This code builds a hash of possible values for a*x^3+b*y^3.
 * a, b are coeffecients. x, y take all values between height and lower.
 * Once the hash is complete, a second function is called to test
 * if against c*u^3+d*v^3.
 * If all possible values for x, y have not been tested, the hash
 * is destroyed and rebuilt until all x, y have been tested.
 *
 * INPUT:
 *   coeffecient values: coeff_a, coeff_b, coeff_c, coeff_d.
 *   lower and upper bound of a height: height, lower (respectively).
 *   the maximum size the hash can grow to before it is destroyed: hash_chunk_size.
 *   the rank of this process, always 0 if not running in MPI.
 *   the number of processes, always 1 if not running in MPI.
 *   a directory to store the resulting files.
 * OUTPUT:
 *   Non zero value if there is an error, otherwise zero.
 */

int
process_range(
        int coeff_a, int coeff_b, int coeff_c, int coeff_d,
        long long int height, long long int lower,
        long int hash_chunk_size,
        int rank,
        int numproc,
        char * logdir) {

    struct uv_struct *s, *uv_hash_table = NULL;
    struct uv_struct *current_uv, *uv_htmp;
    value_pair *uv_list;
    value_pair *elt, *eltmp;

    unsigned long long int count = 0;
    char * key_char = NULL;

    long long int current_u;
    long long int current_v;

    float total_tests;
    char logfilename[200];
    FILE *logfile = NULL;

    mpz_t key_u_mpz;
    mpz_t key_v_mpz;

    total_tests = pow((height - lower + 0.5)*2, 2)/numproc;
    printf("total tests for process %d (of %d) is: %.0f\n", rank, numproc, total_tests);

    if (DO_LOGGING) {
        sprintf(logfilename, "%s/log_%03d.log", logdir, rank);
        printf("logfile: %s\n", logfilename);
        logfile = fopen(logfilename, "w+");
        if (logfile == NULL) {
            perror("failed to open file\n");
            return EXIT_FAILURE;
        }

        fprintf(logfile, "### filename %s\n", logfilename);
        fprintf(logfile, "### coeff a, b, c, d: %d, %d, %d, %d\n", 
                coeff_a, coeff_b, coeff_c, coeff_d);
    }

    mpz_init(key_u_mpz);
    mpz_init(key_v_mpz);

    current_u = -height + rank;
    while (current_u <= height) {
        current_v = -height;
        while (current_v <= height) {

            mpz_set_si(key_u_mpz, current_u);
            mpz_pow_ui(key_u_mpz, key_u_mpz, 3);
            mpz_mul_si(key_u_mpz, key_u_mpz, coeff_c);
            mpz_set_si(key_v_mpz, current_v);
            mpz_pow_ui(key_v_mpz, key_v_mpz, 3);
            mpz_mul_si(key_v_mpz, key_v_mpz, coeff_d);
            mpz_add(key_u_mpz, key_u_mpz, key_v_mpz);

            key_char = mpz_get_str(NULL, 10, key_u_mpz);
            
            HASH_FIND_STR(uv_hash_table, key_char, s);
            if (s == NULL) {
                /* 
                 * The hash key key_char does no exist.
                 *
                 * 1. Create this hash key.
                 * 2. Create a linked list.
                 */
                s = (struct uv_struct*)malloc(sizeof(struct uv_struct));
                if (s == NULL) { 
                    perror ("failed to allocate memory\n");
                    return EXIT_FAILURE;
                }
                /* sizeof(char) = 1 */
                s->uv_str = (char *)malloc(sizeof(char)*strlen(key_char)+1);
                strcpy(s->uv_str, key_char);
                s->uv_list_head = NULL;

                HASH_ADD_KEYPTR(hh, uv_hash_table, s->uv_str, strlen(s->uv_str), s);
            }
            /*
             * At this point, either s contains an 
             * existing value - or we have just created
             * a new one.
             */

            uv_list = (value_pair*)malloc(sizeof(value_pair));
            if (uv_list == NULL) { 
                perror ("failed to allocate memory\n");
                return EXIT_FAILURE;
            }
            uv_list->u = current_u;
            uv_list->v = current_v;
            LL_APPEND(s->uv_list_head, uv_list);


            count++;
            if (count % hash_chunk_size == 0) {
                printf("Hash size: %d searching... ", HASH_COUNT(uv_hash_table));
                test_against_ab(coeff_a, coeff_b, height, lower, uv_hash_table, rank, logfile);
                printf("Complete, reclaiming heap... ");
                HASH_ITER(hh, uv_hash_table, current_uv, uv_htmp) {
                    LL_FOREACH_SAFE(current_uv->uv_list_head, elt, eltmp) {
                        LL_DELETE (s->uv_list_head, elt);
                        free(elt);
                    }
                    free(current_uv->uv_str);
                    HASH_DEL(uv_hash_table, current_uv);
                    free(current_uv);
                }
                printf(" Complete. %.1f%% searched\n", 100.0*(count/total_tests));
                uv_hash_table = NULL;
            }

            free(key_char);

            current_v = current_v + 1;
            if (current_v > - lower && current_v < lower) {
                current_v = lower;
            }
        }
        current_u = current_u + numproc;
        if (current_u > - lower && current_u < lower) {
            current_u = lower + rank;
        }
    }
    test_against_ab(coeff_a, coeff_b, height, lower, uv_hash_table, rank, logfile);
    /*dump_hash(uv_hash_table);*/
   
    mpz_clear(key_u_mpz);
    mpz_clear(key_v_mpz);
    if (DO_LOGGING) {
        fclose(logfile);
    }
    return EXIT_SUCCESS;
}

/* 
 * test_against_ab
 *
 * This function generates all values of a, b between
 * height and lower.
 * a*u^3+b*v^3 is evalulated and the hash uv_hash is 
 * searched to see if the result is contained.
 */

void test_against_ab (long int coeff_a, 
        long int coeff_b, 
        long int h_height, 
        long int l_height, 
        struct uv_struct * uv_hash, 
        int rank, 
        FILE * logfile) {
    long long int current_a;
    long long int current_b;
    char * tmpkey = NULL;
    struct uv_struct *s;
    value_pair *uv_list, *elt; 

    mpz_t ab_sum, b_sum;

    mpz_init(ab_sum);
    mpz_init(b_sum);

    current_a = -h_height;
    while (current_a <= h_height) {
        current_b = -h_height;
        while (current_b <= h_height) {

            mpz_set_si(b_sum, current_b);
            mpz_pow_ui(b_sum, b_sum, 3);
            mpz_mul_si(b_sum, b_sum, coeff_b);

            mpz_set_si(ab_sum, current_a);
            mpz_pow_ui(ab_sum, ab_sum, 3);
            mpz_mul_si(ab_sum, ab_sum, coeff_a);

            mpz_add(ab_sum, ab_sum, b_sum);

            tmpkey = mpz_get_str(NULL, 10, ab_sum);
            HASH_FIND_STR(uv_hash, tmpkey, s);
            if (s) {
                uv_list = s->uv_list_head;
                LL_FOREACH(uv_list, elt) {
                    if (DO_LOGGING) {
                        fprintf(logfile, " (%9ld) %9lld %9lld %9lld %9lld\n", 
                                get_max(current_a, current_b, elt->u, elt->v), 
                                    current_a, 
                                    current_b, 
                                    elt->u, 
                                    elt->v);
                    }
                    /*printf(" (%9ld) %9lld %9lld %9lld %9lld\n", 
                            get_max(current_a, current_b, elt->u, elt->v), 
                                current_a, 
                                current_b, 
                                elt->u, 
                                elt->v);*/
                }
            }
            free(tmpkey);

            current_b = current_b + 1;
            if (current_b > - l_height && current_b < l_height) {
                current_b = l_height;
            }
        }
        current_a = current_a + 1;
        if (current_a > - l_height && current_a < l_height) {
            current_a = l_height;
        }
    }
    mpz_clear(ab_sum);
    mpz_clear(b_sum);
}

/* dump_hash
 * Takes a hash and writes it to sdtout.
 */ 
void dump_hash(struct uv_struct * uv_hash) {
    struct uv_struct *s;
    value_pair *uv_list, *elt;
    for (s = uv_hash; s != NULL; s = s->hh.next) {
        printf(" key %s values ", s->uv_str);
        uv_list = s->uv_list_head;
        LL_FOREACH(uv_list, elt) {
            printf ("(%lld %lld), ", elt->u, elt->v);
        }
        printf("\n");
    }
}

/* format_solution
 * A utility function to present our results in a nice format.
 */
char * format_solution (long int a, long int b, long int u, long int v) {
    char * formatted_out = NULL;
    sprintf(formatted_out, " (%9ld) %9ld %9ld %9ld %9ld\n", 
            get_max(a, b, u, v), a, b, u, v);
    return formatted_out;
}

/* get_max
 * returns the largest values of four long ints.
 */
long int get_max (long int a, long int b, long int u, long int v) {
    long int max = a;
    if (b > max)
        max = b;
    if (u > max)
        max = u;
    if (v > max)
        max = v;
    return max;
}


int main(int argc, char *argv[]) {
    int coeff_a, coeff_b, coeff_c, coeff_d;
    long long int h_height, l_height;
    long int chunk_size;
    int rank, numproc;
    char * logdir;

    if (argc != 9) {
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    coeff_a = atoi(argv[1]);
    coeff_b = atoi(argv[2]);
    coeff_c = atoi(argv[3]);
    coeff_d = atoi(argv[4]);

    h_height = atoi(argv[5]);
    l_height = atoi(argv[6]);

    chunk_size = atoi(argv[7]);
    logdir = argv[8];
    if (strncmp(logdir, "/dev/null", 20) == 0) {
        DO_LOGGING = 0;
        printf("Not logging results to file.\n");
    }

    MPI_Init ( &argc, &argv );
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    MPI_Comm_size (MPI_COMM_WORLD, &numproc);

    process_range(coeff_a, 
            coeff_b, 
            coeff_c, 
            coeff_d, 
            h_height, 
            l_height, 
            chunk_size, 
            rank, 
            numproc,
            logdir);
    MPI_Finalize();

    return EXIT_SUCCESS;
}
