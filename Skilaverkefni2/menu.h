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

int menu();                             // Display main menu
void displayPerson(vector<Person>& list);     // Display all people in list
void displayComputer(vector<Computer>& comps);
Person addPerson();                     // User menu to create person
int deletePerson(vector<Person>& list); // User menu to get index of person to delete
Person SearchMenu();                    // Search User Menu
void Search( vector<Person> & list, Person p ); // Search algorithm
int sortList();                         // Sort menu
bool keepSorted();                      // Asks whether or not the changes should be permanent
Person modify( Person temp );           // Menu to alter a person already in the database

#endif // MENU
