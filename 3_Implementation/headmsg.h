#ifndef HEADMSG_H
#define HEADMSG_H

//creates a heading message to be shown at the beginning of each choices
void headMessage(const char *message){
    system("cls");
    printMessageCenter(message);
}

#endif
