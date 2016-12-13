#!/bin/bash

echo
echo "This is job_HH4bSelection.sh."
echo

cd $TMPDIR
module load root
cp -r /home/tosciri/HH4bSelection .
cd HH4bSelection
echo pwd
pwd

echo
echo "******************** RUNNING job_HH4bSelection"
echo

#root -l -b compileAndLoadLibs.C "analysis.C(\"signal\")"
#root -l -b compileAndLoadLibs.C "analysis.C(\"bkg_4j\")"
#root -l -b compileAndLoadLibs.C "analysis.C(\"bkg_4b\")"
#root -l -b compileAndLoadLibs.C "analysis.C(\"bkg_2b2j\")"
root -l -b compileAndLoadLibs.C "analysis.C(\"bkg_tt_bbjjjj\")"

echo cp *.root ${outdir}
cp *.root ${outdir}

echo
echo "This is the end of job_HH4bSelection.sh."
echo
