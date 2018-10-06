
/*------------------------------------------------------------------------------
 * Author          - Aaron Parks
 * Instructor      - Professor Carol Zander
 * Course          - CSS 343 (17:35 - 19:50)
 * Quarter         - Winter 2010
 * Assignment      - Lab 4: MOVIE Store 
 * Version         - version4
 * Date Started    - 26, February 2010
 * Date Complete   - 08, March 2010
 * Date Typescript - 10, March 2010
 *
 * Description -
 * Using information we've learned in CSS 342 and in this course -- CSS 343 --
 * we create program that will create and popuate collections of objects and
 * then perform an indefinite number of transactions upon those objects.
 *
 * Concepts Utilized -
 * -> pointers                 -> linked lists           -> binary trees
 * -> memory management        -> hash tables            -> inheritance
 * -> operator overloading     -> ofstream manipulation
 -----------------------------------------------------------------------------*/

#include "store.h"
#include <fstream>
#include <iostream>

using namespace std;

int main()
{
   //read in customer file
   ifstream customer_f("data4customers.txt");
   if (!customer_f)
   {
      cout << "Error reading customer file!" << endl;
      return 1;
   }
   //read in movie file
   ifstream movie_f("data4movies.txt");
   if (!movie_f)
   {
      cout << "Error reading customer file!" << endl;
      return 1;
   }
   //read in command file
   ifstream command_f("data4commands.txt");
   if (!command_f)
   {
      cout << "Error reading command file!" << endl;
      return 1;
   }

   //create and populate CustomerArray and TreeArray (and Trees)
   Store newStore(customer_f, movie_f);
   newStore.startDay(command_f);
   newStore.endDay();

   return 0;
}