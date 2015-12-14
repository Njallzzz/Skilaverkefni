#include "ui/personwindow.h"
#include "ui_personwindow.h"

PersonWindow::PersonWindow(QWidget *parent) : QDialog(parent), ui(new Ui::PersonWindow) {
    ui->setupUi(this);
    this->setWindowFlags( Qt::WindowTitleHint | Qt::WindowCloseButtonHint );

    ui->genderInput->addItem("Male");
    ui->genderInput->addItem("Female");

    ui->deathInput->setEnabled(true);
}

PersonWindow::~PersonWindow() {
    delete ui;
}

void PersonWindow::on_addRelationButton_clicked()
{
    PersonAddRelation *rel = new PersonAddRelation;
    rel->exec();
}

void PersonWindow::on_isAliveCheckBox_toggled(bool checked)
{
    if(checked == true){
        ui->deathInput->setEnabled(false);
    }
    else{
        ui->deathInput->setEnabled(true);
    }
}

void PersonWindow::on_cancelButton_clicked()
{
    this->close();
}

void PersonWindow::on_saveButton_clicked()
{
    bool valid = true;
    if(ui->nameInput->text() == NULL){
        valid = false;
        ui->label_name->setText("<font color='red'>Name</font>");
    }
    if( ui->genderInput->currentText() != "Male" && ui->genderInput->currentText() != "Female" ){
        valid = false;
        ui->label_gender->setText("<font color='red'>Gender</font>");
    }
    if(!ui->birthInput->dateTime().isValid()){
        valid = false;
        ui->label_birth->setText("<font color='red'>Birth</font>");
    }
    if(!ui->isAliveCheckBox->isChecked()){
        if(!ui->deathInput->dateTime().isValid()){
            valid = false;
            ui->label_death->setText("<font color='red'>Death</font>");
        }
        if(ui->deathInput->dateTime() > ui->birthInput->dateTime()){
            valid = false;
        }
    }
    if(valid == true){
        this->close();
    }
}
