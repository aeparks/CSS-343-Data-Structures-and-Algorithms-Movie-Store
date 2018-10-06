/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

#include "tree.h"

//------------------------------------------------------------------------------
// Constructor
// - Initializes 'root' of Tree to be NULL.
//------------------------------------------------------------------------------
Tree::Tree() { root = NULL; }

//------------------------------------------------------------------------------
// Destructor
// - Calls makeEmpty function.
//------------------------------------------------------------------------------
Tree::~Tree() { this->makeEmpty(); }

//------------------------------------------------------------------------------
// newTree
// - Instantiates new tree and returns pointer to it.
//------------------------------------------------------------------------------
Tree* Tree::newTree() { return new Tree(); }

//------------------------------------------------------------------------------
// insert
// - Will insert a new Node with a pointer to 'toBeAdded' into a Tree. Data
//   in 'toBeAdded' will be compared with 'Item's already stored in the Tree so
//   the Node with the pointer to 'toBeAdded' will be inserted in the proper
//   location (in order).
// - In the case that 'toBeAdded' matches an existing 'Item' in the Tree, the
//   new Node and 'toBeAdded' will be deleted and the "in stock" value for the
//   existing 'Item' will be increased by 10.
// - Will return false if duplicate 'Item' found in Tree, otherwise will return
//   true.
//------------------------------------------------------------------------------
bool Tree::insert(Item* toBeAdded)
{
   Node* newNode = new Node;                 //new Node to be inserted into Tree
   newNode->data = toBeAdded;                //assign data pointer to parameter
   newNode->left = newNode->right = NULL;    //initialize pointers to NULL

   if (isEmpty())
      root = newNode;
   else
   {
      Node* current = root;       //walking pointer
      bool inserted = false;      //whether inserted yet
      while (!inserted)
      {
         if (*newNode->data < *current->data) //check left
         {
            //check state of left pointer
            //insert if NULL, otherwise ajdust 'current'
            if (current->left != NULL)
               current = current->left;   //go left
            else
            {
               current->left = newNode;
               inserted = true;
            }
         }
         else if (*newNode->data > *current->data) //check right
         {
            //check state of right pointer
            //insert if NULL, otherwise adjust 'current'
            if (current->right != NULL)
               current = current->right; //go right
            else
            {
               current->right = newNode;
               inserted = true;
            }
         }
         else //newNode->data equals current->data
         {
            //increase stock by 10
            current->data->increaseStock();

            delete newNode->data;
            delete newNode;
            newNode = NULL;
            return false;
         }
      }//while loop
   }//else
   return true;
}
//------------------------------------------------------------------------------
// stockAdjustment
// - Will call 'stockAdjustment' function for 'target'. Existance of 'target'
//  was check previously.
//------------------------------------------------------------------------------
bool Tree::stockAdjustment(Item* target, int a_rent, int a_return)
{
   return target->stockAdjustment(a_rent, a_return);
}
//------------------------------------------------------------------------------
// retrieve and retrieve (overloaded)
// - Will search Tree for the Item that matches the 'target' in parameter. If
//   found, will return a pointer to the Item object, otherwise will return
//   NULL.
// - 'retrieve' checks if root is NULL.  If root is NULL, will return NULL,
//   otherwise will pass 'root' and 'target' as parameters to 'retrieve' helper
//   function.
// - 'retrieve' (helper) will recursively traverse Tree comparing Items in Tree
//    with 'target'. If match found will return pointer to found Item. If not
//   found, will return NULL.
//------------------------------------------------------------------------------
Item* const Tree::retrieve(const Item* target) const
{
   if (isEmpty())
      return NULL;
   else
      return retrieve(root, target);
}
/******************************************************************************/
Item* const Tree::retrieve(Node* current, const Item* target) const
{
   if (current != NULL)
   {
      //target found!
      if (*current->data == *target)
         return current->data;

      //go left
      if (*current->data > *target)
         return retrieve(current->left, target);

      //go right
      if (*current->data < *target)
         return retrieve(current->right, target);
   }   
   return NULL;
}
//------------------------------------------------------------------------------
// makeEmpty & makeEmpty (overloaded)
// - Will delete all Nodes and Items pointed to by data pointers.  Deletion is
//   performed by helper function.
// - 'makeEmpty' checks if root is NULL. If 'root' is NULL, funciton exits. If
//   'root' is not NULL, will pass 'root' as a paramete to 'makeEmpty' helper
//   function.
// - 'makeEmpty' (helper) will recursively traverse Tree, deleteing data
//   pointers (deleting memory pointed to by pointers) and deleting Nodes until
//   base case is reached.  Base case: 'left' and 'right' are NULL.
//------------------------------------------------------------------------------
void Tree::makeEmpty()
{
   if (!isEmpty())
      makeEmpty(root);
}
/******************************************************************************/
void Tree::makeEmpty(Node* current)
{
   if (current->left != NULL)
      makeEmpty(current->left);

   if (current->right != NULL)
      makeEmpty(current->right);

   delete current->data;
   delete current;
}
//------------------------------------------------------------------------------
// isEmpty
// Checks if root of tree is NULL.  If NULL, returns true because there are no
//   nodes in the tree.  If not NULL, returns false because at least one node
//   exists in tree.
//------------------------------------------------------------------------------
bool Tree::isEmpty() const { return root == NULL; }

//------------------------------------------------------------------------------
// operator<< & outputHelper
// - Will output the data of all 'Items' stored in the Tree in order (left to
//   right). Display function of 'Item' will be invoked as well as the 'header'
//   function for 'Item' for formatting purposes.
// - Recursive calls to 'outputHelper' will traverse the Tree in order.
//------------------------------------------------------------------------------
ostream& operator<<(ostream& output, const Tree& param)
{
   if (!param.isEmpty())
   {
      param.root->data->header();
      param.outputHelper(param.root, output);
   }
   output << endl;
   return output;
}
/******************************************************************************/
void Tree::outputHelper(Node* current, ostream& output) const
{
   if (current->left != NULL)
      outputHelper(current->left, output);

   current->data->display();

   if (current->right != NULL)
      outputHelper(current->right, output);   
}