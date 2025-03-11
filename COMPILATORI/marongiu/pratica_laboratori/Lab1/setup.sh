#!/bin/bash

export ROOT_LABS=/Users/hoolywear/Desktop/UNIMORE/III_ANNO/COMPILATORI/marongiu/pratica_laboratori
export LLVM_DIR=/opt/homebrew/opt/llvm

cd build

cmake -DLT_LLVM_INSTALL_DIR=$LLVM_DIR $ROOT_LABS/Lab1/

make
