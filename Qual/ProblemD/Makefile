WARNINGS = 
CC = g++
CFLAGS = -O3 $(WARNINGS)
TARGET = main
LIBS = 
DEPS = main.o

all: $(DEPS) $(TARGET) $(TESTS)

$(TARGET): $(DEPS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(TARGET) $(DEPS) $(LFLAGS) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $< 

clean:
	rm --force *.o
	rm --force $(TARGET)
