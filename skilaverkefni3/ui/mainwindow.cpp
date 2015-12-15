#include "ui/mainwindow.h"
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

    connect(ui->people_list->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(people_on_sectionClicked( int )));
    connect(ui->computer_list->horizontalHeader(), SIGNAL(sectionClicked(int)), this, SLOT(computers_on_sectionClicked( int )));

    aWindow = new AboutWindow;

    ui->pushButton_delete_computer->setEnabled(false);
    ui->pushButton_modify_computer->setEnabled(false);
    ui->pushButton_delete_person->setEnabled(false);
    ui->pushButton_modify_person->setEnabled(false);
    ui->pushButton_clear_person->setEnabled(false);
    ui->pushButton_clear_computer->setEnabled(false);

    ui->date_birth_p->setEnabled(false);
    ui->date_death_p->setEnabled(false);
    ui->date_date_c->setEnabled(false);

    QString date = ui->date_birth_p->text();

    //Adds options to dorp-down lists
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

MainWindow::~MainWindow() {
    delete ui;
    delete model;
    delete handler;
    delete aWindow;
}

void MainWindow::on_actionCreate_Person_triggered()         //If create person is selected in the menu bar
{
    PersonWindow *pWindow = new PersonWindow;
    pWindow->getHandler( handler );
    pWindow->exec();
    delete pWindow;
}

void MainWindow::on_actionCreate_Computer_triggered()       //If create computer is selected in the menu bar
{
    ComputerWindow *cWindow = new ComputerWindow;
    cWindow->getHandler( handler );
    cWindow->exec();
    delete cWindow;
    displayComputers();
}

void MainWindow::display() {                            //to display all
    displayPeople();
}

void MainWindow::displayPeople() {                      //to display all, puts data into columns and rows
    vector<Person> &p = handler->getPeople();

    ui->pushButton_delete_person->setEnabled(false);
    ui->pushButton_modify_person->setEnabled(false);
    ui->pushButton_clear_person->setEnabled(false);
    handler->selectPerson(-1);
    displayComputers();

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
                model->setData( index, p[row].getBirth().toString("d.M.yyyy") );
            else if( col == 3 )
                model->setData( index, p[row].getDeath().toString("d.M.yyyy") );
        }
    }

    ui->people_list->setModel(model);
}

