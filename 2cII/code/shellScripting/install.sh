#!/bin/bash


echo "welkcome to the ELECFLUTE version 1 download script :)"
echo "we want sudo"

if [[ $(/usr/bin/id -u) -ne 0 ]]; then
    echo "Not running as root"
    exit
fi

sleep 1
echo "

                                                            
   ___,,,,__________________Q_Q_Q_\_Q_________,_;_=====,___,
  ()____________)_____,_O_O_~_~_~====_PPPP____Q_Q__G__G____)
                      '~~~~~~~~~~~~~~~~~~~~~~~~~~~~'
                                                            

"

sleep 3





echo "installing liblo-tools"
sleep 1 
sudo apt install liblo-tools
echo "installing gum"
sleep 1 
sudo apt install gum
echo "installing cmake and c stuff "
sleep 1 
sudo apt install liblo cmake 
sudo apt install build-essential

cd elecfluteCode
cmake -S . -B build 
cd build
make -j8 




echo  
echo  
echo  
echo  

echo "this was the   ELECFLUTE version 1 download script :)"

echo "


   ___,,,,__________________Q_Q_Q_\_Q_<slide>_,_;_=====,___,
  ()__pi________)_____,_O_O_~_~_~====_PPPP____Q_Q__G__G___M)
                      '~~~~~~~~~~~~~~~~~~~~~~~~~~~~'

"

sleep 3
echo "done! have fun testing buddy :)"
