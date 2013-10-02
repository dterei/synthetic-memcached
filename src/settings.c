#include "settings.h"

#include <gsl/gsl_rng.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// print command line usage.
void usage(void) {
	printf("-h          print this help and exit\n"
	       "-p <num>    TCP port number to listen on (default: 11211)\n"
	       "-t <num>    number of threads to use (default: 4)\n"
			 "-d <num>    normal distribution mean (default: 0)\n"
			 "-D <num>    normal distribution stddev (default: 0)\n"
	       "-v          verbose (print errors/warnings while in event loop)\n"
	       "-vv         very verbose (also print client commands/reponses)\n"
	       "-vvv        extremely verbose (also print internal state transitions)\n");
	return;
}

// create a new, default settings value.
settings settings_init(void) {
	settings s;
	s.verbose = 0;
	s.threads = 1;
	s.tcpport = 11211;
	s.dist_arg1 = 0;
	s.dist_arg2 = 0;
	s.r = gsl_rng_alloc(gsl_rng_taus);
	return s;
}

// process arguments
bool settings_parse(int argc, char **argv, settings *s) {
	char c;
	while (-1 != (c = getopt(argc, argv,
	       "p:" // TCP port number to listen on
	       "h"  // help, licence info
	       "v"  // verbose
	       "t:" // threads
			 "d:" // normal distribution mean
			 "D:" // normal distribution stddev
		))) {
		switch (c) {
		case 'p':
			s->tcpport = atoi(optarg);
			break;
		case 'h':
			usage();
			exit(EXIT_SUCCESS);
		case 'v':
			s->verbose++;
			break;
		case 't':
			s->threads = atoi(optarg);
			if (s->threads <= 0) {
				fprintf(stderr, "Number of threads must be greater than 0\n");
				return false;
			}
			break;
		case 'd':
			s->use_dist = true;
			s->dist_arg1 = atof(optarg);
			break;
		case 'D':
			s->use_dist = true;
			s->dist_arg2 = atof(optarg);
			break;
		default:
			fprintf(stderr, "Illegal argument \"%c\"\n", c);
			return false;
		}
	}
	return true;
}

