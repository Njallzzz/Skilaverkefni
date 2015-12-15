#ifndef COMPUTERWINDOW_H
#define COMPUTERWINDOW_H

#include "models/computer.h"
#include "services/interface.h"
#include <QDialog>
#include <QDebug>

namespace Ui {
    class ComputerWindow;
}

class ComputerWindow : public QDialog {
    Q_OBJECT

public:
    explicit ComputerWindow(QWidget *parent = 0);
    ~ComputerWindow();
    void errorEmpty();                      //Clears all error messages
    bool error();                           //Error handling and diplays error messages
    void getHandler( Interface *h );        //Creates a new handler to interact with Interface.cpp
    void setComputer( int index );          //Set index of computer for modify function
    void initalize();                       //To modify a computer, enters all info from selected computer

private slots:  //Buttons that can be clicked
    void on_pushButton_computer_save_clicked();     //Saves all information inserted to sql database file
    void on_pushButton_computer_cancel_clicked();   //Closes window if cancel button is selected

private:
    int indexComputer;      //Used to hold index when modifying
    Computer comp;          //Used to hold an instnase of computer from computer vector based on selted index, when modifying
    Interface *handler;     //Used to interact with interface class
    Ui::ComputerWindow *ui;
};

#endif // COMPUTERWINDOW_H
