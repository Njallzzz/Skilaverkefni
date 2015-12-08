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

enum action {
    DISPLAY,
    ADD,
    REMOVE,
    MODIFY,
    SEARCH
};

int menu();             // Display main menu
void display(vector<Person>& list, vector<Computer> comps);
void displayPerson(vector<Person>& list);     // Display all people in list
void displayComputer(vector<Computer>& comps);// Display all computers in list
int computersOrPeople( action text );                // User menu to want to check person or computer
Person addPerson();                     // User menu to add a person
Computer addComputer();                 // User meno to add a computer
int deletePerson(vector<Person>& list); // User menu to get index of person to delete
Person SearchPersonMenu();                    // Search Person User Menu
Computer SearchComputerMenu();                // Search Computer User Menu
void Search( vector<Person> & list, Person p );     // Search algorithm
void Search( vector<Computer> & list, Computer c ); // Search algorithm
int sortList();                         // Sort menu
bool keepSorted();                      // Asks whether or not the changes should be permanent
Person modify( Person temp );           // Menu to alter a person already in the database

#endif // MENU
