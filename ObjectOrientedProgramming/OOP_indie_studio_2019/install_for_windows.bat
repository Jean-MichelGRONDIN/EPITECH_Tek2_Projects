::
:: EPITECH PROJECT, 2020
:: oop_indie_studio_2019
:: File description:
:: install_for_windows
::

md build_windows
cd build_windows
cmake -DCMAKE_BUILD_TYPE=Release ..
cmake --build . --config Release
cd Release
move bomberman.exe ../../bin/
cd ../../
