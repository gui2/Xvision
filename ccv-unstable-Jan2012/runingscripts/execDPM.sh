#!/bin/sh

##shopt -s nullglob;
declare -a arr1=('/mnt/glusterfs/pusiol/Data/ADL-DATA/P7_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P8_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P9_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P10_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P11_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P12_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P13_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P14_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P15_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P16_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P17_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P18_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P19_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P20_Short-Results/')

## declare -a arr1=('/mnt/glusterfs/pusiol/Data/ADL-DATA/P7_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P8_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P9_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P10_Short-Results/' '/mnt/glusterfs/pusiol/Data/ADL-DATA/P11_Short-Results/')

##declare -a arr1=('/mnt/glusterfs/pusiol/Data/P7_Short-Results/' '/mnt/glusterfs/pusiol/Data/P8_Short-Results/')

## DPM 1.8-flow
##declare -a arr2=('/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/ARMS2-DPM.1.8/P7_Short-Results-P1.1.8/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/ARMS2-DPM.1.8/P8_Short-Results-P1.1.8/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/ARMS2-DPM.1.8/P9_Short-Results-P1.1.8/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/ARMS2-DPM.1.8/P10_Short-Results-P1.1.8/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/ARMS2-DPM.1.8/P11_Short-Results-P1.1.8/')

##declare -a arr2=('/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/COLOR.2.10/P7_Short-Results-P1.2.10/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/COLOR.2.10/P8_Short-Results-P1.2.10/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/COLOR.2.10/P9_Short-Results-P1.2.10/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/COLOR.2.10/P10_Short-Results-P1.2.10/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/COLOR.2.10/P11_Short-Results-P1.2.10/')

declare -a arr2=('/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/P2.ARMS2-DPM.1.8/P7_PERSON2.1.8-REAL/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/P2.ARMS2-DPM.1.8/P8_PERSON2.1.8-REAL/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/P2.ARMS2-DPM.1.8/P9_PERSON2.1.8-REAL/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/P2.ARMS2-DPM.1.8/P10_PERSON2.1.8-REAL/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/P2.ARMS2-DPM.1.8/P11_PERSON2.1.8-REAL/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/P2.ARMS2-DPM.1.8/P12_PERSON2.1.8-REAL/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/P2.ARMS2-DPM.1.8/P13_PERSON2.1.8-REAL/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/P2.ARMS2-DPM.1.8/P14_PERSON2.1.8-REAL/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/P2.ARMS2-DPM.1.8/P15_PERSON2.1.8-REAL/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/P2.ARMS2-DPM.1.8/P16_PERSON2.1.8-REAL/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/P2.ARMS2-DPM.1.8/P17_PERSON2.1.8-REAL/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/P2.ARMS2-DPM.1.8/P18_PERSON2.1.8-REAL/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/P2.ARMS2-DPM.1.8/P19_PERSON2.1.8-REAL/' '/mnt/glusterfs/pusiol/Data/NIPS-RESULTS/P2.ARMS2-DPM.1.8/P20_PERSON2.1.8-REAL/')


for arrnumb in ${!arr1[*]} ;do
printf "   %d\n" $arrnumb
done

for arrnumb in ${!arr2[*]} ;do
mkdir ${arr2[$arrnumb]}
done


for arrnumb in ${!arr1[*]} ;do
for f in ${arr1[$arrnumb]}*.jpg; do
    ## verify that  file exists already in the output folder
    b=$(basename $f);
    out=${arr2[$arrnumb]}
    c="$out$b.txt"
    ##if not exists then process o el archivo no tiene datos
    if [[ -f "$c" ]] ##&& [ -s "$c" ];
    then
    echo "SKIPPING: $c"  
    else
    echo "PROCESSING $c" 
    ./dpmdetect "$f" /mnt/glusterfs/pusiol/TrainingData/flowtrain/P2.MODEL.4.10/model ${arr2[$arrnumb]}
    fi
    ##((i++));
done
done
