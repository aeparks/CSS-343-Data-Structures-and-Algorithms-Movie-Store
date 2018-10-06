/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

/*-- List ----------------------------------------------------------------------
 * List creates and maintains a linked list of ListNodes. List will search as 
 * a dynamically sized container that will resize as necessary be inserting new
 * nodes to the front of the list.
 *
 *-- Assumptions ---------------------------------------------------------------
 * - insert
 *   -> no check is main against insufficient memory. it is assumed that that
 *      much memory will not be used.
 * - makeEmpty
 *   -> will delete ListNodes and data in 'data' pointers. will not delete any
 *      Movies pointed to by Transactions
 *----------------------------------------------------------------------------*/
#ifndef LIST_H
#define LIST_H

#include "transaction.h"
#include <iostream>

using namespace std;

class List
{
public:
   //constructor
   List();

   //inserts new ListNode into list
   virtual bool insert(Transaction*);
   //returns if head == NULL
   virtual bool isEmpty() const;
   //deletes ListNodes and data
   virtual void makeEmpty();
   //displays the information held in ListNodes
   virtual void displayHistory() const;

protected:
   struct ListNode
   {
      ListNode* next;      //pointer to next linked ListNode in memory
      Transaction* data;   //pointer to a Trans object
   };
   ListNode* head;         //pointer to first ListNode in list

   //recursive helper for 'displayInOrder'
   virtual void displayHistory(ListNode*) const;
};
#endif