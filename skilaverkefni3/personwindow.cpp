#include "personwindow.h"
#include "ui_personwindow.h"

PersonWindow::PersonWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PersonWindow)
{
    ui->setupUi(this);
    ui->genderInput->addItem("Male");
    ui->genderInput->addItem("Female");
}

PersonWindow::~PersonWindow()
{
    delete ui;
}
