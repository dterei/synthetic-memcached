CC=clang
CFLAGS=-O2
LDFLAGS=-levent

EXECUTABLE=server
SOURCES=commands.c connections.c items.c protocol.c server.c settings.c threads.c
OBJECTS=$(SOURCES:.c=.o)

all: $(SOURCES) $(EXECUTABLE)

.PHONY: clean
clean:
	rm -f server
	rm -f *.o

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) -o $@ $(OBJECTS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

