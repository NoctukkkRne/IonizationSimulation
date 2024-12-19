#!/bin/zsh

#make clean
make -j8

./script/Simulation.sh
./script/TrackAnalysis.sh
./script/StepAnalysis.sh
./script/SampleAnalysis.sh
