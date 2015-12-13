#include "computerwindow.h"
#include "computer.h"
#include "ui_computerwindow.h"
#include <QDebug>

Computer c;

ComputerWindow::ComputerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputerWindow)
{
    ui->setupUi(this);
    errorEmpty();
}

ComputerWindow::~ComputerWindow()
{
    delete ui;
}

void ComputerWindow::errorEmpty(){
    ui->label_name_error_star->setText( "\0" );
    ui->label_type_error_star->setText( "\0" );
    ui->label_date_error_star->setText( "\0" );
    ui->label_built_error_star->setText( "\0" );
    ui->label_computer_error->setText( "\0");
}

bool ComputerWindow::error()
{
    errorEmpty();

    bool ifError = false;
    bool yes_checked = ui->radioButton_yes->isChecked();
    bool no_checked = ui->radioButton_no->isChecked();
    bool name_empty = ui->lineEdit_computer_name->text().isEmpty();
    bool type_empty = ui->lineEdit_computer_type->text().isEmpty();

    if( name_empty ){
        ui->label_name_error_star->setText( "<font color='red'>*</font>" );
        ifError = true;
    }
    if( type_empty ){
        ui->label_type_error_star->setText( "<font color='red'>*</font>" );
        ifError = true;
    }
    if( !yes_checked && !no_checked ){
        ui->label_built_error_star->setText( "<font color='red'>*</font>" );
        ifError = true;
    }
    if( ifError ){
        ui->label_computer_error->setText( "<font color='red'>*All textboxes and buttons must be filled in or checked</font>" );
    }
    return ifError;
}

void ComputerWindow::on_pushButton_computer_save_clicked()
{
    bool yes_checked = ui->radioButton_yes->isChecked();

    if ( !error() ) {
        c.setName( ui->lineEdit_computer_name->text() );
        c.setType( ui->lineEdit_computer_type->text() );
        c.setYear( ui->dateEdit_year_built->text() );
        if( yes_checked )
            c.setWasBuilt( 1 );
        else
            c.setWasBuilt( 0 );
        qDebug() << c.getName();
        qDebug() << c.getType();
        qDebug() << c.getYear();
        qDebug() << c.getWasBuilt();
    }
}

void ComputerWindow::on_pushButton_computer_cancel_clicked()
{
    //QDialog::reject();
}
