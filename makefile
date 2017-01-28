<<<<<<< HEAD
#g++ -Wall -O -I/usr/include/boost $(pkg-config --libs rtmidi) $(pkg-config --cflags rtmidi) main.cpp
g++ -Wall -O -std=c++11 -I/usr/local/include/boost -lrtmidi $(pkg-config --cflags --libs libola) main.cpp
=======
g++ -Wall -O -I/usr/include/boost $(pkg-config --libs rtmidi) $(pkg-config --cflags rtmidi) main.cpp
#g++ -Wall -O -std=c++11 -I/usr/local/include/boost -lrtmidi main.cpp
>>>>>>> 9f8166638c65b4fd06a19d97b429fed1e635fefd
