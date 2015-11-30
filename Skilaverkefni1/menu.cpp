#include "menu.h"
using namespace std;

int menu()
{   char x;
    cout << "Choose an option" << endl;
    cout << "   1. Display list" << endl;
    cout << "   2. Add to list" << endl;
    cout << "   3. Remove from list" << endl;
    cout << "   4. Search list" << endl;
    cout << "   5. Sort list" << endl;
    cout << "   6. Quit" << endl;
    cout << "Your choice: ";
    do{
        cin >> x;
        cin.ignore();
        if(x < 49 || x > 54)                //makes sure input is correct
            cout << "Not a valid option!" << endl;
    } while(x < 49 || x > 54);

    int y = x - 48;
    return y;
}

void display(vector<Person>& list)
{

    cout << "\tName\t\t\t\tGender\tBirth\t\tDeath" << endl;
    cout << "-------------------------------------------------------------------------------" << endl;



    for(unsigned int i=0; i < list.size(); i++)
    {
        if(list[i].gender == 1)
        {
            if(list[i].name.length() < 8 )  //if name is less than 8 letters, add a tab before gender
            {
                cout << i+1<< "." <<"\t" << list[i].name.toUtf8().constData() << "\t\t\t\tMale\t";
            }
            else if(list[i].name.length() > 16)
            {
               cout << i+1<< "." <<"\t" << list[i].name.toUtf8().constData() << "\t\tMale\t";
            }

            else
            {
                 cout << i+1<< "." <<"\t" << list[i].name.toUtf8().constData() << "\t\t\tMale\t";
            }
            cout << list[i].birth.toString("dd.MM.yyyy").toUtf8().constData() << "\t";
            cout << list[i].death.toString("dd.MM.yyyy").toUtf8().constData() << endl;
        }

        else if(list[i].gender == 2)        // if name is less than 8 letters, add a tab before gender
        {
            if(list[i].name.length() < 8 )
            {

                cout << i+1<< "." <<"\t" << list[i].name.toUtf8().constData() << "\t\t\t\tFemale\t";
            }
            else if(list[i].name.length() > 16)
            {
                cout << i+1<< "." <<"\t" << list[i].name.toUtf8().constData() << "\t\tFemale\t";
            }

            else
            {
                cout << i+1<< "." <<"\t" << list[i].name.toUtf8().constData() << "\t\t\tFemale\t";

            }
                cout << list[i].birth.toString("dd.MM.yyyy").toUtf8().constData() << "\t";
                cout << list[i].death.toString("dd.MM.yyyy").toUtf8().constData() << endl;
        }
        cout << endl;
    }

}

Person addPerson() {
    Person temp;
    string gender;
    QString birth, death;
    QString name;
    QTextStream in(stdin);

    cout << "Add a person to the list" << endl;

    cout << "Name: ";
    name = in.readLine();
    temp.name = name;


    cout << "Gender: ";
    do{
        cin >> gender;
        if(gender == "male" || gender == "Male")
            temp.gender = 1;
        else if(gender == "female" || gender == "Female")
            temp.gender = 2;
        else
            cout << "Not a valid entry!";
    }while(!(temp.gender == 1 || temp.gender == 2));

    cout << "Birth year(dd.MM.yyyy): ";
    in >> birth;
    temp.birth = QDate::fromString( birth, "dd.MM.yyyy" );

    cout << "Death year(dd.MM.yyyy): ";
    in >> death;
    temp.death = QDate::fromString(death, "dd.MM.yyyy");

    return temp;
}

int deletePerson(vector<Person>& list) {
   int x;
   char choice;
   while( x < 1 || x >= int(list.size()) ) {
       cout << "Select a person to delete(input the number displayed before the name): ";
       cin >> x;
   }
   while( choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N' ) {
       cout << "Are you sure you want to delete '" << list[x-1].name.toUtf8().constData() << "' from the list?(y/n)";
       cin >> choice;
   }

   if(choice == 'y'|| choice == 'Y' )
       return x;

   return 0;
}

