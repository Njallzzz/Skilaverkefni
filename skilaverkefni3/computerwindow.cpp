#include "computerwindow.h"
#include "ui_computerwindow.h"

ComputerWindow::ComputerWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ComputerWindow)
{
    ui->setupUi(this);
}

ComputerWindow::~ComputerWindow()
{
    delete ui;
}

void ComputerWindow::on_radioButton_yes_toggled(bool checked)
{
 //   if(checked)

}
