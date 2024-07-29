#!/bin/sh

echo "----------------"
echo "--- test 2 -----"
echo "Testing solutions of primes between 0 and 12."
echo "Heap reuse."
echo "----------------"
../search 2 3 -5 -7 12 0 40 /tmp > /dev/null

echo "Performing diff. If you see output, there is an error\n"
cat /tmp/log_000.log | sort | uniq | diff - ./test2.res
