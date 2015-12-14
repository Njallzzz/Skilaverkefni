#ifndef COMPUTERWINDOW_H
#define COMPUTERWINDOW_H

#include "models/computer.h"
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
    void errorEmpty();
    bool error();

private slots:
    void on_pushButton_computer_save_clicked();
    void on_pushButton_computer_cancel_clicked();

private:
    Computer c;
    Ui::ComputerWindow *ui;
};

#endif // COMPUTERWINDOW_H
