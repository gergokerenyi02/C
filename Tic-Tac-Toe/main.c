#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int oszlop = 7;
int sor = 6;
int tomb[6][7];

void init()
{
    for(int i = 0; i < sor; i++)
    {

        for(int j = 0; j < oszlop; j++)
        {
            tomb[i][j] = 0;

        }
    }
}


void printTable()
{
    for(int i = 0; i < sor; i++)
    {
        for(int j = 0; j < oszlop; j++)
        {
            printf("%d ", tomb[i][j]);
        }

        printf("\n");
    }
}


int submit(int jatekos, int oszlop)
{  
    // Megkeresem melyik a legutolsó üres
    // Az a i értékére fogom bedobni a player értékét

    int givenOszlop = oszlop - 1;
    int player = jatekos;
    bool placed = false;

    if(givenOszlop < 0 || givenOszlop > 6)
    {
        printf("Illegal\n");
    } else
    {
        for(int i = sor-1; i >= 0 && !placed ; i--)
        {
            if(tomb[i][givenOszlop] == 0)
            {
                tomb[i][givenOszlop] = player;
                placed = true;
                // Ha 0, akkor odateszi
                // Ha nem akkor pedig megyek tovább a felsőbb sorra
            }

        }
        if(placed == false)
        {
        printf("Illegal\n");
        } else if(placed == true)
        {
            printf("Legal\n");
        }

    }
}


int evaluate()
{    


    //Döntetlent is meg kell vizsgálni
    int firstPlayer = 0;
    int secondPlayer = 0;

    for(int i = 0; i < sor; i++)
    {
        for(int j = 0; j < oszlop; j++)
        {
            // Player 1
            
            //Oszlop-check
            if(tomb[i][j] == tomb[i-1][j] && tomb[i][j] == tomb[i+1][j])
            {
                // Megvizsgálom, hogy az egyező adatok 0/1/2
                // Maradékos osztással, vagy esetrebontás

                if(tomb[i][j] == 1 && tomb[i][j] != 0)
                {
                    firstPlayer = 1;
                    return firstPlayer;
                    //printf("First player wins\n");
                } else if(tomb[i][j] == 2 && tomb[i][j] != 0)
                {
                    secondPlayer = 2;
                    return secondPlayer;
                    //printf("Second player wins.\n");
                }
            }

            //Sor-check

            if(tomb[i][j] == tomb[i][j-1] && tomb[i][j] == tomb[i][j+1])
            {
                if(tomb[i][j] == 1 && tomb[i][j] != 0)
                {
                    firstPlayer = 1;
                    return firstPlayer;

                } else if(tomb[i][j] == 2 && tomb[i][j] != 0)
                {
                    secondPlayer = 2;
                    return secondPlayer;
                }
            }






            //Oszlop-check
/*
            if(tomb[i][j] == 1 && tomb[i+1][j] == 1 && tomb[i+2][j] == 1)
            {
                printf("First player wins\n");
            }

            // Player 2

            //Sor-check
            if(tomb[i][j] == 2 && tomb[i][j+1] == 2 && tomb[i][j+2] == 2)
            {
                printf("Second player wins\n");
            }

            //Oszlop-check

            if(tomb[i][j] == 2 && tomb[i+1][j] == 2 && tomb[i+2][j] == 2)
            {
                printf("Second player wins.\n");
            }*/

        }
    }
}


void game(char* letters)
{

for(int i = 1; letters[i] != '\0'; i++)
{
    printf("%d", letters[i]);
    
    if(letters[i] == 'A')
    {
     submit(i % 2, 1);
    }

    if(letters[i] == 'B')
    {
     submit(i % 2, 2);
    }
    if(letters[i] == 'C')
    {
     submit(i % 2, 3);
    }
    if(letters[i] == 'D')
    {
     submit(i % 2, 4);
    }
    if(letters[i] == 'E')
    {
     submit(i % 2, 5);
    }
    if(letters[i] == 'F')
    {
     submit(i % 2, 6);
    }
    if(letters[i] == 'G')
    {
     submit(i % 2, 7);
    }


    

}


}


int main()
{


// Nullázás
init();

// Dobás





// Kiírás
printTable();

evaluate();


char indulas[] = "ABDCAGEEE";

game(indulas);


if(evaluate() == 1)
{
    printf("First player wins.\n");
} else if(evaluate() == 2)
{
    printf("Second player wins.\n");
} else
{
    printf("Nobody won.");
}




return 0;

}