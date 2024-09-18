/*

   locationCleanerApplication.cpp - application file for a program named example
   =====================================================================

   This program is for Assignment No. 1, Course 04-630 Data Structures and Algorithms for Engineers.

   The functionality of the program is defined as follows.

   The program is designed to process a 2D list of ant locations, each location specified by its x and y coordinates and
   the time t that the ant visited that location. This 2D list is provided in an input file named input.txt. This input
   file is located in the data directory. Since this directory is a sibling directory of the bin directory where the
   locationCleaner .exe is located, the filename used when opening the file is "../data/input.txt".

   The program expects a maximum number of 10 test case sets and 27000 locations within each test case set. If more test
   cases are found, only the expected number is considered.

   Before any processing is performed, the program author's Andrew ID is printed to the terminal and a version of the same
   to the output file as well. The output file is located in the data directory as well under the path "../data/output.txt".

   For each location, an existing data structure is scanned to look for the same location. If no duplicate location is found,
   a unique identification number is assigned to that location. The identification numbers form a contiguous sequence,
   beginning with 1, and they reflect the order in which the location was encountered in the original list. The id, time,
   'x' and 'y' coordinates are written to the output file and a version of the same are printed to the terminal. If an
   identical location is found in the data structure, the program moves onto the next location in the test case list. The
   final list appears in ascending order by identification number.

   At the end of each test case set, the program prints a line of dashes i.e. "------------", marking the end of the test
   case set.

   Input
   -----

   - A file containing tests case sets of locations.
     A file whose first list signifies the number of test cases sets in the file.
     The lines after the first should represent a location with details such as time, 'x' and 'y' coordinates as float data
     type.
     Every test case set should be terminated by a time value less than zero i.e. -1.0.
     There can be a maximum number of 27000 locations within a test case set.
     There can be a maximum number of 10 test case sets in the input file.

   Output
   ------

   - A list of locations without duplicates with unique identifiers.
     The first line is the author's Andrew ID.
     The lines after contain the time and locations sorted in ascending order by their unique identification numbers.
     Each set of locations is separated by a line of dashes.

   Sample Input
   ------------

    3
    -2.00   0.000   0.000
    1	1	1
    -2.00   2.000   1.000
    1	1.900	1.900
    2	1.900   1.900
    -253.23	0.0	0.0
    5387.620    13.462    33.137
    5391.859    13.462    33.137
    5391.960    13.462    33.069
    5432.007    13.462    33.069
    5432.107    13.393    33.069
    5457.592    13.393    33.069
    5457.695    13.393    33.137
    5493.895    13.393    33.137
    5493.895    13.393    33.137
    -2 1 1

   Sample Output
   -------------

    miraguha
      1     1.000    0    0
      2     1.000    1    1
    --------------
      1     1.000    1    1
    --------------
      1     1.000    1    1
    --------------
      1    5387.620   13   33
    --------------

   Solution Strategy
   -----------------

   The program utilizes a struct to represent the location to be read from the input file. All locations are stored
   in an array of size 27000 for processing the locations found in each test case set from the input file.
   The array is intialized every time a new test case is to be processed.
   The main algorithm used to process the locations to find duplicates has a complexity running time of O(n^2).

   This is just an example program so there is no real computational problem to solve.  In other cases, you would describe here
   the principle computational theories used in solving the problem, along with the main data structures and algorithms used.

   Pseudocode for algorithm:
   open the file for input
   open the file for output
   read the first line
   if the read result wasnt successful
    close both files and exit
   validate the file line number
    if the number is less the zero
        exit app
    if the number is greater than 10
        set the number to 10
   print andrewid to terminal
   write andrewid to file
   loop through the test cases
    initialize the array to store locations
    initialize t,x,y and id
    while the id is less than the maximum number of locations in a test case
     read the next line in input file
     if failed to read file
      close both files and exit
     if t is less than 0
      end read for test case and print end lines
     if id is not 0
      look for duplicates
     if duplicate found
      increase the id
      store the location in array
      print id and location to terminal
      write id and location to output file
    print end of test case
   close input and output file
   exit application

   Test Strategy
   -------------

   The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:

   - two indentical sets of test cases
   - location data in test case not in ascending order of time (randomly assigned values for time, x and y)
   - empty test case
   - extremely large values (for both time, x and y)
   - one test case of zeros (single location)
   - terminator line has numbers (x,y) with values other than zero for x and y
   - all locations in test case as potential duplicates
   - different test case terminator value (any value not -1)
   - 27001 locations in a test case

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

int main() {
    FILE* fp_in;
    FILE* fp_out;

    check_file_can_open(fp_in, "../data/input.txt", "r");
    check_file_can_open(fp_out, "../data/output.txt", "w");

    int read_result;
    int number_of_test_cases;

    read_result = fscanf(fp_in, "%d", &number_of_test_cases);
    /* Getting any issue i.e. file read error due to invalid input or end of file,
       we exit the program.*/
    if (read_result == EOF)
    {
        printf("Error reading file. Check the file and try again.");
        fclose(fp_in);
        fclose(fp_out);
        prompt_and_exit(1);
    }

    validate_number_is_natural_number((short)number_of_test_cases);

    restrict_test_case_number(number_of_test_cases);

    printf("miraguha\n");
    fprintf(fp_out, "miraguha\n");

    /* we start with 'i' as 1 because we are starting with the first test case set in the file */
    for (short i = 1; i <= number_of_test_cases; i++)
    {
        /*
        * All locations in the test case list will be stored in this array.
        * We will refer to this array when checking for duplicates.
        * Initializing the array of locations for each iteration gets us to reset the array after
        * going through each test case. Data from the previous test case set doesn't have any value
        * in the next test case
        */
        Location antLocations[MAX_SET_OF_LOCATIONS] = { };
        short int id = 0;
        float t;
        float x;
        float y;

        /*
        * We assume that we are reading not more than 27000 locations.
        * Since we are using 'id' in the expression and 'id' is 0, we know the we check for 26999 locations
        */
        while (id < MAX_SET_OF_LOCATIONS) {
            read_result = fscanf(fp_in, "%f %f %f", &t, &x, &y);

            /* Getting any issue i.e. file read error due to invalid input or end of file, we exit the program.*/
            if (read_result == EOF)
            {
                printf("Error reading file. Check the file and try again.\n");
                fclose(fp_in);
                fclose(fp_out);
                prompt_and_exit(1);
            }

            /* if the time not a real number we know its the end of the test case */
            if ((short)t < 0) { break; }

            bool found_duplicate = false;

            /* if we are just starting the test case set, we don't need to search for any duplicates */
            if (id != 0) {
                found_duplicate = duplicate_location_exists(antLocations, (short)x, (short)y, id);
            }

            /* if we didn't find a duplicate then we create a new id before store the location since the
               store_location function uses it to come up with a valid index for the new location.
               Once the location is stored, we write the same details to the output file and print to terminal */
            if (!found_duplicate) {
                id++;
                store_location(antLocations, id, t, (short)x, (short)y);
                fprintf(fp_out, "%3d    %6.3f %4d %4d\n", id, t, (short)x, (short)y);
                printf("%3d    %6.3f %4d %4d\n", id, t, (short)x, (short)y);
            }
        }
        /*Terminate each test case set by a line of dashes only if we found any valid test case */
        if (id != 0) {
            printf("--------------\n");
            fprintf(fp_out, "--------------\n");
        }
    }

    fclose(fp_in);
    fclose(fp_out);

    prompt_and_exit(0);
}