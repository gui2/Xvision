# run job using bash from directory it was submitted from

#! /bin/bash
#$ -cwd

#$ -j y
#$ -R y
#$ -w e

# email address to send notices to
#$ -M guido.pusiol@google.com
#$ -m beas

# set a name to make it easy to pick out of qstat output$
#$ -N LEARN-FRONTAL-BODY.1.10

# if you need more than 1 slot on the same machine
#$ -pe fah 8

#memory request (if you want something other than default 4GB hard limit)
  ##$ -l h_vmem=XG

##echo "loading...."
##module load python

##echo "loading matlab" 
##module load MATLAB-R20122

##echo ""
##echo "final list"
##module list

#just print the name of this machine
nohup ./dpmcreate --positive-list /mnt/glusterfs/pusiol/UpperBodyData/hotelped/Train2/posup.txt  --background-list /mnt/glusterfs/pusiol/UpperBodyData/hotelped/Train2/Neg.txt  --negative-count 12000 --model-component 1 --model-part 6 --working-dir /mnt/glusterfs/pusiol/UpperBodyData/UPPER.1.6 --base-dir  /mnt/glusterfs/pusiol/UpperBodyData/hotelped/Train2/;

