#include "xmlparser.h"

XMLParser::XMLParser( QString filename ) {
    file = filename;
    QFileInfo filelocation(file);
    if( !( filelocation.exists() && filelocation.isFile() ) )
        WriteEmpty();
}

int XMLParser::ReadDatabase( vector<Person> & list ) {
    container.setFileName( file );
    if ( !container.open( QIODevice::ReadOnly | QIODevice::Text ) )
        return 1;

    QXmlStreamReader stream(&container);
    while( (!stream.atEnd()) && (!stream.hasError()) ) {
        bool finished[4] = {false, false, false, false};
        Person temp;
        temp.deathyear = 0;

        //while(  )
        while( !stream.atEnd() && !stream.hasError() && !(finished[0] && finished[1] && finished[2] && finished[3]) ) {
            stream.readNext();

            if( finished[0] && finished[1] && finished[2] )
                finished[3] = true;

            if( stream.name().toString() == "Name" ) {
                temp.name = stream.readElementText();
                finished[0] = true;
            } else if( stream.name().toString() == "Gender" ) {
                if( stream.readElementText() == "Male" )
                    temp.gender = 0;
                else
                    temp.gender = 1;
                finished[1] = true;
            } else if( stream.name().toString() == "BirthYear" ) {
                temp.birthyear = stream.readElementText().toInt();
                finished[2] = true;
           } else if( stream.name().toString() == "DeathYear" ) {
                temp.deathyear = stream.readElementText().toInt();
                finished[3] = true;
           }
        }

        if( finished[0] ) {
            list.push_back(temp);
        }
    }

    if( stream.hasError() )
        return stream.error();

    container.close();
    return 0;
}

int XMLParser::WriteEntry( QString name, bool gender, int birthyear ) {
    container.setFileName( file );
    if ( !container.open(QIODevice::WriteOnly) )
        return 1;

    QXmlStreamWriter stream(&container);
    stream.setAutoFormatting(true);

    stream.writeStartDocument();
    stream.writeStartElement( "Data" );
    stream.writeStartElement( "Person" );

    stream.writeTextElement( "Name", name );
    if(gender)
        stream.writeTextElement( "Gender", "Female" );
    else
        stream.writeTextElement("Gender", "Male");
    stream.writeTextElement( "BirthYear", QString::number(birthyear) );

    stream.writeEndElement();
    stream.writeEndElement();
    stream.writeEndDocument();

    container.close();
    return 0;
}

int XMLParser::WriteEmpty() {
    container.setFileName( file );
    if ( !container.open(QIODevice::WriteOnly) )
        return 1;

    QXmlStreamWriter stream(&container);
    stream.setAutoFormatting(true);

    stream.writeStartDocument();
    stream.writeStartElement( "Data" );

    stream.writeEndElement();
    stream.writeEndDocument();

    container.close();
    return 0;
}
