#ifndef PERSONADDRELATION_H
#define PERSONADDRELATION_H

#include <QDialog>
#include "services/interface.h"
#include "models/person.h"

namespace Ui {
class PersonAddRelation;
}

class PersonAddRelation : public QDialog
{
    Q_OBJECT

public:
    explicit PersonAddRelation(QWidget *parent = 0);
    ~PersonAddRelation();

    void setPerson(Person p);

private slots:
    void on_pushButton_cancel_clicked();

private:
    Ui::PersonAddRelation *ui;
    Person p;

};

#endif // PERSONADDRELATION_H
