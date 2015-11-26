#ifndef PERSON_H
#define PERSON_H

struct Person {
    QString name;
    bool gender;        // 0 = Male, 1 = Female
    int birthyear;      // Format: XXXX, example: 2015
    int deathyear;      // Format: XXXX, example: 2015      0 = Still alive
};

#endif // PERSON_H

