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
#$ -N Hands4-8

# if you need more than 1 slot on the same machine
#$ -pe fah 20

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
nohup ./dpmcreate --positive-list /mnt/glusterfs/pusiol/TrainingData/flowtrain/Hands/Pos.txt --background-list /mnt/glusterfs/pusiol/TrainingData/flowtrain/Hands/Neg.txt  --negative-count 8000 --model-component 4 --model-part 8  --working-dir /mnt/glusterfs/pusiol/TrainingData/flowtrain/HandsModelCluster4-8  --base-dir /mnt/glusterfs/pusiol/TrainingData/flowtrain/Hands --symmetric 0  --grayscale 1

##nohup ./dpmcreate --positive-list /mnt/glusterfs/pusiol/TrainingData/flowtrain/Arms/Pos.txt --background-list /mnt/glusterfs/pusiol/TrainingData/flowtrain/Arms/Neg.txt  --negative-count 12000 --model-component 2 --model-part 10  --working-dir /mnt/glusterfs/pusiol/TrainingData/flowtrain/ArmsModelCluster4  --base-dir /mnt/glusterfs/pusiol/TrainingData/flowtrain/Arms --symmetric 0  --grayscale 1

