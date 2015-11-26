#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QDate>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <vector>
#include "person.h"

// Debug
#include <QDebug>

using namespace std;

class XMLParser {
public:
    //XMLParser( );
    XMLParser( QString filename );

    int ReadDatabase( vector<Person> & list );
    int WriteEntry( Person add );

private:
    int WriteEmpty();

    QString file;
    QFile container;
};

#endif // XMLPARSER_H
