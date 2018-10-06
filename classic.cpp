/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

#include "classic.h"

//------------------------------------------------------------------------------
// Constructor and Default Constructor
// - Creates a new Classic object with the passed attributes.
//------------------------------------------------------------------------------
Classic::Classic() {}

Classic::Classic(string dir, string tit, string fir, string las, int mo, int yr)
{
   Movie::director = dir;
   Movie::title = tit;
   p_first = fir;
   p_last = las;
   month = mo;
   Movie::year = yr;
   Movie::genre = 'C';
}
//------------------------------------------------------------------------------
// createItem
// - Reads in a line from parameter file and creates a new 'Classic' object with
//   that information. 'Month' and 'Year' are checked for validity before
//   object is instantiated. If either are not valid, then NULL will be
//   returned, otherwise a new 'Classic' with information from file will be
//   instantiated and returned.
// - If 'infile' is a command file, check will be made if first line of data
//   is an integer. If it is, then will call constructor for temp Movie to
//   compare to get pointer for actualy movie in a Tree for transaction.
//------------------------------------------------------------------------------
Item* Classic::createItem(ifstream& infile)
{
   string t_dir = "dir";    //holds director string from infile
   string t_tit = "tit";    //holds title string from infile
   string t_fir;            //holds first name string of actor from infile
   string t_las;            //holds last name string of actor from infile
   int t_mon;               //holds integer for month from infile
   int t_yea;               //holds integer for year from infile

   //check if reading in movieFile or cmdFile
   infile.get();  //for blank line before data
   if (!isdigit(infile.peek()))
   {
      getline(infile, t_dir, ',');
      infile.get();    //for blank space before title
      getline(infile, t_tit, ',');
      infile.get();    //for blank space before actor
      infile >> t_fir >> t_las >> t_mon >> t_yea;
   }
   else
      infile >> t_mon >> t_yea >> t_fir >> t_las;

   if (validDate(t_mon, t_yea))
      return new Classic(t_dir, t_tit, t_fir, t_las, t_mon, t_yea);

   return NULL;
}
//------------------------------------------------------------------------------
// operator== [compared by date, then famous actor]
// - Will check if param date (month and year) are the same as calling object
//   and if param actor (p_lName and p_fName) are the same as calling object. If
//   all values are the same, will return true. Will return false at any time
//   these values are not the same.
//------------------------------------------------------------------------------
bool Classic::operator==(const Item& parent) const
{
   //cast parameter to 'Classic'
   const Classic& param = static_cast<const Classic&>(parent);

   if (param.month != month)
      return false;
   if (param.year != year)
      return false;
   if (p_first.compare(param.p_first) != 0)
      return false;
   if (p_last.compare(param.p_last) != 0)
      return false;

   return true;
}
//------------------------------------------------------------------------------
// operator!= [compared by date, then famous actor]
// - Will check if date (month and year) and param date (month and year) are
//   dissimilar and if actor and param actor (p_lName and p_fName) are
//   dissimilar. If any values are dissimilar, will return true otherwise will
//   return false. Function returns the negation of 'operator=='.
//------------------------------------------------------------------------------
bool Classic::operator!=(const Item& parent) const
{
   //cast parameter to 'Classic'
   const Classic& param = static_cast<const Classic&>(parent);

   return !(*this == param);
}
//------------------------------------------------------------------------------
// operator< [compared by date, then famous actor]
// - Will check if calling object is less than parameter. Comparisons will be
//   made against date then actor. If 'this' date is less than 'param' date,
//   will return true. If 'this' date is equal to 'param' date, check will be
//   made against actor. If 'this' actor is less than 'param' actor, then true will
//   be returned, otherwise false.
//------------------------------------------------------------------------------
bool Classic::operator<(const Item& parent) const
{
   //cast parameter to 'Classic'
   const Classic& param = static_cast<const Classic&>(parent);

   //compare month and year
   if (year < param.year)
      return true;
   if (year < param.year && month == param.month)
      return true;
   if (year == param.year)
   {
      if (month > param.month)
         return false;
      if (month < param.month)
         return true;
   }

   //compare actor first and last names
   if (year == param.year && month == param.month)
   {
      if (p_last.compare(param.p_last) < 0)
         return true;
      if (p_first.compare(param.p_first) < 0)
         return true;
   }

   return false;
}
//------------------------------------------------------------------------------
// operator> [compared by date, then famous actor]
// - Will check if calling object is greater than parameter. Comparisons will be
//   made against date then actor. If 'this' date is greater than 'param' date,
//   will return true. If 'this' date is equal to 'param' date, check will be
//   made against actor. If 'this' actor is greater than 'param' actor, then
//   true will be returned, otherwise false.
// - Returns negation of 'operator<'.
//------------------------------------------------------------------------------
bool Classic::operator>(const Item& parent) const
{
   //cast parameter to 'Classic'
   const Classic& param = static_cast<const Classic&>(parent);

   return !(*this < param);
}
//------------------------------------------------------------------------------
// operator<= [compared by date, then famous actor]
// - Will check if calling object is "greater" or equal to the parameter. Calls
//    'operator<' and 'operator=='. Will return true if one of the calls are
//    true.  Will return false if both function calls are false.
//------------------------------------------------------------------------------
bool Classic::operator<=(const Item& parent) const
{
   //cast parameter to 'Classic'
   const Classic& param = static_cast<const Classic&>(parent);

   return (*this < param) || (*this == param);
}
//------------------------------------------------------------------------------
// operator>= [compared by date, then famous actor]
// - Will check if calling object is "less" or equal to the parameter. Calls
//    'operator>' and 'operator=='. Will return true if one of the calls are
//    true.  Will return false if both function calls are false.
//------------------------------------------------------------------------------
bool Classic::operator>=(const Item& parent) const
{
   //cast parameter to 'Classic'
   const Classic& param = static_cast<const Classic&>(parent);

   return (*this > param) || (*this == param);
}
//------------------------------------------------------------------------------
// validDate (overloaded)
// - Checks if year is greater than 1900 and checks if month is between 1 and
//   12. Will return true if both are true, otherwise will return false.
//------------------------------------------------------------------------------
bool Classic::validDate(int month, int year) const
{
   return (month > 0 && month < 13) && year >= 1900;
}
//------------------------------------------------------------------------------
// header
// - Will output header for 'Classic' movie display.  Header inclues display
//   title, DVD column types, and column headings.
//------------------------------------------------------------------------------
void Classic::header() const
{
   cout << "  *** Classics ***\n"
      << "*IN* *OUT*\n"
      << left << setw(HED_DVDIN) << "DVD"
      << left << setw(HED_DVDOT) << "DVD"
      << left << setw(HED_TITLE) << "TITLE"
      << left << setw(HED_DIREC) << "DIRECTOR"
      << left << setw(HED_MONTH) << "MO"
      << left << setw(HED_YEAR) << "YEAR"
      << left << setw(HED_ACTOR) << "ACTOR\n";
}
//------------------------------------------------------------------------------
// display
// - Will define specific output style for outputing information stored in a
//   Classic object.
//------------------------------------------------------------------------------
void Classic::display() const
{
   cout << right << setw(COL_DVDIN) << stock << "   "
      << left << setw(COL_DVDOT) << borrowed
      << left << setw(COL_TITLE) << title.substr(0, TRUNC_TIT)
      << left << setw(COL_DIREC) << director.substr(0, TRUNC_DIR)
      << right << setw(COL_MONTH) << month << " "
      << left << setw(COL_YEAR) << year
      << left << setw(COL_ACTOR) << p_first + " " + p_last << "\n";
}
//------------------------------------------------------------------------------
// display_t
// - Will display some of the information stord about Classic. Special display
//   for displaying Transactions.
//------------------------------------------------------------------------------
void Classic::display_t() const
{
   cout << left << setw(COL_TITLE) << title.substr(0, TRUNC_TIT)
      << left << setw(COL_DIREC) << director.substr(0, TRUNC_DIR)
      << right << setw(COL_MONTH) << month << " "
      << left << setw(COL_YEAR) << year
      << left << setw(COL_ACTOR) << p_first + " " + p_last << "\n";
}