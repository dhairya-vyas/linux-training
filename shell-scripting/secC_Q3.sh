#!/bin/sh

if [ -e $1]
then
    echo "The provided argument is the directory."

elif [ -f $1]
then    
    echo "The provided argument is the file"

else   
    echo "the given argument does not exist on the file system"

fi