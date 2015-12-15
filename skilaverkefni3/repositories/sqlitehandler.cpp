#include "repositories/sqlitehandler.h"

SQLITEHandler::SQLITEHandler() {            //Constructors
    status = false;                         // Initalize variables
}

SQLITEHandler::SQLITEHandler( QString filename ) {      //Constructors
    file = filename;                                    // Initalize variables
    status = false;
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(file);
}

SQLITEHandler::~SQLITEHandler() {                       //Constructors
    if( status == true )                                // Close database if open
        db.close();
}

int SQLITEHandler::SetDatabase( QString filename ) {    // Select a database file
    if( file == "" )
        db = QSqlDatabase::addDatabase("QSQLITE");
    if( status == true )                                // If already connected, fail
        return 1;
    file = filename;
    db.setDatabaseName(file);
    return 0;
}

int SQLITEHandler::connect() {                          // Connect to database file
    if(status)                                          // If already connected, fail
        return 1;

    if( db.open() ) {                                   // Attempt to connect and check failure
        status = true;
        q = QSqlQuery();
    } else
        status = false;
    return !status;
}

int SQLITEHandler::disconnect() {                       // Disconnect from database file
    if( status == true ) {                              // Close database if connected
        db.close();
        status = false;
        return 0;
    } else                                              // Fail if not connected to database
    return 1;
}

int SQLITEHandler::readDatabase( vector<Person> & people, sorting s1 ) {        // Get all people and relations for them
    if( !status )                                                               // If not connected, fail
        return 1;
    people.clear();                                                             // Remove all entries in vector
    if( s1 == NAME_ASC )                                                        // Create query based on requested sorting
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
    else                                                                        // Invalid sorting type
        q.prepare("SELECT * FROM people ORDER BY name COLLATE NOCASE ASC");
    if( !q.exec() )                                                             // Attempt to execute query
        return 3;

    int ref[5];                                                                 // Create table index
    ref[0] = q.record().indexOf("id");                                          // 'id' handle, etc.
    ref[1] = q.record().indexOf("name");
    ref[2] = q.record().indexOf("gender");
    ref[3] = q.record().indexOf("birth");
    ref[4] = q.record().indexOf("death");

    while( q.next() ) {                                                         // Execute until all people have been added to vector
        int id = q.value( ref[0] ).toInt(),                                     // Insert all data into relevant variables
            gender = 0;
        QString name = q.value( ref[1] ).toString(),
                genderString = q.value( ref[2] ).toString();
        QDate birth = QDate::fromString( q.value( ref[3] ).toString(), "yyyy-MM-dd" ),
              death = QDate::fromString( q.value( ref[4] ).toString(), "yyyy-MM-dd" );
        if( genderString == "Male" )
            gender = 1;
        else if( genderString == "Female" )
            gender = 2;
        Person p( id, name, gender, birth, death  );                            // Construct a individual with those variables
        people.push_back( p );                                                  // Add individual to entry
    }

    for(unsigned int x = 0; x < people.size(); x++) {                           // Get relations for all people
        q.prepare("SELECT * FROM relation WHERE person = (:id)");               // Get all from relations table where name
        q.bindValue( ":id", people[x].getId() );
        if( !q.exec() )
            return 4;
        int ref = q.record().indexOf("computer");
        while( q.next() ) {                                                     // Execute query until all relations have been assigned for the individual
            people[x].add_relation( q.value( ref ).toInt() );                   // Add relation to person
        }
    }

    return 0;                                   // Return success
}

