#!/bin/bash

make clean > /dev/null
make > /dev/null
cp bomb web/bomb
if [ $# -gt 0 ]; then
    python web/server.py
fi