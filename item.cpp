/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

#include "item.h"

//------------------------------------------------------------------------------
// Constructor
// - Initializes data members of 'Item'.  Necessary for constructors of dervied
//   classes.
//------------------------------------------------------------------------------
Item::Item()
{
   stock = INITIAL_STOCK;
   borrowed = 0;
}
//------------------------------------------------------------------------------
// stockAdjustment
// - Will adjust 'stock' and 'borrowed' number according parameters. If either
//   'stock' or 'borrowed' cannot be adjusted, will return false. Otherwise,
//   will return true;
//------------------------------------------------------------------------------
bool Item::stockAdjustment(int inStockAdj, int outStockAdj)
{
   //trying to borrow more than the store stock
   if (stock == 0 && outStockAdj > 0)
      return false;
   //trying return movies the store doesn't own
   if (borrowed == 0 && inStockAdj > 0)
      return false;

   //make adjustments //parameters can be positive or negative
   stock += inStockAdj;
   borrowed += outStockAdj;
   return true;
}