#!/bin/bash

make clean > /dev/null
make > /dev/null
cp bomb web/bomb
if [ $# -gt 0 ]; then
    cd web
    python server.py
fi
