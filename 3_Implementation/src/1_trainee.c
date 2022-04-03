#include <stdio.h>
#include <stdlib.h>
#include "myLibrary.h"
#include "Validity.h"


// Add Trainee in list
void AddTraineeIntoDataBase()
{
    struct TraineeInfo Tr_InfoToDataBase = {0}; //To add Trainee Info Into DataBase
    FILE *fptr = NULL;
    int status = 0;
    fptr = fopen(FileName,"ab+");
    if(fptr == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    headMessage("ADD NEW TRAINEE");
    printf("\n\t\t\t********************************************************************************************************\n");
    printf("\n\n\t\t\tENTER YOUR DETAILS BELOW:");
    printf("\n\t\t\t********************************************************************************************************\n");
    printf("\n\t\t\tTrainee ID  = ");
    fflush(stdin);
    scanf("%u",&Tr_InfoToDataBase.Tr_ID);
    do
    {
        printf("\n\t\t\tParent Name  = ");
        fflush(stdin);
        fgets(Tr_InfoToDataBase.ParentName,MaxSize_ParentName,stdin);
        status = isNameValid(Tr_InfoToDataBase.ParentName);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tTrainee Name  = ");
        fflush(stdin);
        fgets(Tr_InfoToDataBase.Tr_Name,MaxSize_Tr_Name,stdin);
        status = isNameValid(Tr_InfoToDataBase.Tr_Name);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        printf("\n\t\t\tTrainee Address  = ");
        fflush(stdin);
        fgets(Tr_InfoToDataBase.Tr_Address,MaxSize_ParentName,stdin);
        status = isNameValid(Tr_InfoToDataBase.Tr_Address);
        if (!status)
        {
            printf("\n\t\t\tName contain invalid character. Please enter again.");
        }
    }
    while(!status);
    do
    {
        //get date year,month and day from user
        printf("\n\t\t\tEnter date in format (DD/MM/YYYY): ");
        scanf("%d/%d/%d",&Tr_InfoToDataBase.TraineeJoiningDate.dd,&Tr_InfoToDataBase.TraineeJoiningDate.mm,&Tr_InfoToDataBase.TraineeJoiningDate.yyyy);
        //check date validity
        status = isValidDate(&Tr_InfoToDataBase.TraineeJoiningDate);
        if (!status)
        {
            printf("\n\t\t\tPlease enter a valid date.\n");
        }
    }
    while(!status);
    fwrite(&Tr_InfoToDataBase,sizeof(Tr_InfoToDataBase), 1, fptr);
    fclose(fptr);
}


// search Trainee
void SearchTrainee()
{
    int found = 0;
    int TraineeId =0;
    struct TraineeInfo Tr_InfoToDataBase = {0};
    FILE *fptr = NULL;
    fptr = fopen(FileName,"rb");
    if(fptr == NULL)
    {
        printf("\n\t\t\tFile is not opened\n");
        exit(1);
    }
    headMessage("SEARCH TRAINEES");
    printf("\n\t\t\t***************************************************\n");
    //put the control on Trainee detail
    if (fseek(fptr,Size_FileHeader,SEEK_SET) != 0)
    {
        fclose(fptr);
        printf("\n\t\t\tFacing issue while reading file\n");
        exit(1);
    }
    printf("\n\n\t\t\tEnter Trainee ID to search:");
    fflush(stdin);
    scanf("%u",&TraineeId);
    while (fread (&Tr_InfoToDataBase, sizeof(Tr_InfoToDataBase), 1, fptr))
    {
        if(Tr_InfoToDataBase.Tr_ID == TraineeId)
        {
            found = 1;
            break;
        }
    }
    if(found)
    {
        printf("\n\t\t\tTrainee id = %d\n",Tr_InfoToDataBase.Tr_ID);
        printf("\n\t\t\tTrainee name = %s",Tr_InfoToDataBase.Tr_Name);
        printf("\t\t\tParent Name = %s",Tr_InfoToDataBase.ParentName);
        printf("\n\t\t\tTrainee Address = %s",Tr_InfoToDataBase.Tr_Address);
        printf("\t\t\tTrainee Admission Date(DD/MM/YYYY) =  (%d/%d/%d)",Tr_InfoToDataBase.TraineeJoiningDate.dd,
               Tr_InfoToDataBase.TraineeJoiningDate.mm, Tr_InfoToDataBase.TraineeJoiningDate.yyyy);
    }
    else
    {
        printf("\n\t\t\tNo Record");
    }
    fclose(fptr);
    printf("\n\n\n\t\t\tPress Enter to go to main menu.....");
    fflush(stdin);
    getchar();
}

