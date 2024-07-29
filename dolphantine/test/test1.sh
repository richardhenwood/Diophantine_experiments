#!/bin/sh

echo "----------------"
echo "--- test 1 -----"
echo "Testing solutions of primes between 0 and 12."
echo "No heap reuse."
echo "----------------"
../search 2 3 -5 -7 12 0 4000 /tmp > /dev/null

echo "Performing diff. If you see output, there is an error\n"
cat /tmp/log_000.log | sort | uniq | diff - ./test1.res
