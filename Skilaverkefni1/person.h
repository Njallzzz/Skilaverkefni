#ifndef PERSON_H
#define PERSON_H


#include <QString>
#include <QDate>


struct Person {
    QString name;
    bool gender;        // 0 = Male, 1 = Female
    QDate birth;
    QDate death;        // if QDate() = empty
};

#endif // PERSON_H

