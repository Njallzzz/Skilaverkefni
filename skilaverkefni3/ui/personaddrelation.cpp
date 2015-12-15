#include "ui/personaddrelation.h"
#include "ui_personaddrelation.h"

PersonAddRelation::PersonAddRelation(QWidget *parent) :QDialog(parent),ui(new Ui::PersonAddRelation){
    ui->setupUi(this);
    ui->pushButton_add_relation->setEnabled(false);
    ui->pushButton_remove_relation->setEnabled(false);
}

PersonAddRelation::~PersonAddRelation()
{
    delete ui;
}

//set which person these relations belong to
void PersonAddRelation::setPerson(Person p)
{
    person = p;
    displayComputers();
}
//displays computers in listboxes
void PersonAddRelation::displayComputers()
{
    related.clear();
    notRelated.clear();
    comps = handler->getComputers( true );
    for(int i = 0; i < person.getSize(); i++){              //find computers that are related to the person
        for(int j = 0; j < int(comps.size()); j++){
            if(handler->getComputer(j).getId() == person.getComputer(i)){
                related.push_back(handler->getComputer(j));
            }
        }
    }
    notRelated = comps;
    for(int i = notRelated.size() - 1; i >= 0; i--){        //find computers that are not related to the person
        for(int j = 0; j < int(related.size()); j++){
            if(notRelated[i].getId() == related[j].getId()){
                notRelated.erase(notRelated.begin() + i);
            }
        }
    }
    model = new QStandardItemModel(related.size(), 1, this);

    //populate the related computers list
    model->setHeaderData(0,Qt::Horizontal, "Computers");

    for(int i = 0; i < int(related.size()); i++){
        QModelIndex index = model->index( i, 0, QModelIndex() );
        model->setData( index, related[i].getName() );
    }
    ui->computer_list_related->setModel(model);

    //populate the notRelated computers list
    model = new QStandardItemModel(notRelated.size(), 1, this);

    model->setHeaderData(0,Qt::Horizontal, "Computers");

    for(int i = 0; i < int(notRelated.size()); i++){
        QModelIndex index = model->index( i, 0, QModelIndex() );
        model->setData( index, notRelated[i].getName() );
    }
    ui->computer_list->setModel(model);
}
//get an instance of the service class
void PersonAddRelation::setHandler(Interface *handler)
{
    this->handler = handler;
}

void PersonAddRelation::on_pushButton_cancel_clicked()
{
    this->close();
}
//add relation
void PersonAddRelation::on_pushButton_add_relation_clicked()
{
    Computer tmp = notRelated[ui->computer_list->currentIndex().row()];     //get an instance of Person
    handler->addRelation(person, tmp);
    person = handler->getPersonById(person.getId());            //Fetch the person again to refresh the lists
    displayComputers();
    ui->pushButton_add_relation->setEnabled(false);
}
//Remove relation
void PersonAddRelation::on_pushButton_remove_relation_clicked()
{
    Computer tmp = related[ui->computer_list_related->currentIndex().row()];
    handler->removeRelation(person, tmp);
    person = handler->getPersonById(person.getId());
    displayComputers();
    ui->pushButton_remove_relation->setEnabled(false);
}
//when no computer is selected the user can't click "Add relation"
void PersonAddRelation::on_computer_list_clicked(const QModelIndex &index)
{
    ui->pushButton_add_relation->setEnabled(true);
}
//when no computer is selected the user can't click "Remove relation"
void PersonAddRelation::on_computer_list_related_clicked(const QModelIndex &index)
{
    ui->pushButton_remove_relation->setEnabled(true);
}
