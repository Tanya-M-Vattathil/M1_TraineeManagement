#ifndef VALIDITY_H
#define VALIDITY_H
#include <string.h>

//Function to Validate Name
int isNameValid(const char *Name)
{
    int validName = 1;
    int l = 0;
    int i = 0;
    l = strlen(Name);
    for(i =0; i <l ; ++i){
        if(!(isalpha(Name[i])) && (Name[i] != '\n') && (Name[i] != ' ')){
            validName = 0;
            break;
        }
    }
    return validName;
}
// Function to check leap year.
//Function returns 1 if entered value is leap year
int  isLeap(int yr)
{
    return (((yr % 4 == 0) &&
             (yr % 100 != 0)) ||
            (yr % 400 == 0));
}
// returns 1 if the given date is valid.
int isValidDate(struct Date *validDate)
{
    //these conditions are to check range of year,month and day
    if (validDate->yyyy > Max_yr ||
            validDate->yyyy < Min_yr)
        return 0;
    if (validDate->mm < 1 || validDate->mm > 12)
        return 0;
    if (validDate->dd < 1 || validDate->dd > 31)
        return 0;
    //these conditions handle february dates when the year is leap year
    if (validDate->mm == 02)
    {
        if (isLeap(validDate->yyyy))
            return (validDate->dd <= 29);
        else
            return (validDate->dd <= 28);
    }
    //these handle months which has only 30 days
    if (validDate->mm == 4 || validDate->mm == 6 ||
            validDate->mm == 9 || validDate->mm == 11)
        return (validDate->dd <= 30);
    return 1;
}


#endif