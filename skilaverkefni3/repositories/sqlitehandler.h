#ifndef SQLITEHANDLER_H
#define SQLITEHANDLER_H

#include <QString>
#include <QtSql>
#include <QDate>
#include "models/computer.h"
#include "models/person.h"
#include <vector>

using namespace std;

enum sorting {      // Sorting type
    NAME_ASC,
    NAME_DESC,
    CREATION_ASC,
    CREATION_DESC,
    TYPE_ASC,
    TYPE_DESC,
    CONSTRUCTED_ASC,
    CONSTRUCTED_DESC,
    GENDER_ASC,
    GENDER_DESC,
    BIRTH_ASC,
    BIRTH_DESC,
    DEATH_ASC,
    DEATH_DESC
};

class SQLITEHandler {       // Database handler
public:
    //Constructors
    SQLITEHandler();
    SQLITEHandler( QString filename );
    ~SQLITEHandler();

    // Connection related functions
    int connect();
    int disconnect();
    int SetDatabase( QString filename );

    // Reads entire database into variables
    int readDatabase( vector<Person> & people, sorting s1 );
    int readDatabase( vector<Computer> & computers, sorting s1 );

    // Computer table related functions
    int addEntry( Computer c );
    int removeEntry( Computer c );
    int modifyEntry( Computer c );

    // People table related functions
    int addEntry( Person p );
    int removeEntry( Person p );
    int modifyEntry( Person p );

    // Relation table  related functions
    int addRelation( Person p, Computer c );
    int deleteRelation( Person p, Computer c );

    Person getPerson(int id);

private:
    QString file;       // Filename
    bool status;        // Whether connected or not
    QSqlDatabase db;    // Database handler
    QSqlQuery q;        // Query handler
};

#endif // SQLITEHANDLER_H
