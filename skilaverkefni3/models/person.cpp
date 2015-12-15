#include "models/person.h"

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
