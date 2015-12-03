#include "sqlitehandler.h"

SQLITEHandler::SQLITEHandler( QString filename ) {
    file = filename;
    status = false;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(file);
}

SQLITEHandler::~SQLITEHandler() {
    if( status == true )
        db.close();
}

int SQLITEHandler::SetDatabase( QString filename ) {
    if( status == true )
        return 1;
    file = filename;
    db.setDatabaseName(file);
    return 0;
}

int SQLITEHandler::connect() {
    if( db.open() )
        status = true;
    return status;
}

int SQLITEHandler::disconnect() {
    if( status == true ) {
        db.close();
        return 0;
    } else
    return 1;
}
