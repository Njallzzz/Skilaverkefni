#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <QString>
#include <QFile>
#include <QFileInfo>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <vector>
#include "person.h"

// Debug
#include <iostream>

using namespace std;

class XMLParser {
public:
    //XMLParser( );
    XMLParser( QString filename );

    int ReadDatabase( vector<Person> & list );

    int WriteEntry( QString name, bool gender, int birthyear );
    int WriteEntry( QString name, bool gender, int birthyear, int deathyear );

private:
    int WriteEmpty();

    QString file;
    QFile container;
};

#endif // XMLPARSER_H
