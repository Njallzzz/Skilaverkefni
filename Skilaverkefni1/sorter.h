#ifndef SORTER
#define SORTER

#include "vector";

class Sorter{
public:
    Sorter();
    Sorter(vector<Person> & theList);
    sortByName(vector<Person> & list, int left, int right);
    sortByBirth(vector<Person> & list, int left, int right);
    sortByDeath(vector<Person> & list, int left, int right);
private:
    vector<Person> list;
}

#endif // SORTER

