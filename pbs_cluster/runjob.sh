#!/bin/bash

echo "Type DoSubmit to submit jobs to the cluster." 


logpath=/home/tosciri/HH4bSelection/HH4bSelection_log
mkdir -p $logpath
outdir=/home/tosciri/HH4bSelection/HH4bSelection_out
mkdir -p $outdir


DoSubmit() {

#  namebase="hh4bselection_signal"
#  namebase="hh4bselection_bkg_4j"
#  namebase="hh4bselection_bkg_4b"
#  namebase="hh4bselection_bkg_2b2j"
  namebase="hh4bselection_bkg_tt_bbjjjj"

  #rm $logpath/*

  elog=$logpath/e_${namebase}.txt
  olog=$logpath/o_${namebase}.txt
  echo
  echo Submitting job now.
  echo
  echo  
  echo qsub -l cput=20:00:00 -l walltime=20:00:00 -o $olog -e $elog -v outdir=$outdir job_HH4bSelection.sh
  qsub -l cput=20:00:00 -l walltime=20:00:00 -o $olog -e $elog -v outdir=$outdir job_HH4bSelection.sh
  echo

}









