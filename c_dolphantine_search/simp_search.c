/* Copyright (C) 2002, 2004 Christopher Clark <firstname.lastname@cl.cam.ac.uk> */

#include "lib/hashtable.h"
#include "lib/hashtable_itr.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h> /* for memcmp */
#include <gmp.h>


static const int ITEM_COUNT = 40;
static const int HEIGHT = 10;

//typedef unsigned int uint32_t;
//typedef unsigned short uint16_t;

//typedef long long int llint_t;

/* solve this: ax^3+by^3+cu^3+dv^3=0 */
/*****************************************************************************/
struct key
{
    char * uv_sum;
};

struct value
{
    long long int u;
    long long int v;
};

DEFINE_HASHTABLE_INSERT(insert_some, struct key, struct value);
DEFINE_HASHTABLE_SEARCH(search_some, struct key, struct value);
DEFINE_HASHTABLE_REMOVE(remove_some, struct key, struct value);
DEFINE_HASHTABLE_ITERATOR_SEARCH(search_itr_some, struct key);


/*****************************************************************************/
static char *
hashfromkey(void *ky)
{
    struct key *k = (struct key *)ky;
    return (char *)"char *";
    //return k->uv_sum;
    /*return (((k->one_ip << 17) | (k->one_ip >> 15)) ^ k->two_ip) +
            (k->one_port * 17) + (k->two_port * 13 * 29);*/
}

static int
equalkeys(void *k1, void *k2)
{
    return (0 == memcmp(k1,k2,sizeof(struct key)));
}


