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

    void display();

private slots:
    void on_actionCreate_Person_triggered();
    void on_actionCreate_Computer_triggered();
    void on_filter_birth_c_p_clicked();
    void on_filter_death_c_p_clicked();
    void on_filter_date_c_c_clicked();
    void on_people_list_clicked(const QModelIndex &index);
    void on_computer_list_clicked();
    void on_filter_name_p_textEdited(const QString &arg1);
    void on_filter_name_c_textEdited(const QString &arg1);
    void on_date_birth_p_dateChanged(const QDate &date);
    void on_date_death_p_dateChanged(const QDate &date);
    void on_filter_type_c_textEdited(const QString &arg1);
    void on_date_date_c_dateChanged(const QDate &date);
    void on_filter_built_c_activated(int index);
    void on_filter_gender_p_activated(const QString &arg1);
    void on_pushButton_delete_person_clicked();
    void on_pushButton_delete_computer_clicked();
    void on_pushButton_clear_person_clicked();
    void on_pushButton_clear_computer_clicked();
    void on_actionAbout_triggered();
    void people_on_sectionClicked( int index );
    void computers_on_sectionClicked( int index );

    void on_people_list_customContextMenuRequested(const QPoint &pos);

    void on_action_Add_Person_triggered();

    void on_computer_list_customContextMenuRequested(const QPoint &pos);

    void on_action_Add_Computer_triggered();

private:
    void resizeEvent( QResizeEvent* event );

    Interface *handler;
    Ui::MainWindow *ui;
    QStandardItemModel *model;
    AboutWindow *aWindow;

    void displayPeople();
    void displayComputers();
};

#endif // MAINWINDOW_H
