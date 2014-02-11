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
#$ -N Face0Short1comp16parts

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
nohup ./dpmcreate --positive-list /afs/.ir/users/p/u/pusiol/face/ANGLE0-Short/Pos2.txt --background-list /afs/.ir/users/p/u/pusiol/face/ANGLE0-Short/Neg.txt --negative-count 12000 --model-component 1 --model-part 16 --working-dir /afs/.ir/users/p/u/pusiol/face/ANGLE0-MODEL1-1COMP-16PART-square_parts_2000 --base-dir /afs/.ir/users/p/u/pusiol/face/ANGLE0-Short/  --symmetric 1  --grayscale 1

##nohup ./dpmcreate --positive-list /afs/.ir/users/p/u/pusiol/face/ANGLE0-Short/Pos.txt --background-list /afs/.ir/users/p/u/pusiol/face/ANGLE0-Short/Neg.txt  --negative-count 12000 --model-component 4 --model-part 10  --working-dir /afs/.ir/users/p/u/pusiol/face/ANGLE0-Short/ANGLE0-MODEL --base-dir /afs/.ir/users/p/u/pusiol/face/ANGLE0-Short/ANGLE0  --grayscale 1

##nohup ./dpmcreate --positive-list /mnt/glusterfs/pusiol/TrainingData/flowtrain/Arms/Pos.txt --background-list /mnt/glusterfs/pusiol/TrainingData/flowtrain/Arms/Neg.txt  --negative-count 12000 --model-component 2 --model-part 10  --working-dir /mnt/glusterfs/pusiol/TrainingData/flowtrain/ArmsModelCluster4  --base-dir /mnt/glusterfs/pusiol/TrainingData/flowtrain/Arms --symmetric 0  --grayscale 1

