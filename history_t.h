/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

/*-- History_T --------------------------------------------------------
 * Derived from 'Transaction'
 * Contains specialized functionality and members for History objects.
 *
 *-- Assumptions ------------------------------------------------------
 *
 *-------------------------------------------------------------------*/
#ifndef HISTORY_H
#define HISTORY_H

#include "transaction.h"

using namespace std;

class History_T : public Transaction
{
public:
   //default constructor
   History_T();
   //constructor
   History_T(int,char,Item*);

   //creates new 'Borrow' by calling constructor
   //returns pointer to new object
   virtual Transaction* createTrans(int,char,Item*);
   //displays formatted data for 'Borrow'
   virtual void display() const;

   //this does nothing
   virtual bool perform();

protected:
   int custID;    //customer id
};
#endif