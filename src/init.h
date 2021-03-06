#ifndef _INIT_H_
#define _INIT_H_

#include "mogconvert.h"
#include "error.h"
#include <unistd.h>
#include <stdlib.h>
//#include <getopt.h> // the standard getopt call is in unistd.h
#include <stdio.h>
#include <string.h>
#include <math.h>

// a structure to easily access the command line arguments
typedef struct mog_info {
	const char *input_file;
	const char *dec_module;
	const char *output_file;
	const char *enc_module;
	int bitrate;
	int reencode_time;
	int copy_tags;
	int check_validity;
} mog_info;


mog_info mog_initmog(int argc, char **argv);
void mog_sumstats(struct mog_info info);
void mog_showhelp(char *app);

#endif /* _INIT_H_ */
