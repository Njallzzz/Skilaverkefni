#include "ui/personwindow.h"
#include "ui_personwindow.h"

PersonWindow::PersonWindow(QWidget *parent) : QDialog(parent), ui(new Ui::PersonWindow) {
    ui->setupUi(this);
    this->setWindowFlags( Qt::WindowTitleHint | Qt::WindowCloseButtonHint );

    ui->genderInput->addItem("Male");
    ui->genderInput->addItem("Female");

    ui->deathInput->setEnabled(true);
    ui->addRelationButton->setEnabled(false);

    /*if(p.getId() > 0){
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
    }*/
    moding = false;
}

PersonWindow::~PersonWindow() {
    delete ui;
}

void PersonWindow::setPerson(Person p)
{
    moding = true;
    person = p;
    ui->label_top->setText("Modify person");
    displayPerson();
}

void PersonWindow::getHandler(Interface *h)
{
    handler = h;
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

    if(ui->saveButton->text() == "Save"){
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
            if(ui->deathInput->dateTime() < ui->birthInput->dateTime()){
                valid = false;
                QMessageBox::warning(this,"Input error", "the birth date you entered was later than the death date!");
            }
        }
        if(valid == true){
            person.setName(ui->nameInput->text());
            person.setGender(ui->genderInput->currentIndex()+1);
            person.setBirth(ui->birthInput->date());
            if(!ui->isAliveCheckBox->isChecked()){
                person.setDeath(ui->deathInput->date());
            }

            if(moding == false){
                handler->addPerson(person);
            }
            else {
                qDebug() << person.getId() << person.getName() << person.getGender() << person.getBirth().toString("dd.MM.yyyy") << person.getDeath().toString("dd.MM.yyyy");
                handler->modifyPerson(person);
            }

            ui->addRelationButton->setEnabled(true);
            ui->saveButton->setText("Close");
        }
    }
    else if(ui->saveButton->text() == "Close")
        this->close();
}

void PersonWindow::displayPerson()
{
    ui->nameInput->setText(person.getName());
    if(person.getGender() == 1)
        ui->genderInput->setCurrentIndex(0);
    else if(person.getGender() == 2)
        ui->genderInput->setCurrentIndex(1);
    ui->birthInput->setDate(person.getBirth());
    if(!person.getDeath().isValid()){
        ui->isAliveCheckBox->setChecked(true);
    }
    else{
        ui->isAliveCheckBox->setChecked(false);
        ui->deathInput->setDate(person.getDeath());
    }
    ui->addRelationButton->setEnabled(true);
}
