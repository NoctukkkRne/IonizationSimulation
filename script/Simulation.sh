#!/bin/zsh

make clean
make -j8

./bin/Simulation -g ./data_in/Geometry/500mmBox.xml -e 100.0e-3 -r 99 -n 100 -o ./data_out/Output.root
#./bin/Simulation -g ./data_in/Geometry/50mmBox.xml -e 5.0 -r 01 -n 100 -o ./data_out/Output_01.root
#./bin/Simulation -g ./data_in/Geometry/50mmBox.xml -e 5.0 -r 02 -n 100 -o ./data_out/Output_02.root
#./bin/Simulation -g ./data_in/Geometry/50mmBox.xml -e 5.0 -r 03 -n 100 -o ./data_out/Output_03.root
#./bin/Simulation -g ./data_in/Geometry/50mmBox.xml -e 5.0 -r 04 -n 100 -o ./data_out/Output_04.root
#./bin/Simulation -g ./data_in/Geometry/50mmBox.xml -e 5.0 -r 05 -n 100 -o ./data_out/Output_05.root
#./bin/Simulation -g ./data_in/Geometry/50mmBox.xml -e 5.0 -r 06 -n 100 -o ./data_out/Output_06.root
#./bin/Simulation -g ./data_in/Geometry/50mmBox.xml -e 5.0 -r 07 -n 100 -o ./data_out/Output_07.root
#./bin/Simulation -g ./data_in/Geometry/50mmBox.xml -e 5.0 -r 08 -n 100 -o ./data_out/Output_08.root
#./bin/Simulation -g ./data_in/Geometry/50mmBox.xml -e 5.0 -r 09 -n 100 -o ./data_out/Output_09.root
#./bin/Simulation -g ./data_in/Geometry/50mmBox.xml -e 5.0 -r 10 -n 100 -o ./data_out/Output_10.root
