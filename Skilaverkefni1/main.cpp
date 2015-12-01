#include <QCoreApplication>
#include "xmlparser.h"
#include "person.h"
#include "sorter.h"
#include "menu.h"
#include <iostream>

using namespace std;

int main() {
    vector<Person> list;

    XMLParser database( "database.xml" );                       // Select database
    if( database.ReadDatabase( list ) )                         // Reads all entries from 'database.xml'
        cout << "Unable to read file 'database.xml'" << endl;

    int choice, sort, remove, index;
    Person add, search, mod;

    while(choice != 7)
    {
        choice = menu();
        switch(choice){
            case 1 :                //1. Display the list
                display(list);
                break;

            case 2 :                //2. Add a person to the list
                add = addPerson();
                database.AddEntry(add);
                break;

            case 3 :               //3. Remove a person to the list
                if( list.size() == 0 ) {        // Check if the database is empty
                    cout << "The database is empty" << endl << endl;
                    break;
                }
                display(list);      //display the list
                remove = deletePerson(list);    //ask for index to be removed, returns 0 if no person is chosen
                if(remove != 0)
                {
                    database.RemoveEntry(remove-1);
                }
                break;

            case 4 :                    //4. Search List
                if( list.size() == 0 ) {        // Check if the database is empty
                    cout << "The database is empty" << endl << endl;
                    break;
                }
                search = SearchMenu();  // get search parameters
                Search(list, search);   // displays search results
                break;

            case 5 :                    //5. Sort the list
                if( list.size() == 0 ) {        // Check if the database is empty
                    cout << "The database is empty" << endl << endl;
                    break;
                }
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
                if( list.size() == 0 ) {        // Check if the database is empty
                    cout << "The database is empty" << endl << endl;
                    break;
                }
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

    return 0;
}
