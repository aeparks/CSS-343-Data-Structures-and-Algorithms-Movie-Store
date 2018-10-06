/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

#include "history_t.h"

//------------------------------------------------------------------------------
// Constructor & Default Constructor
// - Constructor: creates a new 'History' object with the the passed attribute.
// - Default Constructor: empty 'History' constructor necessary for TransFactory.
//------------------------------------------------------------------------------
History_T::History_T() { }

History_T::History_T(int id, char newLine, Item* nullPtr)
{
   custID = id;
   Transaction::t_type = "History";
}
//------------------------------------------------------------------------------
// createTrans
// - Will create a new 'History' transaction. Transaction will hold information
//   for customer ID;
// - Data from 'infile' was verified previously; no error checking necessary.
//------------------------------------------------------------------------------
Transaction* History_T::createTrans(int pID, char media, Item* movie)
{
   return new History_T(pID, media, movie);
}
//------------------------------------------------------------------------------
// perform
// - This functions does nothing. Function definition required for inheritance
//   from base "Transaction" class.
//------------------------------------------------------------------------------
bool History_T::perform() { return true; }

//------------------------------------------------------------------------------
// display
// - Will display information for customer transaction history. Will only
//   display the request for history.
//------------------------------------------------------------------------------
void History_T::display() const
{
   cout << "    Histor  Display Request" << endl;
}