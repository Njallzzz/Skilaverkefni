#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QDate>
#include <QTextStream>
#include <vector>
#include <iostream>

using namespace std;

class Person {// Construct of a individual
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

    void setName(QString name);
    void setGender(int gender);
    void setBirth(QDate birth);
    void setDeath(QDate death);

    void add_relation( int id );

    friend std::istream& operator>>(std::istream& is, Person& p);

    int id;
    QString name;       // Name of a individual
    int gender;         // 0 = Unspecified, 1 = Male, 2 = Female
    QDate birth;
    QDate death;        // if death = QDate() then Invalid
    vector<int> computers;
};

#endif // PERSON_H

