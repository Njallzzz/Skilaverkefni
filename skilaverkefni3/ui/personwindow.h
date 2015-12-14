#ifndef PERSONWINDOW_H
#define PERSONWINDOW_H

#include <QDialog>
#include "personaddrelation.h"

namespace Ui {
class PersonWindow;
}

class PersonWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PersonWindow(QWidget *parent = 0);
    ~PersonWindow();

private slots:
    void on_addRelationButton_clicked();

    void on_isAliveCheckBox_toggled(bool checked);

    void on_cancelButton_clicked();

    void on_saveButton_clicked();

private:
    Ui::PersonWindow *ui;
};

#endif // PERSONWINDOW_H
