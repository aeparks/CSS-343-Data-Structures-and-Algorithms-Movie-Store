/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

/*-- Comedy -----------------------------------------------------------
 * Derived from 'Movie'
 * Contains specified functionality for Comedy objects.
 *
 *-- Assumptions ------------------------------------------------------
 * - createItem
 *   -> If any title begins with a number, the number will be in
 *      in written form
 *---------------------------------------------------------------------*/
#ifndef COMEDY_H
#define COMEDY_H

#include "movie.h"

using namespace std;

class Comedy : public Movie
{
public:
   //default constructor //used by MovieFactory
   Comedy();
   //constructor
   Comedy(string,string,int);

   //creates new 'Comedy' by calling constructor //returns pointer to new object
   virtual Item* createItem(ifstream&);

   //boolean comparison operators
   virtual bool operator==(const Item&) const;
   virtual bool operator!=(const Item&) const;
   virtual bool operator>(const Item&) const;
   virtual bool operator<(const Item&) const;
   virtual bool operator>=(const Item&) const;
   virtual bool operator<=(const Item&) const;

   //for displaying item header
   virtual void header() const;
};
#endif