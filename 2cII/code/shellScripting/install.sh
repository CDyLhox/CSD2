#!/bin/bash


echo "welkcome to the ELECFLUTE version 1 download script :)"
echo "we want sudo"

if [[ $(/usr/bin/id -u) -ne 0 ]]; then
    echo "Not running as root"
    exit
fi

delay 1
echo "


   ___,,,,__________________Q_Q_Q_\_Q_________,_;_=====,___,
  ()____________)_____,_O_O_~_~_~====_PPPP____Q_Q__G__G____)
                      '~~~~~~~~~~~~~~~~~~~~~~~~~~~~'

"

delay 3





echo "installing liblo-tools"
delay 1 
sudo apt install liblo-tools
echo "installing gum"
sudo apt install gum

