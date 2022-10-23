#include <stdio.h>
#define Max 100

char linein[Max];

char line1[Max];
char line2[Max];

int getline2(char output[Max]);
int fold(char out1[], char in[], int len);

int main()
{
    int length;

    while ((length = getline2(linein)) > 0)
    {
        fold(line1, linein, length);

        printf("%s\n%s\n\n", line1, line2);

    }

    return 0;
}


int fold(char out1[], char in[], int len)
{
    int l, i, extendo, charSpot, foldpoint, blankSpot;
    i = 0;
    charSpot = 0;
    foldpoint = 10;
    l = 0;
    extendo = 0;
    blankSpot = 0;

    for(i; i < foldpoint; i++)
    {

        out1[l] = in[i];

        //final instance of a non blank character
        if ((in[i] != ' ') && (in[i] != '\t'))
        {
            charSpot = i;
        }

        //trackdown the blanks
        if((i[in] == ' ') || (i[in] == '\t'))
        {
            blankSpot = i;
        }

        //fold if approaching foldpoint
        if((i == foldpoint -1))
        {

            //if we have a new blank on curent line
            if(blankSpot > (foldpoint - 10))
            {
                out1[blankSpot + extendo] = '\n';
                foldpoint = blankSpot + 1;
            }

            //triggers when the letters go through an entire foldpoint
            else
            {
                out1[l+1] = '\n';
                l++;
                extendo++;
            }

            //if there are many chars left, increase to the next foldpoint
            if((foldpoint + 10) < len)
            {
                foldpoint = foldpoint + 10;
            } 

            else
            {
                //final line
                while (i<len + extendo)
                {
                    i++;
                    out1[l+1] = in[i];
                    l++;
                }
            }
        }

        l++;
    }

    out1[i] = '\0';
    return 0;

}


//gets a line and returns length
int getline2(char output[])
{
    int c, i;
    i = 0;

    while(((c = getchar()) != EOF) && (c != '\n'))
    {
        output[i] = c;
        i++;
        
    }
    output[i] = '\0';
    return i;
}

