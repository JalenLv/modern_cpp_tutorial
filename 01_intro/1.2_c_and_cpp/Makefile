C := gcc
CXX := g++

SOURCE_C := foo.c
OBJECTS_C := foo.o

SOURCE_CXX := bar.cpp

TARGET := bar.out
LDFLAGS_COMMON := -std=c++2a

all:
	$(C) -c $(SOURCE_C)
	$(CXX) $(SOURCE_CXX) $(OBJECTS_C) $(LDFLAGS_COMMON) -o $(TARGET)

clean:
	rm -rf *.o $(TARGET)
