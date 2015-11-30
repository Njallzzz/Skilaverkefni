#ifndef PERSON_H
#define PERSON_H

struct Person {
    QString name;
    int gender;        // 0 = Male, 1 = Female
    QDate birth;
    QDate death;        // if QDate() = empty
};

#endif // PERSON_H

