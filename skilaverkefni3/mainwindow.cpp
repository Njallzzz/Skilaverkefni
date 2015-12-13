#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);

    ui->people_list->setEditTriggers( QAbstractItemView::NoEditTriggers );
    ui->people_list->verticalHeader()->setSectionResizeMode( QHeaderView::Fixed );
    ui->people_list->horizontalHeader()->setStretchLastSection( true );
    ui->people_list->setSelectionBehavior( QAbstractItemView::SelectRows  );
    ui->computer_list->setEditTriggers( QAbstractItemView::NoEditTriggers );
    ui->computer_list->verticalHeader()->setSectionResizeMode( QHeaderView::Fixed );
    ui->computer_list->horizontalHeader()->setStretchLastSection( true );
    ui->computer_list->setSelectionBehavior( QAbstractItemView::SelectRows  );

    ui->pushButton_delete_computer->setEnabled(false);
    ui->pushButton_modify_computer->setEnabled(false);
    ui->pushButton_delete_person->setEnabled(false);
    ui->pushButton_modify_person->setEnabled(false);

    ui->date_birth_p->setEnabled(false);
    ui->date_death_p->setEnabled(false);
    ui->date_date_c->setEnabled(false);

    ui->filter_gender_p->addItem( "" );
    ui->filter_gender_p->addItem( "Male" );
    ui->filter_gender_p->addItem( "Female" );

    ui->filter_built_c->addItem( "" );
    ui->filter_built_c->addItem( "Yes" );
    ui->filter_built_c->addItem( "No" );

    handler = new Interface();
    handler->Initialize();

    display();
}

MainWindow::~MainWindow()
{
    delete ui;
    delete model;
    delete handler;
}

void MainWindow::on_actionCreate_Person_triggered()
{
    PersonWindow *pWindow = new PersonWindow;
    pWindow->exec();
}

void MainWindow::on_actionCreate_Computer_triggered()
{
    ComputerWindow *cWindow = new ComputerWindow;
    cWindow->exec();
}

void MainWindow::display() {
    displayPeople();
    displayComputers();
}

void MainWindow::displayPeople() {
    vector<Person> p;

    handler->getPeople( p );

    model = new QStandardItemModel( p.size(), 4, this);

    model->setHeaderData( 0, Qt::Horizontal, "Name" );
    model->setHeaderData( 1, Qt::Horizontal, "Gender" );
    model->setHeaderData( 2, Qt::Horizontal, "Birth" );
    model->setHeaderData( 3, Qt::Horizontal, "Death" );

    for(unsigned int row = 0; row < p.size(); row++){
        for(int col = 0; col < 4; col++) {
            QModelIndex index = model->index( row, col, QModelIndex() );
            if( col == 0 )
                model->setData( index, p[row].getName() );
            else if( col == 1 ) {
                if( p[row].getGender() == 1 )
                    model->setData( index, "Male" );
                else if( p[row].getGender() == 2 )
                    model->setData( index, "Female" );
                else
                    model->setData( index, "Unspecified" );
            } else if( col == 2 )
                model->setData( index, p[row].getBirth() );
            else if( col == 3 )
                model->setData( index, p[row].getDeath() );
        }
    }

    ui->people_list->setModel(model);
}

void MainWindow::displayComputers() {
    vector<Computer> c;
    handler->getComputers( c );

    model = new QStandardItemModel( c.size(), 4, this);

    model->setHeaderData( 0, Qt::Horizontal, "Name" );
    model->setHeaderData( 1, Qt::Horizontal, "Type" );
    model->setHeaderData( 2, Qt::Horizontal, "Date" );
    model->setHeaderData( 3, Qt::Horizontal, "Built" );

    for(unsigned int row = 0; row < c.size(); row++){
        for(int col = 0; col < 4; col++) {
            QModelIndex index = model->index( row, col, QModelIndex() );
            if( col == 0 )
                model->setData( index, c[row].getName() );
            else if( col == 1 )
                model->setData( index, c[row].getType() );
            else if( col == 2 )
                model->setData( index, c[row].getYear() );
            else if( col == 3 ) {
                if( c[row].getWasBuilt() == 0 )
                    model->setData( index, "No" );
                else if( c[row].getWasBuilt() == 1 )
                    model->setData( index, "Yes" );
                else if( c[row].getWasBuilt() == 2 )
                    model->setData( index, "Unspecfified" );
            }
        }
    }

    ui->computer_list->setModel(model);
}


