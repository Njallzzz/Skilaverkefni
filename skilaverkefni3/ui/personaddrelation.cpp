#include "ui/personaddrelation.h"
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
    displayComputers();
}

void PersonAddRelation::displayComputers()
{
    vector<Computer> comps = handler->getComputers( true );
    vector<Computer> related;
    vector<Computer> notRelated;
    for(int i = 0; i < person.getSize(); i++){
        for(int j = 0; j < int(comps.size()); j++){
            if(handler->getComputer(j).getId() == person.getComputer(i)){
                related.push_back(handler->getComputer(j));
            }
        }
    }
    notRelated = comps;
    for(int i = notRelated.size() - 1; i >= 0; i--){
        for(int j = 0; j < int(related.size()); j++){
            if(notRelated[i].getId() == related[j].getId()){
                notRelated.erase(notRelated.begin() + i);
            }
        }
    }
    model = new QStandardItemModel(related.size(), 1, this);

    model->setHeaderData(0,Qt::Horizontal, "Computers");

    for(int i = 0; i < int(related.size()); i++){
        QModelIndex index = model->index( i, 0, QModelIndex() );
        model->setData( index, related[i].getName() );
    }
    ui->computer_list_related->setModel(model);

    model = new QStandardItemModel(notRelated.size(), 1, this);

    model->setHeaderData(0,Qt::Horizontal, "Computers");

    qDebug() << comps.size();

    for(int i = 0; i < int(notRelated.size()); i++){
        QModelIndex index = model->index( i, 0, QModelIndex() );
        model->setData( index, notRelated[i].getName() );
    }
    ui->computer_list->setModel(model);
}

void PersonAddRelation::setHandler(Interface *handler)
{
    this->handler = handler;
}

void PersonAddRelation::on_pushButton_cancel_clicked()
{
    this->close();
}

void PersonAddRelation::on_pushButton_add_relation_clicked()
{

}
