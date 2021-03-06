#ifndef COMPUTER_H
#define COMPUTER_H

#include <QString>
#include <QDate>
#include <QTextStream>
#include <iostream>

using namespace std;

class Computer {
public:
    //Constructors
    Computer();
    Computer(int ID, QString theName, QDate year, QString theType, bool built);

    //Getters
    int getId();
    QString getName();
    QString getYear();
    QString getType();
    int getWasBuilt();

    //Setters
    void setId( int id );
    void setName(QString theName);
    void setYear(QString year);
    void setType(QString theType);
    void setWasBuilt(int built);

    // Display
    friend std::ostream& operator<<(std::ostream& os, const Computer& c);

    // Add/Modify
    friend std::istream& operator>>(std::istream& is, Computer& c);

private:
    int id;
    QString name;
    QDate yearOfBuild;
    QString type;
    int wasBuilt;
};

#endif // COMPUTER_H
