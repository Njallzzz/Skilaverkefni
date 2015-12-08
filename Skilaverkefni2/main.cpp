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

    sorting sortType = NAME_ASC;
    if( db.readDatabase( comps, sortType ) ) {
        cout << "Unable to read from database" << endl;
        return 2;
    }
    if( db.readDatabase( people, sortType ) ) {
        cout << "Unable to read from database" << endl;
        return 3;
    }






   db.deleteRelation(people[1],comps[1]);








    int choice = 0;

    while(choice != 9) {
        choice = menu();
        switch(choice) {
            case 1 : {                //1. Display the list
                int menuChoice = computersOrPeople( DISPLAY );
                if ( menuChoice == 1 )
                    display(people, comps);
                else if( menuChoice == 2 )
                    displayPerson( people );
                else if( menuChoice == 3 )
                    displayComputer( comps );
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
            case 3 : {
                vector<int> relation = addRelation(people, comps);
                db.addRelation(people[relation[0]-1], comps[relation[1]-1]);
                break;
            }

            case 4 : {              //3. Remove a person to the list
                int menuChoice = computersOrPeople( REMOVE );
                if( menuChoice == 1 ) {
                    if( people.size() == 0 ) {
                        cout << "The database is empty" << endl << endl;
                        break;
                    }
                    displayPerson( people );      //display the list
                    int remove = deletePerson( people );    //ask for index to be removed, returns 0 if no person is chosen
                    if(remove != 0)
                        db.removeEntry( people[remove - 1] );
                } else if( menuChoice == 2 ) {
                    if( comps.size() == 0 ) {
                        cout << "The database is empty" << endl << endl;
                        break;
                    }
                    displayComputer( comps );      //display the list
                    int remove = deleteComputer( comps );    //ask for index to be removed, returns 0 if no person is chosen
                    if(remove != 0)
                        db.removeEntry( comps[remove - 1] );
                }
                break;
            }
            case 6 : {                    //4. Search List
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
                break;
            }

            case 7 : {                    //5. Sort the list
                int sortChoice = computersOrPeople(SORT_MENU);
                int sortAction;
                if(sortChoice == 1) {
                    sortAction = sortPerson();
                    if(sortAction == 1)
                        sortType = NAME_ASC;
                    else if(sortAction == 2)
                        sortType = NAME_DESC;
                    else if(sortAction == 3)
                        sortType = BIRTH_ASC;
                    else if(sortAction == 4)
                        sortType = BIRTH_DESC;
                    else if(sortAction == 5)
                        sortType = DEATH_ASC;
                    else if(sortAction == 6)
                        sortType = DEATH_DESC;
                    else if(sortAction == 7)
                        sortType = GENDER_ASC;
                    else if(sortAction == 8)
                        sortType = GENDER_DESC;

                    if( db.readDatabase( people, sortType ) ) {
                        cout << "Unable to read from database" << endl;
                        return 3;
                    }
                    displayPerson( people );
                } else if(sortChoice == 2) {
                    sortAction = sortComputer();
                    if(sortAction == 1)
                        sortType = NAME_ASC;
                    else if(sortAction == 2)
                        sortType = NAME_DESC;
                    else if(sortAction == 3)
                        sortType = CREATION_ASC;
                    else if(sortAction == 4)
                        sortType = CREATION_DESC;
                    else if(sortAction == 5)
                        sortType = TYPE_ASC;
                    else if(sortAction == 6)
                        sortType = TYPE_DESC;
                    else if(sortAction == 7)
                        sortType = CONSTRUCTED_ASC;
                    else if(sortAction == 8)
                        sortType = CONSTRUCTED_DESC;

                    if( db.readDatabase( comps, sortType ) ) {
                        cout << "Unable to read from database" << endl;
                        return 2;
                    }
                    displayComputer( comps );
                }

                break;
            }
            /*
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

        if( db.readDatabase( comps, sortType ) ) {
            cout << "Unable to read from database" << endl;
            return 2;
        }
        if( db.readDatabase( people, sortType ) ) {
            cout << "Unable to read from database" << endl;
            return 3;
        }
    }
    db.disconnect();

    return 0;
}
