#Move to CMake in the not-too-distant future
ritchie: globals.h orderNumber.h order.h book.h main.cpp
	g++ -std=c++11 main.cpp globals.h orderNumber.h order.h book.h -I. -o ritchie

