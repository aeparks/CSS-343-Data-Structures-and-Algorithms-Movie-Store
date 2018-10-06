/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

/*-- Return_T ------------------------------------------------------------------
 * Derived from 'Transaction'
 * Contains specialized functionality and data members to perform a Return
 * transaction. Return will alter "in-stock" and "out-stock" values when
 * performed.
 *
 *-- Assumptions ---------------------------------------------------------------
 * - Default Constructor
 *   -> will only be used by TransFactory
 * - createTrans
 *   -> data passed will have already been verified as good. this includes the
 *      object pointed to by the parameter Item pointer.
 *----------------------------------------------------------------------------*/
#ifndef RETURN_T_H
#define RETURN_T_H

#include "transaction.h"

using namespace std;

class Return_T : public Transaction
{
public:
   //default constructor
   Return_T();
   //constructor
   Return_T(int,char,Item*);

   //creates new 'Return' by calling constructor
   //returns pointer to new object
   virtual Transaction* createTrans(int,char,Item*);
   //diplays formatted private/protected data members
   virtual void display() const;

   //modifies the values of the Item action is being performed on
   virtual bool perform();

protected:
   int custID;       //customer ID
   char media;       //media type transaction is acting upon
   Item* returning;  //Item being returned //used for 'retrieve'
};
#endif