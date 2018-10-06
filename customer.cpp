/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

#include "customer.h"

//------------------------------------------------------------------------------
// Constructor
// - Initializes customer fName and lName and id from parameters. Creates a new
//   List object for the 'history' pointer to point to. History is a pointer to
//   a list object which will store a Customer's transaction history.
//------------------------------------------------------------------------------
Customer::Customer(string first, string last, int indx)
{
   fName = first;
   lName = last;
   id = indx;
   history = new List();
}
//------------------------------------------------------------------------------
// appendHistory
// - Will append a Trasaction object into a List for 'this' Customer. Actual
//   insertion is handled by 'insert' function of List. If insertion is
//   successful, true will be returned and function will exit. If false is
//   returned, will display a message stating Transaction object was not
//   inserted.
//------------------------------------------------------------------------------
void Customer::appendHistory(Transaction* appendable)
{
   if (!history->insert(appendable))
   {
      cout << " Could not append transaction to customer history\n" << endl;
   }
}
//------------------------------------------------------------------------------
// deleteHistory
// - Will delete all ListNodes in history list and will delete all Transasction
//   objects pointed to by ListNode data pointers.
//------------------------------------------------------------------------------
void Customer::deleteHistory()
{
   history->makeEmpty();
   delete history;
}
//------------------------------------------------------------------------------
// operator<<
// - Will display Customer 'header' and customer history (if any).
//------------------------------------------------------------------------------
ostream& operator<<(ostream& output, const Customer& param)
{
   //display customer id and name (header)
   output << "   *** Customer ID = " << param.id
      << "  " << param.lName + " " + param.fName + "\n";

   //output customer history
   if (!param.history->isEmpty())
      param.history->displayHistory();
   else
      output << " No History on File\n";

   output << endl;
   return output;
}