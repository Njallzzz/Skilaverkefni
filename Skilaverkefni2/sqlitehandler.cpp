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
    if(status)
        return 1;

    if( db.open() ) {
        status = true;
        q = QSqlQuery();
    } else
        status = false;
    return !status;
}

int SQLITEHandler::disconnect() {
    if( status == true ) {
        db.close();
        return 0;
    } else
    return 1;
}

int SQLITEHandler::readDatabase( vector<Person> & people, sorting s1, sorting s2 ) {
    if( !status )
        return 1;
    if( s1 == NAME_ASC )
        q.prepare("SELECT * FROM people ORDER BY name COLLATE NOCASE ASC");
    else if( s1 == NAME_DESC )
        q.prepare("SELECT * FROM people ORDER BY name COLLATE NOCASE DESC");
    else if( s1 == GENDER_ASC )
        q.prepare("SELECT * FROM people ORDER BY gender COLLATE NOCASE ASC");
    else if( s1 == GENDER_DESC )
        q.prepare("SELECT * FROM people ORDER BY gender COLLATE NOCASE DESC");
    else if( s1 == BIRTH_ASC )
        q.prepare("SELECT * FROM people ORDER BY birth COLLATE NOCASE ASC");
    else if( s1 == BIRTH_DESC )
        q.prepare("SELECT * FROM people ORDER BY birth COLLATE NOCASE DESC");
    else if( s1 == DEATH_ASC )
        q.prepare("SELECT * FROM people ORDER BY death COLLATE NOCASE ASC");
    else if( s1 == DEATH_DESC )
        q.prepare("SELECT * FROM people ORDER BY death COLLATE NOCASE DESC");
    else
        return 2;
    if( !q.exec() )
        return 3;

    int ref[5];
    ref[0] = q.record().indexOf("id");
    ref[1] = q.record().indexOf("name");
    ref[2] = q.record().indexOf("gender");
    ref[3] = q.record().indexOf("birth");
    ref[4] = q.record().indexOf("death");

    while( q.next() ) {
        int id = q.value( ref[0] ).toInt(),
            gender = q.value( ref[2] ).toInt();
        QString name = q.value( ref[1] ).toString();
        QDate birth = QDate::fromString( q.value( ref[3] ).toString(), "yyyy-mm-dd" ),
              death = QDate::fromString( q.value( ref[4] ).toString(), "yyyy-mm-dd" );

        Person p( id, name, gender, birth, death  );
        people.push_back( p );
    }
    return 0;
}

int SQLITEHandler::readDatabase( std::vector<Computer> & computers, sorting s1, sorting s2 ) {      // Yet to add sorting for s2
    if( !status )
        return 1;
    if( s1 == NAME_ASC )
        q.prepare("SELECT * FROM computers ORDER BY name COLLATE NOCASE ASC");
    else if( s1 == NAME_DESC )
        q.prepare("SELECT * FROM computers ORDER BY name COLLATE NOCASE DESC");
    else if( s1 == CREATION_ASC )
        q.prepare("SELECT * FROM computers ORDER BY creation COLLATE NOCASE ASC");
    else if( s1 == CREATION_DESC )
        q.prepare("SELECT * FROM computers ORDER BY creation COLLATE NOCASE DESC");
    else if( s1 == TYPE_ASC )
        q.prepare("SELECT * FROM computers ORDER BY type COLLATE NOCASE ASC");
    else if( s1 == TYPE_DESC )
        q.prepare("SELECT * FROM computers ORDER BY type COLLATE NOCASE DESC");
    else if( s1 == CONSTRUCTED_ASC )
        q.prepare("SELECT * FROM computers ORDER BY constructed COLLATE NOCASE ASC");
    else if( s1 == CONSTRUCTED_DESC )
        q.prepare("SELECT * FROM computers ORDER BY constructed COLLATE NOCASE DESC");
    else
        return 2;
    if( !q.exec() )
        return 3;

    int ref[5];
    ref[0] = q.record().indexOf("id");
    ref[1] = q.record().indexOf("name");
    ref[2] = q.record().indexOf("creation");
    ref[3] = q.record().indexOf("type");
    ref[4] = q.record().indexOf("constructed");

    while( q.next() ) {
        int id = q.value( ref[0] ).toInt();
        QString name = q.value( ref[1] ).toString(),
                type = q.value( ref[3] ).toString();
        QDate date = QDate::fromString( q.value( ref[2] ).toString(), "yyyy" );
        bool constructed = q.value( ref[4] ).toBool();

        Computer t( id, name, date, type, constructed  );
        computers.push_back( t );
    }
    return 0;
}