int SQLITEHandler::readDatabase( std::vector<Computer> & computers, sorting s1 ) {      // Get all computers and relations for them
    if( !status )                                                                       // If not connected, fail
        return 1;
    computers.clear();                                                                  // Remove all entries in vector
    if( s1 == NAME_ASC )                                                                // Create query based on requested sorting
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
    else                                                                                // Invalid sorting type
        q.prepare("SELECT * FROM computers ORDER BY name COLLATE NOCASE ASC");
    if( !q.exec() )                                                                     // Attempt to execute query
        return 3;

    int ref[5];                                                                         // Create table index
    ref[0] = q.record().indexOf("id");                                                  // 'id' handle, etc.
    ref[1] = q.record().indexOf("name");
    ref[2] = q.record().indexOf("creation");
    ref[3] = q.record().indexOf("type");
    ref[4] = q.record().indexOf("constructed");

    while( q.next() ) {                                     // Execute until all computers have been added to vector
        int id = q.value( ref[0] ).toInt();
        QString name = q.value( ref[1] ).toString(),
                type = q.value( ref[3] ).toString();
        QDate date = QDate::fromString( q.value( ref[2] ).toString(), "yyyy" );
        bool constructed = q.value( ref[4] ).toBool();

        Computer t( id, name, date, type, constructed  );   // Construct a computer with those variables
        computers.push_back( t );                           // Add computer to entry
    }
    return 0;
}

int SQLITEHandler::addEntry( Computer c ) {         // Add Computer to database
    if( !status )                                   // If not connected, fail
        return 1;
    q.prepare( "INSERT INTO computers (name, creation, type, constructed) VALUES (:name, :creation, :type, :constructed)" );
    q.bindValue( ":name", c.getName() );
    q.bindValue( ":creation", c.getYear() );
    q.bindValue( ":type", c.getType() );
    q.bindValue( ":constructed", c.getWasBuilt() );
    if( !q.exec() )                                 // Attempt to execute query
        return 1;
    return 0;                   // Return Success
}

int SQLITEHandler::addEntry( Person p ) {           // Add Person to database
    qDebug() << p.getName() << " " << p.getGender() << " " << p.getBirth().toString("dd.MM.yyyy") << " " << p.getDeath().toString("dd.MM.yyyy");

    if( !status )                                   // If not connected, fail
        return 1;
    q.prepare( "INSERT INTO people (name, gender, birth, death) VALUES (:name, :gender, :birth, :death)" );
    q.bindValue( ":name", p.getName() );
    if( p.getGender() == 1 )
        q.bindValue( ":gender", "Male" );
    else if( p.getGender() == 2 )
        q.bindValue( ":gender", "Female" );
    q.bindValue( ":birth", p.getBirth().toString("yyyy-MM-dd") );
    q.bindValue( ":death", p.getDeath().toString("yyyy-MM-dd") );

    if( !q.exec() )                                 // Attempt to execute query
        return 1;
    return 0;                   // Return Success
}

int SQLITEHandler::removeEntry( Computer c ) {      // Remove computer from database
    if( !status )                                   // If not connected, fail
        return 1;
    q.prepare( "DELETE FROM computers WHERE id = (:id)" );      // Delete computer
    q.bindValue( ":id", c.getId() );
    if( !q.exec() )
        return 2;

    q.prepare( "DELETE FROM relation WHERE computer = (:id)" ); // Delete relations
    q.bindValue( ":id", c.getId() );
    if( !q.exec() )                                 // Attempt to execute query
        return 3;

    return 0;                   // Return Success
}

int SQLITEHandler::removeEntry( Person p ) {        // Remove Person from database
    if( !status )                                   // If not connected, fail
        return 1;
    q.prepare( "DELETE FROM people WHERE id = (:id)" );      // Delete person
    q.bindValue( ":id", p.getId() );
    if( !q.exec() )
        return 2;

    q.prepare( "DELETE FROM relation WHERE person = (:id)" ); // Delete relations
    q.bindValue( ":id", p.getId() );
    if( !q.exec() )                                 // Attempt to execute query
        return 3;

    return 0;                   // Return Success
}