struct hashtable *
generate_uv(
        int rank, int numproc, 
        int coeff_a, int coeff_b, int coeff_c, int coeff_d, 
        long long int height, long long int lower ) {
    struct key *k;
    struct value *v;

    long long int current_u;
    long long int current_v;

    mpz_t key_u_mpz;
    mpz_t key_v_mpz;
    mpz_init(key_u_mpz);
    mpz_init(key_v_mpz);

    struct hashtable *h;
    h = create_hashtable(16, hashfromkey, equalkeys);
    
    current_u = -height + rank;
    while (current_u <= height) {
        current_v = -height;
        while (current_v <= height) {

            v = (struct value *)malloc(sizeof(struct value));
            v->u = current_u;
            v->v = current_v;

            k = (struct key *)malloc(sizeof(struct key));

            mpz_set_si(key_u_mpz, current_u);
            mpz_pow_ui(key_u_mpz, key_u_mpz, 3);
            mpz_mul_si(key_u_mpz, key_u_mpz, coeff_c);
            mpz_set_si(key_v_mpz, current_v);
            mpz_pow_ui(key_v_mpz, key_v_mpz, 3);
            mpz_mul_si(key_v_mpz, key_v_mpz, coeff_d);
            mpz_add(key_u_mpz, key_u_mpz, key_v_mpz);

            k->uv_sum = mpz_get_str(NULL, 10, key_u_mpz);

            //k->uv_sum = coeff_c*(current_u^3) + coeff_d*(current_v^3);

            if (!insert_some(h,k,v)) exit(-1); /*oom*/

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
    printf("After insertion, uv_hashtable contains %u items.\n",
            hashtable_count(h));

    mpz_clear(key_u_mpz);
    mpz_clear(key_v_mpz);
    return h;

}

int print_hashtable(struct hashtable * h) {
    struct hashtable_itr *itr;
    struct key *k;
    struct value *v;
    long long int i;

    itr = hashtable_iterator(h);
    i = 0;
    if (hashtable_count(h) > 0)
    {
        do {
            k = hashtable_iterator_key(itr);
            v = hashtable_iterator_value(itr);
            /* here (kk,v) are a valid (key, value) pair */
            /* We could call 'hashtable_remove(h,kk)' - and this operation
             * 'free's kk. However, the iterator is then broken.
             * This is why hashtable_iterator_remove exists - see below.
             */
            i++;
            printf("key = %s value = (%lld, %lld)\n", k->uv_sum, v->u, v->v);

        } while (hashtable_iterator_advance(itr));
    }
    printf("Iterated through %lld entries.\n", i);
    free(k);
    free(v);
    free(itr);

    return 0;

}


/*****************************************************************************/
int
main(int argc, char **argv)
{
    struct key *k, *kk;
    struct value *v, *found;
    struct hashtable *h;
    struct hashtable_itr *itr;
    int i;

    struct hashtable *uv_hash;

    uv_hash = generate_uv(0, 1, 2, 3, -5, -7, 10, 0);
    print_hashtable(uv_hash);

    h = create_hashtable(16, hashfromkey, equalkeys);
    if (NULL == h) exit(-1); /*oom*/


/*****************************************************************************/
/* Insertion */
    for (i = 0; i < ITEM_COUNT; i++)
    {
        k = (struct key *)malloc(sizeof(struct key));
        if (NULL == k) {
            printf("ran out of memory allocating a key\n");
            return 1;
        }
        k->uv_sum = 1000 + i;
        
        v = (struct value *)malloc(sizeof(struct value));
        v->u = 12;
        v->v = 13;
        
        if (!insert_some(h,k,v)) exit(-1); /*oom*/
    }
    printf("After insertion, hashtable contains %u items.\n",
            hashtable_count(h));

/*****************************************************************************/
/* Hashtable search */
    k = (struct key *)malloc(sizeof(struct key));
    if (NULL == k) {
        printf("ran out of memory allocating a key\n");
        return 1;
    }
    
    for (i = 0; i < ITEM_COUNT; i++)
    {
        k->uv_sum = 1000 + i;
        
        if (NULL == (found = search_some(h,k))) {
            printf("BUG: key not found\n");
        }
    }

/*****************************************************************************/
/* Hashtable iteration */
    /* Iterator constructor only returns a valid iterator if
     * the hashtable is not empty */
    itr = hashtable_iterator(h);
    i = 0;
    if (hashtable_count(h) > 0)
    {
        do {
            kk = hashtable_iterator_key(itr);
            v = hashtable_iterator_value(itr);
            /* here (kk,v) are a valid (key, value) pair */
            /* We could call 'hashtable_remove(h,kk)' - and this operation
             * 'free's kk. However, the iterator is then broken.
             * This is why hashtable_iterator_remove exists - see below.
             */
            i++;
   //         printf("key = %lld value = (%lld, %lld)\n", kk->uv_sum, v->u, v->v);

        } while (hashtable_iterator_advance(itr));
    }
    //printf("Iterated through %u entries.\n", i);

/*****************************************************************************/
/* Hashtable iterator search */

    /* Try the search some method */
    for (i = 0; i < ITEM_COUNT; i++)
    {
        k->uv_sum = 1000 + i;
        
        if (0 == search_itr_some(itr,h,k)) {
            printf("BUG: key not found searching with iterator");
        }
    }

/*****************************************************************************/
/* Hashtable removal */

    for (i = 0; i < ITEM_COUNT; i++)
    {
        k->uv_sum = 1000 + i;
        
        if (NULL == (found = remove_some(h,k))) {
            printf("BUG: key not found for removal\n");
        }
    }
    printf("After removal, hashtable contains %u items.\n",
            hashtable_count(h));

/*****************************************************************************/
/* Hashtable destroy and create */

    hashtable_destroy(h, 1);
    h = NULL;
    free(k);

    h = create_hashtable(160, hashfromkey, equalkeys);
    if (NULL == h) {
        printf("out of memory allocating second hashtable\n");
        return 1;
    }

/*****************************************************************************/
/* Hashtable insertion */

    for (i = 0; i < ITEM_COUNT; i++)
    {
        k = (struct key *)malloc(sizeof(struct key));
        k->uv_sum = 1000 + i;
        
        v = (struct value *)malloc(sizeof(struct value));
        v->u = 12;
        v->v = 13;
        
        if (!insert_some(h,k,v))
        {
            printf("out of memory inserting into second hashtable\n");
            return 1;
        }
    }
    printf("After insertion, hashtable contains %u items.\n",
            hashtable_count(h));

/*****************************************************************************/
/* Hashtable iterator search and iterator remove */

    k = (struct key *)malloc(sizeof(struct key));
    if (NULL == k) {
        printf("ran out of memory allocating a key\n");
        return 1;
    }
    
    for (i = ITEM_COUNT - 1; i >= 0; i = i - 7)
    {
        k->uv_sum = 1000 + i;
        
        if (0 == search_itr_some(itr, h, k)) {
            printf("BUG: key %u not found for search preremoval using iterator\n", i);
            return 1;
        }
        if (0 == hashtable_iterator_remove(itr)) {
            printf("BUG: key not found for removal using iterator\n");
            return 1;
        }
    }
    free(itr);

/*****************************************************************************/
/* Hashtable iterator remove and advance */

    for (itr = hashtable_iterator(h);
         hashtable_iterator_remove(itr) != 0; ) {
        ;
    }
    free(itr);
    printf("After removal, hashtable contains %u items.\n",
            hashtable_count(h));

/*****************************************************************************/
/* Hashtable destroy */

    hashtable_destroy(h, 1);
    free(k);
    return 0;
}

