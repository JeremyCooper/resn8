#g++ -Wall -O -I/usr/include/boost $(pkg-config --libs rtmidi) $(pkg-config --cflags rtmidi) main.cpp
g++ -Wall -O -std=c++11 -I/usr/local/include/boost -lrtmidi $(pkg-config --cflags --libs libola) main.cpp
#g++ -Wall -O -std=c++11 -I/usr/local/include/boost -lrtmidi main.cpp
