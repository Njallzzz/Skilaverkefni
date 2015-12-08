#include <QString>
#include <vector>
#include <QTextStream>
#include <iostream>
#include "person.h"
#include "menu.h"
#include "sqlitehandler.h"

using namespace std;

int main() {
    vector<Computer> comps;
    vector<Person> people;

    SQLITEHandler db("Database.db");
    if( db.connect() ) {
        cout << "Unable to connect to database" << endl;
        return 1;
    }

    if( db.readDatabase( comps, NAME_ASC ) ) {
        cout << "Unable to read from database" << endl;
        return 2;
    }
    if( db.readDatabase( people, NAME_ASC ) ) {
        cout << "Unable to read from database" << endl;
        return 3;
    }

    /*for( unsigned int x = 0; x < comps.size(); x++ ) {
        cout << x+1 << ".\t" << comps[x] << endl;
    }

    for( unsigned int x = 0; x < people.size(); x++ ) {
        cout << x+1 << ".\t" << people[x] << endl;
    }*/

    int choice = 0;

    while(choice != 7)
    {
        choice = menu();
        switch(choice) {
            case 1 : {                //1. Display the list
                display(people, comps);
                break;
            }
            case 2 : {                //2. Add a person to the list
                int addChoice = computersOrPeople( ADD );
                if(addChoice == 1) {
                    db.addEntry( addPerson() );
                } else if(addChoice == 2) {
                    db.addEntry( addComputer() );
                }
                break;
            }

            /*case 3 :               //3. Remove a person to the list
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
                break;*/

            case 4 : {                    //4. Search List
                int searchChoice = computersOrPeople( SEARCH );
                if( searchChoice == 1 && people.size() == 0 ) {  // Check if the database is empty
                    cout << "There are no people to search" << endl << endl;
                    break;
                } else if( searchChoice == 2 && comps.size() == 0 ) {       // Check if the database is empty
                    cout << "There are no computers to search" << endl << endl;
                    break;
                }
                if( searchChoice == 1 ) {
                    Person search = SearchPersonMenu();  // get search parameters
                    Search(people, search);              // displays search results
                } else if( searchChoice == 2 ) {
                    Computer search = SearchComputerMenu();  // get search parameters
                    Search(comps, search);              // displays search results
                }

                //Search(people, search);   // displays search results
                break;
            }
            /*
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
                QString indexString;
                while( !( index = indexString.toInt() ) ) {
                    cout << "Select index of entry to modify: ";
                    indexString = in.readLine();
                    if( !indexString.toInt() )
                        cout << "Invalid entry!" << endl;
                }
                cout << endl;

                mod = modify( list[index-1] );
                database.ModifyEntry( index-1, mod );
                break;

        }
        */

        }

        if( db.readDatabase( comps, NAME_ASC ) ) {
            cout << "Unable to read from database" << endl;
            return 2;
        }
        if( db.readDatabase( people, NAME_ASC ) ) {
            cout << "Unable to read from database" << endl;
            return 3;
        }
    }
    db.disconnect();

    return 0;
}
