#ifndef SORTER
#define SORTER

#include <vector>
#include "person.h"
#include <QDate>
#include <QString>

using namespace std;

class Sorter{
public:
    Sorter();
    Sorter(vector<Person> & theList);
    void sortByName(vector<Person> & list, int left, int right);
    void sortByBirth(vector<Person> & list, int left, int right);
    void sortByDeath(vector<Person> & list, int left, int right);
private:
    vector<Person> list;
};

#endif // SORTER

