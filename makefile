g++ -Wall -O -I/usr/include/boost $(pkg-config --libs rtmidi) $(pkg-config --cflags rtmidi) main.cpp
