##
## EPITECH PROJECT, 2020
## oop_indie_studio_2019
## File description:
## install_for_linus
##

mkdir build_linux;
cd build_linux;
cmake -DCMAKE_BUILD_TYPE=Release ..;
make;
mv ./bomberman ../bin/ ;
cd ..;