#ifndef COMPUTER_H
#define COMPUTER_H

#include <QString>
#include <QDate>

class Computer
{
public:
    //Constructors
    Computer();
    Computer(QString theName, int year, QString theType, bool built);

    //Getters
    QString getName();
    int getYear();
    QString getType();
    bool getWasBuilt();

    //Setters
    void setName(QString theName);
    void setYear(int year);
    void setType(QString theType);
    void setWasBuilt(bool built);


private:
    int id;
    QString name;
    int yearOfBuild;
    QString type;
    bool wasBuilt;
};

#endif // COMPUTER_H
