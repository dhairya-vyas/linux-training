#!/bin/bash
echo "Enter 3 numbers:"
read a b c

if ((a==b && a==c))
then
    echo "It is an equilateral triangle"
elif ((a==b||b==c||a==c ))
then
   echo "It is an isoceles triangle"

else 
   echo "It is an scalene triangle"
fi