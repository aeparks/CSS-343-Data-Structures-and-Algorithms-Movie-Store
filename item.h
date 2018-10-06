/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v3 - MOVIE Store */

/*-- Item ----------------------------------------------------------------------
 * Base (parent) for all rentable things in the store. Item is the lowest level,
 * thus most basic form, of an Item.  As such, it mostly contains pure virutal
 * functions to be overridden with object-specific instructions. The one
 * non-pure virtual function is for managing the stock of an Item which is a
 * universal activity for physical, rentable, products.
 *
 *-- Assumptions ---------------------------------------------------------------
 * - stockAdjustment
 *   -> 'stock' and 'borrowed' will never have to be modified more than +1 or -1
 *----------------------------------------------------------------------------*/
#ifndef ITEM_H
#define ITEM_H
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;

int const INITIAL_STOCK = 10;   //starting count of items in stock

class Item
{
public:
   //constructor
   Item();

   //pure virtual functions //to be overridden by children
   //calls constructor
   virtual Item* createItem(ifstream&) = 0;

   //boolean comparison operators
   virtual bool operator==(const Item&) const = 0;
   virtual bool operator!=(const Item&) const = 0;
   virtual bool operator>(const Item&) const = 0;
   virtual bool operator<(const Item&) const = 0;
   virtual bool operator>=(const Item&) const = 0;
   virtual bool operator<=(const Item&) const = 0;

   //for displaying item header
   virtual void header() const = 0;

   //for displaying formatted output
   virtual void display() const = 0;

   //for displaying formatted output for transactions
   virtual void display_t() const = 0;

   //for increasing stock during duplicate insertion
   virtual void increaseStock() = 0;

   //modifies 'stock' and 'borrowed' values
   virtual bool stockAdjustment(int,int);

protected:
   int stock;         //number of this item in stock
   int borrowed;      //number of this item currently borrowed
};
#endif