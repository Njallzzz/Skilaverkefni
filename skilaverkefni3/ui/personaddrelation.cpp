#include "personaddrelation.h"
#include "ui_personaddrelation.h"

PersonAddRelation::PersonAddRelation(QWidget *parent) :QDialog(parent),ui(new Ui::PersonAddRelation){
    ui->setupUi(this);
}

PersonAddRelation::~PersonAddRelation()
{
    delete ui;
}

void PersonAddRelation::setPerson(Person p)
{
    person = p;
}

void PersonAddRelation::displayComputers()
{
    vector<Computer> comps = handler->getComputers(true);
    vector<Computer> related;
    vector<Computer> notRelated;
    for(int i = 0; i < person.getSize(); i++){
        related.push_back(handler->getComputer(person.getComputer(i)));
    }
    for(int i = 0; i < comps.size(); i++){

    }
}

void PersonAddRelation::gethandler(Interface *handler)
{
    this->handler = handler;
}

void PersonAddRelation::on_pushButton_cancel_clicked()
{
    this->close();
}
