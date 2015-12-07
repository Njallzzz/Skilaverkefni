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

