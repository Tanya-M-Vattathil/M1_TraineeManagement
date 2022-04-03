#include "unity.h"
#include <stdio.h>
#include <stdlib.h>
#include "myLibrary.h"


/* Modify these two lines according to the project */

#define PROJECT_NAME = "TraineeRecordManagement"

/* Prototypes for all the test functions */
void test_AddTraineeIntoDataBase(void);
void test_SearchTrainee(void);
void test_ViewTrainee(void);
void test_DeleteTrainee(void);

/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST (test_AddTraineeIntoDataBase);
  RUN_TEST(test_SearchTrainee);
  
 

  /* Close the Unity Test Framework */
  return UNITY_END();
}

void test_AddTraineeIntoDataBase(void){
    TEST_ASSERT_EQUAL("1" "Joe" "Tanya" "India" "10/12/2020", AddTraineeIntoDataBase("1" "Joe" "Tanya" "India" "10/12/2020"));

    /* Dummy fail*/
  // TEST_ASSERT_EQUAL("1" "Joe" "India" "10/12/2020", AddTraineeIntoDataBase("1" "Joe" "Tanya" "India" "10/12/2020"));

}


void test_SearchTrainee(void) {
    // TEST_ASSERT_EQUAL("1" "Joe" "Tanya" "India" "10/12/2020", SearchTrainee(1));
    
    /* Dummy fail*/
    TEST_ASSERT_EQUAL("No Record", SearchTrainee(1));

}




