#ifndef ABOUTWINDOW_H
#define ABOUTWINDOW_H

#include <QDialog>
#include <QPixmap>

//The about window diplays information regarding the project i.e. introdution, software version, who made it and a link to github page.

namespace Ui {
    class AboutWindow;
}

class AboutWindow : public QDialog {
    Q_OBJECT

public:
    explicit AboutWindow(QWidget *parent = 0);
    ~AboutWindow();

private:
    Ui::AboutWindow *ui;
};

#endif // ABOUTWINDOW_H
