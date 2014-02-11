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
#$ -N D.ARM1.8

# if you need more than 1 slot on the same machine
#$ -pe fah 1

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
nohup ./execDPM.sh



