#include "models/computer.h"

Computer::Computer() {

}
Computer::Computer( int ID, QString theName, QDate year, QString theType, bool built)
    :name(theName), yearOfBuild(year), type(theType), wasBuilt(built){
    id = ID;
}

//To get data
int Computer::getId() {
    return id;
}
QString Computer::getName() {
    return name;
}
QString Computer::getYear() {
    return yearOfBuild.toString("yyyy");
}
QString Computer::getType() {
    return type;
}
int Computer::getWasBuilt() {
    return wasBuilt;
}

//To set data
void Computer::setName(QString theName) {
    name = theName;
}
void Computer::setYear(QString year) {
    yearOfBuild = QDate::fromString( year, "yyyy" );
}
void Computer::setType(QString theType) {
    type = theType;
}
void Computer::setWasBuilt(int built) {
    wasBuilt = built;
}
