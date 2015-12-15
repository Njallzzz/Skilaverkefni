#include "ui/computerwindow.h"
#include "ui_computerwindow.h"

ComputerWindow::ComputerWindow(QWidget *parent) : QDialog(parent), ui(new Ui::ComputerWindow) {
    ui->setupUi(this);
    this->setWindowFlags( Qt::WindowTitleHint | Qt::WindowCloseButtonHint );
    errorEmpty();
    indexComputer = -1;                     //Saves index to modify computer, if index = -1 then no computer is selected
}

void ComputerWindow::initalize(){                                       //To modify a computer, enters all info from selected computer
    comp = handler->getComputer( indexComputer );
    ui->groupBox_newComputer->setTitle( "Modify Computer" );
    ui->lineEdit_computer_name->setText( comp.getName() );
    ui->lineEdit_computer_type->setText( comp.getType() );
    ui->dateEdit_year_built->setDate( QDate::fromString( comp.getYear(), "yyyy" ) );
    if( comp.getWasBuilt() )
        ui->radioButton_yes->setChecked( 1 );
    else
        ui->radioButton_no->setChecked( 1 );
}

ComputerWindow::~ComputerWindow() {
    delete ui;
}

void ComputerWindow::errorEmpty() {                     //Clear all error messages
    ui->label_name_error_star->setText( "\0" );
    ui->label_type_error_star->setText( "\0" );
    ui->label_date_error_star->setText( "\0" );
    ui->label_built_error_star->setText( "\0" );
    ui->label_computer_error->setText( "\0");
}

bool ComputerWindow::error() {                          //Error handling and diplays error messages
    errorEmpty();

    bool ifError = false;
    bool yes_checked = ui->radioButton_yes->isChecked();
    bool no_checked = ui->radioButton_no->isChecked();
    bool name_empty = ui->lineEdit_computer_name->text().isEmpty();
    bool type_empty = ui->lineEdit_computer_type->text().isEmpty();
    bool date_empty = ui->dateEdit_year_built->text().isEmpty();

    if( name_empty ){
        ui->label_name_error_star->setText( "<font color='red'>*</font>" );
        ifError = true;
    }
    if( type_empty ){
        ui->label_type_error_star->setText( "<font color='red'>*</font>" );
        ifError = true;
    }
    if( date_empty ) {
        ui->label_date_error_star->setText( "<font color='red'>*</font>" );
        ifError = true;
    }
    if( !yes_checked && !no_checked ){
        ui->label_built_error_star->setText( "<font color='red'>*</font>" );
        ifError = true;
    }
    if( ifError ){
        ui->label_computer_error->setText( "<font color='red'>*All information must be filled in</font>" );
    }
    return ifError;
}

void ComputerWindow::on_pushButton_computer_save_clicked() {    //Saves all information inserted to sql database file
    bool yes_checked = ui->radioButton_yes->isChecked();

    if ( !error() ) {
        comp.setName( ui->lineEdit_computer_name->text() );
        comp.setType( ui->lineEdit_computer_type->text() );
        comp.setYear( ui->dateEdit_year_built->text() );
        if( yes_checked )
            comp.setWasBuilt( 1 );
        else
            comp.setWasBuilt( 0 );

        if( indexComputer > -1 )                //used if index is pre-selected
            handler->modifyComputer( comp );
        else                                    //else
            handler->addComputer( comp );
        this->hide();
    }
}

void ComputerWindow::on_pushButton_computer_cancel_clicked() {      //Closes window if cancel button is selected
    this->hide();
}

void ComputerWindow::getHandler( Interface *h ){                    //creates a new handler to interact with Interface.cpp
    handler = h;
}

void ComputerWindow::setComputer( int index ){                      //Set index of computer for modify function
    indexComputer = index;
}
