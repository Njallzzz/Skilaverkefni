#include <QCoreApplication>
#include <QDebug>
#include "xmlparser.h"
#include "person.h"
#include <iostream>
#include <string>

using namespace std;
int menu();


int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    XMLParser database( "database.xml" );                       // Select database

    vector<Person> list;

    Person temp;

    temp.name = "Grace Hopper";
    temp.gender = 2;
    temp.birth = QDate::fromString( "09.12.1906", "dd.MM.yyyy" );
    temp.death = QDate::fromString( "01.01.1992", "dd.MM.yyyy" );
    list.push_back(temp);

    temp.name = "Tim Berners-Lee";
    temp.gender = 1;
    temp.birth = QDate::fromString( "08.06.1955", "dd.MM.yyyy" );
    temp.death = QDate();                                       // Empty Value for death = still alive
    list.push_back(temp);

    temp.name = "Charles Babbage";
    temp.gender = 1;
    temp.birth = QDate::fromString( "26.12.1791", "dd.MM.yyyy" );
    temp.death = QDate::fromString( "18.10.1871", "dd.MM.yyyy" );
    list.push_back(temp);

    temp.name = "Ada Lovelace";
    temp.gender = 2;
    temp.birth = QDate::fromString( "10.12.1815", "dd.MM.yyyy" );
    temp.death = QDate::fromString( "27.11.1852", "dd.MM.yyyy" );
    list.push_back(temp);

    database.WriteDatabase( list );                       // Example of how to write everything to 'database.xml'

    temp.name = "Alan Turing";                                  // Example of how to write single entry into 'database.xml'
    temp.gender = 1;
    temp.birth = QDate::fromString( "23.06.1912", "dd.MM.yyyy" );
    temp.death = QDate::fromString( "07.06.1954", "dd.MM.yyyy" );
    database.AddEntry( temp );

    temp.name = "Alan Turing (Modified)";                                  // Example of how to modify single entry into 'database.xml'
    temp.gender = 0;
    temp.birth = QDate::fromString( "23.06.1912", "dd.MM.yyyy" );
    temp.death = QDate::fromString( "07.06.1954", "dd.MM.yyyy" );
    database.ModifyEntry( 4, temp );

    temp.name = "Jonh Doe";                                  // Example of how to modify single entry into 'database.xml'
    temp.gender = 0;
    temp.birth = QDate::fromString( "01.01.2000", "dd.MM.yyyy" );
    temp.death = QDate::fromString( "20.12.2100", "dd.MM.yyyy" );
    database.ModifyEntry( 0, temp );

    if( database.ReadDatabase( list ) )                         // Example of how to read from 'database.xml'
        qDebug() << "Unable to read file 'database.xml'" << endl;

    int choice = menu();

    if(choice == 1)
    {
        for(unsigned int x = 0; x < list.size(); x++) {
            qDebug() << "Name: " << list[x].name;
            if ( list[x].gender  == 1)
                qDebug() << "Gender: Male";
            else if( list[x].gender  == 2)
                qDebug() << "Gender: Female";
            qDebug() << "Birth Year: " << list[x].birth.toString("dd.MM.yyyy");

            qDebug() << "Death Year: " << list[x].death.toString("dd.MM.yyyy") << endl;
        }
    }

    database.WriteDatabase( list );
    if( database.RemoveEntry( "Ada Lovelace" ) )                     // Example of how to remove every person with name: 'Ada Lovelace'
        qDebug() << "Unable to delete 'Ada Lovelace' from database" << endl;

    if( database.RemoveEntry( 0 ) )                                 // Example of how to remove a single entry by index
        qDebug() << "Unable to delete entry 1 from database" << endl;

    qDebug() << "End of Program";
    return a.exec();
}

int menu()
{   int x;

    qDebug() << "<<<<<<<<FAMOUS COMPUTER SCIENTISTS>>>>>>>>" << endl << endl;
    qDebug() << "Choose an option: " << endl;
    qDebug() << "   1. Display list" << endl;
    qDebug() << "   2. Add an entry" << endl;
    qDebug() << "   3. Remove an entry" << endl;
    qDebug() << "   4. Search list" << endl;
    qDebug() << "   5. Quit" << endl;

    cin >> x;
    return x;
}
