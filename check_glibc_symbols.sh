#!/bin/bash

LIB=$1

if [ ! -f $LIB ]; then
    echo "Error: file ${LIB} does not exist"
    exit 1
fi

# tls is accepted by Valgrind
nm -u ${LIB} | grep GLIBC | grep -v __tls_get_addr >symbols
if [[ $? == 0 ]]; then
    echo "Error: ${LIB} contains GLIB symbols"
    cat symbols
    echo "Remove them in order to be compatible with Verrou"
    exit 1
fi
