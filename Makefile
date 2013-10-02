CC=clang
CFLAGS=-O2
LDFLAGS=-levent

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
	$(CC) $(LDFLAGS) -o $@ $+

build/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

