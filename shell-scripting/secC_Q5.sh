#!/bin/bash
for i in {1..10}
do
if [ -e exam${i} ]
then
    echo exam ${i} can not be created because it already exist
else 
    mkdir exam${i}
fi
done