void MainWindow::displayComputers() {                       //to display computers, puts data into columns and rows
    vector<Computer> &c = handler->getComputers();

    ui->pushButton_delete_computer->setEnabled(false);
    ui->pushButton_modify_computer->setEnabled(false);
    ui->pushButton_clear_computer->setEnabled(false);

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

void MainWindow::resizeEvent( QResizeEvent* event ) {                   //resizes columns to fit data
    ui->people_list->setColumnWidth( 0, 120 + ( (this->width() - 790) / 2 ) );
    ui->people_list->setColumnWidth( 1, 60 );
    ui->people_list->setColumnWidth( 2, 80 );
    ui->people_list->setColumnWidth( 3, 80 );

    ui->computer_list->setColumnWidth( 0, 110 + ( (this->width() - 790) / 4 ) );
    ui->computer_list->setColumnWidth( 1, 110 + ( (this->width() - 790) / 4 ) );
    ui->computer_list->setColumnWidth( 2, 60 );
    ui->computer_list->setColumnWidth( 3, 40 );
    QMainWindow::resizeEvent(event);
}

void MainWindow::on_filter_birth_c_p_clicked() {                    //if peolple filtered by birth checkbox is checked
    if( ui->filter_birth_c_p->isChecked() ) {
        ui->date_birth_p->setEnabled(true);
        handler->peopleFilterBirth( ui->date_birth_p->date() );
    } else {
        ui->date_birth_p->setEnabled(false);
        handler->peopleFilterBirth( QDate() );
    }

    displayPeople();
}

void MainWindow::on_filter_death_c_p_clicked() {                 //if peolple filtered by death checkbox is checked
    if( ui->filter_death_c_p->isChecked() ) {
        ui->date_death_p->setEnabled(true);
        handler->peopleFilterDeath( ui->date_death_p->date() );
    } else {
        ui->date_death_p->setEnabled(false);
        handler->peopleFilterDeath( QDate() );
    }

    displayPeople();
}

void MainWindow::on_filter_date_c_c_clicked() {              //if computers filtered by year made checkbox is checked
    if( ui->filter_date_c_c->isChecked() ) {
        ui->date_date_c->setEnabled(true);
        handler->ComputerFilterDate( ui->date_date_c->date() );
    } else {
        ui->date_date_c->setEnabled(false);
        handler->ComputerFilterDate( QDate() );
    }

    displayComputers();
}

void MainWindow::on_people_list_clicked(const QModelIndex &index) {     //highlights a row in person if clicked and enables buttons below
    ui->pushButton_delete_person->setEnabled(true);                     //also displays computers linked to selected person
    ui->pushButton_modify_person->setEnabled(true);
    ui->pushButton_clear_person->setEnabled(true);
    handler->selectPerson( index.row() );
    displayComputers();
}

void MainWindow::on_computer_list_clicked() {                           //highlights a row in computer if clicked and enables buttons below
    ui->pushButton_delete_computer->setEnabled(true);
    ui->pushButton_modify_computer->setEnabled(true);
    ui->pushButton_clear_computer->setEnabled(true);
}

void MainWindow::on_filter_name_p_textEdited(const QString &arg1) { //filters people based on name typed into searchbox
    handler->peopleFilterName( arg1 );
    displayPeople();
}

void MainWindow::on_filter_name_c_textEdited(const QString &arg1) { //filters computers based on name typed into searchbox
    handler->ComputerFilterName( arg1 );
    displayComputers();
}

void MainWindow::on_date_birth_p_dateChanged(const QDate &date) { //filters people based on date of birth selected in searchbox
    handler->peopleFilterBirth( date );
    displayPeople();
}

void MainWindow::on_date_death_p_dateChanged(const QDate &date) { //filters people based on date of death selected in searchbox
    handler->peopleFilterDeath( date );
    displayPeople();
}

void MainWindow::on_filter_type_c_textEdited(const QString &arg1) { //filters computers based on type typed into searchbox
    handler->ComputerFilterType( arg1 );
    displayComputers();
}

void MainWindow::on_date_date_c_dateChanged(const QDate &date) {   //filters computers based on date built selected in searchbox
    handler->ComputerFilterDate( date );
    displayComputers();
}

void MainWindow::on_filter_built_c_activated(int index) {   //filters computers based on if built or not selected in drop-down list
    handler->ComputerFilterBuilt( index );
    displayComputers();
}

void MainWindow::on_filter_gender_p_activated(const QString &arg1) {    //filters people based on gender selected in dropbox
    handler->peopleFilterGender( arg1 );
    displayPeople();
}

void MainWindow::on_pushButton_delete_person_clicked() {                //Deletes person based on row selected
    QMessageBox confirm;
    confirm.setWindowTitle( "Delete a person" );
    confirm.setText("Are you sure you want to delete the selected person?");
    confirm.setStandardButtons(QMessageBox::Yes);
    confirm.addButton( QMessageBox::No );
    confirm.setDefaultButton( QMessageBox::No );

    if( confirm.exec() == QMessageBox::Yes ) {                      //If yes selected in "confirm" pop-up box then person is deleted
        handler->deletePerson( ui->people_list->currentIndex().row() );
        displayPeople();
    }
}

void MainWindow::on_pushButton_delete_computer_clicked() {          //Deletes computer based on row selected
    QMessageBox confirm;
    confirm.setWindowTitle( "Delete a computer" );
    confirm.setText("Are you sure you want to delete the selected computer?");
    confirm.setStandardButtons(QMessageBox::Yes);
    confirm.addButton( QMessageBox::No );
    confirm.setDefaultButton( QMessageBox::No );

    if( confirm.exec() == QMessageBox::Yes ) {                      //If yes is selected in "confirm" pop-up box then computer is deleted
        handler->deleteComputer( ui->computer_list->currentIndex().row() );
        displayComputers();
    }
}

void MainWindow::on_pushButton_clear_person_clicked() {             //Displays all people in database without filters
    ui->pushButton_clear_person->setEnabled(false);
    ui->pushButton_delete_person->setEnabled(false);
    ui->pushButton_modify_person->setEnabled(false);
    ui->people_list->setCurrentIndex( ui->people_list->model()->index(-1, 0) );
    handler->selectPerson(-1);
    displayComputers();
}

void MainWindow::on_pushButton_clear_computer_clicked() {           //Displays all computers in database without filters
    ui->pushButton_clear_computer->setEnabled(false);
    ui->pushButton_delete_computer->setEnabled(false);
    ui->pushButton_modify_computer->setEnabled(false);
    ui->computer_list->setCurrentIndex( ui->computer_list->model()->index(-1, 0) );
}

void MainWindow::on_actionAbout_triggered() {                   //Displays about window that provides info of the project
    aWindow->show();
}

void MainWindow::people_on_sectionClicked( int index ) {        //sorts people based on column title clicked
    handler->sortPerson( index );
    displayPeople();
}

void MainWindow::computers_on_sectionClicked( int index ) {     //sorts computers based on column title clicked
    handler->sortComputer( index );
    displayComputers();
}

void MainWindow::on_people_list_customContextMenuRequested(const QPoint &pos)   //Displays right click menu in people list
{
    QMenu menu;
    menu.addAction(ui->action_Add_Person);
    menu.addAction(ui->action_Refresh_People);

    menu.exec(ui->people_list->viewport()->mapToGlobal(pos));
}

void MainWindow::on_action_Add_Person_triggered()
{
    PersonWindow *pWindow = new PersonWindow;
    pWindow->getHandler( handler );
    pWindow->exec();
    delete pWindow;
    displayPeople();
}

void MainWindow::on_computer_list_customContextMenuRequested(const QPoint &pos) //Displays right click menu in computer list
{
    QMenu menu;
    menu.addAction(ui->action_Add_Computer);
    menu.addAction(ui->action_Refresh_Computers);

    menu.exec(ui->computer_list->viewport()->mapToGlobal(pos));
}

void MainWindow::on_action_Add_Computer_triggered()                             //Like create computer in menu bar except in the right click menu
{
    ComputerWindow *cWindow = new ComputerWindow;
    cWindow->getHandler( handler );
    cWindow->exec();
    delete cWindow;
    displayComputers();
}

void MainWindow::on_pushButton_modify_person_clicked()          //Allows the user to modify selected person
{
    PersonWindow *pWindow = new PersonWindow;
    Person p = handler->getPerson(ui->people_list->currentIndex().row());
    pWindow->getHandler( handler );
    pWindow->setPerson(p);

    pWindow->exec();
    delete pWindow;
    displayPeople();
}

void MainWindow::on_pushButton_modify_computer_clicked()        //Allows the user to modify selected computer
{
    ComputerWindow *cWindow = new ComputerWindow;
    cWindow->getHandler( handler );
    cWindow->setComputer( ui->computer_list->currentIndex().row() );
    cWindow->initalize();
    cWindow->exec();
    delete cWindow;
    displayComputers();
}

void MainWindow::on_action_Refresh_People_triggered()   // refresh list of people if for some reason it hasnt
{
    displayPeople();
}

void MainWindow::on_action_Refresh_Computers_triggered()    // refresh list of computers if for some reason it hasnt
{
    displayComputers();
}
