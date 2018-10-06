#!/bin/bash

echo 'Please enter num1.'
read num1
echo 'Please enter num2.'
read num2

val=`expr $num1 + $num2`
echo "$num1 + $num2 = $val"

val=`expr $num1 - $num2`
echo "$num1 - $num2 = $val"

val=`expr $num1 \* $num2`
echo "$num1 * $num2 = $val"

val=`expr $num1 / $num2`
echo "$num1 / $num2 = $val"
