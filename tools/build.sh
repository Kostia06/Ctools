#!/bin/bash

CC="clang"
NAME="ctools"
C_FLAGS="-lobjc -std=gnu2x"
SRC=$(find ../src/ -type f -name "*.c" -o -name "*.m")
ARGS=""
for i in {1..10}
do
    if [ -n "${!i}" ]; then
        ARGS+=${!i}
        ARGS+=" "
    fi
done

$CC $C_FLAGS $SRC -o $NAME

EXECUTE="./$NAME"

time $EXECUTE $ARGS
