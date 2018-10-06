/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

/*-- Borrow -----------------------------------------------------------
 * Derived from 'Transaction'
 * Contains specialized functionality for Borrow Transaction types.
 *
 *-- Assumptions ------------------------------------------------------
 * - Default Constructor
 *   -> will only be invoked by TransFactory
 * - createItem
 *   -> parameters were checked for validity before being passed to
 *      this function. Item is a valid Item object.
 *-------------------------------------------------------------------*/
#ifndef BORROW_H
#define BORROW_H
#include "transaction.h"
#include <string>

using namespace std;

class Borrow : public Transaction
{
public:
   //default constructor
   Borrow();
   //constructor
   Borrow(int,char,Item*);

   //creates new 'Borrow' by calling constructor
   //returns pointer to new object
   virtual Transaction* createTrans(int,char,Item*);
   //displays formatted data for 'Borrow'
   virtual void display() const;

   //modifies the values of the Item action is being performed on
   virtual bool perform();

protected:
   int custID;    //customer ID
   char media;    //media type transaction is acting upon
   Item* rented;  //Item being borrow //used for 'retrieve'
   
};
#endif