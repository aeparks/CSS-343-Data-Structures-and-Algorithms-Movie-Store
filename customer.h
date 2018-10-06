/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

/*-- Customer ------------------------------------------------------------------
 * Customer is an arbitrary object that represents the profile of an actual
 * movie store customer. As such, Customer has data members that hold a
 * four-digit customer ID number (redundancy), a string first name, a string
 * last name and a pointer to a List object which will contain the an indefinite
 * number of transactions performed with the ID number.
 *
 *-- Assumptions ---------------------------------------------------------------
 * - Constructor
 *   -> will only be called if informatin passed to it (first, last, and id) 
 *      were verified previously
 * - history
 *   -> possible for history (List) be empty. if it is, will display a message
 *      stating as such
 *----------------------------------------------------------------------------*/
#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "list.h"
#include <iostream>
#include <string>

using namespace std;

class Customer
{
   //overloaed output //for outputting 'S' command
   friend ostream& operator<<(ostream&, const Customer&);

public:
   //constructor
   Customer(string,string,int);

   //adds new ListNode and Transaction data to list
   void appendHistory(Transaction*);
   //deletes ListNodes and data (Transactions) pointed to
   void deleteHistory();

private:
   int id;          //holds a 4-digit number representing customer ID
   string fName;    //first name of customer
   string lName;    //last name of customer

   List* history;   //pointer to List contain the history of customer
};
#endif