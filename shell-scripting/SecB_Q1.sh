#!/bin/sh
echo "Enter two number:"
read num1 num2

sum =$(expr $num1 + $num2)
product =$(expr $num1\* $num2)

echo "Sum: $sum"
echo "Product: $product"

let sum =$(expr $num1 + $num2)
let product =$(expr $num1\* $num2)

echo "Sum: $sum"
echo "Product: $product"

sum =$(echo "$num1 + $num2" | bc)
product =$(echo "$num1* $num2" | bc)

echo "Sum: $sum"
echo "Product: $product"


