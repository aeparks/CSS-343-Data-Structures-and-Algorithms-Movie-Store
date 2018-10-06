/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

#include "borrow.h"

//------------------------------------------------------------------------------
// Constructor & Default Constructor
// - Constructor: creates a new 'Borrow' object with the passed attributes.
// - Default Constructor: empty 'Borrow' constructor necessary for TransFactory.
//------------------------------------------------------------------------------
Borrow::Borrow() { }

Borrow::Borrow(int id, char med, Item* m_borrowed)
{
   media = med;
   custID = id;
   Transaction::t_type = "Borrow";
   rented = m_borrowed;
}
//------------------------------------------------------------------------------
// createTrans
// - Will create a new 'Borrow' transaction. Transaction will hold information
//   for customer ID, and media type and a pointer to a movie that's beening
//   borrowed.
// - Data from 'infile' and 'movie' were verified previously; no error checking
//   necessary.
//------------------------------------------------------------------------------
Transaction* Borrow::createTrans(int pID, char pMedia, Item* movie)
{
   return new Borrow(pID, pMedia, movie);
}
//------------------------------------------------------------------------------
// perform (Borrow)
// - Will adjust the stock as follows: "in stock" number will be decreased by
//   one and "borrowed" number will be increased by one. If the number in stock
//   is at zero, perform will fail and display an error message and return
//   false. If  'stockAdjustment' is successful, values will be modified
//   accordingly and true will be returned.
//------------------------------------------------------------------------------
bool Borrow::perform()
{
   if (rented->stockAdjustment(-1,1))
      return true;
   else
   {
      cout << " Item not in stock\n" << endl;
      return false;
   }
}
//------------------------------------------------------------------------------
// display
// - Will display information for customer transaction history. Including
//   media type, the type of transaction (in this case: Borrow) and limited
//   information about the Item being pointed to.
// - Displaying of information of the Item is handled by the Item.
//------------------------------------------------------------------------------
void Borrow::display() const
{
   //display media type
   if (media == 'D')
      cout << "DVD ";
   else
      cout << "UNK ";

   cout << t_type << "  ";

   //display information from Item*
   rented->display_t();
}