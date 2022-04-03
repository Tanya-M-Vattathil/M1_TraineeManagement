#include <stdio.h>
#include <stdlib.h>
#include "myLibrary.h"


// view Trainees function
void ViewTrainee()
{
    int found = 0;
    struct TraineeInfo Tr_InfoToDataBase = {0};
    FILE *fptr = NULL;
    unsigned int countTrainee = 1;
    headMessage("VIEW TRAINEE DETAILS");
    printf("\n\t\t\t***************************************************\n");
    fptr = fopen(FileName,"rb");
    if(fptr == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    if (fseek(fptr,Size_FileHeader,SEEK_SET) != 0)
    {
        fclose(fptr);
        printf("Facing issue while reading file\n");
        exit(1);
    }
    while (fread (&Tr_InfoToDataBase, sizeof(Tr_InfoToDataBase), 1, fptr))
    {
        printf("\n\t\t\tTrainee Count = %d\n\n",countTrainee);
        printf("\t\t\tTrainee id = %u\n",Tr_InfoToDataBase.Tr_ID);
        printf("\t\t\tTrainee Name = %s",Tr_InfoToDataBase.Tr_Name);
        printf("\t\t\tParent Name = %s",Tr_InfoToDataBase.ParentName);
        printf("\t\t\tTrainee Address = %s",Tr_InfoToDataBase.Tr_Address);
        printf("\t\t\tTrainee Admission Date(DD/MM/YYYY) =  (%d/%d/%d)\n\n",Tr_InfoToDataBase.TraineeJoiningDate.dd,
               Tr_InfoToDataBase.TraineeJoiningDate.mm, Tr_InfoToDataBase.TraineeJoiningDate.yyyy);
        found = 1;
        ++countTrainee;
    }
    fclose(fptr);
    if(!found)
    {
        printf("\n\t\t\tNo Record");
    }
    printf("\n\n\t\t\tPress Enter to go to main menu");
    fflush(stdin);
    getchar();
}


// Delete Trainee entry
void DeleteTrainee()
{
    int found = 0;
    int TraineeDelete = 0;
    struct Tr_FHead fileHeaderInfo = {0};
    struct TraineeInfo Tr_InfoToDataBase = {0};
    FILE *fptr = NULL;
    FILE *tmpFp = NULL;
    headMessage("Delete Trainee Details");
    fptr = fopen(FileName,"rb");
    if(fptr == NULL)
    {
        printf("File is not opened\n");
        exit(1);
    }
    tmpFp = fopen("tmp.bin","wb");
    if(tmpFp == NULL)
    {
        fclose(fptr);
        printf("File is not opened\n");
        exit(1);
    }
    fread (&fileHeaderInfo,Size_FileHeader, 1, fptr);
    fwrite(&fileHeaderInfo,Size_FileHeader, 1, tmpFp);
    printf("\n\t\t\tEnter Trainee ID NO. for delete:");
    scanf("%d",&TraineeDelete);
    while (fread (&Tr_InfoToDataBase, sizeof(Tr_InfoToDataBase), 1, fptr))
    {
        if(Tr_InfoToDataBase.Tr_ID != TraineeDelete)
        {
            fwrite(&Tr_InfoToDataBase,sizeof(Tr_InfoToDataBase), 1, tmpFp);
        }
        else
        {
            found = 1;
        }
    }
    (found)? printf("\n\t\t\tRecord deleted successfully....."):printf("\n\t\t\tRecord not found");
    fclose(fptr);
    fclose(tmpFp);
    remove(FileName);
    rename("tmp.bin",FileName);
}


