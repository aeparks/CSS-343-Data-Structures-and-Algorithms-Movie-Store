/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

/*-- Drama ------------------------------------------------------------
 * Derived from 'Movie'
 * Contains specified functionality for Drama objects.
 *
 *-- Assumptions ------------------------------------------------------
 *
 *-------------------------------------------------------------------*/
#ifndef DRAMA_H
#define DRAMA_H

#include "movie.h"

using namespace std;

class Drama : public Movie
{
public:
   //default constructor //used by MovieFactory
   Drama();
   //constructor
   Drama(string, string, int);

   //creates new 'Drama' by calling constructor //returns pointer to new object
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