// Server settings and option parsing
#ifndef _SETTINGS_H
#define _SETTINGS_H

#include <stdbool.h>

// Settings the server has
typedef struct _settings {
	int verbose;
	int threads;
	int tcpport;
} settings;

void usage(void);
settings settings_init(void);
bool settings_parse(int argc, char **argv, settings *s);

#endif

