#!/bin/bash 

for name in "$@"
do
    xxd -i $name
done
