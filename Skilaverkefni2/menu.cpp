#include "menu.h"

int menu() {
    char x;
    cout << "Choose an option" << endl;
    cout << "   1. Display list" << endl;
    cout << "   2. Add entry to list" << endl;
    cout << "   3. Add a relation" << endl;
    cout << "   4. Remove entry from list" << endl;
    cout << "   5. Remove relation" << endl;
    cout << "   6. Search list" << endl;
    cout << "   7. Sort list" << endl;
    cout << "   8. Modify list entry" << endl;
    cout << "   9. Quit" << endl;

    do{
        cout << "Your choice: ";
        cin >> x;
        if(x < 49 || x > 58)                //makes sure input is correct
            cout << "Not a valid option!" << endl;
    } while(x < 49 || x > 58);      //do while loop runs while input is not correct
    cout << endl;

    int y = x - 48;
    return y;
}

void display(vector<Person>& list, vector<Computer> comps) {
    cout << "\tName\t\t\t\tGender\tBirth\t\tDeath\t\tComputers" << endl;
    cout << "--------------------------------------------------------------------------------------------" << endl;

    for(unsigned int x = 0; x < list.size(); x++) {
        cout << x+1 << ".\t" << list[x];
        for(int y = 0; y < list[x].getSize(); y++) {
            int id = 0;
            for(unsigned int z = 0; z < comps.size(); z++) {
                if( comps[z].getId() == list[x].getComputer(y) )
                    id = z;
            }
            cout << "\t" << comps[ id ].getName().toUtf8().constData() << endl;
            if( (list[x].getSize() - 1) != y )
                cout << "\t\t\t\t\t\t\t\t\t";
        }
        if( list[x].getSize() == 0 )
            cout << endl;
    }

    /*int choice = computersOrPeople(DISPLAY);

    if(choice == 1)
        displayPerson(list);
    else if(choice == 2)
        displayComputer(comps);*/
}
void displayPerson(vector<Person>& list) {

    cout << "\tName\t\t\t\tGender\tBirth\t\tDeath" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;

    for(unsigned int x=0; x < list.size(); x++)
    {
        cout << x+1 << ".\t" << list[x] << endl;
    }
}


void displayComputer(vector<Computer>& comps)
{
    cout << "\tName\t\t\tCreated\t\tType\t\t\tBuilt" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;
    for(unsigned int x =0; x < comps.size();x++)
    {
        cout << x+1 << ".\t" << comps[x] << endl;
    }
}

int computersOrPeople( action text ) {
    QTextStream in(stdin);
    QString input;
    while( input != "1" && input != "2" ) {
        if( text == DISPLAY ) {
            cout << "1. Display people" << endl;
            cout << "2. Display computers" << endl;
        } else if( text == ADD ) {
            cout << "1. Add a person to the list" << endl;
            cout << "2. Add a computer to the list" << endl;
        } else if( text == REMOVE ) {
            cout << "1. Remove a person from the list" << endl;
            cout << "2. Remove a computer from the list" << endl;
        } else if( text == MODIFY ) {
            cout << "1. Modify a person in the list" << endl;
            cout << "2. Modify a computer in the list" << endl;
        } else if( text == SEARCH ) {
            cout << "1. Search for a person in the list" << endl;
            cout << "2. Search for a computer in the list" << endl;
        } else if( text == SORT ) {
            cout << "1. Sort the list of people" << endl;
            cout << "2. Sort the list of computers" << endl;
        }


        cout << "Your choice: ";
        input = in.readLine();
        if( input != "1" && input != "2" )
            cout << "Invalid input!" << endl;
    }
    return input.toInt();
}

Person addPerson() {
    Person temp;
    cout << "Add a person to the list" << endl;
    cin >> temp;
    return temp;
}

Computer addComputer()
{
    Computer temp;
    cout << "Add a computer to the list" << endl;
    cin >> temp;
    return temp;
}


int deletePerson(vector<Person>& list) {
    int x = 0;
    char choice = 0;
    QString index;
    QTextStream in(stdin);

    if( list.size() == 0 ) {
        cout << "The database is empty" << endl << endl;
        return 0;
    }
    while( x < 1 || x > int(list.size()) ) {
        cout << "Select a person to delete(input the number displayed before the name): ";
        index = in.readLine();
        x = index.toInt();
        if( x < 1 || x > int(list.size()) )
            cout << "Please enter a valid index" << endl;
    }
    while( choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N' ) {
        cout << "Are you sure you want to delete '" << list[x-1].getName().toUtf8().constData() << "' from the list(y/n)?: ";
        cin >> choice;
    }
    cout << endl;
    if(choice == 'y'|| choice == 'Y' )
       return x;

    return 0;
}

