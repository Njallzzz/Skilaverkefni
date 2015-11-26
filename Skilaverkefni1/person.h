#ifndef PERSON_H
#define PERSON_H

struct Person {
    QString name;
    bool gender;      // 0 = Male, 1 = Female
    QDate birth;
    QDate death;
};

#endif // PERSON_H

