#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QDebug>
#include <QtCore>
#include <QtGui>
#include "services/interface.h"
#include "ui/personwindow.h"
#include "ui/computerwindow.h"
#include "ui/aboutwindow.h"
#include <QMenu>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    void display();                 //to display all

private slots:
    void on_actionCreate_Person_triggered();            //if create person is selected in the menu bar
    void on_actionCreate_Computer_triggered();          //if create computer is selected in the menu bar
    void on_filter_birth_c_p_clicked();                 //if peolple filtered by birth checkbox is checked
    void on_filter_death_c_p_clicked();                 //if peolple filtered by death checkbox is checked
    void on_filter_date_c_c_clicked();                  //if computers filtered by year made checkbox is checked
    void on_people_list_clicked(const QModelIndex &index);  //highlights a row in person if clicked and enables buttons below and computers linked to selected person
    void on_computer_list_clicked();                        //highlights a row in computer if clicked and enables buttons below
    void on_filter_name_p_textEdited(const QString &arg1);  //filters people based on name typed into searchbox
    void on_filter_name_c_textEdited(const QString &arg1);  //filters computers based on name typed into searchbox
    void on_date_birth_p_dateChanged(const QDate &date);    //filters people based on date of birth selected in searchbox
    void on_date_death_p_dateChanged(const QDate &date);    //filters people based on date of death selected in searchbox
    void on_filter_type_c_textEdited(const QString &arg1);  //filters computers based on type typed into searchbox
    void on_date_date_c_dateChanged(const QDate &date);     //filters computers based on date built selected in searchbox
    void on_filter_built_c_activated(int index);            //filters computers based on if built or not selected in drop-down list
    void on_filter_gender_p_activated(const QString &arg1); //filters people based on gender selected in dropbox
    void on_pushButton_delete_person_clicked();             //Deletes person based on row selected
    void on_pushButton_delete_computer_clicked();           //Deletes computer based on row selected
    void on_pushButton_clear_person_clicked();              //Unselects all in person list and drops filters
    void on_pushButton_clear_computer_clicked();            //Unselects all in computers list and drops filtes
    void on_actionAbout_triggered();                        //Displays "about window" that provides info of the project
    void people_on_sectionClicked( int index );             //Sorts people based on column title clicked
    void computers_on_sectionClicked( int index );          //Sorts computers based on column title clicked
    void on_people_list_customContextMenuRequested(const QPoint &pos);  //Displays right click menu in people list
    void on_action_Add_Person_triggered();                              //Like create computer in menu bar except in the right click menu
    void on_computer_list_customContextMenuRequested(const QPoint &pos);    //Displays right click menu in computer list
    void on_action_Add_Computer_triggered();                            //Like create computer in menu bar except in the right click menu
    void on_pushButton_modify_person_clicked();                         //Allows the user to modify selected person
    void on_pushButton_modify_computer_clicked();                       //Allows the user to modify selected computer
    void on_action_Refresh_People_triggered();                          //Refresh list of people if for some reason it hasnt
    void on_action_Refresh_Computers_triggered();                       //Refresh list of computers if for some reason it hasnt

private:
    void resizeEvent( QResizeEvent* event );

    Interface *handler;
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    AboutWindow *aWindow;

    void displayPeople();           //to display(/refresh ) all, puts data into columns and rows
    void displayComputers();         //to display(/refresh ) computers, puts data into columns and rows
};

#endif // MAINWINDOW_H
