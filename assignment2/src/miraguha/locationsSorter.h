/*

   locationCleaner.h - interface file for a program named example
   ======================================================

   This program is for Assignment No. 1, Course 04-630 Data Structures and Algorithms for Engineers.

   Please refer to the application file - exampleApplication.cpp - for details of the functionality of this program

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

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include <ctype.h>

#define TRUE 1
#define FALSE 0

#define MAX_SET_OF_LOCATIONS 27000
#define MAX_TEST_CASES 10

//Structure to store location details such as the time(t), 'x' and 'y' coordinates.
struct Location
{
    float t;
    short x;
    short y;
};
typedef struct Location temp;

void prompt_and_exit(int status);

/// <summary>
/// Lookup the locations for the given x and y coordinates.
/// </summary>
/// <param name="locations"> This should be an array of type "Location".</param>
/// <param name="x">'x' value of co-ordinate.</param>
/// <param name="y">'y' value of co-ordinate.</param>
/// <param name="end_search_index">An index specifying at what index the search should be ended. If there's more data in the array after this index,
/// it will not be considered.</param>
/// <returns>True if duplicate found otherwise false</returns>
bool duplicate_location_exists(Location  locations[MAX_SET_OF_LOCATIONS], short x, short y, short end_search_index);

/// <summary>
/// Stores the 'x' and 'y' coordinates in a locations array.
/// The id will be used to uniquely store the coordinates in the array.
/// </summary>
/// <param name="locations">An array of type Location.</param>
/// <param name="id">A unique number that identifies the co-ordinates.</param>
/// <param name="t">The time value of the location set.</param>
/// <param name="x">The 'x' coordinate value of the location set.</param>
/// <param name="y">The 'y' coordinate value of the location set.</param>
void store_location(Location  locations[MAX_SET_OF_LOCATIONS], short index, float t, short x, short y);

/// <summary>
/// Verifies that the number is a natural number i.e. 1,2,3 etc. This verifies the validation rul tc>=1
/// </summary>
/// <param name="number">Any number up to 32767</param>
void validate_number_is_natural_number(short number);

/// <summary>
/// Checks that the number of test cases provided follow the validation rule of tc<=10.
/// </summary>
/// <param name="number_of_test_cases">Number representing the total number of test cases</param>
void restrict_test_case_number(int number_of_test_cases);

/// <summary>
/// Opens the specified file in the specified mode.
/// </summary>
/// <param name="fp">Pointer to file.</param>
/// <param name="filename">Path to file.</param>
/// <param name="mode">Mode to open file i.e. 'r' for read and 'w' for write.</param>
void check_file_can_open(FILE*& fp, char* filename, char* mode);
