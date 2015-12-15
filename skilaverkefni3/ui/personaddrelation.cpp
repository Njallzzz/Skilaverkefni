#include "ui/personaddrelation.h"
#include "ui_personaddrelation.h"

PersonAddRelation::PersonAddRelation(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonAddRelation)
{
    ui->setupUi(this);
}

PersonAddRelation::~PersonAddRelation()
{
    delete ui;
}

void PersonAddRelation::on_pushButton_cancel_clicked()
{
    this->close();
}
