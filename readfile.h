#ifndef _MREADFILE_H_
#define _MREADFILE_H_


enum {
	READ_SUCCESS = 0,
	READ_FAILED,
	MALLOC_FAILED
};

int readfile(char *filename, char **bufptr);

//~ int freefile(void *buffer);
#endif //_MREADFILE_H_
