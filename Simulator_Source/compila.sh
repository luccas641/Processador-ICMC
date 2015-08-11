#!/bin/bash

#g++ Model.cpp -c
#g++ View.cpp -c `pkg-config --libs --cflags gtk+-3.0`
#g++ Controller.cpp -c `pkg-config --libs --cflags gtk+-3.0`
g++ -g main.cpp Controller.cpp Model.cpp View.cpp pit.cpp video.cpp -std=c++11  -O3 -march=native -o sim `pkg-config --libs --cflags gtk+-2.0` -lcurses -pthread -lgthread-2.0
