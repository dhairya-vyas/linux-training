#!/bin/bash

curr_year=$(date+%Y)
curr_month=$(date+%m)

prev_year=$(expr $curr_year -1)
echo "Calendar for $curr_month $prev_year:"
cal $curr_month $prev_year

next_year=$(expr $curr_year +1)
echo "Calendar for $curr_month $next_year:"
cal $curr_month $next_year
