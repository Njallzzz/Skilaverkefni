#ifndef COMPUTERWINDOW_H
#define COMPUTERWINDOW_H

#include <QDialog>

namespace Ui {
class ComputerWindow;
}

class ComputerWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ComputerWindow(QWidget *parent = 0);
    ~ComputerWindow();

private:
    Ui::ComputerWindow *ui;
};

#endif // COMPUTERWINDOW_H
