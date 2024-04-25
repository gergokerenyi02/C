#include <stdbool.h>

#ifndef PROGRAMUTILS
#define PROGRAMUTILS

void terminate();
void reverse(char** strings, int length, bool lineOn);
void freeMem(char** stringsArr, int length);
bool containsNewline(char* buffer, int length);

#endif