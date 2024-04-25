#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// HEADER FILE(S)
#include "programs.h"
#include "programUtils.h"

void revStdin(struct init defaultValues)
{
    char** strings;
    int defaultLength = 8;
    int amountOfStrings = 0;

    
    char buffer[defaultValues.maxLength];
    int stringLength = 0;


    strings = malloc(defaultLength * sizeof(char *));
    if(strings != NULL) // Sikeres memóriafoglalás esetén 
    {
        bool EndOfFile = false;
        
        while(!EndOfFile) // olvasás EOF-ig
        {   
            char* result = fgets(buffer, defaultValues.maxLength + 2, stdin);


            if(result == NULL) // EOF
            {
                EndOfFile = true;
                printf("\n");

                // REVERSE PROGRAM...
                reverse(strings, amountOfStrings, defaultValues.lineOn);

            } else
            {   
                stringLength = strlen(buffer); 
                buffer[stringLength - 1] = '\0';

                if(amountOfStrings == defaultLength) // Dinamikus tömbben nincs hely a következőnek, realloc...
                {
                    strings = realloc(strings, (2 * defaultLength * sizeof(char*)));

                    if(strings == NULL)
                    {
                        terminate();
                    } else
                    {
                        defaultLength = defaultLength * 2;
                    }   
                }


                if(amountOfStrings < defaultLength) // = elhagyható(?)
                {

                strings[amountOfStrings] = malloc(stringLength * sizeof(char));
                if(strings[amountOfStrings] == NULL)
                {
                    terminate();
                } else
                {
                    strcpy(strings[amountOfStrings], buffer);
                    amountOfStrings++;
                }
                }
                

                fflush(stdin); // stdin-ről minden ami megadott karakterhossz után van DELETE, különben belecsúszik a kövibe!
            }
        }
    } else
    { 
        terminate();
    }
    // FREE MEMORY
    freeMem(strings, amountOfStrings);
}

void revFileRead(int argc, char** argv, struct init defaultValues)
{
    char** lines;
    int defaultLength = 8;
    int amountOfCorrectLines = -1;

    char buffer[defaultValues.maxLength];
    int stringLength = 0;

    lines = malloc(defaultLength * sizeof(char *));

    if(lines == NULL)
    {
        terminate();
    } else
    {    
    for(int i = 3; i < argc; i++)
    {
        FILE* file;
        file = fopen(argv[i], "r");
        
        if (file != NULL)
        {
            while(fgets(buffer, defaultValues.maxLength + 2, file) != NULL)
            {
                stringLength = strlen(buffer);
                bool contains = containsNewline(buffer, defaultValues.maxLength);
                

                if(contains == 1) //Megfelelő a szó, nem túl hosszú
                {
                    buffer[stringLength - 1] = '\0';
                    amountOfCorrectLines++; // -1-ről indult...

                    if(amountOfCorrectLines == defaultLength)
                    {
                        lines = realloc(lines, (2 * defaultLength * sizeof(char*)));
                        if(lines == NULL)
                        {
                            terminate();
                        } else
                        {
                            defaultLength = defaultLength * 2;
                        }
                    }

                    lines[amountOfCorrectLines] = malloc(stringLength * sizeof(char));
                    if(lines[amountOfCorrectLines] != NULL)
                    {
                        strcpy(lines[amountOfCorrectLines], buffer);
                    } else
                    {
                        terminate();
                    }
                } else 
                {
                    // SKIP felesleges input
                    // ---------------------------
                    char c;
                    do
                    {
                        c = fgetc(file);
                    } while(c != '\n');

                    // ---------------------------
                    
                    buffer[defaultValues.maxLength] = '\0';
                    amountOfCorrectLines++;

                    if(amountOfCorrectLines == defaultLength)
                    {
                        lines = realloc(lines, (2 * defaultLength * sizeof(char*)));
                        if(lines == NULL)
                        {
                            terminate();
                        } else
                        {
                            defaultLength = defaultLength * 2;
                        }
                    }

                    lines[amountOfCorrectLines] = malloc(stringLength * sizeof(char));
                    if(lines[amountOfCorrectLines] != NULL)
                    {
                        strcpy(lines[amountOfCorrectLines], buffer);
                    } else
                    {
                        terminate();
                    }
                }                
            }

            fclose(file);
        } else
        {
            printf("File opening unsuccessful: <%s>\n", argv[i]);
            continue;
        }
    }
    
    // REVERSE
    reverse(lines, amountOfCorrectLines + 1, defaultValues.lineOn);
    
    // FREE MEMORY
    freeMem(lines, amountOfCorrectLines);
    }
}