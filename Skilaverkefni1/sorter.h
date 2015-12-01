#ifndef SORTER
#define SORTER

#include <QDate>
#include <QString>
#include <vector>
#include "person.h"

using namespace std;

void sortByName(vector<Person> & list);
void nameSort(vector<Person> & list, int left, int right);

void sortByBirth(vector<Person> & list);
void birthSort(vector<Person> & list, int left, int right);

void sortByDeath(vector<Person> & list);
void deathSort(vector<Person> & list, int left, int right);

void genderSort(vector<Person> & list, int left, int right);

#endif // SORTER

