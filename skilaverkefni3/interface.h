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
    ~Interface();
    int Initialize();

    vector<Person> & getPeople( bool all = false );
    vector<Computer> & getComputers( bool all = false );

    int selectPerson( int index );

    void deletePerson( int index );
    void deleteComputer( int index );

    void peopleFilterName( QString name );
    void peopleFilterGender( QString gender );
    void peopleFilterBirth( QDate date );
    void peopleFilterDeath( QDate date );

    void ComputerFilterName( QString name );
    void ComputerFilterType( QString type );
    void ComputerFilterDate( QDate date );
    void ComputerFilterBuilt( int built );

private:
    vector<Person> p;
    vector<Computer> c;

    vector<Person> Filter( vector<Person> & people );
    vector<Computer> Filter( vector<Computer> & computers );

    sorting sortComputers;
    sorting sortPeople;

    SQLITEHandler db;

    Person personSearch;
    Computer computerSearch;
    int SelectedPerson;
};

#endif // INTERFACE_H
