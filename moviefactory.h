/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

/*-- MovieFactory --------------------------------------------------------------
 * MovieFactory will initiate intialization of Movie objects based upon their
 * genre. Genre will be hashed to an integer value which will be used to index
 * a pointer to a constructor in the factory array.
 *
 *-- Assumptions ---------------------------------------------------------------
 * -> factory
 *    - factory length is default 26.  the genre used to define Movie objects
 *      was a single, alphabetic character so it was assumed any additional
 *      Movie objects would be defined as such
 * -> hashGenre
 *    - will only return a value between 0 and MOVIEF_SIZE
 *    
 *----------------------------------------------------------------------------*/
#ifndef MOVIEFACTORY_H
#define MOVIEFACTORY_H
#include "classic.h"
#include "drama.h"
#include "comedy.h"
#include <iostream>

using namespace std;

int const MOVIEF_SIZE = 26;    //size of factory array

class MovieFactory
{
public:
   //constructor
   MovieFactory();
   //destructor
   ~MovieFactory();

   //calls the contructor of the appropriate type
   Item* createMovie(ifstream&);

private:
   //each 'defined' index will point to a specific constructor
   //constructors currently in factory: 'classic','drama','comedy'
   Item* factory[MOVIEF_SIZE];

   //will output an index for factory array
   int hashGenre(char); 
};
#endif