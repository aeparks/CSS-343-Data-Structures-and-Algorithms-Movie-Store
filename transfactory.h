/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store &*/

/*-- TrasFactory ---------------------------------------------------------------
 * TransFactory is a 'factory' class that produces Transaction objects. This
 * class contains an array of pointers to Transaction constructors whose index
 * values correspond to their hashed types. Only known and accepted 'transaction
 * types' will hash to constructors, all other values will hash to NULL
 * pointers.
 *
 *-- Assumptions ---------------------------------------------------------------
 * - factory
 *   -> factory size is 26, it is assumed that because single, alphabetic chars
 *      are being used for designating transaction type, characters 'A' through
 *      'Z' will only be used.
 * - createTrans(char,int,char);
 *   -> will only be called if there is a transaction type that does not
 *      require a pointer to an Item object (such as command 'H'
 * - createTrans(char,int,char,Item*)
 *   -> will only be called if there is a transaction type that requires a
 *      pointer to an Item object (such as commands 'B' and 'R'
 *----------------------------------------------------------------------------*/
#ifndef TRANSFACTORY_H
#define TRANSFACTORY_H

#include "item.h"
#include "borrow.h"
#include "return_t.h"
#include "history_t.h"
#include <iostream>

using namespace std;

int const TRANSF_SIZE = 26;   //size of factory array

class TransFactory
{
public:
   //constructor
   TransFactory();
   //destructor
   ~TransFactory();

   //calls the contructor of the appropriate type
   //used for non-item based transactions, such as 'H'
   Transaction* createTrans(char,int,char);
   //similar to 'createTrans' //takes an 'Item' as a parameter
   Transaction* createTrans(char,int,char,Item*);

   //checks which factory index genre hashes to
   bool inFactory(char);

private:
   //each 'defined' index will point to a specific constructor
   //constructors currently in factory: 'borrow','return_t','history_t',
   Transaction* factory[TRANSF_SIZE];

   //will output an index for factory array
   int hashType(char);
};
#endif