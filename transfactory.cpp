/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

#include "transfactory.h"

//------------------------------------------------------------------------------
// Constructor
// - Instantiates a new hash factory of Transactions
//------------------------------------------------------------------------------
TransFactory::TransFactory()
{
   //initialize array
   for (int i = 0; i < TRANSF_SIZE; i++)
      factory[i] = NULL;

   //allows for only 'defined' types to produce Transactions
   /* ... can add more as necessary ... */
   factory[1]  = new Borrow();       //borrow transaction
   factory[7]  = new History_T();    //history transaction
   factory[17] = new Return_T();     //return transaction
   /* ... can add more as necessary ... */
}
//------------------------------------------------------------------------------
// Destructor
// - Will delete functions pointed to by factory array and will reset pointers
//   to NULL.
//------------------------------------------------------------------------------
TransFactory::~TransFactory()
{
   for (int i = 0; i < TRANSF_SIZE; i++)
   {
      delete factory[i];
      factory[i] = NULL;
   }
}
//------------------------------------------------------------------------------
// createTrans
// - Will call a dervied Transaction object's constructor from factory. Factory
//   index is supplied by hashing 'pType' which is a char representing a
//   transaction type. Function's parameters other than 'pType' will be passed
//   to the Transaction constructor. Will either return a pointer to a new
//   (derived) Transaction object or a NULL pointer.
// - If 'pType' is not a valid Transaction type, NULL will be returned. All
//   other error checking is performed in respective 'createTrans' functions.
//------------------------------------------------------------------------------
Transaction* TransFactory::createTrans(char pType, int pID, char pMedia)
{
   Item* nullItem = NULL;
   char pMed = '\n';

   int index = hashType(pType);

   if (factory[index] != NULL)
      return factory[index]->createTrans(pID, pMed, nullItem);
   else
      return NULL;
}
//------------------------------------------------------------------------------
// createTrans (overloaded)
// - Will call a dervied Transaction object's constructor from factory. Factory
//   index is supplied by hashing 'pType' which is a char representing a
//   transaction type. Function's parameters other than 'pType' will be passed
//   to the Transaction constructor. Will either return a pointer to a new
//   (derived) Transaction object or a NULL pointer.
// - If type is in valid, NULL will be returned. All other error checking is
//   performed in respective 'createTrans' functions.
// - New 'Transaction' will have a pointer to the parameter Item.
//------------------------------------------------------------------------------
Transaction* TransFactory::createTrans(char pType, int pID, char pMedia, Item* movie)
{
   int index = hashType(pType);

   if (factory[index] != NULL)
      return factory[index]->createTrans(pID, pMedia, movie);
   else
      return NULL;
}
//------------------------------------------------------------------------------
// inFactory
// - Will return a boolean value of whether 'pType' hashes to a non-NULL index
//   in factory.
//------------------------------------------------------------------------------
bool TransFactory::inFactory(char pType)
{
   int h_pType;

   h_pType = hashType(pType);

   return factory[h_pType] != NULL;
}
//------------------------------------------------------------------------------
// hashType
// - Will hash parameter and return its integer equivalent.
//------------------------------------------------------------------------------
int TransFactory::hashType(char param)
{
   return (param - 'A') % TRANSF_SIZE;
}