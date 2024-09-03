/* 

   exampleApplication.cpp - application file for a program named example
   =====================================================================

   This program is for Assignment No. 0, Course 04-630 Data Structures and Algorithms for Engineers. 

   The functionality of the program is defined as follows.
   
   Read a single-line message from an input file, write it to the terminal, and also write a version of it to an output file.
   The message to be written to file is prepended with the following text:

   "The message is: "

   The first line of the output file is the author's Andrew ID.
   
   A function is used to prepend the text and write the message to the output file.

   Input data with a test case message is provided in an input file named input.txt.  
   This input file is located in the data directory. Since this directory is a sibling directory of the bin directory 
   where the example .exe file resides, the filename used when opening the file is "../data/assignment0Input.txt".

   Output for the test case is written to an output file "../data/assignment0Output.txt"

   There are a maximum of eighty of characters in the message.  If message has more than eighty characters, only the first eighty are read.


   Input
   -----

   - A single line of text no longer than 80 characters.


   Output
   ------

   - Two lines of text:
	 The first line is the Andrew ID.
	 The second line is a the text that was read from the input file, beginning with "The message is: "
 

   Sample Input
   ------------
   
   Hello World!


   Sample Output
   -------------

   dvernon
   The message is: Hello World!


   Solution Strategy
   -----------------

   This is just an example program so there is no real computational problem to solve.  In other cases, you would describe here
   the principle computational theories used in solving the problem, along with the main data structures and algorithms used.


   Test Strategy
   -------------

   The program has been tested with a variety of test data sets that reflect all valid conditions, including boundary conditions:

   - message with no characters
   - message with number of characters in the range 1-80
   - message with more than eighty characters



   File organization
   -----------------

   example.h                  interface file:      
							  contains the declarations required to use the functions that implement the solution to this problem
							  typically, these will include the definitions of the abstract data types used in the implementation

   exampleImplementation.cpp  implementation file: 
							  contains the definitions of the functions that implement the algorithms used in the implementation
 
   exampleApplication.cpp     application file:    
							  contains the code that instantiates the abstract data types and calls the associated functions
							  in order to effect the required functionality for this application


   Author
   ------

   Mark Iraguha, Carnegie Mellon University Africa
   08/28/2024


   Audit Trail
   -----------

   
*/
 
#include "example.h"
 
#define MAX_SET_OF_LOCATIONS 27000


typedef struct Location
{
	int x;
	int y;
};



void location_exists(int size_of_array, Location  antlocations[27000], float x, float y, bool& found_duplicate);

int main() {

   int number_of_test_cases;
   int id; // identification number
   //int locations[MAX_SET_OF_LOCATIONS];
   float t, x, y;
   Location antlocations[MAX_SET_OF_LOCATIONS] = {0};

	

   FILE *fp_in, *fp_out;

   if ((fp_in = fopen("../data/input.txt","r")) == 0) {
	  printf("Error can't open input input.txt\n");
	 prompt_and_exit(1);
   }

   if ((fp_out = fopen("../data/output.txt","w")) == 0) {
	  printf("Error can't open output output.txt\n");
	 prompt_and_exit(1);
   }

   /* read the message from the input file */
   //fgets(message, MAX_MESSAGE_LENGTH, fp_in);
   
   //assignment to number_of_test_cases
   fscanf(fp_in, "%d", &number_of_test_cases);
   printf("Number of test cases:  %d\n", number_of_test_cases);
   if (number_of_test_cases <= 0) {
	   printf("Test cases should be a real number.");
   }

   //if the number of test cases are more than 10 we just only consider the first 10
   if (number_of_test_cases > 10) {
	   number_of_test_cases = 10;
   }


   printf("miraguha\n");
   for (short i = 1; i <= number_of_test_cases; i++)
   {
	   
	   id = 1;
	   //we assume that we are reading not more than 27000 locations
	   while (id<=MAX_SET_OF_LOCATIONS) {

		//if the time not a real number we know its the end of the test case
		fscanf(fp_in, "%f %f %f", &t, &x, &y);
		
		if ((int)t < 0) { break; }

		// we  don't need to search for existing locations if we are on the first location in the file
		if (id == 1) {
			antlocations[id - 1].x = (int)x;
			antlocations[id - 1].y = (int)y;
			printf("%3d    %6.3f %4d %4d\n", id, t, (int)x, (int)y);
			id++;
			
		}
		else {
			bool found_duplicate = false;

			for (int i=0; i < MAX_SET_OF_LOCATIONS; i++)
			{
				found_duplicate = false;

				if ((antlocations[i].x == (int)x) && (antlocations[i].y == (int)y)) {
					found_duplicate = true;
					break;
				}
			}
			
			if (!found_duplicate) {
				antlocations[id - 1].x = (int)x;
				antlocations[id - 1].y = (int)y;
				printf("%3d    %6.3f %4d %4d\n", id, t, (int)x, (int)y);
				id++;
			}
		}
	   }
	   printf("--------------\n");
   }
   
 

   fclose(fp_in);
   fclose(fp_out);

   prompt_and_exit(0);
}


