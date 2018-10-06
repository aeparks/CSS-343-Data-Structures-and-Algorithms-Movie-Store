/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

/*-- Classic ----------------------------------------------------------
 * Derived from 'Movie'
 * Contains specified functionality for Comedy objects.
 *
 *-- Assumptions ------------------------------------------------------
 * - createItem
 *   -> If any title begins with a number, the number will be in
 *      in written form
 *-------------------------------------------------------------------*/
#ifndef CLASSIC_H
#define CLASSIC_H
#include "movie.h"

using namespace std;

//values for formatting header
int const HED_MONTH = 3;       //width for 'month' column heading
int const HED_ACTOR = 6;       //width for 'actor' column heading

//values for formatting output
int const COL_MONTH = 2;       //column width for month
int const COL_ACTOR = 17;      //column width for actor

class Classic : public Movie
{
public:
   //default constructor //used by MovieFactor
   Classic();
   //constructor
   Classic(string,string,string,string,int,int);

   //creates new 'Classic' by calling constructor //returns pointer to new object
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

   //for displaying formatted output
   virtual void display() const;

   //for displaying formatted output for transactions
   virtual void display_t() const;

protected:
   int month;               //month classic was released
   string p_first;          //main performer's first name
   string p_last;           //main performer's last name

   //checks if year and month are valid
   virtual bool validDate(int,int) const;
};
#endif