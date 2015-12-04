#ifndef SQLITEHANDLER_H
#define SQLITEHANDLER_H

#include <QString>
#include <QtSql>
#include <QDate>
#include "computer.h"
#include <vector>
#include <iostream>

using namespace std;

// Debug
#include <QDebug>

enum sorting {
    NAME_ASC,
    NAME_DESC,
    CREATION_ASC,
    CREATION_DESC,
    TYPE_ASC,
    TYPE_DESC,
    CONSTRUCTED_ASC,
    CONSTRUCTED_DESC
};

class SQLITEHandler {
public:
    SQLITEHandler( QString filename );
    ~SQLITEHandler();
    int connect();
    int disconnect();
    int SetDatabase( QString filename );

    //int readDatabase( vector<Person> & people );
    int readDatabase( vector<Computer> & computers, sorting s1, sorting s2 = NAME_ASC );

    // Computer table related functions
    int addEntry( Computer comp );
    int removeEntry( Computer comp );
    int modifyEntry( Computer comp );

    // People table related functions
    //int addEntry( Person p );
    //int removeEntry( Person p );
    //int modifyEntry( Person p );

    // Relation table  related functions
    // int addRelation( Person p, Computer comp );
    // ?

private:
    QString file;
    bool status;
    QSqlDatabase db;
    QSqlQuery q;
};

#endif // SQLITEHANDLER_H
