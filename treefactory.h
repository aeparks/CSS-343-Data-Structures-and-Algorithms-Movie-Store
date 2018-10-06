/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

/*--- TreeFactory --------------------------------------------------------------
 * Contains the necessary functions and members to generate Tree objects. The
 * factory in this class is an array of pointers to Tree constructors. However,
 * factory only contains pointers to the same constructor. The hashing to the
 * indices of those function pointers are used to verifty accurate information
 * being passed to the factory. 'createTree' is called perform the actual call
 * to the factory.
 
 *-- Assumptions ---------------------------------------------------------------
 * - factory
 *   -> contains indices from 0 to 25 (A - Z). it was assumed that because the 
 *      genres were single, alphabetic characters, any additional genres would
 *      follow this pattern.
 * - hashGenre
 *   -> will only return a value between 0 - 25 (inclusive). the interger value
 *      produced by the actual hashing is modded by M_LENGTH (default: 26) which
 *      is the lengh of factory.  thus, chars passed to this function will hash
 *      within the bounds of factory.
 *----------------------------------------------------------------------------*/
#ifndef TREEFACTORY_H
#define TREEFACTORY_H
#include "tree.h"
#include <iostream>

using namespace std;

int const TREEF_SIZE = 26;   //size of factory array

class TreeFactory
{
public:
   //constructor
   TreeFactory();
   //destructor
   ~TreeFactory();

   //calls 'newTree' function from 'Tree' which returns an instantiation of a 'Tree'
   Tree* createTree(char);

private:
   //each 'defined' index will point to the 'Tree' constructor
   //defined means that the hashed value is a valid value in program
   Tree* factory[TREEF_SIZE];

   //will output an index for factory array
   int hashGenre(char);    
};
#endif