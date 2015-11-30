#ifndef MENU
#define MENU

#endif // MENU
#include <QDate>
#include <QString>
#include <vector>
#include <iostream>
#include "person.h"
#include <string>
#include <QTextStream>


using namespace std;
int menu();
void display(vector<Person>& list);
Person addPerson();
int deletePerson(vector<Person>& list);
int sortList();
bool keepSorted();
Person modify( Person temp );
