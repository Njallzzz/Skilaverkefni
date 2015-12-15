#ifndef PERSONADDRELATION_H
#define PERSONADDRELATION_H

#include <QDialog>
#include "services/interface.h"
#include "models/person.h"
#include "services/interface.h"
#include <QtCore>
#include <QtGui>

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
    void displayComputers();
    void setHandler(Interface *handler);

private slots:
    void on_pushButton_cancel_clicked();
    void on_pushButton_add_relation_clicked();
    void on_pushButton_remove_relation_clicked();
    void on_computer_list_clicked();
    void on_computer_list_related_clicked();

private:
    Ui::PersonAddRelation *ui;
    Person person;
    Interface *handler;
    QStandardItemModel *model;

    vector<Computer> comps;
    vector<Computer> related;
    vector<Computer> notRelated;
};

#endif // PERSONADDRELATION_H
