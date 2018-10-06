/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

/*-- Tree ----------------------------------------------------------------------
 * Tree is a binary tree of Nodes with pointers to Item nodes. Tree does not
 * contain functionality to balance itself. Tree does contain functionality to
 * 'insert' new Items, 'retrieve' Items being stored in Tree, and clearing all
 * all contents of the Tree (Nodes and Items being stored).
 *
 *-- Assumptions ---------------------------------------------------------------
 * - insert
 *   -> parameter 'Item' will be checked for errors before being handed to
 *      this function.
 *   -> will only return false if paramter cannot be inserted due to duplicate
 *      'Item' found.
 *   -> will only return true if parameter 'Item' is inserted
 *----------------------------------------------------------------------------*/
#ifndef TREE_H
#define TREE_H

#include "item.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Tree
{
   //overloaded output //for outputting 'S' command
   friend ostream& operator<<(ostream&, const Tree&);

public:
   //constructor
   Tree();
   //destructor
   ~Tree();

   //instantiates new 'Tree'
   virtual Tree* newTree();
   //inserts an new 'Item' into a 'Tree'
   virtual bool insert(Item*);
   //adjusts the stock amount of parameter 'Item'
   virtual bool stockAdjustment(Item*,int,int);
   //searches Tree for first param //assigns second param if found
   virtual Item* const retrieve(const Item*) const;

   //checks if root == NULL
   virtual bool isEmpty() const;
   //deletes all Nodes and Items from Tree
   virtual void makeEmpty();

protected:
   struct Node
   {
      Node* left;           //pointer to left branch
      Node* right;          //pointer to right branch
      Item* data;           //pointer to an Item (derived from Item)
   };
   Node* root;              //pointer to root of Tree

   //recursive helper function for 'retrieve'
   virtual Item* const retrieve(Node*, const Item*) const;
   //recursive helper function for 'makeEmpty'
   virtual void makeEmpty(Node*);
   //recursive helper function for 'operato<<'
   virtual void outputHelper(Node*,ostream&) const;
};
#endif