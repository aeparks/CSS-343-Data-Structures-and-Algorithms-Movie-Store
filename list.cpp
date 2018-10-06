/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

#include "list.h"

//------------------------------------------------------------------------------
// Constructor
// - Initializes head to NULL.
//------------------------------------------------------------------------------
List::List() { head = NULL; }

//------------------------------------------------------------------------------
// insert
// - Will create a new ListNode object and assign the data point to the 
//   parameter Transaction object.  Will insert new ListNode at the front of 
//   the list and reassign it as the head of the list.
//------------------------------------------------------------------------------
bool List::insert(Transaction* toBeInserted)
{
   ListNode* newNode = new ListNode;
   newNode->next = NULL;
   newNode->data = toBeInserted;

   //patch newNode in as new head
   if (isEmpty())
      head = newNode;
   else
   {
      newNode->next = head;
      head = newNode;
   }
   return true;
}

//------------------------------------------------------------------------------
// isEmpty
// - Return true if head is NULL (thus there is no list) or returns false if
//   root is not NULL (thus there is at least one node in list).
//------------------------------------------------------------------------------
bool List::isEmpty() const { return head == NULL; }

//------------------------------------------------------------------------------
// makeEmpty
// - Will delete all data in a List and deleting the 'Trans' data object and
//   and the ListNode of the previous pointer. The current pointer points to
//   the ListNode following the ListNode being pointer to by current int order.
//------------------------------------------------------------------------------
void List::makeEmpty()
{
   if (!isEmpty())
   {
      ListNode* previous = head;
      ListNode* current = head;

      while (current != NULL)
      {
         current = previous->next;
         delete previous->data;
         delete previous;
         previous = current;

      }
   }
}
//------------------------------------------------------------------------------
// displayHistory & displayHistory (overloaded)
// - Will traverse history linked list and display information about the 
//   'Transaction' object pointed to by the ListNode pointer. Information will
//   displayed when stack frames resolve, meaning entire list will be traversed
//   then information will be display in reverse order, last node first.
//------------------------------------------------------------------------------
void List::displayHistory() const
{
   if (!isEmpty())
      displayHistory(head);
}
/******************************************************************************/
void List::displayHistory(ListNode* current) const
{
   if (current->next != NULL)
      displayHistory(current->next);

   current->data->display();
}