void MainWindow::resizeEvent( QResizeEvent* event ) {
    ui->people_list->setColumnWidth( 0, 140 + ( (this->width() - 790) / 2 ) );
    ui->people_list->setColumnWidth( 1, 50 );
    ui->people_list->setColumnWidth( 2, 70 );
    ui->people_list->setColumnWidth( 3, 70 );

    ui->computer_list->setColumnWidth( 0, 125 + ( (this->width() - 790) / 4 ) );
    ui->computer_list->setColumnWidth( 1, 125 + ( (this->width() - 790) / 4 ) );
    ui->computer_list->setColumnWidth( 2, 40 );
    ui->computer_list->setColumnWidth( 3, 40 );
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_filter_birth_c_p_clicked() {
    if( ui->filter_birth_c_p->isChecked() ) {
        ui->date_birth_p->setEnabled(true);
        handler->peopleFilterBirth( ui->date_birth_p->date() );
    } else {
        ui->date_birth_p->setEnabled(false);
        handler->peopleFilterBirth( QDate() );
    }

    displayPeople();
}

void MainWindow::on_filter_death_c_p_clicked() {
    if( ui->filter_death_c_p->isChecked() ) {
        ui->date_death_p->setEnabled(true);
        handler->peopleFilterDeath( ui->date_death_p->date() );
    } else {
        ui->date_death_p->setEnabled(false);
        handler->peopleFilterDeath( QDate() );
    }

    displayPeople();
}

void MainWindow::on_filter_date_c_c_clicked() {
    if( ui->filter_date_c_c->isChecked() ) {
        ui->date_date_c->setEnabled(true);
        handler->ComputerFilterDate( ui->date_date_c->date() );
    } else {
        ui->date_date_c->setEnabled(false);
        handler->ComputerFilterDate( QDate() );
    }

    displayComputers();
}

void MainWindow::on_people_list_clicked(const QModelIndex &index) {
    ui->pushButton_delete_person->setEnabled(true);
    ui->pushButton_modify_person->setEnabled(true);
    qDebug() << "Person: " << index.row();
}

void MainWindow::on_computer_list_clicked(const QModelIndex &index) {
    ui->pushButton_delete_computer->setEnabled(true);
    ui->pushButton_modify_computer->setEnabled(true);
    qDebug() << "Computer: " << index.row();
}

void MainWindow::on_filter_name_p_textEdited(const QString &arg1) {
    handler->peopleFilterName( arg1 );
    displayPeople();
}

void MainWindow::on_filter_name_c_textEdited(const QString &arg1) {
    handler->ComputerFilterName( arg1 );
    displayComputers();
}

void MainWindow::on_date_birth_p_dateChanged(const QDate &date) {
    handler->peopleFilterBirth( date );
    displayPeople();
}

void MainWindow::on_date_death_p_dateChanged(const QDate &date) {
    handler->peopleFilterDeath( date );
    displayPeople();
}

void MainWindow::on_filter_type_c_textEdited(const QString &arg1) {
    handler->ComputerFilterType( arg1 );
    displayComputers();
}

void MainWindow::on_date_date_c_dateChanged(const QDate &date) {
    handler->ComputerFilterDate( date );
    displayComputers();
}

void MainWindow::on_filter_built_c_activated(int index) {
    handler->ComputerFilterBuilt( index );
    displayComputers();
}

void MainWindow::on_filter_gender_p_activated(const QString &arg1) {
    handler->peopleFilterGender( arg1 );
    displayPeople();
}

// DEBUG BUTTON FUNCTIONS HERE (REMEMBER TO REMOVE BEFORE RELEASE)
void MainWindow::on_pushButton_3_clicked() {
    PersonWindow *pWindow = new PersonWindow;
    pWindow->exec();
}

void MainWindow::on_pushButton_2_clicked() {
    ComputerWindow *cWindow = new ComputerWindow;
    cWindow->exec();
}
// ~DEBUG BUTTON FUNCTIONS HERE (REMEMBER TO REMOVE BEFORE RELEASE)
