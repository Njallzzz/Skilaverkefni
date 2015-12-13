#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QtCore>
#include <QtGui>
#include "interface.h"
#include "personwindow.h"
#include "computerwindow.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    ~MainWindow();

    void display();

private slots:
    void on_actionCreate_Person_triggered();
    void on_actionCreate_Computer_triggered();
    void on_filter_birth_c_p_clicked();
    void on_filter_death_c_p_clicked();
    void on_filter_date_c_c_clicked();
    void on_people_list_clicked(const QModelIndex &index);
    void on_computer_list_clicked(const QModelIndex &index);
    void on_filter_name_p_textEdited(const QString &arg1);
    void on_filter_name_c_textEdited(const QString &arg1);
    void on_date_birth_p_dateChanged(const QDate &date);
    void on_date_death_p_dateChanged(const QDate &date);
    void on_filter_type_c_textEdited(const QString &arg1);
    void on_date_date_c_dateChanged(const QDate &date);
    void on_filter_built_c_activated(int index);
    void on_filter_gender_p_activated(const QString &arg1);
    // DEBUG BUTTON FUNCTIONS HERE (REMEMBER TO REMOVE BEFORE RELEASE)
    void on_pushButton_3_clicked();
    void on_pushButton_2_clicked();
    // ~DEBUG BUTTON FUNCTIONS HERE (REMEMBER TO REMOVE BEFORE RELEASE)

    void on_pushButton_delete_person_clicked();

    void on_pushButton_delete_computer_clicked();

private:
    void resizeEvent( QResizeEvent* event );

    Interface *handler;
    Ui::MainWindow *ui;
    QStandardItemModel *model;

    void displayPeople();
    void displayComputers();
};

#endif // MAINWINDOW_H
