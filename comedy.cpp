/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

#include "comedy.h"

//------------------------------------------------------------------------------
// Constructor and Default Constructor
// Creates a new Comedy object with the passed attributes.
//------------------------------------------------------------------------------
Comedy::Comedy() {}

Comedy::Comedy(string dir, string tit, int yr)
{
   Movie::director = dir;
   Movie::title = tit;
   Movie::year = yr;
   Movie::genre = 'F';
}
//------------------------------------------------------------------------------
// createItem
// - Reads in a line from parameter file and creates a new 'Comedy' object with
//   that information. 'year' is checked for validity before object is created.
//   If 'year' is not valid, then NULL will be returned, otherwise a new
//   'Comedy' with information from file will be created and returned.
// - Contains the functionality to create 'full' Comedies or 'limited' Comedies
//   used for comparison for Transactions. Check for digit will be made against
//   year, if there is no digit, then a 'limited' Comedy will be created, if it
//   is a digit a 'full' Comedy will be made.
// - The difference between a 'full' Comedy' and a 'limited' quantity is
//   wheter the default values for director or title will be used.
//------------------------------------------------------------------------------
Item* Comedy::createItem(ifstream& infile)
{
   string temp;             //holds ambiguous string while other data is checked
   string t_dir = "dir";    //holds director string from infile
   string t_tit = "tit";    //holds title string from infile
   int t_yea;               //holds integer for year from infile

   infile.get();   //for blank space
   getline(infile, temp, ',');
   infile.get();    //for blank space
   if (!isdigit(infile.peek()))
   {
      t_dir = temp;
      getline(infile, t_tit, ',');
      infile.get();    //for blank space before year
      infile >> t_yea;
   }
   else
   {
      t_tit = temp;
      infile >> t_yea;
   }

   if (validDate(t_yea))
      return new Comedy(t_dir, t_tit, t_yea);

   return NULL;
}
//------------------------------------------------------------------------------
// operator== [compared by title, then date]
// - Will check if title and param title are the same and if param yaer and year
//   are the same. If all values are the same, will return true otherwise will
//   return false.
//------------------------------------------------------------------------------
bool Comedy::operator==(const Item& parent) const
{
   //cast parameter to 'Comedy'
   const Comedy& param = static_cast<const Comedy&>(parent);

   if (title.compare(param.title) != 0)
      return false;
   if (year != param.year)
      return false;

   return true;
}
//------------------------------------------------------------------------------
// operator!= [compared by title, then date]
// - Will check if title and param title are dissimilar and if year and param
//   year are dissimilar. If any values are dissimilar will return true
//   otherwise (in the case of both being same) will return false. Function
//   returns the negation of 'operator=='.
//------------------------------------------------------------------------------
bool Comedy::operator!=(const Item& parent) const
{
   //cast parameter to 'Comedy'
   const Comedy& param = static_cast<const Comedy&>(parent);

   return !(*this == param);
}
//------------------------------------------------------------------------------
// operator< [compared by title, then date]
// - Will check if calling object is less than parameter. Comparisons will be
//   made against title then date. If 'this' title is less than 'param' title,
//   will return true. If 'this' title is equal to 'param' title, check will be
//   made against date. If 'this' date is less than 'param' date, then true will
//   be returned, otherwise false.
//------------------------------------------------------------------------------
bool Comedy::operator<(const Item& parent) const
{
   //cast parameter to 'Comedy'
   const Comedy& param = static_cast<const Comedy&>(parent);

   if (title.compare(param.title) < 0)
      return true;
   if (title.compare(param.title) == 0)
   {
      if (year < param.year)
         return true;
   }
   return false;
}
//------------------------------------------------------------------------------
// operator> [compared by title, then date]
// - Will check if calling object is greater than parameter. Comparisons will be
//   made against title then date. If 'this' title is greater than 'param'
//   title, will return true. If 'this' title is equal to 'param' title, check
//   will be made against date. If 'this' date is greater than 'param' date,
//   then true will be returned, otherwise false.
// - Returns negation of 'operator<'.
//------------------------------------------------------------------------------
bool Comedy::operator>(const Item& parent) const
{
   //cast parameter to 'Comedy'
   const Comedy& param = static_cast<const Comedy&>(parent);

   return !(*this < param);
}
//------------------------------------------------------------------------------
// operator>= [compared by title, then date]
// - Will check of calling object is "greater" than or equal to parameter. Calls
//   to "operator>" and "operator==" will be used to compare. If either function
//   call returns true, then true will be returned. If both return false, false
//   will be returned.
//------------------------------------------------------------------------------
bool Comedy::operator>=(const Item& parent) const
{
   //cast parameter to 'Comedy'
   const Comedy& param = static_cast<const Comedy&>(parent);

   return (*this > param) || (*this == param);
}
//------------------------------------------------------------------------------
// operator<= [compared by title, then date]
// - Will check if calling object is "less" than or equal to paramter. Calls to
//   "operator<" and "operator==" will be used to compare. If either function
//   call returns true, then true will be returned. If both return false, false
//   will be returned.
//------------------------------------------------------------------------------
bool Comedy::operator<=(const Item& parent) const
{
   //cast parameter to 'Comedy'
   const Comedy& param = static_cast<const Comedy&>(parent);

   return (*this < param) || (*this == param);
}
//------------------------------------------------------------------------------
// header
// - Will output header for 'Comedy' movie display.  Header inclues display
//   title, DVD column types, and column headings.
//------------------------------------------------------------------------------
void Comedy::header() const
{
   cout << "  *** Comedy ***\n"
      << "*IN* *OUT*\n"
      << left << setw(HED_DVDIN) << "DVD"
      << left << setw(HED_DVDOT) << "DVD"
      << left << setw(HED_TITLE) << "TITLE"
      << left << setw(HED_DIREC) << "DIRECTOR"
      << left << setw(HED_YEAR) << "   YEAR" << endl;
}