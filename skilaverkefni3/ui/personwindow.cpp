#include "ui/personwindow.h"
#include "ui_personwindow.h"

PersonWindow::PersonWindow(QWidget *parent) : QDialog(parent), ui(new Ui::PersonWindow) {
    ui->setupUi(this);
    this->setWindowFlags( Qt::WindowTitleHint | Qt::WindowCloseButtonHint );

    ui->genderInput->addItem("Male");
    ui->genderInput->addItem("Female");

    ui->deathInput->setEnabled(true);
    ui->addRelationButton->setEnabled(false);

    if(p.getId() > 0){
        ui->nameInput->setText(p.getName());
        if(p.getGender() == 1)
            ui->genderInput->setCurrentIndex(0);
        else if(p.getGender() == 2)
            ui->genderInput->setCurrentIndex(1);
        ui->birthInput->setDate(p.getBirth());
        if(!p.getDeath().isValid()){
            ui->isAliveCheckBox->setChecked(false);
        }
        else{
            ui->isAliveCheckBox->setChecked(true);
            ui->deathInput->setDate(p.getDeath());
        }
    }
}

PersonWindow::~PersonWindow() {
    delete ui;
}

void PersonWindow::setPerson(Person p)
{
    this->p = p;
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
            QMessageBox::warning(this,"Input error", "the birth date you entered was later than the death date!");
        }
    }
    if(valid == true){
        ui->addRelationButton->setEnabled(true);
        ui->saveButton->setText("Close");
    }
}
