/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

/*-- Movie ------------------------------------------------------------
 * Derived from 'Item'
 * Contains functions and data members for Movie objects.
 *-- Assumptions ------------------------------------------------------
 *
 *-------------------------------------------------------------------*/
#ifndef MOVIE_H
#define MOVIE_H
#include "item.h"
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

//values for formatting output
int const HED_DVDIN = 5;     //width for 'dvdIn' column heading
int const HED_DVDOT = 4;     //width for 'dvdOut' column heading
int const HED_TITLE = 22;    //width for 'title' column heading
int const HED_DIREC = 17;    //width for 'director' column heading
int const HED_YEAR  = 5;     //width for 'year' column heading

//values for formatting output
int const COL_DVDIN = 2;     //column width for 'dvdIn'
int const COL_DVDOT = 4;     //column width for 'dvdOut'
int const COL_TITLE = 22;    //column width for 'title'
int const COL_DIREC = 17;    //column width for 'director'
int const COL_YEAR  = 5;     //column width for 'year'

//for truncation
int const TRUNC_TIT = 21;    //number of characters to display
int const TRUNC_DIR = 16;    //number of characters to display

int const NEW_STOCK = 10;    //amount to increase stock

class Movie : public Item
{
public:
   //pure virtual functions //to be overridden later by children
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

   //virtual functions //possibly overridden later by children
   //for displaying formatted output
   virtual void display() const;

   //for displaying formatted output for transactions
   virtual void display_t() const;

   //for increasing stock
   virtual void increaseStock();

protected:
   int year;           //year movie was released
   string title;       //title of the movie
   string director;    //director of the movie
   char genre;         //genre of movie

   //checks if year is greater than 1900 or not
   virtual bool validDate(int) const;
};
#endif