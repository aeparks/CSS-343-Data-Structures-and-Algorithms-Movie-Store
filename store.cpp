/* Aaron Parks
 * Prof. Carol Zander
 * CSS 343 : Winter 2010
 * Lab 4v4 - MOVIE Store */

#include "store.h"
#include "tree.h"
#include "customer.h"
#include "transaction.h"
#include "treefactory.h"
#include "moviefactory.h"
#include "transfactory.h"
#include <iostream>
#include <fstream>

//------------------------------------------------------------------------------
// Constructor
// - Instantiates and populates CustomerArray and TreeArray. Instantiation of
//   Trees for TreeArray; the population of CustomerArray; and the population
//   of the Trees in TreeArray are all handled by separate functions.
//------------------------------------------------------------------------------
Store::Store(ifstream& customer_f, ifstream& movie_f)
{
   //initialize TreeArray
   for (int i = 0; i < T_LENGTH; i++)
      TreeArray[i] = NULL;

   //initialize CustomerArray
   for (int j = 0; j < C_LENGTH; j++)
      CustomerArray[j] = NULL;

   //validity of "customer_f" and "movie_f" were checked in main
   this->createTrees(movie_f);
   this->populateCustomerArray(customer_f);
}
/******************************************************************************
 *          FUNCTIONS USED BY CONSTRUCTOR FOR OBJECT INITIALIZATION           *
 ******************************************************************************/
//------------------------------------------------------------------------------
// createTrees
// - Will read in the first character from each line in an external file and
//   will pass control to 'treeFactory' which will create new binary trees. Only
//   indices that have been defined in the 'treeFactory' will produce Tree
//   objects, otherwise NULL will be handed back.
// - Upon exiting, 'TreeArray' will contain pointers equal to the number of
//   defined genres.
//------------------------------------------------------------------------------
void Store::createTrees(ifstream& movieFile)
{
   TreeFactory tree_Factory;

   int index;                //value of hashed genre
   char genre = '/0';        //holder for movie's genre //currently 'c','d','f'

   while (true)
   {
      movieFile >> genre;
      if (!movieFile.eof())
      {
         index = hashGenre(genre);
         //check if genre hashed within bounds of array
         if (index >= 0 && index < T_LENGTH)
         {
            movieFile.unget();  //move read pointer back
            //check 'TreeArray' for prior existance of genre tree
            if (TreeArray[index] == NULL)
               TreeArray[index] = tree_Factory.createTree(genre);
            
            if (TreeArray[index] != NULL)
               addItem(movieFile,index);
            else
               movieFile.ignore(S_LENGTH,'\n');
         }
         else //this means 'genre' is holding a char not between a and z
            movieFile.ignore(S_LENGTH,'\n');
      }
      else
         break;
   }
}
//------------------------------------------------------------------------------
// addItem
// - Will read in a line of data and create new Item object. Not necessary to
//   do error checking on genre and its hash value; already checked in previous
//   function. If insertion is unsuccessful, will display an error message
//   stating as such and will display a message stating the stock increase for
//   the Item.
//------------------------------------------------------------------------------
void Store::addItem(ifstream& movieFile, int index)
{
   MovieFactory movie_Factory;

   Item* newMovie;       //pointer to new Movie object from 'MovieFactory'

   //create new movie
   newMovie = movie_Factory.createMovie(movieFile);
   //insert into tree
   if(!TreeArray[index]->insert(newMovie))
   {
      cout << "Insertion of new movie unsuccessful!\n"
         << "Stock increased for existing item." << endl;
   }
}
//------------------------------------------------------------------------------
// populateCustomerArray
// - Will populate 'CustomerArray' with 'Customer' objects created from
//   external file in parameter. If customerID is beyonds the bounds of the
//   CustomerArray or if the slot in the array is already occupied, will display
//   an error message and the Customer object will not be created or inserted.
//------------------------------------------------------------------------------
void Store::populateCustomerArray(ifstream& customerFile)
{
   int index;      //holds customer ID //used to index to the array
   string first;   //holds customer first name //Customer constructor parameter
   string last;    //holds customer last name //Customer constructor parameter

   while (true)
   {
      customerFile >> index;
      if (!customerFile.eof())
      {
         if (isValid(index)) //check if index is a valid customerID
         {
            customerFile >> last >> first;
            CustomerArray[index] = new Customer(first, last, index);
         }
         else
            cout << " Customer ID: " << index << " not valid." << endl;
      }
      else
         break;
   }
}
/******************************************************************************
 *                          TRANSACTION FUNCTIONS                             *
 ******************************************************************************/
