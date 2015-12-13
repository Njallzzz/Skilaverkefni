#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include <QString>
#include "person.h"
#include "computer.h"
#include "sqlitehandler.h"

using namespace std;

class Interface {
public:
    Interface();
    int Initialize();

    int getPeople( vector<Person> & p, bool all = false );
    int getComputers( vector<Computer> & c, bool all = false );

    void peopleFilterName( QString name );
    void peopleFilterGender( QString gender );
    void peopleFilterBirth( QDate date );
    void peopleFilterDeath( QDate date );

    void ComputerFilterName( QString name );
    void ComputerFilterType( QString type );
    void ComputerFilterDate( QDate date );
    void ComputerFilterBuilt( int built );

private:
    vector<Person> Filter( vector<Person> & p );
    vector<Computer> Filter( vector<Computer> & c );

    sorting sortComputers;
    sorting sortPeople;

    SQLITEHandler db;

    Person personSearch;
    Computer computerSearch;
};

#endif // INTERFACE_H
