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

    vector<Person> & getPeople( bool all = false );         //retrieves "people" data from sql database file and inserts it into a vector
    vector<Computer> & getComputers( bool all = false );    //retrieves "computer" data from sql database file and inserts it into a vector

    void sortPerson( int index );
    void sortComputer( int index );

    int selectPerson( int index );

    void deletePerson( int index );
    void deleteComputer( int index );

    void peopleFilterName( QString name );          //To filter people by name
    void peopleFilterGender( QString gender );      //To filter people by gender
    void peopleFilterBirth( QDate date );           //To filter people by birth date
    void peopleFilterDeath( QDate date );           //To filter people by death date

    void ComputerFilterName( QString name );        //To filter computers by name
    void ComputerFilterType( QString type );        //To filter computers by type
    void ComputerFilterDate( QDate date );          //To filter computers by date built
    void ComputerFilterBuilt( int built );          //To filter computers by if built

    void addComputer( Computer comp );
    void modifyComputer( Computer comp );
    Computer getComputer( int index );

    void addPerson(Person p);
    void modifyPerson(Person p);
    Person getPerson(int index);

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
