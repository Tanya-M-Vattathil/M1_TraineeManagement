#ifndef PRINTMSG_H
#define PRINTMSG_H
#include <stdio.h>
#include <string.h>

//Align the message to show in the center if the screen or according to the programmer's choice
void printMessageCenter(const char* message)
{
    int l =0;
    int pos = 0;
    //calculate after how many spaces you need to print
    l = (90 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < l ; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}

#endif