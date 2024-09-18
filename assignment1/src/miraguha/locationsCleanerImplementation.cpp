/*

   locationCleanerImplementation.cpp - implementation file for a program named example
   ============================================================================

   This program is for Assignment No. 1, Course 04-630 Data Structures and Algorithms for Engineers.

   Please refer to the application file - locationCleanerApplication.cpp - for details of the functionality of this program.

   File organization
   -----------------

   locationCleaner.h                         interface file:
                                             contains the declarations required to use the functions that implement the solution to this problem
                                             typically, these will include the definitions of the abstract data types used in the implementation

   locationCleanerImplementation.cpp         implementation file:
                                             contains the definitions of the functions that implement the algorithms used in the implementation

   locationCleanerApplication.cpp            application file:
                                             contains the code that instantiates the abstract data types and calls the associated functions
                                             in order to effect the required functionality for this application

   Author
   ------

   Mark Iraguha, Carnegie Mellon University Africa
   08/28/2024

   Audit Trail
   -----------


*/

#include "locationsCleaner.h"

void prompt_and_exit(int status) {
    printf("Press any key to continue and close terminal\n");
    getchar();
    exit(status);
}

void store_location(Location  locations[MAX_SET_OF_LOCATIONS], short id, float t, short x, short y)
{
    locations[id - 1].t = t;
    locations[id - 1].x = x;
    locations[id - 1].y = y;
}

bool duplicate_location_exists(Location  locations[MAX_SET_OF_LOCATIONS], short x, short y, short end_search_index)
{
    for (int index = 0; index <= end_search_index; index++)
    {
        if ((locations[index].x == x) && (locations[index].y == y)) {
            return true;
        }
    }
    return false;
}

void restrict_test_case_number(int number_of_test_cases)
{
    /* if the number of test cases are more than 10, we just only consider the first 10 */
    if (number_of_test_cases > MAX_TEST_CASES) {
        number_of_test_cases = MAX_TEST_CASES;
    }
}

void validate_number_is_natural_number(short number)
{
    /* if the number of test cases are less than 1, we know its an error */
    if (number <= 0) {
        printf("Test cases should be a real number.\n");
        prompt_and_exit(1);
    }
}

void check_file_can_open(FILE*& fp, char* filename, char* mode)
{
    /* opening the file in the specified mode, if it fails, we print an error message and exit */
    if ((fp = fopen(filename, mode)) == 0) {
        printf("Error can't open %s\n", filename);
        prompt_and_exit(1);
    }
}