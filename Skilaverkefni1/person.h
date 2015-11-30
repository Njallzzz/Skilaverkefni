#ifndef PERSON_H
#define PERSON_H


#include <QString>
#include <QDate>


struct Person {
    QString name;
    int gender;        // 1 = Male, 2 = Female
    QDate birth;
    QDate death;        // if QDate() = empty
};

#endif // PERSON_H