Person SearchPersonMenu() {       // Get search paramters from user
    Person temp;    char key = 0;   QTextStream in(stdin);
    temp.setName("");
    temp.setGender(0);
    while( key != '5' ) {           // while looping while inserting search parameters
        cout << "Please specify search parameters" << endl;
        cout << "\t1. Search by name(";
        if( temp.getName() == "" )               // If wildcard
            cout << "any)" << endl;
        else                                // if user specified
            cout << temp.getName().toUtf8().constData() << ")" << endl;     // Write current name parameters

        cout << "\t2. Search by gender(";
        if( temp.getGender() == 0 )              // If wildcard
            cout << "any)" << endl;
        else if( temp.getGender() == 1 )         // if user specified
            cout << "male)" << endl;
        else if( temp.getGender() == 2 )         // if user specified
            cout << "female)" << endl;

        cout << "\t3. Search by birth(";
        if( !temp.getBirth().isValid() )         // If wildcard
            cout << "any)" << endl;
        else                                // if user specified
            cout << temp.getBirth().toString("d.M.yyyy").toUtf8().constData() << ")" << endl;  // Write current birth parameters

        cout << "\t4. Search by death(";
        if( !temp.getDeath().isValid() )         // If wildcard
            cout << "any)" << endl;
        else                                // if user specified
            cout << temp.getDeath().toString("d.M.yyyy").toUtf8().constData() << ")" << endl;  // Write current death parameters
        cout << "\t5. Search" << endl;

        cout << "Your choice: ";
        cin >> key;                 // Get user input for next action, 1: name parameter, 2: gender parameter, 3: birth parameter, 4: death parameter and 5: Search
        cin.ignore();

        if( key == '1' ) {          // Set user name search parameter
            cout << "Insert name to search for: ";
            temp.setName( in.readLine() );
        } else if( key == '2' ) {   // Set user gender search parameter
            temp.setGender( -1 );
            while( (temp.getGender() < 0) || (temp.getGender() > 2) ) {
                QString gender;
                cout << "Insert gender to search for(any/male/female): ";
                gender = in.readLine();
                if( gender == "any" || gender == "Any" )
                    temp.setGender( 0 );
                else if( gender == "male" || gender == "Male" )
                    temp.setGender( 1 );
                else if( gender == "female" || gender == "Female" )
                    temp.setGender( 2 );
                else
                    cout << "Please enter a valid gender" << endl;
            }
        } else if( key == '3' ) {   // Set user birth search parameter
            QString birthstring = "";
            temp.setBirth( QDate() );   // Set empty date (Also used as wildcard)
            while( birthstring != "0" && !temp.getBirth().isValid() ) {
                cout << "Insert birth date(dd.mm.yyyy, 0 for any): ";
                birthstring = in.readLine();
                if( birthstring != "0" )
                    temp.setBirth( QDate::fromString( birthstring, "dd.MM.yyyy" ) );
            }
        } else if( key == '4' ) {   // Set user death search parameter
            QString deathstring = "";
            temp.setDeath( QDate() );   // Set empty date (Also used as wildcard)
            while( deathstring != "0" && !temp.getDeath().isValid() ) {
                cout << "Insert death date(dd.mm.yyyy, 0 for any): ";
                deathstring = in.readLine();
                if( deathstring != "0" )
                    temp.setDeath( QDate::fromString( deathstring, "dd.MM.yyyy" ) );
            }
        }
    }
    cout << endl;
    return temp;        // Returns template for person to search for
}

