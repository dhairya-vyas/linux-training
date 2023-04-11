#!/bin/bash

echo "Enter a Year: "
read year

if (($(($year %4))== 0 && (($year %100)) != 0 || $(($year%400))== 0)); then
echo $year is a leap year"
else
echo "$year id not a leap year"
fi