int SQLITEHandler::addEntry( Computer comp ) {
    if( !status )
        return 1;
    q.prepare( "INSERT INTO computers (name, creation, type, constructed) VALUES (:name, :creation, :type, :constructed)" );
    q.bindValue( ":name", comp.getName() );
    q.bindValue( ":creation", comp.getYear() );
    q.bindValue( ":type", comp.getType() );
    q.bindValue( ":constructed", comp.getWasBuilt() );
    if( !q.exec() )
        return 1;
    return 0;
}

int SQLITEHandler::addEntry( Person p ) {
    if( !status )
        return 1;
    q.prepare( "INSERT INTO people (name, gender, birth, death) VALUES (:name, :gender, :birth, :death)" );
    q.bindValue( ":name", p.getName() );
    if( p.getGender() == 1 )
        q.bindValue( ":gender", "Male" );
    else if( p.getGender() == 2 )
        q.bindValue( ":gender", "Female" );
    q.bindValue( ":birth", p.getBirth().toString("yyyy-mm-dd") );
    q.bindValue( ":death", p.getDeath().toString("yyyy-mm-dd") );

    if( !q.exec() )
        return 1;
    return 0;
}

int SQLITEHandler::removeEntry( Computer comp ) {
    if( !status )
        return 1;
    q.prepare( "DELETE FROM computers WHERE id = (:id)" );      // Delete computer
    q.bindValue( ":id", comp.getID() );
    if( !q.exec() )
        return 1;

    q.prepare( "DELETE FROM relation WHERE computer = (:id)" ); // Delete relations
    q.bindValue( ":id", comp.getID() );
    if( !q.exec() )
        return 2;

    return 0;
}

int SQLITEHandler::removeEntry( Person p ) {
    if( !status )
        return 1;
    q.prepare( "DELETE FROM people WHERE id = (:id)" );      // Delete person
    q.bindValue( ":id", p.getId() );
    if( !q.exec() )
        return 1;

    q.prepare( "DELETE FROM relation WHERE person = (:id)" ); // Delete relations
    q.bindValue( ":id", p.getId() );
    if( !q.exec() )
        return 2;

    return 0;
}

int SQLITEHandler::modifyEntry( Computer comp ) {
    if( !status )
        return 1;
    q.prepare( "UPDATE computers SET name = (:name), creation = (:creation), type = (:type), constructed = (:constructed) WHERE id = (:id)" );
    q.bindValue( ":id", comp.getID() );
    q.bindValue( ":name", comp.getName() );
    q.bindValue( ":creation", comp.getYear() );
    q.bindValue( ":type", comp.getType() );
    q.bindValue( ":constructed", comp.getWasBuilt() );
    if( !q.exec() )
        return 1;
    return 0;
}

int SQLITEHandler::modifyEntry( Person p ) {
    if( !status )
        return 1;
    q.prepare( "UPDATE people SET name = (:name), gender = (:gender), birth = (:birth), death = (:death) WHERE id = (:id)" );
    q.bindValue( ":id", p.getId() );
    q.bindValue( ":name", p.getName() );
    q.bindValue( ":gender", p.getGender() );
    q.bindValue( ":birth", p.getBirth().toString("yyyy-mm-dd") );
    q.bindValue( ":death", p.getBirth().toString("yyyy-mm-dd") );
    if( !q.exec() )
        return 1;
    return 0;
}
