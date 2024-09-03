/* 

   exampleImplementation.cpp - implementation file for a program named example
   ============================================================================

   This program is for Assignment No. 0, Course 04-630 Data Structures and Algorithms for Engineers. 

   Please refer to the application file - exampleApplication.cpp - for details of the functionality of this program


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

   David Vernon, Carnegie Mellon University Africa
   05/01/2019


   Audit Trail
   -----------

   - Added prompt_and_exit() to allow users to read the terminal messages before it is closed.  David Vernon, 06/01/2019.

*/

 
 
#include "example.h"

void prompt_and_exit(int status) {
   printf("Press any key to continue and close terminal\n");
   getchar();
   exit(status);
}

void print_message_to_file(FILE *fp, char message[]) {
 
   fprintf(fp,"The message is: %s\n", message);
}

bool location_exists(FILE *fp, long start_read_position, long end_read_position, int x, int y)
{
    //printf("Current read position is: %ld\n ", /*start_read_position*/);
    //printf("Current x: %d and y: %d \n", x,y);
    //fseek(fp, start_read_position, SEEK_SET);
    fseek(fp, start_read_position, SEEK_SET);
    //printf("Current read position is: %ld\n ",ftell(fp));
    //printf("Current END read position is: %ld\n ", end_read_position);

    float f_t, f_x, f_y;

    while (ftell(fp) < end_read_position) {
        
        //printf("Current read position is: %ld\n ", ftell(fp));
        //printf("Time: %6.3f\n ", f_t);

        fscanf(fp, "%f %f %f", &f_t, &f_x, &f_y);
        //if (f_t <= 0.0) { return -1; }
        //printf("Current end read position is: %ld\n ", end_read_position);
        //printf("Current x: %d and y: %d \n", (int)f_x, (int)f_y);
        //printf("Comparison x: %d and y: %d \n", x,y);


        if (((int)f_x == x) && ((int)f_y == y)) {
            printf(" %d matches %d and  %d matches   %d\n", (int)(f_x),x, (int)(f_y), y);
            return true;
        }
        else {
            //printf("Current x: %d and y: %d  don't match comparison x: %d and y: %d \n",(int)f_x, (int)f_y, x,y);
            printf(" DIdnt match\n");
        }
        //printf("next read position is: %ld\n ", ftell(fp));
    }
    printf("exiting nothing found\n");
    return false;
}
