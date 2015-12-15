#include "models/computer.h"

Computer::Computer() {

}
Computer::Computer( int ID, QString theName, QDate year, QString theType, bool built)
    :name(theName), yearOfBuild(year), type(theType), wasBuilt(built){
    id = ID;
}

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

void Computer::setId( int theId ) {
    id = theId;
}
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

std::ostream& operator<<(std::ostream& os, const Computer& c) {
    os << c.name.toUtf8().constData();
    if( c.name.length() < 8 )
        os << "\t\t\t";
    else if( c.name.length() >= 8 && c.name.length() < 16 )
        os << "\t\t";
    else
        os << "\t";

    os << c.yearOfBuild.toString("yyyy").toUtf8().constData();
    os << "\t\t" << c.type.toUtf8().constData();

    os << "\t";
    if( c.type.length() < 8 )
        os << "\t\t";
    else if( c.type.length() >= 8 && c.type.length() < 16 )
        os << "\t";

    if( c.wasBuilt )
        os << "built";
    else
        os << "Not built";
    return os;
}


