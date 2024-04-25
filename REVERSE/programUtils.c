#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "programUtils.h"

void terminate()
{
    printf("Memory allocation failed!");
    exit(-1);
}

void reverse(char** strings, int length, bool lineOn)
{

    if(lineOn == 0)
    {

    for(int i = length - 1; i >= 0; i--)
    {
        int currentLength = strlen(strings[i]);
        
        for(int j = currentLength - 1; j >= 0; j--)
        {
        
            printf("%c", strings[i][j]);
        
        }
        printf("\n");
    }
    } else
    {

        for(int i = length - 1; i >= 0; i--)
        {
            int currentLength = strlen(strings[i]);
        
            printf("%d ", i + 1);
        

            for(int j = currentLength - 1; j >= 0; j--)
            {
                printf("%c", strings[i][j]);
            }
            printf("\n");
        }
    }
}


void freeMem(char** stringsArr, int length)
{
    for(int i = 0; i < length; i++)
    {
     free(stringsArr[i]);
    }

    free(stringsArr);
}

bool containsNewline(char* buffer, int length)
{

    for(int i = 0; i <= length; i++)
    {
        if(buffer[i] == '\n')
        {
            return 1;
        }
    }

    return 0;
}