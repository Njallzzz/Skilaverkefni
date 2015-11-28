#include "xmlparser.h"

XMLParser::XMLParser() {            // Default constructor
    file = "";                      // Set empty filename
}

XMLParser::XMLParser( QString filename ) {  // Constructor
    file = filename;                        // Input filename to private member 'file'
    QFileInfo filelocation(file);                                   // File Information handler
    if( !( filelocation.exists() && filelocation.isFile() ) )       // If file doesn't exist and isn't a file then create a empty database
        WriteEmpty();
}

void XMLParser::SetDatabase( QString filename ) {           // Change database
    file = filename;                                        // Input filename to private member 'file'
    QFileInfo filelocation(file);                                   // File Information handler
    if( !( filelocation.exists() && filelocation.isFile() ) )       // If file doesn't exist and isn't a file then create a empty database
        WriteEmpty();
}

int XMLParser::ReadDatabase( vector<Person> & list ) {      // Read all entries in database file
    if( file == "" )                                        // If database has not been specified return error 1
        return 1;
    container.setFileName( file );                          // Set filename to access to handler
    if ( !container.open( QIODevice::ReadOnly ) )           // Attempt to access file with handler (if fail give error 2)
        return 2;

    list.clear();                                           // Empty 'vector<Person> list' for new entries
    QXmlStreamReader stream(&container);                    // Give XMLStreamReader file handler pointer
    while( (!stream.atEnd()) && (!stream.hasError()) ) {    // Read until end of file or error
        bool finished[4] = {false, false, false, false};    //
        Person temp;

        while( !stream.atEnd() && !stream.hasError() && !(finished[0] && finished[1] && finished[2] && finished[3]) ) {
            stream.readNext();

            if( finished[0] && finished[1] && finished[2] )
                finished[3] = true;
            //if( stream.name().toString() == "Person"  )
            //    finished[3] = true;

            if( stream.name().toString() == "Name" ) {
                temp.name = stream.readElementText();
                finished[0] = true;
            } else if( stream.name().toString() == "Gender" ) {
                if( stream.readElementText() == "Male" )
                    temp.gender = 0;
                else
                    temp.gender = 1;
                finished[1] = true;
            } else if( stream.name().toString() == "Birth" ) {
                temp.birth = QDate::fromString( stream.readElementText(), "dd.MM.yyyy" );
                finished[2] = true;
            } else if( stream.name().toString() == "Death" ) {
                temp.death = QDate::fromString( stream.readElementText(), "dd.MM.yyyy" );
                finished[3] = true;
            }
        }

        if( finished[0] ) {
            list.push_back(temp);
        }
    }
    container.close();                  // Close file handler

    if( stream.hasError() )             // If a error occured return its value
        return stream.error();

    return 0;                           // Return success
}

int XMLParser::WriteDatabase( vector<Person> & list ) {     // Write all entries in database file, warning: removes any missing entries if they are not present in vector
    if( file == "" )                                        // If database has not been specified return error 1
        return 1;
    container.setFileName( file );                          // Set filename to access to handler
    if ( !container.open(QIODevice::WriteOnly) )            // Attempt to access file with handler (if fail give error 2)
        return 2;

    QXmlStreamWriter stream(&container);                    // Give XMLStreamWriter file handler pointer
    stream.setAutoFormatting(true);                         // Use XML Spacing (tabs)

    stream.writeStartDocument();                            // Write XML Header
    stream.writeStartElement( "Data" );                     // Start 'Data' Element

    for(unsigned int x = 0; x < list.size(); x++) {         // Loop for all 'Person' Entry in vector
        stream.writeStartElement( "Person" );               // Write start of new element 'Person'
        stream.writeTextElement( "Name", list[x].name );    // Write name of person
        if( list[x].gender )                                // if gender = female then
            stream.writeTextElement( "Gender", "Female" );
        else                                                // else is male
            stream.writeTextElement("Gender", "Male");
        if( !list[x].death.isNull() )                       // If death of person is specified write date of death
            stream.writeTextElement( "Death", list[x].death.toString("dd.MM.yyyy") );
        stream.writeTextElement( "Birth", list[x].birth.toString("dd.MM.yyyy") );       // Write birth of person
        stream.writeEndElement();                           // Write end of element 'Person'
    }

    stream.writeEndElement();                               // Write end of element 'Data'
    stream.writeEndDocument();                              // Specify end of XML file

    container.close();                                      // Close file handler
    return 0;                                               // Return success
}

int XMLParser::AddEntry( Person person ) {                  // Adds a single entry into database
    if( file == "" )                                        // If database has not been specified return error 1
        return 1;
    vector<Person> temp;                                    // Create temporary vector
    int error = 0;
    error = this->ReadDatabase( temp );                // Read all entries in current database
    if(error)
        return error;
    temp.push_back( person );                               // Add entry to vector
    error = this->WriteDatabase( temp );               // Write all entries in vector to database
    if(error)
        return error;
      return 0;                                               // Return success
}

int XMLParser::RemoveEntry( QString name ) {            // Remove entry in database by name
    if( file == "" )                                    // If database has not been specified return error 1
        return 1;
    vector<Person> temp;                                // Create temporary vector
    int error = 0;
    error = this->ReadDatabase( temp );                 // Read all entries in current database
    if(error)
        return error;
    for(unsigned int x = 0; x < temp.size(); x++) {     // Check for each element in vector for a match
        if( name == temp[x].name )
            temp.erase( temp.begin() + x );          // delete entry if it matches
    }
    error = this->WriteDatabase( temp );                // Write all entries in vector to database
    if(error)
        return error;
    return 0;
}

int XMLParser::RemoveEntry( int index ) {
    if( file == "" )                                    // If database has not been specified return error 1
        return 1;
    vector<Person> temp;                                // Create temporary vector
    int error = 0;
    error = this->ReadDatabase( temp );                 // Read all entries in current database
    if(error)
        return error;
    if( index >= 0 && index < int(temp.size()) )         // Delete entry from database by index
        temp.erase( temp.begin() + index );
    else                                                // If the index is invalid return error 2
        return 2;
    error = this->WriteDatabase( temp );                // Write all entries in vector to database
    if(error)
        return error;
    return 0;
}

int XMLParser::WriteEmpty() {                       // Writes a empty database folder
    container.setFileName( file );                  // Set filename to access to handler
    if ( !container.open(QIODevice::WriteOnly) )    // Attempt to access file with handler (if fail give error 1)
        return 1;

    QXmlStreamWriter stream(&container);            // Give XMLStreamWriter file handler pointer
    stream.setAutoFormatting(true);                 // Use XML Spacing (tabs)

    stream.writeStartDocument();                    // Write XML Header
    stream.writeStartElement( "Data" );             // Start 'Data' Element
    stream.writeEndElement();                       // Write end of element 'Data'
    stream.writeEndDocument();                      // Specify end of XML file

    container.close();                              // Close file handler
    return 0;                                       // Return success
}
