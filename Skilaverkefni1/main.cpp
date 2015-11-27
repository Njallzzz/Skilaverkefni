#include <QCoreApplication>
#include <QDebug>
#include "xmlparser.h"
#include "person.h"

using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);

    XMLParser database( "database.xml   " );
    //database.WriteEntry( name, 0, 1993 );
    //database.WriteEntry( "Anna", 1, 1995 );

    vector<Person> list;
    if( database.ReadDatabase( list ) )
        qDebug() << "Error!" << endl;

    for(unsigned int x = 0; x < list.size(); x++) {
        qDebug() << "Name: " << list[x].name;
        if( list[x].gender )
            qDebug() << "Gender: Female";
        else
            qDebug() << "Gender: Male";
        qDebug() << "Birth Year: " << list[x].birth.toString("dd.MM.yyyy");
        qDebug() << "Death Year: " << list[x].death.toString("dd.MM.yyyy") << endl;
    }


    qDebug() << "End of Program";
    return a.exec();
}
