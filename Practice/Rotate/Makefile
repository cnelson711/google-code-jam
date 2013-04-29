WARNINGS = -Wall -g
CC = g++
CFLAGS = $(WARNINGS) -O3 -std=c++11 
TARGET = main
LIBS = -lgmpxx -lgmp 
DEPS = iterator2d.o main.cpp 

all: $(DEPS) $(TARGET) $(TESTS)

$(TARGET): $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(DEPS) $(LFLAGS) $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	rm --force *.o
	rm --force $(TARGET)