//------------------------------------------------------------------------------
// displayAll (Transaction: Show)
// - Will display all Trees stored in 'TreeArray'.
//------------------------------------------------------------------------------
void Store::displayAll() const
{
   //traverse TreeArray and output
   for (int i = 0; i < T_LENGTH; i++)
   {
      if (TreeArray[i] != NULL)
         cout << *TreeArray[i];
   }
   cout << endl;
}
/******************************************************************************
 *               STARTDAY AND ENDDAY PUBLIC FUNCTIONS                         *
 ******************************************************************************/
//------------------------------------------------------------------------------
// startDay
// - Reads in lines from the paramter 'cmdFile' and creates a transaction
//   objects. Transaction objects are created by the 'transFactory' which uses
//   the first character in the line to access the proper index in
//   'transFactory' hash table.
// - Once the trasaction is completed, the a pointer to the transaction object
//   is handed to the history list of the customer.
//------------------------------------------------------------------------------
void Store::startDay(ifstream& cmdFile)
{
   TransFactory tFactory;
   Transaction* newTrans = NULL;       //ptr to result of 'tFactory.createTrans'

   char transType;            //holder for transaction type
   Item* found = NULL;        //ptr to Item found in a Tree in TreeArray
   int refID = -1;            //holder for customerID
   char refMedia = '\n';      //holder for media

   while (true)
   {
      cmdFile >> transType;
      if (!cmdFile.eof())
      {
         if (transType == S_CMD)
            displayAll();
         else
         {
            //verify a single line in 'cmdFile'
            if (verifyTransaction(cmdFile, refID, refMedia, found))
            {
               if (found == NULL) //pointer never reassigned //possible 'H' transaction
               {
                  newTrans = tFactory.createTrans(transType, refID, refMedia);
                  if (newTrans != NULL)
                  {
                     cout << *CustomerArray[refID];  //display customer History
                     CustomerArray[refID]->appendHistory(newTrans);
                  }
               }
               else //possible 'B', 'R', or invalid transaction
               {
                  newTrans = tFactory.createTrans(transType, refID, refMedia, found);
                  if (newTrans != NULL)
                  {
                     if(newTrans->perform())
                        CustomerArray[refID]->appendHistory(newTrans);
                     else
                        delete newTrans;
                  }
               }
            }
            cmdFile.clear();
         }
      }
      else
         break;
   }
}
//------------------------------------------------------------------------------
// endDay
// - Initiates deletion of all dynamically allocated memory. Calls 'makeEmpty'
//   function for all valid Trees stored in TreeArray and calls 'makeEmpty' for
//   all valid CustomerIDs in CustomerArray.  
//------------------------------------------------------------------------------
void Store::endDay()
{
   //clear TreeArray
   for (int i = 0; i < T_LENGTH; i++)
   {
      if (TreeArray[i] != NULL)
      {
         TreeArray[i]->makeEmpty();
         TreeArray[i] = NULL;
      }
   }

   //clear CustomerArray
   for (int j = 0; j < C_LENGTH; j++)
   {
      if (CustomerArray[j] != NULL)
         CustomerArray[j]->deleteHistory();
     delete CustomerArray[j];
   }
}
/******************************************************************************
 *                           UTILITY FUNCTIONS                                *
 ******************************************************************************/
