#include "person.h"

Person::Person() {}

Person::Person(QString name, int gender, QDate birth, QDate death)
    : name(name), gender(gender), birth(birth), death(death){}

Person::Person( int id, QString name, int gender, QDate birth, QDate death)
    : id(id), name(name), gender(gender), birth(birth), death(death) {}

Person::Person(QString name, int gender, QDate birth)
    : name(name), gender(gender), birth(birth){}

int Person::getId(){
    return id;
}

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
int Person::getComputer(int i) {
    return computers[i];
}

int Person::getSize() {
    return computers.size();
}

void Person::setId(int id){
    this->id = id;
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

void Person::add_relation( int id ) {
    computers.push_back( id );
}

bool Person::isRelated( Computer c ) {
    bool related = false;
    for( unsigned int x = 0; x < computers.size(); x++ ) {
        if( computers[x] == c.getId() )
            related = true;
    }
    return related;
}

std::ostream& operator<<(std::ostream& os, Person& p) {
    os << p.name.toUtf8().constData();
    if( p.name.length() < 8 )
        os << "\t\t\t";
    else if( p.name.length() >= 8 && p.name.length() < 16 )
        os << "\t\t";
    else if( p.name.length() >= 16 && p.name.length() < 24 )
        os << "\t";
    else
        os << "";

    if( p.gender == 1 )
        os << "Male\t";
    else if( p.gender == 2 )
        os << "Female\t";

    os << p.birth.toString("d.M.yyyy").toUtf8().constData();
    if( p.getDeath().isValid() )
        os << "\t" << p.death.toString("d.M.yyyy").toUtf8().constData();
    else
        os << "\t\t";
    return os;
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

    cin.ignore();
    while( !p.birth.isValid() ) {
        cout << "Birth date(dd.mm.yyyy): ";
        p.birth = QDate::fromString( in.readLine(), "dd.MM.yyyy" );
        if( !p.birth.isValid() )
            cout << "Invalid Date!" << endl;
    }
    char stillAlive = 'a';
    while( stillAlive != 'n' && stillAlive != 'N' && stillAlive != 'y' && stillAlive != 'Y') {
        cout << "Is this person still alive(y/n)?";
        cin >> stillAlive;
        cin.ignore();
        if( stillAlive != 'n' && stillAlive != 'N' && stillAlive != 'y' && stillAlive != 'Y' )
            cout << "Invalid input!" << endl;
    }
    if(stillAlive == 'y' || stillAlive == 'Y')
        return is;
    else if( stillAlive == 'n' || stillAlive == 'N')
    {
        do{
            p.death = QDate();
            QString death = "";
            while( !p.death.isValid() && death != "0") {
                cout << "Death date(dd.mm.yyyy): ";
                death = in.readLine();
                if( death != "0" )
                    p.death = QDate::fromString( death, "dd.MM.yyyy");
                else if(death == "0")
                    p.death = QDate::fromString(0);

                if(p.death <= p.birth && p.death.isValid() ) {
                    cout << "A person can not die before it is born!" << endl;
                }
            }
        } while(p.death < p.birth);
    }
    return is;
}
