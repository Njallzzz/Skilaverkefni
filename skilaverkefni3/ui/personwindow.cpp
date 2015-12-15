#include "ui/personwindow.h"
#include "ui_personwindow.h"

PersonWindow::PersonWindow(QWidget *parent) : QDialog(parent), ui(new Ui::PersonWindow) {
    ui->setupUi(this);
    this->setWindowFlags( Qt::WindowTitleHint | Qt::WindowCloseButtonHint );

    ui->genderInput->addItem("Male");
    ui->genderInput->addItem("Female");

    ui->deathInput->setEnabled(true);
    ui->addRelationButton->setEnabled(false);

    //modifying or adding user
    moding = false;
}

PersonWindow::~PersonWindow() {
    delete ui;
}

//set which person this information belongs to
void PersonWindow::setPerson(Person p)
{
    moding = true;
    person = p;
    ui->label_top->setText("Modify person");
    displayPerson();
}

//get an instance of the service class
void PersonWindow::getHandler(Interface *h)
{
    handler = h;
}

void PersonWindow::on_addRelationButton_clicked()
{
    PersonAddRelation *rel = new PersonAddRelation;
    rel->setHandler( handler );
    rel->setPerson(person);
    rel->exec();
}

//toggles whether you can enter anything into the death column
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

    if(ui->saveButton->text() == "Save"){       //check wheather the button should save the person or close the window
        bool valid = true;

        //validation for input
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
                handler->modifyPerson(person);
            }

            ui->addRelationButton->setEnabled(true);
            person = handler->getLatestPerson();
            ui->saveButton->setText("Close");       //Change buttons text to "Close when a person is saved"
        }
    }
    else if(ui->saveButton->text() == "Close")
        this->close();
}
//insert correct information into the edit boxes
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
