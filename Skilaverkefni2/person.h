#ifndef PERSON_H
#define PERSON_H

#include <QString>
#include <QDate>

struct Person {         // Construct of a individual
    QString name;       // Name of a individual
    int gender;         // 0 = Unspecified, 1 = Male, 2 = Female
    QDate birth;
    QDate death;        // if death = QDate() then Invalid
};

#endif // PERSON_H

