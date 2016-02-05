CXX=clang++

SRC=main.cpp

all: binarysearchtree 

CFLAGS=-std=c++11 -stdlib=libc++
LDFLAGS=

binarysearchtree: $(SRC)
	$(CXX) -o binarysearchtree $(SRC) $(CFLAGS) $(LDFLAGS)

clean:
	rm -Rf binarysearchtree *.o

rebuild: clean binarysearchtree
