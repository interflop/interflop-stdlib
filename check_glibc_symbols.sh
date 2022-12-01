#!/bin/bash

LIB=$1

if [ ! -f $LIB ]; then
    echo "Error: file ${LIB} does not exist"
    exit 1
fi

nm -u ${LIB} | grep GLIBC >symbols
if [[ $? == 0 ]]; then
    echo "Error: ${LIB} contains GLIB symbols"
    cat symbols
    echo "Remove them in order to be compatible with Verrou"
    exit 1
fi
