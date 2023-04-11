#!/bin/bash
echo "Enter 3 numbers:"
read a b c

if ((a>b && a>c))
then
    echo "$a is biggest number"
elif ((b>a && b>c))
then
    echo "$b is biggest number"

else 
    echo "$c is biggest number"

avg=$(echo"($a + $b + $c) / 3" | bc)
echo "/n The average of $a,$b, and $c is $avg "
fi