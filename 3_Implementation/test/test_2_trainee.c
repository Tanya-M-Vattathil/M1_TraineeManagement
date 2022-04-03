#include "unity.h"
#include <stdio.h>
#include <stdlib.h>
#include "myLibrary.h"
#include "Validity.h"



/* Modify these two lines according to the project */

#define PROJECT_NAME = "Trainee Record Management"

/* Prototypes for all the test functions */
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
  RUN_TEST(test_ViewTrainee);
  RUN_TEST(test_DeleteTrainee);
 

  /* Close the Unity Test Framework */
  return UNITY_END();
}

void test_ViewTrainee(void) {
  TEST_ASSERT_EQUAL("1" "Joe" "Tanya" "India" "10/12/2020", ViewTrainee(1));
  
  /* Dummy fail*/
  // TEST_ASSERT_EQUAL("No Record", ViewTrainee(1));
}

void test_DeleteTrainee(void) {
  TEST_ASSERT_EQUAL("\n\t\t\tRecord deleted successfully.....", DeleteTrainee(1));
  /* Dummy fail*/
  // TEST_ASSERT_EQUAL("No Record", ViewTrainee(1));
}