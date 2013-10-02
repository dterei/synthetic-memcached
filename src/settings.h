// Server settings and option parsing
#ifndef _SETTINGS_H
#define _SETTINGS_H

#include <gsl/gsl_rng.h>
#include <stdbool.h>

// Settings the server has
typedef struct _settings {
	int verbose;
	int threads;
	int tcpport;
	double dist_arg1; // normal distribution mean
	double dist_arg2; // normal distribution stddev
	bool use_dist;
	gsl_rng *r;
} settings;

void usage(void);
settings settings_init(void);
bool settings_parse(int argc, char **argv, settings *s);

#endif

