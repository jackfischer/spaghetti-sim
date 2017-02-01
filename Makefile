CXX       := g++
CXXFLAGS  := -std=c++14 -g -Wall -Wextra -pedantic -O0


#spaghetti: spaghetti.o
#	$(CXX) $(CXXFLAGS) -c $@ $^

#main: main.o
#	$(CXX) $(CXXFLAGS) -c $@ $^


all:
	$(CXX) $(CXXFLAGS) main.cpp -o main



.PHONY clean:
	rm -rf *.o main

