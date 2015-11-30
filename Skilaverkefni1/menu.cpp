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
    cout << "   6. Modify list entry" << endl;
    cout << "   7. Quit" << endl;

    do{
    cin >> x;
    if(x < 49 || x > 55)                //makes sure input is correct
    {
        cout << "Not a valid option!" << endl;
    }
    }while(x < 49 || x > 55);

    int y = x-48;
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

Person addPerson()
{
    Person temp;
    string gender;
    QString birth, death;
    QString name;
    QTextStream in(stdin);

    cout << "Add a person to the list" << endl;


    cout << "Name: ";
    cin.ignore();
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

int deletePerson(vector<Person>& list)
{
   int x;
   char choice;
   cout << "Select a person to delete(input the number displayed before the name): ";
   cin >> x;
   cout << "Are you sure you want to delete '" << list[x-1].name.toUtf8().constData() << "' from the list?(y/n)";
   cin >> choice;

   if(choice == 'y'|| choice == 'Y' )
   {
       return x;
   }

   else if (choice == 'n' || choice == 'N')
   {
       return 0;
   }

}


int sortList()
{
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
    {
        cout << "Not a valid option! Please choose a number from 1 to 4" << endl;
    }
    }while(x < 49 || x > 52);

    int y = x-48;
    return y;

}

bool keepSorted()
{   char x;
    cout << "Do you want to keep the list sorted?(y/n)";
    cin >> x;
    if (x=='y' || x =='Y')
    {
        return true;
    }
    if(x=='n' || x == 'N')
    {
        return false;
    }

}

Person modify( Person temp ){
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
        temp.name = in.readLine();
        cout << "Name: ";
        name = in.readLine();
        temp.name = name;
        break;

    case '2':                                   //To modify gender only
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
        break;

    case '3':                                   //To modify birth year only
        cout << "Birth year(dd.MM.yyyy): ";
        in >> birth;
        temp.birth = QDate::fromString( birth, "dd.MM.yyyy" );
        break;

    case '4':                                   //To modify death year only
        cout << "Death year(dd.MM.yyyy): ";
        in >> death;
        temp.death = QDate::fromString(death, "dd.MM.yyyy");
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

