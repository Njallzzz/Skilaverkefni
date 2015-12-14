#ifndef PERSONWINDOW_H
#define PERSONWINDOW_H

#include <QDialog>

namespace Ui {
class PersonWindow;
}

class PersonWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PersonWindow(QWidget *parent = 0);
    ~PersonWindow();

private:
    Ui::PersonWindow *ui;
};

#endif // PERSONWINDOW_H
