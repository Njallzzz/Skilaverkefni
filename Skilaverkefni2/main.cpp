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
    int sort;

    while(choice != 9)
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

                //Search(people, search);   // displays search results
                break;
            }

            case 7 : {                    //5. Sort the list

                    int sortChoice = computersOrPeople(SORT);
                    if(sortChoice ==1)
                    {
                    sort = sortPerson();
                    if(sort == 1)
                        db.readDatabase(people, NAME_ASC);
                    else if(sort == 2)
                        db.readDatabase(people, NAME_DESC);
                    else if(sort == 3)
                        db.readDatabase(people, BIRTH_ASC);
                    else if(sort == 4)
                        db.readDatabase(people, BIRTH_DESC);
                    else if(sort == 5)
                        db.readDatabase(people, DEATH_ASC);
                    else if(sort == 6)
                        db.readDatabase(people, DEATH_DESC);
                    else if(sort == 7)
                        db.readDatabase(people, GENDER_ASC);
                    else if(sort == 8)
                        db.readDatabase(people, GENDER_DESC);
                    displayPerson(people);

                }
                else if(sortChoice == 2)
                {
                    sort = sortComputer();
                    if(sort == 1)
                        db.readDatabase(comps, NAME_ASC);
                    else if(sort == 2)
                        db.readDatabase(comps, NAME_DESC);
                    else if(sort == 3)
                        db.readDatabase(comps, CREATION_ASC);
                    else if(sort == 4)
                        db.readDatabase(comps, CREATION_DESC);
                    else if(sort == 5)
                        db.readDatabase(people, TYPE_ASC);
                    else if(sort == 6)
                        db.readDatabase(people, TYPE_DESC);
                    else if(sort == 7)
                        db.readDatabase(people, CONSTRUCTED_ASC);
                    else if(sort == 8)
                        db.readDatabase(people, CONSTRUCTED_DESC);
                    displayComputer(comps);
                }

                break;
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
}}
