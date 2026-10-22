CC = gcc
CFLAGS = -Wall -g

TARGET = infix
OBJ = main.o dec.o

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

main.o: main.c defines.h
	$(CC) $(CFLAGS) -c main.c

dec.o: dec.c defines.h
	$(CC) $(CFLAGS) -c dec.c

clean:
	rm -f $(OBJ) $(TARGET)

