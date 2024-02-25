#!/bin/sh

dirName=$1
fileName=$2

# compile
g++-12 -std=gnu++2b \
-O2 -DONLINE_JUDGE -DATCODER \
-Wall -Wextra \
-mtune=native -march=native \
-fconstexpr-depth=2147483647 -fconstexpr-loop-limit=2147483647 -fconstexpr-ops-limit=2147483647 \
-I/opt/ac-library \
-I/opt/boost/gcc/include \
-L/opt/boost/gcc/lib \
-o a.out ${dirName}/${fileName} \
-Igmpxx -Igmp \
-I/usr/include/eigen3 \

if [ $? -ne 0 ]; then
    echo "[\033[31mERROR\033[0m] Compile"
    exit 1
fi
echo "[\033[34mSUCCESS\033[0m] Compile"
