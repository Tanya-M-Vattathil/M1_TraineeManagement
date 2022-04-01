#ifndef PRINTMSG_H
#define PRINTMSG_H
#include <stdio.h>
#include <string.h>

//Align the message
void printMessageCenter(const char* message)
{
    int len =0;
    int pos = 0;
    //calculate how many space need to print
    len = (90 - strlen(message))/2;
    printf("\t\t\t");
    for(pos =0 ; pos < len ; pos++)
    {
        //print space
        printf(" ");
    }
    //print message
    printf("%s",message);
}

#endif