/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

#include "movie.h"

//------------------------------------------------------------------------------
// validDate
// - Checks if year read from external file is greater than 1900.
//------------------------------------------------------------------------------
bool Movie::validDate(int year) const { return year >= 1900; }

//------------------------------------------------------------------------------
// increaseStock
// - Will increase stock by a factor of 10 whenever a duplicate Movie is found
//   while inserting into Tree.
//------------------------------------------------------------------------------
void Movie::increaseStock() { Item::stock += NEW_STOCK; }

//------------------------------------------------------------------------------
// display
// Will define specific output style for outputing information stored in a
//   Movie object and children classes.
//------------------------------------------------------------------------------
void Movie::display() const
{
   cout << right << setw(COL_DVDIN) << stock << "   "
      << left << setw(COL_DVDOT) << borrowed
      << left << setw(COL_TITLE) << title.substr(0, TRUNC_TIT)
      << left << setw(COL_DIREC) << director.substr(0, TRUNC_DIR) << "   "
      << left << setw(COL_YEAR) << year << endl;
}
//------------------------------------------------------------------------------
// display_t
// - Will display some of the information stored about a Movie. Speciall display
//   for displaying for Transactions.
//------------------------------------------------------------------------------
void Movie::display_t() const
{
   cout << left << setw(COL_TITLE) << title.substr(0, TRUNC_TIT)
      << left << setw(COL_DIREC) << director.substr(0, TRUNC_DIR) << "   "
      << left << setw(COL_YEAR) << year << endl;
}