#!/bin/sh

i=0;
for arrnumb in */0/*.jpg ;do
let i=i+1;

cp $arrnumb "ANGLE0/$i.jpg"; 
printf "  %s\n" $arrnumb
done


