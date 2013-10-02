CC=clang
CFLAGS=-O2 -D_GNU_SOURCE
LDFLAGS=-levent -pthread

EXECUTABLE=server
SOURCES=commands.c connections.c items.c protocol.c server.c settings.c threads.c utils.c
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

