#!/bin/sh

echo "----------------"
echo "--- test 3 -----"
echo "Testing solutions of primes between 0 and 12."
echo "No heap reuse."
echo "Running with MPI, 2 processes"
echo "----------------"
mpirun -np 2 ../search 2 3 -5 -7 12 0 40000 /tmp > /dev/null

echo "Performing diff. If you see output, there is an error\n"
cat /tmp/log_000.log /tmp/log_001.log | sort | uniq | diff - ./test3.res
