##!/bin/sh

##shopt -s nullglob;

declare -a arr1="/home/lomazzacamo/headcam-cropped/";
declare -a arr2='/home/lomazzacamo/headcam-cropped/frames/';



for arrnumb in ${!arr1[*]} ;do
printf "   %d\n" $arrnumb
done

#for arrnumb in ${!arr2[*]} ;do
#mkdir ${arr2[$arrnumb]}
#echo ${arr2[$arrnumb]}
#done

for arrnumb in ${!arr1[*]} ;do
for f in ${arr1[$arrnumb]}*.mov; do
    ## verify that  file exists already in the output folder
    b=$(basename $f);
    out=${arr2[$arrnumb]}
    c="$out$b/"
    #mkdir $c
    ##if not exists then process o el archivo no tiene datos
    if [[ -f "$c" ]] 
     then
     echo "SKIPPING: $f"  
     else
     echo "PROCESSING $f" 
     ##echo ./opentld -d VID -i "$f" -w "$c";
     ./opentld -d VID -i "$f" -p "$c";
    fi
done
done
