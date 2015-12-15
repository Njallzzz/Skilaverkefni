#ifndef INTERFACE_H
#define INTERFACE_H

#include <vector>
#include <QString>
#include "models/person.h"
#include "models/computer.h"
#include "repositories/sqlitehandler.h"

using namespace std;

class Interface {
public:
    Interface();
    ~Interface();
    int Initialize();

    vector<Person> & getPeople( bool all = false );
    vector<Computer> & getComputers( bool all = false );

    void sortPerson( int index );
    void sortComputer( int index );

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
    void addComputer( Computer comp );
    void modifyComputer( Computer comp );
    Computer getComputer( int index );
    //void setComputer( int index );


    void addPerson(Person p);
    void modifyPerson(Person p);

    Person getPerson(int index);

    void addRelation(Person p, Computer c);
    void removeRelation(Person p, Computer c);

    Person getPersonById(int id);

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
