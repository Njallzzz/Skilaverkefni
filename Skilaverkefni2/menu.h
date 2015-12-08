#ifndef MENU
#define MENU

#include <QDate>
#include <QString>
#include <vector>
#include <iostream>
#include <string>
#include <QTextStream>
#include "person.h"
#include "computer.h"

using namespace std;

int menu();             // Display main menu
void display(vector<Person>& list, vector<Computer> comps);
void displayPerson(vector<Person>& list);     // Display all people in list
void displayComputer(vector<Computer>& comps);// Display all computers in list
Person addPerson();                     // User menu to add a person
Computer addComputer();                 // User meno to add a computer
int deletePerson(vector<Person>& list); // User menu to get index of person to delete
Person SearchMenu();                    // Search User Menu
void Search( vector<Person> & list, Person p ); // Search algorithm
int sortList();                         // Sort menu
bool keepSorted();                      // Asks whether or not the changes should be permanent
Person modify( Person temp );           // Menu to alter a person already in the database

#endif // MENU
