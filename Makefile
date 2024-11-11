CC = gcc
CFLAGS = -g -std=c17
GRADER = grader
PROGRAM3EXAMPLE = program3


.PHONY: all clean

all: $(GRADER) $(PROGRAM3EXAMPLE)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $<

$(GRADER): main.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(PROGRAM3EXAMPLE): program3.o $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm *.o $(GRADER) $(PROGRAM3EXAMPLE)