# command : ./file_comparator file_1 file_2
CC = gcc
CFLAGS = -lm -o
SOURCES = file_comparator.c
EXECUTABLE = file_comparator

comparator: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) $(EXECUTABLE)

clean:
	$(RM) $(EXECUTABLE) *~ *.o