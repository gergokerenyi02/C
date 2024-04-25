#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// HEADER FILE(S)
#include "programs.h"


// Program helytelen indításakor...
void stopProgram()
{
    printf("Usage:\n");
    printf("\trev [SHOW LINE NUMBERS] [MAX LINE LENGTH] files...\n");
    exit(0);
}

// Paraméterek helyességének ellenőrzése, majd kezdőértékek inicializálása..
struct init checkArgs(int argc, char** argv)
{
    struct init a;

    if(argc > 2) // Megfelelő mennyiségű paraméter esetén...
    {
    
    // 1. paraméter helyességének ellenőrzése
    if(strcmp(argv[1], "linenums") == 0 || strcmp(argv[1], "nolinenums") == 0) // Ha helyes egyáltalán az input, akkor tovább...
    {
        // Számozva legyen e vagy sem...
        if(strcmp(argv[1], "linenums") == 0)
        {
            a.lineOn = true;
        } else
        {
            a.lineOn = false;
        }
    } else // ...ha nem helyes, manual.
    {
        stopProgram();
    }
    
    // 2. paraméter helyességének ellenőrzése
    int maxLength = atoi(argv[2]);
    
    if(isdigit(*argv[2]) > 0 && maxLength > 0) // ha szám, és > 0, akkor inicializálom
    {
        a.maxLength = atoi(argv[2]);
    } else // ...ha nem, manual.
    {
        stopProgram();
    }
    } else // kevesebb mint 2 param, manual
    {
        stopProgram();
    }

    return a;
}


void programType(int argc, char** argv, struct init defaultValues)
{
    if(argc == 3) // 0 FILE esetén -> STANDARD INPUT
    {
        revStdin(defaultValues);
    } else // FILE esetén -> FILE-ból
    {
        revFileRead(argc,argv,defaultValues);
    }
}

int main(int argc, char **argv)
{
    struct init defaultValues = checkArgs(argc, argv); // Paraméterek ellenőrzése...
    programType(argc, argv, defaultValues); // Program futtatása

    return 0;
}