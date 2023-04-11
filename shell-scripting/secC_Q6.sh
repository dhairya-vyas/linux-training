#!/bin/bash
directory_path="/home/dhairya/Desktop"

for entry in "$directory_path"/*
do 
    if [ -d "$entry" ]
    then
        echo "$entry is a directory"
    elif [ -f "$entry" ]
    then   
        echo "entry is a file"
    else
        echo "$entry is not a valid file or directory"
    fi
done    