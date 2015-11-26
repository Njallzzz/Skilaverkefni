#include "xmlparser.h"

XMLParser::XMLParser( QString filename ) {
    file = filename;
    QFileInfo filelocation(file);
    if( !( filelocation.exists() && filelocation.isFile() ) )
        WriteEmpty();
}

int XMLParser::ReadDatabase( vector<Person> & list ) {
    container.setFileName( file );
    if ( !container.open( QIODevice::ReadOnly ) )
        return 1;

    QXmlStreamReader stream(&container);
    while( (!stream.atEnd()) && (!stream.hasError()) ) {
        bool finished[4] = {false, false, false, false};
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
    container.close();

    if( stream.hasError() )
        return stream.error();

    return 0;
}

int XMLParser::WriteEntry( Person add ) {
/*    container.setFileName( file );
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

    container.close();*/
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
