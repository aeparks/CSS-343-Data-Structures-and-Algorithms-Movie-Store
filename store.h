/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

/*-- Store ---------------------------------------------------------------------
 * Store is the manager class for this program. External data files are read
 * in in 'main.cpp' then passes as parameters to Store. Store is then
 * for the creation and maintaining of a collection of Customer objects 
 * (CustomerArray), a collection of Item objects (TreeArray) and executing lines
 * in the 'command' external file.
 * Upon exit, Store is also responsible for initializing clean-up of dynamically
 * allocated memory. Only memory dynamically allocated by it will be delete by
 * Store. All other dynamically allocated memory will be deleted once Store
 * executes the functions that instruct the other data structures to delete
 * dynamically allocated memory allocated by them.
 *
 *-- Assumptions ---------------------------------------------------------------
 * - Data Files
 *   -> all data files are formatted correctly as per the assignment
 *      instructions. As such, "genre" of the "movie" file should always be
 *      an alphabetic character (A - Z).  Leaving coding in place that checks
 *      hashed values beyond what A - Z would hash to.
 *   -> line length in the "movie" file will never exceed 1024 characters
 * - CustomerArray
 *   -> the number of unique Customers objects will never exceed 9999.
 * - TreeArray
 *   -> size is 26 therefore holds the potential to index to hashes of
 *      characters 'A' through 'Z' 
 *----------------------------------------------------------------------------*/
#ifndef STORE_H
#define STORE_H

#include <iostream>
#include <string>

using namespace std;

int const T_LENGTH = 26;           //size of TreeArray (hash table)
int const M_LENGTH = 26;           //size of Transaction hash table
int const C_LENGTH = 10000;        //size of 'CustomerArray'
int const S_LENGTH = 1024;         //maximum length of string for 'ignore'

char const MED_TYPE = 'D';         //accepted media type //"DVD"
char const S_CMD   = 'S';          //character of show command

//forward reference for 'Item' pointers
class Item;
//forward reference for 'Tree' pointers
class Tree;
//forward reference for 'Customer' pointers
class Customer;
//forward reference for 'Transaction' pointers
class Transaction;

class Store
{
public:
   //construtor
   //initializes CustomerArray and TreeArray //calls separate functions for initialization
   Store(ifstream&,ifstream&);

   //reads and performs lines of commands in parameter file
   virtual void startDay(ifstream&);
   //initiates deletion of dynamic memory for associated objects
   virtual void endDay();

protected:
   //functions called by 'constructor'
   //read from customer file //populate 'CustomerArray' with Customer objects
   virtual void populateCustomerArray(ifstream&);
   //read from movie file //attempts to add new Item to a Tree
   virtual void addItem(ifstream&,int);
   //read from movie file //read in genre and create new Trees
   virtual void createTrees(ifstream&);

   //displays all business information //for transaction 'S'
   virtual void displayAll() const;

   // ***utility functions***
   //hashing functions
   //returns hash vaule of char parameter
   virtual int hashGenre(char);
   //returns hash vaule of char parameter
   virtual int hashCmd(char);

   //validation functions
   //checks validity of transaction information (not movie information)
   virtual bool verifyTransaction(ifstream&,int&,char&,Item*&);
   //check if customer id is within bounds of 'CustomerArray'
   virtual bool isValid(int) const;

   //array of Trees, each representing a different genre
   Tree* TreeArray[T_LENGTH];
   //array of Customer for the store
   Customer* CustomerArray[C_LENGTH];
};
#endif