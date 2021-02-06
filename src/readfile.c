#include <stdio.h>
#include <stdlib.h>
#include "readfile.h"

int readfile(char *filename, char **bufptr)
{
	int retval = READ_SUCCESS;
	//~ printf("%s\n", filename);
	FILE *fh = fopen(filename, "rb");
	if ( fh != NULL )
	{
		fseek(fh, 0L, SEEK_END);
		long s = ftell(fh);
		rewind(fh);
		*bufptr = malloc(s);
		if ( *bufptr != NULL )
		{
			fread(*bufptr, s, 1, fh);
			//~ fwrite(*bufptr, s, 1, stdout);
		}
		else
		{
			retval = MALLOC_FAILED;
		}
	}
	else
	{
		retval = READ_FAILED;
	}
	
	if (fh != NULL) fclose(fh);
	return retval;
}
