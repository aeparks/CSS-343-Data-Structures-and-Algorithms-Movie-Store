/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

#include "drama.h"

//------------------------------------------------------------------------------
// Constructor and Default Constructor
// Creates a new Drama object with the passed attributes.
//------------------------------------------------------------------------------
Drama::Drama() {}

Drama::Drama(string dir, string tit, int yr)
{
   Movie::director = dir;
   Movie::title = tit;
   Movie::year = yr;
   Movie::genre = 'D';
}
//------------------------------------------------------------------------------
// createItem
// - Reads in a line from parameter file and creates a new 'Drama' object with
//   that information. 'year' is checked for validity before object is created.
//   If 'year' is not valid, then NULL will be returned, otherwise a new
//   'Drama' with information from file will be created and returned.
//------------------------------------------------------------------------------
Item* Drama::createItem(ifstream& infile)
{
   string t_dir;           //holds director string from infile
   string t_tit;           //holds title string from infile
   int t_yea = 1901;       //holds integer for year from infile

   infile.get();    //for blank space before director
   getline(infile, t_dir, ',');
   infile.get();    //for blank space before title
   getline(infile, t_tit, ',');
   infile.get();    //for blank space before year

   if (infile.peek() != '\n')
      infile >> t_yea;
   //infile.clear();

   if (validDate(t_yea))
      return new Drama(t_dir, t_tit, t_yea);

   return NULL;
}
//------------------------------------------------------------------------------
// operator== [compared by director, then title]
// - Will check if director and param director are the same and if year and
//   param year are the same. If all values are the same, will return true
//   otherwise will return false.
//------------------------------------------------------------------------------
bool Drama::operator==(const Item& parent) const
{
   //cast parameter to 'Drama'
   const Drama& param = static_cast<const Drama&>(parent);

   if (director.compare(param.director) != 0)
      return false;
   if (title.compare(param.title) != 0)
      return false;

   return true;
}
//------------------------------------------------------------------------------
// operator!= [compared by director, then title]
// - Will check if director and param director are dissimilar and if year and
//   param year and dissimilar. If any values are dissimilar, will return true
//   otherwise will return false. Function returns negation of 'operator=='.
//------------------------------------------------------------------------------
bool Drama::operator!=(const Item& parent) const
{
   //cast parameter to 'Drama'
   const Drama& param = static_cast<const Drama&>(parent);

   return !(*this == param);
}
//------------------------------------------------------------------------------
// operator< [compared by director, then title]
// - Will check if calling object is less than parameter. Comparisons will be
//   made against director then title. If 'this' director is less than 'param'
//   director will return true. If 'this' director is equal to 'param' director,
//   check will be made against title. If 'this' title is less than 'param'
//   title then true will be returned, otherwise false.
//------------------------------------------------------------------------------
bool Drama::operator<(const Item& parent) const
{
   //cast parameter to 'Drama'
   const Drama& param = static_cast<const Drama&>(parent);

   if (director.compare(param.director) < 0)
      return true;

   if (director.compare(param.director) == 0)
   {
      if (title.compare(param.title) < 0)
         return true;
   }
   return false;
}
//------------------------------------------------------------------------------
// operator> [compared by director, then title]
// - Will check if calling object is greater than parameter. Comparisons will be
//   made against director then title. If 'this' director is greater than
//   'param' director will return true. If 'this' director is equal to 'param'
//   director, check will be made against title. If 'this' title is greater than
//   'param' title then true will be returned, otherwise false.
// - Returns negation of 'operator<'
//------------------------------------------------------------------------------
bool Drama::operator>(const Item& parent) const
{
   //cast parameter to 'Drama'
   const Drama& param = static_cast<const Drama&>(parent);

   return !(*this < param);
}
//------------------------------------------------------------------------------
// operator>= [compared by director, then title]
// - Will check if calling object is "greater" than or equal to param. Calls to
//   'operator>' and 'operator==' will be used to compare. If either function
//   call returns true, true will be returned. If both function calls return
//   false, false will be returned.
//------------------------------------------------------------------------------
bool Drama::operator>=(const Item& parent) const
{
   //cast parameter to 'Drama'
   const Drama& param = static_cast<const Drama&>(parent);

   return (*this > param) || (*this == param);
}
//------------------------------------------------------------------------------
// operator<= [compared by director, then title]
// - Will check if calling object is "less" than or equal to param. Calls to
//   'operator<' and 'operator==' will be used to compare. If either function
//   call returns true, true will be returned. If both function calls return
//   false, false will be returned.
//------------------------------------------------------------------------------
bool Drama::operator<=(const Item& parent) const
{
   //cast parameter to 'Drama'
   const Drama& param = static_cast<const Drama&>(parent);

   return (*this < param) || (*this == param);
}
//------------------------------------------------------------------------------
// header
// - Will output header for 'Comedy' movie display.  Header inclues display
//   title, DVD column types, and column headings.
//------------------------------------------------------------------------------
void Drama::header() const
{
   cout << "  *** Drama ***\n"
      << "*IN* *OUT*\n"
      << left << setw(HED_DVDIN) << "DVD"
      << left << setw(HED_DVDOT) << "DVD"
      << left << setw(HED_TITLE) << "TITLE"
      << left << setw(HED_DIREC) << "DIRECTOR"
      << left << setw(HED_YEAR) << "   YEAR" << endl;
}