#!/bin/sh

INC_DIR=/usr/include
LIB_DIR=/usr/lib

cp -v bin/libits.so "${LIB_DIR}"
cp -v src/its.h "${INC_DIR}"

