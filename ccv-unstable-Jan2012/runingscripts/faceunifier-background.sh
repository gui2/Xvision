#!/bin/sh

i=0;
for arrnumb in /afs/.ir/users/p/u/pusiol/Data/background/*.jpg ;do
let i=i+1;

mv $arrnumb "/afs/.ir/users/p/u/pusiol/Data/background/back$i.jpg"; 
printf "  %s\n" $arrnumb
done


