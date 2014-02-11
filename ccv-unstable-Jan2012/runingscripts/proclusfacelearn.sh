# run job using bash from directory it was submitted from

#! /bin/bash
#$ -cwd

##$ -j y
#$ -R y
#$ -w e

# email address to send notices to
#$ -M guido.pusiol@google.com
#$ -m beas

# set a name to make it easy to pick out of qstat output$
#$ -N D-5-DPMCLUSTER

# if you need more than 1 slot on the same machine
#$ -pe shm 10

#memory request (if you want something other than default 4GB hard limit)
##$ -l h_vmem=XG

##echo "loading...."
##module load python

##echo "loading matlab" 
##module load MATLAB-R2012b

##echo ""
##echo "final list"
##module list

#just print the name of this machine
nohup ./dpmcreate --positive-list /home/pusiol/face/ANGLE0/Pos.txt --background-list /home/pusiol/face/ANGLE0/Neg.txt  --negative-count 20000 --model-component 6 --model-part 12  --working-dir /home/pusiol/face/ANGLE0-MODEL --base-dir /home/pusiol/face/ANGLE0 --symmetric 1  --grayscale 1

##nohup ./dpmcreate --positive-list /mnt/glusterfs/pusiol/TrainingData/flowtrain/Arms/Pos.txt --background-list /mnt/glusterfs/pusiol/TrainingData/flowtrain/Arms/Neg.txt  --negative-count 12000 --model-component 2 --model-part 10  --working-dir /mnt/glusterfs/pusiol/TrainingData/flowtrain/ArmsModelCluster4  --base-dir /mnt/glusterfs/pusiol/TrainingData/flowtrain/Arms --symmetric 0  --grayscale 1