int SQLITEHandler::modifyEntry( Computer c ) {      // Modify computer in database
    if( !status )                                   // If not connected, fail
        return 1;
    q.prepare( "UPDATE computers SET name = (:name), creation = (:creation), type = (:type), constructed = (:constructed) WHERE id = (:id)" );
    q.bindValue( ":id", c.getId() );
    q.bindValue( ":name", c.getName() );
    q.bindValue( ":creation", c.getYear() );
    q.bindValue( ":type", c.getType() );
    q.bindValue( ":constructed", c.getWasBuilt() );
    if( !q.exec() )                                 // Attempt to execute query
        return 2;
    return 0;                   // Return Success
}

int SQLITEHandler::modifyEntry( Person p ) {        // Modify Person in database
    if( !status )                                   // If not connected, fail
        return 1;
    q.prepare( "UPDATE people SET name = (:name), gender = (:gender), birth = (:birth), death = (:death) WHERE id = (:id)" );
    q.bindValue( ":id", p.getId() );
    q.bindValue( ":name", p.getName() );
    if( p.getGender() == 1 )
        q.bindValue( ":gender", "Male" );
    else if( p.getGender() == 2 )
        q.bindValue( ":gender", "Female" );
    q.bindValue( ":birth", p.getBirth().toString("yyyy-MM-dd") );
    q.bindValue( ":death", p.getDeath().toString("yyyy-MM-dd") );
    if( !q.exec() )                                 // Attempt to execute query
        return 2;
    return 0;                   // Return Success
}

int SQLITEHandler::addRelation( Person p, Computer c ) {    // Add relation between Person and Computer to database
    if( !status )                                   // If not connected, fail
        return 1;
    if( p.isRelated( c ) )                                  // Check if relation already exists
        return 2;
    q.prepare( "INSERT INTO relation (person, computer) VALUES (:person, :computer)" );         // Delete relation
    q.bindValue( ":person", p.getId() );
    q.bindValue( ":computer", c.getId() );
    if( !q.exec() )                                 // Attempt to execute query
        return 3;
    return 0;                   // Return Success
}

int SQLITEHandler::deleteRelation( Person p, Computer c ) { // Delete relation between Person and Computer in database
    if( !status )                                   // If not connected, fail
        return 1;
    q.prepare( "DELETE FROM relation WHERE person = (:person) AND computer = (:computer)" );      // Delete relation
    q.bindValue( ":person", p.getId() );
    q.bindValue( ":computer", c.getId() );
    if( !q.exec() )                                 // Attempt to execute query
        return 2;
    return 0;                   // Return Success
}

Person SQLITEHandler::getPerson(int cid)
{
    q.prepare("SELECT * FROM people WHERE id = (:id)");
    q.bindValue(":id", cid);

    if( !q.exec() )
        return Person();

    int ref[5];                                                                 // Create table index
    ref[0] = q.record().indexOf("id");                                          // 'id' handle, etc.
    ref[1] = q.record().indexOf("name");
    ref[2] = q.record().indexOf("gender");
    ref[3] = q.record().indexOf("birth");
    ref[4] = q.record().indexOf("death");

    q.next();
    Person p;                                                         // Execute until all people have been added to vector
    int id = q.value( ref[0] ).toInt(),                                     // Insert all data into relevant variables
        gender = 0;
    QString name = q.value( ref[1] ).toString(),
            genderString = q.value( ref[2] ).toString();
    qDebug() << id << "hæ";
    QDate birth = QDate::fromString( q.value( ref[3] ).toString(), "yyyy-MM-dd" ),
          death = QDate::fromString( q.value( ref[4] ).toString(), "yyyy-MM-dd" );
    if( genderString == "Male" )
        gender = 1;
    else if( genderString == "Female" )
        gender = 2;
    p = Person( id, name, gender, birth, death  );

    q.prepare("SELECT * FROM relation WHERE person = (:id)");               // Get all from relations table where name
    q.bindValue( ":id", cid );
    if( !q.exec() )
        return Person();
    int reference = q.record().indexOf("computer");
    while( q.next() ) {                                                     // Execute query until all relations have been assigned for the individual
        p.add_relation( q.value( reference ).toInt() );                   // Add relation to person
    }
    qDebug() << p.getId() << " " << p.getName();
    return p;
}
