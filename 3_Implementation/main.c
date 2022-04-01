#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "myLibrary.h"
#include "printmsg.h"
#include "headmsg.h"



//Display message
void welcomeMessage(){
    printf("\n\t\t\t                 CODIFY.ME TRAINEE RECORD          ");
    printf("\n\t\t\t                    MANAGEMENT SYSTEM              \n\n");
    printf("\n\t\t\t                      WELCOME USER!                \n");
    printf("\n\n\n\t\t\t          You can enter any key to Login");
    getch();
}

//function to update credential
void UpdateUSNorPSWD(void)
{
    struct Tr_FHead fileHeaderInfo = {0};
    FILE *fptr = NULL;
    unsigned char userName[Max_UserNameSize] = {0};
    unsigned char password[Max_PasswordSize] = {0};
    headMessage("Update Credential");
    fptr = fopen(FileName,"rb+");
    if(fptr == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,Size_FileHeader, 1, fptr);
    if (fseek(fptr,0,SEEK_SET) != 0)
    {
        fclose(fptr);
        printf("\n\t\t\tFacing issue while updating password\n");
        exit(1);
    }
    printf("\n\n\t\t\tNew Username:");
    fflush(stdin);
    fgets(userName,Max_UserNameSize,stdin);
    printf("\n\n\t\t\tNew Password:");
    fflush(stdin);
    fgets(password,Max_PasswordSize,stdin);
    strncpy(fileHeaderInfo.username,userName,sizeof(userName));
    strncpy(fileHeaderInfo.password,password,sizeof(password));
    fwrite(&fileHeaderInfo,Size_FileHeader, 1, fptr);
    fclose(fptr);
    printf("\n\t\t\t Your Password has been changed successfully");
    printf("\n\t\t\t Login Again:");
    fflush(stdin);
    getchar(); 
    exit(1);
}
//Display menu
void menu()
{
    int choice = 0;
    do
    {
        headMessage("MAIN MENU");
        printf("\n\n\n\t\t\t1.Add Trainee");
        printf("\n\t\t\t2.Search Trainee");
        printf("\n\t\t\t3.View Trainee");
        printf("\n\t\t\t4.Delete Trainee");
        printf("\n\t\t\t5.Update Password");
        printf("\n\t\t\t0.Exit");
        printf("\n\n\n\t\t\tEnter choice => ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            AddTraineeIntoDataBase();
            break;
        case 2:
            SearchTrainee();
            break;
        case 3:
            ViewTrainee();
            break;
        case 4:
            DeleteTrainee();
            break;
        case 5:
            UpdateUSNorPSWD();
            break;
        case 0:
            printf("\n\n\n\t\t\t\tThank you!!!\n\n\n\n\n");
            exit(1);
            break;
        default:
            printf("\n\n\n\t\t\tINVALID INPUT!!! please try again");
        }                                            //Switch Ended
    }
    while(choice!=0);                                 //Loop Ended
}

//login password
void login()
{
    unsigned char userName[Max_UserNameSize] = {0};
    unsigned char password[Max_PasswordSize] = {0};
    int L=0;
    struct Tr_FHead fileHeaderInfo = {0};
    FILE *fptr = NULL;
    headMessage("Login");
    fptr = fopen(FileName,"rb");
    if(fptr == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,Size_FileHeader, 1, fptr);
    fclose(fptr);
    do
    {
        printf("\n\n\n\t\t\t\tUsername:");
        fgets(userName,Max_UserNameSize,stdin);
        printf("\n\t\t\t\tPassword:");
        fgets(password,Max_PasswordSize,stdin);
        if((!strcmp(userName,fileHeaderInfo.username)) && (!strcmp(password,fileHeaderInfo.password)))
        {
            menu();
        }
        else
        {
            printf("\t\t\t\tLogin Failed Enter Again Username & Password\n\n");
            L++;
        }
    }
    while(L<=3);
    if(L>3)
    {
        headMessage("Login Failed");
        printf("\t\t\t\tSorry,Unknown User.");
        getch();
        system("cls");
    }
}
//Check file exist or not
int isFileExists(const char *path)
{
    // Try to open file
    FILE *fptr = fopen(path, "rb");
    int status = 0;
    // If file does not exists
    if (fptr != NULL)
    {
        status = 1;
        // File exists hence close file
        fclose(fptr);
    }
    return status;
}

void init() 
{
    FILE *fptr = NULL;
    int status = 0;
    const char defaultUsername[] ="TMVJcode\n";
    const char defaultPassword[] ="TMVJcode\n";
    struct Tr_FHead fileHeaderInfo = {0};
    status = isFileExists(FileName);
    if(!status)
    {
        //create the binary file
        fptr = fopen(FileName,"wb");
        if(fptr != NULL)
        {
            //Copy default password
            strncpy(fileHeaderInfo.password,defaultPassword,sizeof(defaultPassword));
            strncpy(fileHeaderInfo.username,defaultUsername,sizeof(defaultUsername));
            fwrite(&fileHeaderInfo,Size_FileHeader, 1, fptr);
            fclose(fptr);
        }
    }
}

int main()
{
    init();
    welcomeMessage();
    login();
    return 0;
}