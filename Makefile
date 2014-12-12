CC=c99
CFLAGS=-O2 -D_GNU_SOURCE
LDFLAGS=-lpthread

CFLAGS+=`pkg-config --cflags gsl libevent`
LDFLAGS+=`pkg-config --libs gsl libevent`

EXECUTABLE=server
SOURCE_FILES=commands.c connections.c items.c protocol.c server.c settings.c threads.c utils.c
SOURCES=$(patsubst %,src/%,$(SOURCE_FILES))
OBJECTS=$(patsubst %.c,build/%.o,$(SOURCE_FILES))

all: $(SOURCES) $(EXECUTABLE)

.PHONY: clean
clean:
	rm -f server
	rm -f build/*.o

$(OBJECTS): | build

build:
	@mkdir -p $@

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $+ $(LDFLAGS)

build/%.o: src/%.c src/%.h
	$(CC) $(CFLAGS) -c $< -o $@

