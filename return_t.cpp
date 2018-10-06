/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

#include "return_t.h"

//------------------------------------------------------------------------------
// Deafult Constructor & Constructor
// - Constructor: creates a new 'Return' object with the passed attributes.
// - Default Constructor: empty 'Return' constructor necessary for TransFactory.
//------------------------------------------------------------------------------
Return_T::Return_T() {}

Return_T::Return_T(int id, char med, Item* m_returned)
{
   media = med;
   custID = id;
   Transaction::t_type = "Return";
   returning = m_returned;
}
//------------------------------------------------------------------------------
// createTran
// - Will create a new 'Return' transaction. Transaction will hold information
//   for customer ID, and media type and a pointer to and Item that's being
//   returned.
// - Data from 'infile' and 'movie' were verified previously; no error checking
//   necessary.
//------------------------------------------------------------------------------
Transaction* Return_T::createTrans(int pID, char pMedia, Item* movie)
{
   return new Return_T(pID, pMedia, movie);
}
//------------------------------------------------------------------------------
// perform (Borrow)
// - Will adjust the stock as follows: "in stock" number will be increased by
//   one and "borrowed" number will be decreased by one. If the number
//   "borrowed" is at zero, will display an error message and return false. If
//   'stockAdjustment' is successful, values will be modified accordingly and
//   true will be returned.
//------------------------------------------------------------------------------
bool Return_T::perform()
{
   if (returning->stockAdjustment(1,-1))
      return true;
   else
   {
      cout << " Stock full, cannot return\n" << endl;
      return false;
   }
}
//------------------------------------------------------------------------------
// display
// - Will display information for customer transaction history. Including
//   media type, the type of transaction (in this case: Return) and limited
//   information about the Item being pointed to.
// - Displaying of information of the Item is handled by the Item.
//------------------------------------------------------------------------------
void Return_T::display() const
{
   //display media type
   if (media == 'D')
      cout << "DVD ";
   else
      cout << "UNK ";

   cout << t_type << "  ";

   //display information from Item*
   returning->display_t();
}