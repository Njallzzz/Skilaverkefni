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

using namespace std;

class XMLParser {                               // XML Database Class
public:
    XMLParser();                                // Default constructor
    XMLParser( QString filename );              // Second constructor, Select database filename, accessed in same directory as executable

    void SetDatabase( QString filename );       // Change database

    int ReadDatabase( vector<Person> & list );  // Read all entries in database file
    int WriteDatabase( vector<Person> & list ); // Write all entries in database file, warning: removes any missing entries if they are not present in vector

    int AddEntry( Person person );              // Adds a single entry into database
    int RemoveEntry( QString name );            // Remove entries from database by name
    int RemoveEntry( int index );               // Remove a single entry from database by index
    int ModifyEntry( int index, Person person );// Change the entry of a person in the database
private:
    int WriteEmpty();                           // Writes a empty database folder

    QString file;                               // Stores filename of database
    QFile container;                            // File handler for database access
};

#endif // XMLPARSER_H
