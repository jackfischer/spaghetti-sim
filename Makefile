CXX       := g++
CXXFLAGS  := -std=c++14 -Wall -Wextra -pedantic -O0


#spaghetti: spaghetti.o
#	$(CXX) $(CXXFLAGS) -c $@ $^

#main: main.o
#	$(CXX) $(CXXFLAGS) -c $@ $^


all: main spaghetti 
	$(CXX) $(CXXFLAGS) *.o -o main



.PHONY clean:
	rm -rf *.o main

