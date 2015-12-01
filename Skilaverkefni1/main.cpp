#include <QCoreApplication>
#include "xmlparser.h"
#include "person.h"
#include "sorter.cpp"
#include "menu.h"
#include <iostream>

// Debug
#include <QDebug>

using namespace std;

int main() {
    XMLParser database( "database.xml" );                       // Select database

    vector<Person> list;

    Person temp;
    /*
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

    temp.name = "Alan Turing";                                  // Example of how to modify a single entry in 'database.xml'
    temp.gender = 1;
    temp.birth = QDate::fromString( "23.06.1912", "dd.MM.yyyy" );
    temp.death = QDate::fromString( "07.06.1954", "dd.MM.yyyy" );
    database.ModifyEntry( 4, temp );


    temp.name = "John Doe";                                  // Example of how to modify a single entry in 'database.xml'
    temp.gender = 1;
    temp.birth = QDate::fromString( "01.01.2000", "dd.MM.yyyy" );
    temp.death = QDate::fromString( "20.12.2100", "dd.MM.yyyy" );
    database.ModifyEntry( 0, temp );
     */


    if( database.ReadDatabase( list ) )                         // Example of how to read from 'database.xml'
        cout << "Unable to read file 'database.xml'" << endl;

    int choice, sort, remove, index;
    Person add,search;

    while(choice != 7)
    {
        choice =menu();
        switch(choice){
            case 1 :
                display(list);
                break;

            case 2 :
                add = addPerson();
                database.AddEntry(add);
                break;

            case 3 :
                display(list);
                remove = deletePerson(list);
                if(remove != 0)
                {
                    database.RemoveEntry(remove-1);
                }
                break;

            case 4 :
                search = SearchMenu();
                Search(list, search);
                break;

            case 5 :
                sort = sortList();
                if(sort == 1)
                    sortByName(list);
                else if(sort == 2)
                    sortByBirth(list);
                else if(sort == 3)
                    sortByDeath(list);
                else if(sort == 4)
                    genderSort(list, 0, list.size() - 1);

                display(list);
                if(keepSorted())
                        database.WriteDatabase(list);
                break;

            case 6 :
                display(list);
                cout << "Select index of entry to modify: ";
                cin >> index;
                cout << endl;

                Person mod = modify( list[index-1] );
                database.ModifyEntry( index-1, mod );
                break;

        }
        database.ReadDatabase(list);
    }

    /*int choice = 0;
    while(choice != 8) {
        choice  = menu();
        if(choice == 1) {
            display(list);
        } else if(choice == 2) {
            Person add = addPerson();
            database.AddEntry(add);
        } else if(choice == 3) {
            display(list);
            int remove = deletePerson(list);
            if(remove != 0)
                 database.RemoveEntry(remove-1);
        } else if( choice == 4 ) {
            Person temp = SearchMenu();
            Search( list, temp );
        } else if(choice == 5) {
            int sort = sortList();
            if(sort == 1)
                sortByName(list);
            else if(sort == 2)
                sortByBirth(list);
            else if(sort == 3)
                sortByDeath(list);
            else if(sort == 4)
                genderSort(list, 0, list.size() - 1);

            display(list);



            if(keepSorted())
                database.WriteDatabase(list);
        }

        if( choice == 6 ){
            int index;

            display(list);
            cout << "Select index of entry to modify: ";
            cin >> index;
            cout << endl;

            Person mod = modify( list[index-1] );
            database.ModifyEntry( index-1, mod );
        }

        if( choice == 7 ){
            return 0;
        }

        database.ReadDatabase(list);
    }   */


        // Sample Code
        /*sorter.sortByDeath(list, 0, list.size() - 1);
        for(unsigned int x = 0; x < list.size(); x++) {
            qDebug() << "Name: " << list[x].name;
            if ( list[x].gender  == 1)
                qDebug() << "Gender: Male";
            else if( list[x].gender  == 2)
                qDebug() << "Gender: Female";
            qDebug() << "Birth Year: " << list[x].birth.toString("dd.MM.yyyy");

            qDebug() << "Death Year: " << list[x].death.toString("dd.MM.yyyy") << endl;
        }*/
    return 0;
}
