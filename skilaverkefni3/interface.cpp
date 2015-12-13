#include "interface.h"

Interface::Interface() {
    db = SQLITEHandler( "Database.db" );
    sortPeople = NAME_ASC;
    sortComputers = NAME_ASC;

    computerSearch.setName("");
    computerSearch.setType("");
    computerSearch.setWasBuilt(2);

    personSearch.setName("");
    personSearch.setGender(0);
}

int Interface::Initialize() {
    if( db.connect() )
        return 1;
    return 0;
}

int Interface::getPeople( vector<Person> & p, bool all ) {
    p.clear();

    if( db.readDatabase( p, sortPeople ) )
        return 1;

    if(!all)
        p = Filter(p);

    return 0;
}

int Interface::getComputers( vector<Computer> & c, bool all ) {
    c.clear();

    if( db.readDatabase( c, sortComputers ) )
        return 1;

    if(!all)
        c = Filter(c);

    return 0;
}

vector<Person> Interface::Filter( vector<Person> & p ) {
    vector<Person> results;
    for( unsigned int x = 0; x < p.size(); x++) {    // Search each entry of list
        bool add = true;                                    // We say the entry should be added by default then exclude it based on the template person
        if( personSearch.getName() != "" )
            if( !p[x].getName().contains( personSearch.getName(), Qt::CaseInsensitive ) )
                add = false;

        if( personSearch.getGender() != 0 )
            if( !(p[x].getGender() == personSearch.getGender() ) )
                add = false;

        if( personSearch.getBirth().isValid() )
            if( !(p[x].getBirth() == personSearch.getBirth() ) )
                add = false;

        if( personSearch.getDeath().isValid() )
            if( !(p[x].getDeath() == personSearch.getDeath() ) )
                add = false;

        if(add)
            results.push_back( p[x] );
    }
    return results;
}

vector<Computer> Interface::Filter( vector<Computer> & c ) {
    vector<Computer> results;
    for( unsigned int x = 0; x < c.size(); x++) {    // Search each entry of list
        bool add = true;                                    // We say the entry should be added by default then exclude it based on the template person
        if( computerSearch.getName() != "" )
            if( !c[x].getName().contains( computerSearch.getName(), Qt::CaseInsensitive ) )
                add = false;

        if( computerSearch.getType() != "" )
            if( !c[x].getType().contains( computerSearch.getType() , Qt::CaseInsensitive ) )
                add = false;

        if( computerSearch.getWasBuilt() != 2 )
            if( !(c[x].getWasBuilt() == computerSearch.getWasBuilt() ) )
                add = false;

        if( computerSearch.getYear() != "" )
            if( !(c[x].getYear() == computerSearch.getYear() ) )
                add = false;

        if(add)
            results.push_back( c[x] );
    }
    return results;
}

void Interface::peopleFilterName( QString name ) {
    personSearch.setName( name );
}

void Interface::peopleFilterGender( QString gender ) {
    if( gender == "Male" )
        personSearch.setGender( 1 );
    else if( gender == "Female" )
        personSearch.setGender( 2 );
    else
        personSearch.setGender( 0 );
}

void Interface::peopleFilterBirth( QDate date ) {
    personSearch.setBirth( date );
}

void Interface::peopleFilterDeath( QDate date ) {
    personSearch.setDeath( date );
}

void Interface::ComputerFilterName( QString name ) {
    computerSearch.setName( name );
}

void Interface::ComputerFilterType( QString type ) {
    computerSearch.setType( type );
}

void Interface::ComputerFilterDate( QDate date ) {
    computerSearch.setYear( date.toString("yyyy") );
}

void Interface::ComputerFilterBuilt( int built ) {
    if( built == 0 )
        computerSearch.setWasBuilt( 2 );
    else if( built == 1 )
        computerSearch.setWasBuilt( 1 );
    else if( built == 2 )
        computerSearch.setWasBuilt( 0 );
}
