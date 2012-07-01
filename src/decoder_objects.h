#ifndef _MOGDECODEOBJECTS_H_
#define _MOGDECODEOBJECTS_H_

#include "mogconvert.h"
#include <stdio.h>

class decoder {
public:
	virtual bool test(FILE *inputfile)=0;
	virtual bool init(FILE *inputfile)=0;
	// it'd be nice if this function was actually
	// virtual struct generic_file_info& getgfi();
    virtual char* get_decoder_name()=0;
	virtual void getgfi(struct generic_file_info &gfi)=0;
	virtual int decode(unsigned char &wave_buffer)=0 ;		// This function returns number of BYTES
	virtual int close(unsigned char &wave_buffer)=0 ;
	//virtual ~decoder();
};
#include "decoders/flac.h"
#include "decoders/ogg.h"
//#include "decoders/cdda.h"

// You can all shut up, this works.

#endif /* _MOGDECODEOBJECTS_H_ */