Computer SearchComputerMenu() {
    Computer temp;    char key = 0;   QTextStream in(stdin);
    temp.setName("");
    temp.setType("");
    temp.setWasBuilt(2);
    while( key != '5' ) {           // while looping while inserting search parameters
        cout << "Please specify search parameters" << endl;
        cout << "\t1. Search by name(";
        if( temp.getName() == "" )               // If wildcard
            cout << "any)" << endl;
        else                                // if user specified
            cout << temp.getName().toUtf8().constData() << ")" << endl;     // Write current name parameters

        cout << "\t2. Search by type(";
        if( temp.getType() == "" )              // If wildcard
            cout << "any)" << endl;
        else
            cout << temp.getType().toUtf8().constData() << ")" << endl;     // Write current type parameters

        cout << "\t3. Search by built(";
        if( temp.getWasBuilt() == 2 )         // If wildcard
            cout << "any)" << endl;
        else if( temp.getWasBuilt() == 0 )                               // if user specified
            cout << "not built)" << endl;  // Write current birth parameters
        else if( temp.getWasBuilt() == 1 )
            cout << "built)" << endl;  // Write current birth parameters

        cout << "\t4. Search by year(";
        if( temp.getYear() == "" )         // If wildcard
            cout << "any)" << endl;
        else                                // if user specified
            cout << temp.getYear().toUtf8().constData() << ")" << endl;  // Write current death parameters
        cout << "\t5. Search" << endl;

        cout << "Your choice: ";
        cin >> key;                 // Get user input for next action, 1: name parameter, 2: gender parameter, 3: birth parameter, 4: death parameter and 5: Search
        cin.ignore();

        if( key == '1' ) {          // Set user name search parameter
            cout << "Insert name to search for: ";
            temp.setName( in.readLine() );
        } else if( key == '2' ) {   // Set user type search parameter
            cout << "Insert type to search for: ";
            temp.setType( in.readLine() );
        } else if( key == '3' ) {   // Set user birth search parameter
            temp.setWasBuilt( -1 );
            while( (temp.getWasBuilt() < 0) || (temp.getWasBuilt() > 2) ) {
                QString built;
                cout << "Insert built or not to search for(any/built/not built): ";
                built = in.readLine();
                if( built == "any" || built == "Any" )
                    temp.setWasBuilt( 2 );
                else if( built == "not built" || built == "Not built" || built == "not Built" || built == "Not Built" )
                    temp.setWasBuilt( 0 );
                else if( built == "built" || built == "Built" )
                    temp.setWasBuilt( 1 );
                else
                    cout << "Invalid input!" << endl;
            }
        } else if( key == '4' ) {   // Set user death search parameter
            QString deathstring = "";
            temp.setYear( "" );   // Set empty date (Also used as wildcard)
            while( deathstring != "0" && temp.getYear() == "" ) {
                cout << "Insert death date(dd.mm.yyyy, 0 for any): ";
                deathstring = in.readLine();
                if( deathstring != "0" )
                    temp.setYear( deathstring );
            }
        }
    }
    cout << endl;
    return temp;        // Returns template for person to search for
}

void Search( vector<Person> & list, Person p ) {        // Search for members in list based on template person p
    vector<Person> SearchList;                      // Create search result vector

    for( unsigned int x = 0; x < list.size(); x++) {    // Search each entry of list
        bool add = true;                                    // We say the entry should be added by default then exclude it based on the template person
        if( p.getName() != "" )
            if( !list[x].getName().contains( p.getName(), Qt::CaseInsensitive ) )
                add = false;

        if( p.getGender() != 0 )
            if( !(list[x].getGender() == p.getGender() ) )
                add = false;

        if( p.getBirth().isValid() )
            if( !(list[x].getBirth() == p.getBirth() ) )
                add = false;

        if( p.getDeath().isValid() )
            if( !(list[x].getDeath() == p.getDeath() ) )
                add = false;

        if(add)
            SearchList.push_back( list[x] );
    }
    displayPerson( SearchList );              // Display search results
}

void Search( vector<Computer> & list, Computer p ) {        // Search for members in list based on template person p
    vector<Computer> SearchList;                      // Create search result vector

    for( unsigned int x = 0; x < list.size(); x++) {    // Search each entry of list
        bool add = true;                                    // We say the entry should be added by default then exclude it based on the template person
        if( p.getName() != "" )
            if( !list[x].getName().contains( p.getName(), Qt::CaseInsensitive ) )
                add = false;

        if( p.getType() != "" )
            if( !list[x].getType().contains( p.getType() , Qt::CaseInsensitive ) )
                add = false;

        if( p.getWasBuilt() != 2 )
            if( !(list[x].getWasBuilt() == p.getWasBuilt() ) )
                add = false;

        if( p.getYear() != "" )
            if( !(list[x].getYear() == p.getYear() ) )
                add = false;

        if(add)
            SearchList.push_back( list[x] );
    }
    displayComputer( SearchList );              // Display search results
}

