#!/bin/bash

echo "1.To find length of strings"
echo "2.Copying string"
echo "3. Concatenation of Strings"
echo "4. comparison of string"
echo "5. reversing of strings"
echo "6. Exit"
echo -n "Enter your menu choice[1-6]:"

while true
do

read choice
case $choice in

1str="this is a sample string"
    n=${#str}
    echo "Length of the string is: $n"

2 source_string ="Hello from Scaledge"
    destination_string=""
    echo "source string: $source_string"
    echo "Destination string (before copy): $destination_string"

    destination_string=$source_string
    echo "Destination string(after copy): $destination_string"

3 read a b
    a+=$b
    echo $a

4 var1="Dhairya"
    var2="Dhairya"

    if ["$var1" = "$var2"]; then
        echo "String are equal"
    else
        echo "strings are not equal"
    fi

5 s= "Hello world"
    revstr=`echo $s |rev`
    echo "original string : $s"
    echo "Reversed string :revstr"

6 echo "Exiting..."
exit;;

* echo "invalid option ";;

esac
echo -n "Enter your menu choice[1-6]:"
done