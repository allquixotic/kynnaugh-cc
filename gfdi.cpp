#ifdef _WIN32

#include <stdio.h>

FILE _iob[] = {*stdin, *stdout, *stderr};

extern "C" FILE * __cdecl __iob_func(void)
{
    return _iob;
}

#endif
