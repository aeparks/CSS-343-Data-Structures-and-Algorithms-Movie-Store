/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

#include "moviefactory.h"
#include <iostream>

//------------------------------------------------------------------------------
// Constructor
// - Instantiates a new hash factory of Items (Movies)
//------------------------------------------------------------------------------
MovieFactory::MovieFactory()
{
   //initialize array
   for (int i = 0; i < MOVIEF_SIZE; i++)
      factory[i] = NULL;

   //allows for only 'defined' genres to produce trees
   /* ... can add more as necessary ... */
   factory[2] = new Classic();      //classic movie
   factory[3] = new Drama();        //drama movie
   factory[5] = new Comedy();       //comedy movie
   /* ... can add more as necessary ... */
}
//------------------------------------------------------------------------------
// Destructor
// - Will delete functions pointed to by factory array and will reset pointers
//   to NULL.
//------------------------------------------------------------------------------
MovieFactory::~MovieFactory()
{
   for (int i = 0; i < MOVIEF_SIZE; i++)
   {
      delete factory[i];
      factory[i] = NULL;
   }
}
//------------------------------------------------------------------------------
// createMovie
// - Will read one line from parameter file.  Genre will be read from file to
//   hash to the proper index of 'factory'.  The file parameter will then be
//   passed to the 'createItem' function of the indexed object where the data
//   in the line will be read into a new object of that type.
//------------------------------------------------------------------------------
Item* MovieFactory::createMovie(ifstream& infile)
{
   char genre;
   infile >> genre;

   int index = hashGenre(genre);

   if (factory[index] != NULL)
      return factory[index]->createItem(infile);
   else
      return NULL;
}
//------------------------------------------------------------------------------
// hashGenre
// - Will hash parameter and return its integer equivalent.
//------------------------------------------------------------------------------
int MovieFactory::hashGenre(char param)
{
   return (param - 'A') % MOVIEF_SIZE;
}