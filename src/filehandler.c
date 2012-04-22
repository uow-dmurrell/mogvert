#include "mogconvert.h"
#include "error.h"
#include <unistd.h>
#include <stdlib.h>
//#include <getopt.h> // the standard getopt call is in unistd.h
#include <stdio.h>
#include <string.h>


// TODO: Get the length of string to be passed in, too
// TODO: More importantly, fix the code that passes in an uninitialised value for string
//	and causes a segfault.
int get_code(const char *string) {
    
    int length =3;
    
	int code = FORMAT_MP3; // Default
        if (strncasecmp("WAV",string+length-3,3) == 0)
                code = FORMAT_WAV;
        if (strncasecmp("MP3",string+length-3,3) == 0)
                code = FORMAT_MP3;
        if (strncasecmp("OGG",string+length-3,3) == 0)
                code = FORMAT_OGG;
        if (strncasecmp("FLAC",string+length-4,4) == 0)
                code = FORMAT_FLAC;
        if (strncasecmp("AO",string+length-2,2) == 0)
                code = FORMAT_AO;
    fprintf(stderr,"found format: %d ",code);
	return code;
}

char get_letter() {
	char input[1024];
	char c = 0;
	int  i = 0;
	for(i = 0; i < 1024; i++)
		input[i] = 0;
	scanf("%s",input);
	c = input[0];
	return c;
}

int check_encoder(const char *encoder) {
	char *encoders[] = { "mp3","ao" };
	int i = 0;
	for(i = 0; i < NUM_ENCODERS; i++) {
		if(strcasecmp(encoder,encoders[i])==0) break;
		if(i == NUM_ENCODERS-1 && strcasecmp(encoder,encoders[i]) != 0) invalid_encoder(encoder); // <-- WTF Does this do?
	}
	return 1;
}


int check_decoder(const char *decoder) {
	char *decoders[] = { "ogg","flac" };
	int i = 0;
	for(i = 0; i < NUM_DECODERS; i++) {
		if(strcasecmp(decoder,decoders[i])==0) break;
		if(i == NUM_DECODERS-1 && strcasecmp(decoder,decoders[i]) != 0) invalid_encoder(decoder); // <-- WTF Does this do?
	}
	return 1;
}

