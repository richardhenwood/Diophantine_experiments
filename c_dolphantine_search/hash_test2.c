#include "glib.h"
#include <stdio.h>
#include <stdlib.h>
#include <search.h>
#include <gmp.h>

struct value_pair
{
    int u;
    int v;
};


static void
destroy_hash_values_func (GSList *list) {
    g_slist_free(list);
    return;
}

int main(int argc, char *argv[]) {
    GHashTable * g_hash_table = NULL;
    int i;

    g_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, (GDestroyNotify) destroy_hash_values_func);
    for
}

int
perform_lookup_uv(
        int rank, int numproc,
        int coeff_a, int coeff_b, int coeff_c, int coeff_d,
        long long int height, long long int lower,
        long int hash_chunk_size) {

    GHashTable * g_hash_table = NULL;
    GSList *list = NULL;
//    GSList *iter = NULL;
    unsigned long long int count = 0;

    char * key_char;
    //struct value_pair * uv_pair;
    struct value_pair * uv_pair = g_new(struct value_pair, 1);

    //value_pair *uv_pair = NULL;
    //uv_pair = malloc(sizeof(struct value_pair));
//    struct value_pair *uv_pair = g_slice_new(struct value_pair);

    long long int current_u;
    long long int current_v;

    mpz_t key_u_mpz;
    mpz_t key_v_mpz;
    mpz_init(key_u_mpz);
    mpz_init(key_v_mpz);

    //g_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify) destroy_hash_values_func);
    //g_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, NULL);
    //g_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, g_free);
    g_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, (GDestroyNotify) destroy_hash_values_func);
    //g_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, NULL);

    current_u = -height + rank;
    while (current_u <= height) {
        current_v = -height;
        while (current_v <= height) {

            //struct value_pair *uv_pair = g_slice_new(struct value_pair);
            //struct value_pair *uv_pair = g_new(struct value_pair, 0);
            //uv_pair = g_new(struct value_pair, 1);
            uv_pair->u = current_u;
            uv_pair->v = current_v;

            mpz_set_si(key_u_mpz, current_u);
            mpz_pow_ui(key_u_mpz, key_u_mpz, 3);
            mpz_mul_si(key_u_mpz, key_u_mpz, coeff_c);
            mpz_set_si(key_v_mpz, current_v);
            mpz_pow_ui(key_v_mpz, key_v_mpz, 3);
            mpz_mul_si(key_v_mpz, key_v_mpz, coeff_d);
            mpz_add(key_u_mpz, key_u_mpz, key_v_mpz);

            key_char = mpz_get_str(NULL, 10, key_u_mpz);

            if ( g_hash_table_lookup(g_hash_table, key_char) == NULL) {
                //printf("creating new list on hash: %s\n", key_char);
                GSList *list = NULL;

                //GSList *list = g_slice_new(GSList*);
                //list = NULL;
                list = g_slist_prepend(list, uv_pair);
                g_hash_table_insert(g_hash_table, key_char, list);
                

                //g_hash_table_insert(g_hash_table, key_char, (gpointer)uv_pair);
            }
            else {
                // in this case, there is already a value for this key.
                // So get the value (which is a list) and add our new uv_pair to it.
                //printf("adding to hash list: %s\n", key_char);
                list = g_hash_table_lookup(g_hash_table, key_char);
                list = g_slist_prepend(list, uv_pair);
                
                //g_hash_table_insert(g_hash_table, key_char, list);

                //for (iter = list; iter; iter = iter->next) {
                //    uv_pair = (struct value_pair *)iter->data;
                //     printf("key = '%s', value = (%lld, %lld)\n", key_char, uv_pair->u, uv_pair->v);
                //}
            }
            //uv_pair = g_hash_table_lookup(g_hash_table, key_char);

            count++;
            if (count % hash_chunk_size == 0) {
                test_against_ab(coeff_a, coeff_b, height, lower, g_hash_table, rank);

                printf("destroying hash on count '%lld'\n", count);
                //g_hash_table_remove_all(g_hash_table);
                //g_hash_table_destroy(g_hash_table);
                //g_hash_table = NULL;
                //g_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, NULL, (GDestroyNotify) destroy_hash_values_func);
                //g_hash_table = g_hash_table_new_full(g_str_hash, g_str_equal, g_free, (GDestroyNotify) destroy_hash_values_func);
            }

            current_v = current_v + 1;
            if (current_v > - lower && current_v < lower) {
                current_v = lower;
            }
            free(key_char);
        }
        current_u = current_u + numproc;
        if (current_u > - lower && current_u < lower) {
            current_u = lower + rank;
        }
    }

    //free(uv_pair);
    //free(key_char);

    printf(" size: %d\n",g_hash_table_size(g_hash_table));
    g_hash_table_destroy(g_hash_table);
    //g_slist_free(list);
   
    mpz_clear(key_u_mpz);
    mpz_clear(key_v_mpz);
    return 0;
}

int 
print_hash_table (GHashTable * htable) {
    GHashTableIter hiter;
    GSList * uv_list = NULL;
    GSList * liter = NULL;
    unsigned long long int hsize; 
    char * key_char;
    struct value_pair * uv_pair;
    
    hsize = g_hash_table_size(htable);
    printf("First size: %lld\n",hsize);

    g_hash_table_iter_init(&hiter, htable);
    while (g_hash_table_iter_next (&hiter, (gpointer)&key_char, (gpointer)&uv_list)) {
        printf("key = '%s'\n", key_char);

        for (liter = uv_list; liter; liter = liter->next) {

            uv_pair = (struct value_pair *)liter->data;
            printf("\tfinal value = (%lld, %lld)\n", uv_pair->u, uv_pair->v);
        }
    }

    return 0;
}

void usage (char * progname) {
    printf("need more command line arguments\n");
    printf("example: %s 2 3 -5 -7 1000 0 2500000 /path/for/logfiles\n\n", progname);
}




int main(int argc, char *argv[]) {

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
