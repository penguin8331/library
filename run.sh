#!/bin/bash
dirName=${1}
fileName=${2}

# compile
g++ -std=gnu++17 -Wall -Wextra -O2 -DONLINE_JUDGE -I/opt/boost/gcc/include -L/opt/boost/gcc/lib -I/opt/ac-library -o ./a.out ${dirName}/${fileName}
if [ $? -ne 0 ]; then
    echo "[\033[31mERROR\033[0m] Compile"
    exit 1
fi
echo "[\033[34mSUCCESS\033[0m] Compile"
