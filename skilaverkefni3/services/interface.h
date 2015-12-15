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
    Interface();            //Sets all search and sort options to default
    ~Interface();
    int Initialize();       //Check sql database connection

    vector<Person> & getPeople( bool all = false );         //retrieves "people" data from sql database file and inserts it into a vector
    vector<Computer> & getComputers( bool all = false );    //retrieves "computer" data from sql database file and inserts it into a vector

    void sortPerson( int index );                   //To sort people list
    void sortComputer( int index );                 //To sort computer list

    int selectPerson( int index );                  //Checks id

    void deletePerson( int index );                 //Deletes person from sql database based on selected index
    void deleteComputer( int index );               //Deletes computer from sql database based on selected index

    void peopleFilterName( QString name );          //To filter people by name
    void peopleFilterGender( QString gender );      //To filter people by gender
    void peopleFilterBirth( QDate date );           //To filter people by birth date
    void peopleFilterDeath( QDate date );           //To filter people by death date

    void ComputerFilterName( QString name );        //To filter computers by name
    void ComputerFilterType( QString type );        //To filter computers by type
    void ComputerFilterDate( QDate date );          //To filter computers by date built
    void ComputerFilterBuilt( int built );          //To filter computers by if built

    void addComputer( Computer comp );              //Adds computer to the sql database
    void modifyComputer( Computer comp );           //Modifies computer in the sql database
    Computer getComputer( int index );              //returns computer from computer vector based on selected index

    void addPerson(Person p);                       //Adds person to the sql database
    void modifyPerson(Person p);                    //Modifies person in the sql database
    Person getPerson(int index);                    //returns person from person vector based on selected index

    Person getPersonById(int id);
    void removeRelation(Person p, Computer c);
    void addRelation(Person p, Computer c);

private:
    vector<Person> p;       //Person vector, data on persons is moved from the sql database into this vector
    vector<Computer> c;     //Computer vector, data on computers is moved from the sql database into this vector

    vector<Person> Filter( vector<Person> & people );
    vector<Computer> Filter( vector<Computer> & computers );

    sorting sortComputers;      //the sorting option for computers is kept in this varible
    sorting sortPeople;         //the sorting option for people is kept in this varible

    SQLITEHandler db;           //Used to interact with the SQLITEHandler class

    Person personSearch;        //the searching options for persons are kept in this varable
    Computer computerSearch;    //the searching options for computers are kept in this varable
    int SelectedPerson;         //Checks id
};

#endif // INTERFACE_H
