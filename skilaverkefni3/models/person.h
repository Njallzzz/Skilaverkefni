#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QDate>
#include <QTextStream>
#include <vector>
#include <iostream>
#include "models/computer.h"

using namespace std;

class Person {      // Construct of a individual
public:
    Person();
    Person( int id, QString name, int gender, QDate birth, QDate death);
    Person(QString name, int gender, QDate birth, QDate death);
    Person(QString name, int gender, QDate birth);

    int getId();
    QString getName();
    int getGender();
    QDate getBirth();
    QDate getDeath();
    int getSize();
    int getComputer(int i);

    void setId( int id );
    void setName(QString name);
    void setGender(int gender);
    void setBirth(QDate birth);
    void setDeath(QDate death);

    void add_relation( int id );        // Add a relation to this person

    bool isRelated( Computer c );       // Check if this person is related with a computer

    friend std::istream& operator>>(std::istream& is, Person& p);
    friend std::ostream& operator<<(std::ostream& os, Person& p);

private:
    int id;
    QString name;       // Name of a individual
    int gender;         // 0 = Unspecified, 1 = Male, 2 = Female
    QDate birth;
    QDate death;        // if death = QDate() then Invalid
    vector<int> computers;
};

#endif // PERSON_H

