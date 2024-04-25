#include <stdbool.h>

#ifndef PROGRAMS
#define PROGRAMS


struct init
{
    bool lineOn;
    int maxLength;
};

void revStdin(struct init defaultValues);

void revFileRead(int argc, char** argv, struct init defaultValues);

#endif