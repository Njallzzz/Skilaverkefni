#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    model = new QStandardItemModel(10,4,this);

    model->setHeaderData( 0, Qt::Horizontal, "Name" );
    model->setHeaderData( 1, Qt::Horizontal, "Gender" );
    model->setHeaderData( 2, Qt::Horizontal, "Birth" );
    model->setHeaderData( 3, Qt::Horizontal, "Death" );

    for(int row = 0; row < 10; row++){
        for(int col = 0; col < 2; col++) {
            QModelIndex index = model->index( row, col, QModelIndex() );
            model->setData( index, "hello" );
        }
    }

    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionCreate_Person_triggered()
{
    PersonWindow *pWindow = new PersonWindow;
    pWindow->exec();
}
