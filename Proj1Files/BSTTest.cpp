/**
 * @file BSTTest.cpp
 * @author Professor Gregory
 * @date January 2, 2015
 * This program demonstrates the use of a BinarySearchTree to store
 * items of the Student class type. It creates some Student objects, 
 * adds them to a binary search tree, inputs data for a Student object
 * and adds that student to the tree. It removes a Student object from
 * the tree. Next, it displays the data stored in the tree using all 
 * three types of tree traversals, and then saves the data to a text 
 * file using a preorder traversal.
 */
#include "StudentDatabase.h"
#include <cstdlib>
#include <iostream>
using namespace std;

void explanation(void);


int main (void)
{
    explanation();
    
    StudentDatabase studentDB; // database to store Student objects
    studentDB.createDatabase();
    studentDB.displayData();
    studentDB.saveDatabase();

    return EXIT_SUCCESS;
}


/**
 * Provides an explanation of the program for the user
 */
void explanation(void)
{
    cout << "This program demonstrates the use of a binary search tree" << endl;
    cout << "to store items of the Student class type to help CSI 250" << endl;
    cout << "students understand how to use the binary search tree classes" << endl;
    cout << "provided by the textbook. The program creates eight arbitrary" << endl;
    cout << "pre-defined Student objects, which consist of name, id," << endl;
    cout << "and phone, and adds them to a binary search tree. It then" << endl;
    cout << "inputs data for a new Student object from the user, giving" << endl;
    cout << "the user specific instructions about data entry. The program" << endl;
    cout << "adds the entered Student object to the binary search tree." << endl << endl;
    cout << "The program searches for a specific student in the tree, and" << endl;
    cout << "deletes that student, if found. The program then displays the" << endl;
    cout << "data in the binary search tree using an inorder traversal," << endl;
    cout << "which results in an alphabetical listing of Student objects" << endl;
    cout << "in the tree. Next, the program displays the contents of the" << endl;
    cout << "tree using a preorder and a postorder traversal, so the order" << endl;
    cout << "of the Student objects appears random. Before exiting, the"<< endl;
    cout << "program saves the data for each Student object in the tree" << endl;
    cout << "to a text file using a preorder traversal." << endl  << endl;
}

