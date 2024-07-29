#include <stdio.h>
#include <stdlib.h>
#ifdef __GNUC__
    #include <gmp.h>
#else
    #include "mkl_gmp.h"
#endif
#include "uthash.h"
#include "utlist.h"

typedef struct value_pair
{
    long long int u;
    long long int v;
    struct value_pair *next;
    //char *uvstr;
} value_pair; // typedef value_pair;

value_pair *
new_value_pair () {
    return (value_pair *) malloc (sizeof(value_pair));
    //return g_new (value_pair, 1);
}

struct uv_struct {
    //char * uv_str[100];
    char *uv_str;
    value_pair *head;
    UT_hash_handle hh;
};

void print_intemediary(long long int count, long long int u, long long int v, mpz_t mp_sum) {
    //printf("%lld value = %lld %lld ", count, u, v);
    mpz_out_str (stdout, 10, mp_sum);
    printf("\n");
}

int
perform_lookup_uv(
        int rank, int numproc,
        int coeff_a, int coeff_b, int coeff_c, int coeff_d,
        long long int height, long long int lower,
        long int hash_chunk_size) {

    struct uv_struct *s, *uv_hash_table = NULL;
    struct uv_struct *current_uv, *uv_htmp;
    value_pair *uv_list, *elt, *eltmp;
//    value_pair *uv_pair;

    unsigned long long int count = 0;
    char * key_char;
    //char key_char[200];

    long long int current_u;
    long long int current_v;

    mpz_t key_u_mpz;
    mpz_t key_v_mpz;
    mpz_init(key_u_mpz);
    mpz_init(key_v_mpz);

    current_u = -height + rank;
    while (current_u <= height) {
        current_v = -height;
        while (current_v <= height) {
            //printf("loop: %lld, %lld\n", current_v, height);
            //;uv_list = new_value_pair();

            mpz_set_si(key_u_mpz, current_u);
            mpz_pow_ui(key_u_mpz, key_u_mpz, 3);
            mpz_mul_si(key_u_mpz, key_u_mpz, coeff_c);
            mpz_set_si(key_v_mpz, current_v);
            mpz_pow_ui(key_v_mpz, key_v_mpz, 3);
            mpz_mul_si(key_v_mpz, key_v_mpz, coeff_d);
            mpz_add(key_u_mpz, key_u_mpz, key_v_mpz);

            //print_intemediary(count, current_u, current_v, key_u_mpz);

            //printf("mpz_get_str...");
            key_char = mpz_get_str(NULL, 10, key_u_mpz);
            //mpz_get_str(key_char, 10, key_u_mpz);
            //key_char = "hellowork";
            
            //printf("looking up str %s\n", key_char);
            HASH_FIND_STR(uv_hash_table, key_char, s);
            //printf("finished lokup\n");
            if (s) {
                printf("hash values already exists.\n\n");
            }
            else {
                //printf("make new!");
                // if there is no hash for this 
                // value of the sum, create it - and 
                // a linked list to store the values of uv.
                s = (struct uv_struct*)malloc(sizeof(struct uv_struct));
                if (s == NULL) { // can't allocate memory 
                    exit(1);
                }
                //s->uv_str = key_char;
                s->uv_str = (char *)malloc(sizeof(char)*strlen(key_char)+1);
                strcpy(s->uv_str, key_char);
                s->head = NULL;

            }
            //printf("create element");
            uv_list = (value_pair*)malloc(sizeof(value_pair));
            if (uv_list == NULL) { // can't allocate memory 
                exit(1);
            }
            uv_list->u = current_u;
            uv_list->v = current_v;
            //uv_list = (value_pair*)malloc(size_of(value_pair));
            //strncpy(uv_list->u, current_u);
            //strncpy(uv_list->v, current_v);
            //printf("now append!"); 
            LL_APPEND(s->head, uv_list);
            //printf("now add!"); 
            //HASH_ADD_KEYPTR( hh, uv_hash_table, s->uv_str, strlen(s->uv_str), s );
            HASH_ADD_STR( uv_hash_table, uv_str, s );

            count++;
            if (count % hash_chunk_size == 0) {
                printf("count = chunksize %ld ", hash_chunk_size);
                test_against_ab(coeff_a, coeff_b, height, lower, uv_hash_table, rank);

                printf("destroying hash on count '%lld'\n", count);

                HASH_ITER(hh, uv_hash_table, current_uv, uv_htmp) {
                    LL_FOREACH_SAFE(current_uv->head, elt, eltmp) {
//                        printf("%lld, %lld '%s'\n", elt->u, elt->v, current_uv->uv_str);
                        LL_DELETE (s->head, elt);
                        free(elt);
                    }
                    free(current_uv->uv_str);
                    HASH_DEL(uv_hash_table, current_uv);
                    free(current_uv);
                }

                //g_hash_table_remove_all(g_hash_table);

                //g_hash_table_destroy(g_hash_table);
                //g_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, (GDestroyNotify) destroy_hash_values_func);

                //g_hash_table = NULL;
                //g_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, (GDestroyNotify) destroy_hash_values_func);
                //g_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify) destroy_hash_values_func);
            }

            current_v = current_v + 1;
            if (current_v > - lower && current_v < lower) {
                current_v = lower;
            }
            //free(key_char);
            //printf("now finish\n"); 
        }
        current_u = current_u + numproc;
        if (current_u > - lower && current_u < lower) {
            current_u = lower + rank;
        }
    }

    //free(uv_pair);
    //free(key_char);

    //printf(" size: %d\n",g_hash_table_size(uv_hash_table));
    //g_hash_table_destroy(g_hash_table);
    //g_free(list);
    //g_slist_free(list);
   
    mpz_clear(key_u_mpz);
    mpz_clear(key_v_mpz);
    return 0;
}

int test_against_ab () {
    return 0;
}


//int 
//print_hash_table (GHashTable * htable) {
//    GHashTableIter hiter;
//    GSList * uv_list = NULL;
//    GSList * liter = NULL;
//    unsigned long long int hsize; 
//    char * key_char;
//    value_pair * uv_pair;
//    
//    hsize = g_hash_table_size(htable);
//    printf("First size: %lld\n",hsize);
//
//    g_hash_table_iter_init(&hiter, htable);
//    while (g_hash_table_iter_next (&hiter, (gpointer)&key_char, (gpointer)&uv_list)) {
//        printf("key = '%s'\n", key_char);
//
//        for (liter = uv_list; liter; liter = liter->next) {
//
//            uv_pair = (value_pair *)liter->data;
//            //printf("\tfinal value = (%s)\n", uv_pair->uvstr);
//        }
//    }
//
//    return 0;
//}

void usage (char * progname) {
    printf("need more command line arguments\n");
    printf("example: %s 2 3 -5 -7 1000 0 2500000 /path/for/logfiles\n\n", progname);
}




int main(int argc, char *argv[]) {
    //g_mem_set_vtable (glib_mem_profiler_table);

    if (argc != 9) {
        usage(argv[0]);
        return 1;
    }

    int coeff_a = atoi(argv[1]);
    int coeff_b = atoi(argv[2]);
    int coeff_c = atoi(argv[3]);
    int coeff_d = atoi(argv[4]);

    long long int h_height = atoi(argv[5]);
    long long int l_height = atoi(argv[6]);

    long int chunk_size = atoi(argv[7]);

    //char * logpath = argv[8];



    perform_lookup_uv(0, 1, coeff_a, coeff_b, coeff_c, coeff_d, h_height, l_height, chunk_size);
    return 0;
}
