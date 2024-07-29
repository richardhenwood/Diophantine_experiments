#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <utility> // make_pair
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
// An IFDEF complier switch
// to include the correct GMP header.
// The correct mkl header depends on the
// target (i.e. desktop linux or HPC cluster with intel MKL)
#ifdef __GNUC__
    #include <gmp.h>
#else
    #include "mkl_gmp.h"
#endif
#include <mpi.h>

#define DEBUG 1

using namespace std;

// This code solves a problem for T.D. Browning et al.
// long int values are good for up-to ~2billion on typical architectures.

struct uv_long {
    long long int u;
    long long int v;
};


void test_ab (long int coeff_a, long int coeff_b, long int h_height, long int l_height, multimap<string, uv_long> &myMMap, int rank, char * logpath);
string format_solution (long int x, long int y, long int u, long int v);
long int get_max (long int x, long int y, long int u, long int v);
int process_range (
    long long int h_height, 
    long long int l_height, 
    int rank, 
    int numproc,
    int coeff_a,
    int coeff_b,
    int coeff_u,
    int coeff_v, 
    long int chunksize,
    char * logpath);
double diffclock(clock_t clock1,clock_t clock2);


void usage (string progname) {
    cout << "need more command line arguments" << endl;
    cout << "example: " << progname << " 2 3 -5 -7 1000 0 2500000 /path/for/logfiles" << endl;
}

int main(int argc, char *argv[]) {
    int rank, numproc;

    if (argc != 9) {
        usage(argv[0]); 
        return 1;
    }

    MPI_Init ( &argc, &argv );
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    MPI_Comm_size (MPI_COMM_WORLD, &numproc);

    int coeff_a = atoi(argv[1]);
    int coeff_b = atoi(argv[2]);
    int coeff_u = atoi(argv[3]);
    int coeff_v = atoi(argv[4]);

    long long int h_height = atoi(argv[5]);
    long long int l_height = atoi(argv[6]);

    long int chunk_size = atoi(argv[7]);

    char * logpath = argv[8];

    process_range(h_height, l_height, rank, numproc, coeff_a, coeff_b, coeff_u, coeff_v, chunk_size, logpath);

    MPI_Finalize ( );

    return 0;
}

int process_range (
    long long int h_height, 
    long long int l_height, 
    int rank, 
    int numproc,
    int coeff_a,
    int coeff_b,
    int coeff_u,
    int coeff_v, 
    long int chunksize,
    char * logpath) {
 
    int current_u;
    int current_v;
    mpz_t uv_sum, v_sum;
    //char * tmpkey;
    //string tmpkeystr;

    long int count = 0;
    float total_tests = pow((h_height - l_height + 0.5)*2,2)/numproc;

    multimap<string, uv_long> myMMap;

    mpz_init(uv_sum);
    mpz_init(v_sum);

    if (DEBUG) {
        cout << "process rank: " << rank << " total quantity of processes: " << numproc << endl;
        cout << "estimated tests: " << total_tests << endl;
    }

    uv_long tmpuv;

    current_u = -h_height + rank;
    while (current_u <= h_height) {
        current_v = -h_height;
        while (current_v <= h_height) {

            tmpuv.u = current_u;
            tmpuv.v = current_v;

            mpz_set_si(v_sum, current_v);
            mpz_pow_ui(v_sum, v_sum, 3);
            mpz_mul_si(v_sum, v_sum, coeff_v);

            mpz_set_si(uv_sum, current_u);
            mpz_pow_ui(uv_sum, uv_sum, 3);
            mpz_mul_si(uv_sum, uv_sum, coeff_u);

            mpz_add(uv_sum, uv_sum, v_sum);
            char * tmpkey = mpz_get_str(NULL, 10, uv_sum);

            string tmpkeystr = tmpkey;
            free(tmpkey);

            myMMap.insert(pair<string, uv_long>(tmpkeystr, tmpuv));

            count++;
            if (count % chunksize == 0) {

                test_ab(coeff_a, coeff_b, h_height, l_height, myMMap, rank, logpath);
                myMMap.clear();

                if (DEBUG)
                    cout << "proc: " << rank << " done: " << count << " ("<< (count/total_tests)*100 << "%)" << endl;

            }

            current_v = current_v + 1;
            if (current_v > - l_height && current_v < l_height) {
                current_v = l_height;
            }
        }

        current_u = current_u + numproc;
        if (current_u > - l_height && current_u < l_height) {
            current_u = l_height + rank;
        }
    }
    test_ab(coeff_a, coeff_b, h_height, l_height, myMMap, rank, logpath);

    mpz_clear(uv_sum);
    mpz_clear(v_sum);
    if (DEBUG) 
        cout << "proc: " << rank << " completed (100%) count = " << count << endl;

    myMMap.clear();
    return 0;
}

void test_ab (long int coeff_a, long int coeff_b, long int h_height, long int l_height, multimap<string, uv_long> &myMMap, int rank, char * logpath) {
    int current_a;
    int current_b;

    mpz_t ab_sum, b_sum;

    multimap<string, uv_long>::iterator it;

    ofstream logfile; 

    char logfilename[50];
    sprintf(logfilename, "%s/log_%03d.log", logpath, rank);
    logfile.open (logfilename, ios::out | ios::app);

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

            // convert the char to a string
            char * tmpkey = mpz_get_str(NULL, 10, ab_sum);
            string tmpkeystr = tmpkey;
            free(tmpkey);
            
            it = myMMap.find( tmpkeystr );
            if ( it != myMMap.end()) {
                
                uv_long uv = it->second;
                logfile << format_solution (current_a, current_b, uv.u, uv.v);

                ++it;
            }
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
    logfile.close();
    return;
}

string format_solution (long int a, long int b, long int u, long int v) {
    char formatted_out[100];
    string tmpstr;
    sprintf(formatted_out, " (%9ld) %9ld %9ld %9ld %9ld\n", get_max(a, b, u, v), a, b, u, v);
    tmpstr = formatted_out;
    return tmpstr;
}

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

double diffclock(clock_t clock1,clock_t clock2)
{
    double diffticks=clock1-clock2;
    double diffms=(diffticks*1000)/CLOCKS_PER_SEC;
    return diffms;
} 
