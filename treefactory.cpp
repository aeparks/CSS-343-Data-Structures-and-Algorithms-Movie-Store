/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

#include "treefactory.h"
#include <iostream>

//------------------------------------------------------------------------------
// Constructor
// - Instantiates a new hash factory of trees.
//------------------------------------------------------------------------------
TreeFactory::TreeFactory()
{
   //initialize array
   for (int i = 0; i < TREEF_SIZE; i++)
      factory[i] = NULL;

   //allows for only 'defined' genres to produce trees
   /* ... can add more as necessary ... */
   factory[2] = new Tree();         //classic binary tree
   factory[3] = new Tree();         //drama binary tree
   factory[5] = new Tree();         //comedy binary tree
   /* ... can add more as necessary ... */
}
//------------------------------------------------------------------------------
// Destructor
// - Will delete functions pointed to by factory array and will reset pointers
//   NULL.
//------------------------------------------------------------------------------
TreeFactory::~TreeFactory()
{
   for (int i = 0; i < TREEF_SIZE; i++)
   {
      delete factory[i];
      factory[i] = NULL;
   }
}
//------------------------------------------------------------------------------
// createTree
// - Will hash parameter char that represents the eventual genre of the final
//   tree.  The hash of the genre will index to the Tree constructor that will
//   build a tree to hold movie objects of that genre.
//------------------------------------------------------------------------------
Tree* TreeFactory::createTree(char genre)
{
   int index = hashGenre(genre);

   if (factory[index] != NULL)
      return factory[index]->newTree();
   else
      return NULL;
}
//------------------------------------------------------------------------------
// hashGenre
// - Will 'hash' char paremeter to an integer value.  Returned integer represents
//   an index to any array of Trees.
//------------------------------------------------------------------------------
int TreeFactory::hashGenre(char type)
{
   return (type - 'A') % TREEF_SIZE;
}