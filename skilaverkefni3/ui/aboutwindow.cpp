#include "aboutwindow.h"
#include "ui_aboutwindow.h"

//The about window diplays information regarding the project i.e. introdution, software version, who made it and a link to github page.

AboutWindow::AboutWindow(QWidget *parent) : QDialog(parent), ui(new Ui::AboutWindow) {
    ui->setupUi(this);
    this->setWindowFlags( Qt::WindowTitleHint | Qt::WindowCloseButtonHint );
    ui->label_url->setTextInteractionFlags( Qt::TextBrowserInteraction );
    ui->label_url->setOpenExternalLinks(true);
    ui->image_label->setScaledContents(true);
    ui->image_label->setPixmap( QPixmap(":/rocks.jpg") );
}

AboutWindow::~AboutWindow() {
    delete ui;
}
