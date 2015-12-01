/**
 * @file AthleteDatabase.h
 * @author Kylie Nicholson
 * @date November 13, 2015
 * @class AthleteDatabase
 * This class creates a database using a BinarySearchTree to store
 * items of the Athlete class type. It inputs data for an Athlete object
 * and adds that Athlete to the tree. It searches for an Athlete object,
 * removing that Athlete object if it was found. Next, it displays the 
 * data using all three types of tree traversals, and then saves the 
 * data to a text file using a preorder traversal.
 */
#ifndef ATHLETEDATABASE_H
#include "BinarySearchTree.h"
#include "Athlete.h"
using namespace std;

class AthleteDatabase
{
private:
   /**
    * binary search tree to store Person data
    */
   BinarySearchTree<Athlete> AthleteDatabaseBST;

public:
   /**
    * Read in the text file to create a database of athletes
    */
   void readTextFile (void);
	
	/**
    * Create a new Athlete object.
    */
   void addNewAthlete (void);
	
	/**
    * Search for and Delete an Athlete object.
    */
   void deleteAthlete (Athlete&);


   /**
    * Displays database data using inorder,
    * preorder, and postorder traversals.
    */
   void displayData (void);

   /**
    * Saves the database to an output file using a preorder
    * traversal.
    */
   void saveDatabase (void);
};

#define ATHLETEDATABASE_H
#endif



