CXX       := g++
CXXFLAGS  := -std=c++14 -g -Wall -Wextra -pedantic -O3


#spaghetti: spaghetti.o
#	$(CXX) $(CXXFLAGS) -c $@ $^

#main: main.o
#	$(CXX) $(CXXFLAGS) -c $@ $^


all:
	$(CXX) $(CXXFLAGS) main.cpp -o main

testclient:
	$(CXX) $(CXXFLAGS) testclient.cpp -o test


.PHONY clean:
	rm -rf *.o main *.dSYM a.out test

