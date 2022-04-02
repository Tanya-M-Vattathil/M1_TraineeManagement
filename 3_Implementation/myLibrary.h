#ifndef LIBRARY_H
#define LIBRARY_H


//Used macro
// Macros are related to the dates as well as login credentials to be inputted
#define Max_yr  9999
#define Min_yr  1900
#define Max_UserNameSize 30
#define Max_PasswordSize  20
#define FileName  "Trainee_Records.bin"
// Below Macros are related to the Trainees info
#define MaxSize_ParentName 50
#define MaxSize_Tr_Name 50
#define MaxSize_Tr_Address 300
#define Size_FileHeader  sizeof(struct Tr_FHead)

//structure to store date
struct Date{
    int yyyy;
    int mm;
    int dd;
} ;

// structure to store username and password
struct Tr_FHead{
    char username[Max_UserNameSize];
    char password[Max_PasswordSize];
} ;

//Elements of below structure are to be called in program
struct TraineeInfo 
{
    unsigned int Tr_ID; // declare the integer data type
    char ParentName[MaxSize_ParentName];// declare the charecter data type
    char Tr_Name[MaxSize_Tr_Name];// declare the character data type
    char Tr_Address[MaxSize_Tr_Address];// declare the character data type
    struct Date TraineeJoiningDate;// declare the integer data type
} ;

#endif