Person SearchMenu() {       // Get search paramters from user
    Person temp;    char key;   QTextStream in(stdin);
    temp.name = "";
    temp.gender = 0;
    while( key != '5' ) {           // while looping while inserting search parameters
        cout << "Please specify search parameters" << endl;
        cout << "\t1. Search by name(";
        if( temp.name == "" )               // If wildcard
            cout << "any)" << endl;
        else                                // if user specified
            cout << temp.name.toUtf8().constData() << ")" << endl;     // Write current name parameters

        cout << "\t2. Search by gender(";
        if( temp.gender == 0 )              // If wildcard
            cout << "any)" << endl;
        else if( temp.gender == 1 )         // if user specified
            cout << "male)" << endl;
        else if( temp.gender == 2 )         // if user specified
            cout << "female)" << endl;

        cout << "\t3. Search by birth(";
        if( !temp.birth.isValid() )         // If wildcard
            cout << "any)" << endl;
        else                                // if user specified
            cout << temp.birth.toString("dd.MM.yyyy").toUtf8().constData() << ")" << endl;  // Write current birth parameters

        cout << "\t4. Search by death(";
        if( !temp.death.isValid() )         // If wildcard
            cout << "any)" << endl;
        else                                // if user specified
            cout << temp.death.toString("dd.MM.yyyy").toUtf8().constData() << ")" << endl;  // Write current death parameters
        cout << "\t5. Search" << endl;

        cout << "Your choice: ";
        cin >> key;                 // Get user input for next action, 1: name parameter, 2: gender parameter, 3: birth parameter, 4: death parameter and 5: Search
        cin.ignore();

        if( key == '1' ) {          // Set user name search parameter
            cout << "Insert name to search for: ";
            temp.name = in.readLine();
        } else if( key == '2' ) {   // Set user gender search parameter
            temp.gender = -1;
            while( (temp.gender < 0) || (temp.gender > 2) ) {
                cout << "Insert gender to search for(0 for any, 1 for male, 2 for female): ";
                cin >> temp.gender;
                cin.ignore();
            }
        } else if( key == '3' ) {   // Set user birth search parameter
            QString birthstring = "";
            temp.birth = QDate();   // Set empty date (Also used as wildcard)
            while( birthstring != "00.00.0000" && !temp.birth.isValid() ) {
                cout << "Insert birth date(format: dd.mm.yyyy, 00.00.0000 for any): ";
                birthstring = in.readLine();
                if( birthstring != "00.00.0000" )
                    temp.birth = QDate::fromString( birthstring, "dd.MM.yyyy" );
            }
        } else if( key == '4' ) {   // Set user death search parameter
            QString deathstring = "";
            temp.death = QDate();   // Set empty date (Also used as wildcard)
            while( deathstring != "00.00.0000" && !temp.death.isValid() ) {
                cout << "Insert death date(format: dd.mm.yyyy, 00.00.0000 for any): ";
                deathstring = in.readLine();
                if( deathstring != "00.00.0000" )
                    temp.death = QDate::fromString( deathstring, "dd.MM.yyyy" );
            }
        }
    }

    return temp;        // Returns template for person to search for
}

void Search( vector<Person> & list, Person p ) {        // Search for members in list based on template person p
    vector<Person> SearchList;                      // Create search result vector

    for( unsigned int x = 0; x < list.size(); x++) {    // Search each entry of list
        bool add = true;                                    // We say the entry should be added by default then exclude it based on the template person
        if( p.name != "" )
            if( !list[x].name.contains( p.name, Qt::CaseInsensitive ) )
                add = false;

        if( p.gender != 0 )
            if( !(list[x].gender == p.gender) )
                add = false;

        if( p.birth.isValid() )
            if( !(list[x].birth == p.birth) )
                add = false;

        if( p.death.isValid() )
            if( !(list[x].death == p.death) )
                add = false;

        if(add)
            SearchList.push_back( list[x] );
    }
    display( SearchList );              // Display search results
}

int sortList() {
    char x;
    cout << "Choose how you want to sort the list" << endl;
    cout << "\t1. Sort by name" << endl;
    cout << "\t2. Sort by birth year" << endl;
    cout << "\t3. Sort by death year" << endl;
    cout << "\t4. Sort by gender" << endl;

    cout << "Your choice: " ;
    do{
        cin >> x;
        if(x < 49 || x > 52)                //makes sure input is correct
            cout << "Not a valid option! Please choose a number from 1 to 4" << endl;
    } while(x < 49 || x > 52);

    int y = x - 48;
    return y;

}

bool keepSorted() {
    char x;
    while( x != 'y' && x != 'Y' && x != 'n' && x != 'N' ) {
        cout << "Do you want to keep the list sorted?(y/n)";
        cin >> x;
    }
    if ( x == 'y' || x == 'Y' )
        return true;

    return false;
}


