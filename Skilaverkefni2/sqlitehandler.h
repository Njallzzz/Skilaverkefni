#ifndef SQLITEHANDLER_H
#define SQLITEHANDLER_H

#include <QString>
#include <QtSql>

class SQLITEHandler {
public:
    SQLITEHandler( QString filename );
    ~SQLITEHandler();
    int connect();
    int disconnect();
    int SetDatabase( QString filename );

private:
    QString file;
    bool status;
    QSqlDatabase db;
};

#endif // SQLITEHANDLER_H
