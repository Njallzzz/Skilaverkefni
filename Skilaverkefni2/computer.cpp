#include "computer.h"

Computer::Computer()
{

}
Computer::Computer(QString theName, int year, QString theType, bool built)
    :name(theName), yearOfBuild(year), type(theType), wasBuilt(built){

}

QString Computer::getName(){
    return name;
}
int Computer::getYear(){
    return yearOfBuild;
}
QString Computer::getType(){
    return type;
}
bool Computer::getWasBuilt(){
    return wasBuilt;
}

void Computer::setName(QString theName){
    name = theName;
}
void Computer::setYear(int year){
    yearOfBuild = year;
}
void Computer::setType(QString theType){
    type = theType;
}
void Computer::setWasBuilt(bool built){
    wasBuilt = built;
}
