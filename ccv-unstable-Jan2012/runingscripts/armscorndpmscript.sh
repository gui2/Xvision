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
#$ -N DPM.COLOR

# if you need more than 1 slot on the same machine
#$ -pe fah 4

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
nohup ./dpmcreate --positive-list /mnt/glusterfs/pusiol/TrainingData/flowtrain/ARMS-COLOR/Pos.txt --background-list /mnt/glusterfs/pusiol/TrainingData/flowtrain/ARMS-COLOR/Neg.txt  --negative-count 8000 --model-component 1 --model-part 8  --working-dir /mnt/glusterfs/pusiol/TrainingData/flowtrain/P1.ARMS.MODEL-COLOR.1.8  --base-dir /mnt/glusterfs/pusiol/TrainingData/flowtrain/ARMS-COLOR  --grayscale 1


