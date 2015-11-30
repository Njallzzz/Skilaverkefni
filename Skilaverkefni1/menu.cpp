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

    do{
    cin >> x;
    if(x < 49 || x > 54)                //makes sure input is correct
    {
        cout << "Not a valid option!" << endl;
    }
    }while(x < 49 || x > 53);

    int y = x-48;
    return y;
}

void display(vector<Person>& list)
{
    cout << "\tName\t\t\tGender\tBirth\t\tDeath" << endl;
    cout << "---------------------------------------------------------------------" << endl;
    for(unsigned int i=0; i < list.size(); i++)
    {
        if(list[i].gender == 0)
        {
            if(list[i].name.length() < 8 )  //if name is less than 8 letters, add a tab before gender
            {
                cout << i+1<< "." <<"\t" << list[i].name.toUtf8().constData() << "\t\t\tMale\t";
            }
            else
            {
                 cout << i+1<< "." <<"\t" << list[i].name.toUtf8().constData() << "\t\tMale\t";
            }
            cout << list[i].birth.toString("dd.MM.yyyy").toUtf8().constData() << "\t";
            cout << list[i].death.toString("dd.MM.yyyy").toUtf8().constData() << endl;
        }

        else if(list[i].gender == 1)        // if name is less than 8 letters, add a tab before gender
        {
            if(list[i].name.length() < 8 )
            {
                cout << i+1<< "." <<"\t" << list[i].name.toUtf8().constData() << "\t\t\tMale\t";
            }
            else
            {
                cout << i+1<< "." <<"\t" << list[i].name.toUtf8().constData() << "\t\tMale\t";
            }
                cout << list[i].birth.toString("dd.MM.yyyy").toUtf8().constData() << "\t";
                cout << list[i].death.toString("dd.MM.yyyy").toUtf8().constData() << endl;
        }
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
            temp.gender = 0;
        else if(gender == "female" || gender == "Female")
            temp.gender = 1;
        else
            cout << "Not a valid entry!";
    }while(!(temp.gender == 0 || temp.gender == 1));

    cout << "Birth year(dd.MM.yyyy): ";
    in >> birth;
    temp.birth = QDate::fromString( birth, "dd.MM.yyyy" );

    cout << "Death year(dd.MM.yyyy): ";
    in >> death;
    temp.death = QDate::fromString(death, "dd.MM.yyyy");

    return temp;
}
