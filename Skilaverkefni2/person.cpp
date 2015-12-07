#include "person.h"

Person::Person()
{

}

Person::Person(QString name, int gender, QDate birth, QDate death)
    : name(name), gender(gender), birth(birth), death(death){}

Person::Person(QString name, int gender, QDate birth)
    : name(name), gender(gender), birth(birth){}

QString Person::getName(){
    return name;
}

int Person::getGender(){
    return gender;
}

QDate Person::getBirth(){
    return birth;
}

QDate Person::getDeath(){
    return death;
}

void Person::setName(QString name){
    this->name = name;
}
void Person::setGender(int gender){
    this->gender = gender;
}
void Person::setBirth(QDate birth){
    this->birth = birth;
}
void Person::setDeath(QDate death){
    this->death = death;
}

std::istream& operator>>(std::istream& is, Person& p) {
    QTextStream in(stdin);
    string gender;

    cout << "Name: ";
    p.name = "";
    while( p.name == "" )
            p.name = in.readLine();
    do{
    cout << "Gender(male/female): ";
    cin >> gender;
    if(gender == "male" || gender == "Male")
    {
        p.gender = 1;
    }
    else if(gender == "female" || gender == "Female")
    {
        p.gender = 2;
    }
    else
        cout << "Invalid input!" << endl;
    }while(p.gender != 1 && p.gender != 2);



    cout << "Birth year: ";
    p.birth = QDate();
    while( !p.birth.isValid() )
        p.birth = QDate::fromString( in.readLine(), "dd.MM.yy" );

    cout << "Death year: ";
    p.death = QDate();
    while( !p.death.isValid())
        p.death = QDate::fromString( in.readLine(), "dd.MM.yy");


    return is;
}
