#ifndef SORTER
#define SORTER

#include <QDate>
#include <QString>
#include <vector>
#include "person.h"

using namespace std;

void sortByName(vector<Person> & list);     //Sort a list by name
void nameSort(vector<Person> & list, int left, int right);      //Recursive algorithm that sorts a list by name

void sortByBirth(vector<Person> & list);    //Sort a list by Birth date
void birthSort(vector<Person> & list, int left, int right);     //Recursive algorithm that sorts a list by Birthday

void sortByDeath(vector<Person> & list);    //Sort a list by death date
void deathSort(vector<Person> & list, int left, int right);     //Recursive algorithm that sorts a list by deathdate

void genderSort(vector<Person> & list, int left, int right);    //Sort a list by gender

#endif // SORTER