int sortPerson() {        // Gets the method of which the user wants to sort the list
    char x;
    cout << "Choose how you want to sort the list" << endl;
    cout << "\t1. Sort by name ascending(default)" << endl;
    cout << "\t2. Sort by name descending" << endl;
    cout << "\t3. Sort by birth ascending" << endl;
    cout << "\t4. Sort by birth descending" << endl;
    cout << "\t5. Sort by death ascending" << endl;
    cout << "\t6. Sort by death descending" << endl;
    cout << "\t7. Sort by gender ascending" << endl;
    cout << "\t8. Sort by gender descending" << endl;

    do{                         // Error check user input
        cout << "Your choice: " ;
        cin >> x;
        cin.ignore();
        if(x < 49 || x > 56)                //makes sure input is correct
            cout << "Not a valid option! Please choose a number from 1 to 7" << endl;
    } while(x < 49 || x > 56);
    cout << endl;

    int y = x - 48;         // Convert the character the the numerical equivalent
    return y;               // Return input
}

int sortComputer() {
    char x;
    cout << "Choose how you want to sort the list" << endl;
    cout << "\t1. Sort by name ascending" << endl;
    cout << "\t2. Sort by name descending" << endl;
    cout << "\t3. Sort by year created ascending" << endl;
    cout << "\t4. Sort by year created descending" << endl;
    cout << "\t5. Sort by type ascending" << endl;
    cout << "\t6. Sort by type descending" << endl;
    cout << "\t7. Sort by built or not ascending" << endl;
    cout << "\t8. Sorty by built or not descending" << endl;

    do{                         // Error check user input
        cout << "Your choice: " ;
        cin >> x;
        cin.ignore();
        if(x < 49 || x > 56)                //makes sure input is correct
            cout << "Not a valid option! Please choose a number from 1 to 7" << endl;
    } while(x < 49 || x > 56);
    cout << endl;

    int y = x - 48;         // Convert the character the the numerical equivalent
    return y;               // Return input
}

bool keepSorted() {     // Ask whether the user wants to keep the list sorted
    char x = 0;
    while( x != 'y' && x != 'Y' && x != 'n' && x != 'N' ) {     // While there is no valid input
        cout << "Do you want to keep the list sorted(y/n)?: ";
        cin >> x;
        cin.ignore();
    }
    cout << endl;
    if ( x == 'y' || x == 'Y' )
        return true;

    return false;
}

Person modify( Person temp ) {      // User menu that changes a persons template for the modify person operation
    QTextStream in(stdin);
    string gender;
    QString birth, death, name;
    char modify;

    cout << "  1. Name\n" <<
            "  2. Gender\n" <<
            "  3. Birth date\n" <<
            "  4. Death date\n" <<
            "  5. All" << endl;
    cout << "What would you like to modify: ";
    cin >> modify;

    switch(modify){
    case '1':                                   //To modify name only
        cout << "Name: ";
        cin.ignore();
        name = in.readLine();
        temp.setName(name);
        break;

    case '2':                                   //To modify gender only
        cout << "Gender(male/female): ";
        do{
            cin >> gender;
            cin.ignore();
            if(gender == "male" || gender == "Male")
                temp.setGender(1);
            else if(gender == "female" || gender == "Female")
                temp.setGender(2);
            else
                cout << "Not a valid entry!";
        } while( !(temp.getGender() == 1 || temp.getGender() == 2) );
        break;

    case '3':                                   //To modify birth year only
        do{
        cout << "Birth year(dd.mm.yyyy): ";
        birth = in.readLine();

        temp.setBirth(QDate::fromString( birth, "dd.MM.yyyy" ));
        if(!(temp.getBirth().isValid()))
        {
            cout <<"Not a valid date!"<< endl;
        }
        }while(!(temp.getBirth().isValid()));
        break;

    case '4':                                   //To modify death year only
        do{
        cout << "Death year(dd.mm.yyyy, enter 0 if person is still alive): ";
        death = in.readLine();
        temp.setDeath(QDate::fromString(death, "dd.MM.yyyy"));
        if(death == "0")
        {
            break;
        }
        if(!(temp.getBirth().isValid()))
        {
            cout <<"Not a valid date!" << endl;
        }
        }while(!(temp.getDeath().isValid()));
        break;

    case '5':                                   //To modify all
        temp = addPerson();
        break;

    default:
        cout << "Not a valid option" << endl;
        break;
    }
    cout << endl;
    return temp;
}

