/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

/*-- Transaction ---------------------------------------------------------------
 * Base class for Transactions
 * No constructor necessary, data member declared by children.
 *
 *-- Assumptions ---------------------------------------------------------------
 * - createTrans
 *   -> all transactions will have a pointer to an Item object
 *----------------------------------------------------------------------------*/
#ifndef TRANS_H
#define TRANS_H

#include "item.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Transaction
{
public:
   //pure virtual functions //to be overriden by children
   //calls constructor
   virtual Transaction* createTrans(int,char,Item*) = 0;
   //diplays formatted private/protected data members
   virtual void display() const = 0;

   //performs transaction
   virtual bool perform() = 0;

protected:
   string t_type;   //description of transation type
};
#endif