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
    Person add,search, mod;

    while(choice != 7)
    {
        choice =menu();
        switch(choice){
            case 1 :                //1. Display the list
                display(list);
                break;

            case 2 :                //2. Add a person to the list
                add = addPerson();
                database.AddEntry(add);
                break;

            case 3 :               //3. Remove a person to the list
                display(list);      //display the list
                remove = deletePerson(list);    //ask for index to be removed, returns 0 if no person is chosen
                if(remove != 0)
                {
                    database.RemoveEntry(remove-1);
                }
                break;

            case 4 :                    //4. Search List
                search = SearchMenu();  // get search parameters
                Search(list, search);   // displays search results
                break;

            case 5 :                    //5. Sort the list
                sort = sortList();      // asks the user how to sort the list
                if(sort == 1)
                    sortByName(list);   // sorts the list by name
                else if(sort == 2)
                    sortByBirth(list);  // sorts the list by birth date
                else if(sort == 3)
                    sortByDeath(list);  // sorts the list by death date
                else if(sort == 4)
                    genderSort(list, 0, list.size() - 1);   // sorts the list by gender

                display(list);
                if(keepSorted())                // asks the user if he/she wants to keep the list sorted
                        database.WriteDatabase(list);
                break;

            case 6 :                    //6. Modify the list
                display(list);
                cout << "Select index of entry to modify: ";
                cin >> index;
                cout << endl;

                mod = modify( list[index-1] );
                database.ModifyEntry( index-1, mod );
                break;

        }
        database.ReadDatabase(list);    // reads the database if it has changed
    }




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