//------------------------------------------------------------------------------
// verifyTransaction
// - Will the separate data fields of 'infile' and check if they are valid. If
//   at any anytime data does not pass a test, a message stating the error will
//   be displayed and the rest of the line will be discarded.
//   If all tests pass, reference parameters will contain values (depending on
//   transaction type).
//------------------------------------------------------------------------------
bool Store::verifyTransaction(ifstream& infile, int& refCID, char& refMedia,
                              Item*& refItem)
{
   TransFactory t_tFactory;
   MovieFactory t_mFactory;

   Item* temp = NULL;   //result of 'createMovie
   int h_gen;           //hashed genre value
   char type;           //transaction type
   int cID = -1;        //customer ID from file
   char media = '\n';   //media from file
   char genre;          //genre from file

   infile.unget();  //rewind read ptr to transType;

   //read in all data
   infile >> type;

   if (!t_tFactory.inFactory(type))
   {
      cout << "!-Transaction Type " << type << " Unknown\n" << endl;
      infile.ignore(S_LENGTH,'\n');
      return false;
   }

   infile.get();    //read blank space before customer ID;
   infile >> cID;

   //check if c_id is between 0 and C_LENGTH
   if (cID >= C_LENGTH || cID < 0)
   {
      cout << "!-Customer ID " << cID << " Outside Bounds of Array\n" << endl;
      infile.ignore(S_LENGTH,'\n');
      return false;
   }
   //check if cID represents a valid customer
   if (CustomerArray[cID] == NULL)
   {
      cout << "!-Customer ID " << cID << " Not Assigned\n" << endl;
      infile.ignore(S_LENGTH,'\n');
      return false;
   }
   //check if next char //if newline, transaction may be 'History
   //assign cID value to refCID
   refCID = cID;
   if (infile.peek() == '\n')
   {
      infile.get();  //get newline
      return true;
   }
   //read in the rest of the transaction data
   infile >> media >> genre;

   //check if media is a valid type
   if (media != MED_TYPE)
   {
      cout << "!-Media Type " << media << " Is Unknown\n" << endl;
      infile.ignore(S_LENGTH,'\n');
      return false;
   }
   //check if genre is valid
   h_gen = hashGenre(genre);

   if (TreeArray[h_gen] == NULL)
   {
      cout << "!-Genre " << genre << " Is Unknown\n" << endl;
      infile.ignore(S_LENGTH,'\n');
      return false;
   }

   infile.unget(); //rewind read pointer to genre
   temp = t_mFactory.createMovie(infile);
   refItem = TreeArray[h_gen]->retrieve(temp);
   delete temp;

   if (refItem == NULL)
   {
      cout << "! Movie Not Found In Collection\n" << endl;
      return false;
   }
   else
      infile.ignore(S_LENGTH,'\n');

   //assign values to ref values
   refCID = cID;
   refMedia = media;
   infile.clear();

   return true;
}
//------------------------------------------------------------------------------
// isValid [Customer ID]
// - Checks if customer id (param) is within the bounds of 'CustomerArray'. Will
//   then check if customer id has already been assigned to a customer (and
//   therefore already in CustomerArray). Will return true if both tests pass.
//   Will return false otherwise.
//------------------------------------------------------------------------------
bool Store::isValid(int c_cid) const
{
   //check if within bounds of CustomerArray
   if (c_cid >= C_LENGTH && c_cid < 0)
   {
      cout << " Customer ID: " << c_cid << " not in bounds of array\n" << endl;
      return false;
   }
   //check slot in CustomerArray has been assigned
   if (CustomerArray[c_cid] != NULL)
   {
      cout << "Customer ID: " << c_cid << " already assigned\n" << endl;
      return true;
   }
   return true;
}
//------------------------------------------------------------------------------
// hashGenre
// - Will hash the char parameter and return an interger value.  Result will be
//   modded by T_LENGTH (default: 26) to keep result within the bounds of array.
//------------------------------------------------------------------------------
int Store::hashGenre(char param)
{
   return (param - 'A') % T_LENGTH;
}
//------------------------------------------------------------------------------
// hashCmd
// - Will hash the char parameter and return an interger value.  Result will be
//   modded by M_LENGTH (default: 26) to keep result within the bounds of array.
//------------------------------------------------------------------------------
int Store::hashCmd(char param)
{
   return (param - 'A') % M_LENGTH;
}