#include "services/interface.h"

Interface::Interface() {
    db.SetDatabase( "Database.db" );
    sortPeople = NAME_ASC;
    sortComputers = NAME_ASC;

    computerSearch.setName("");
    computerSearch.setType("");
    computerSearch.setWasBuilt(2);

    personSearch.setName("");
    personSearch.setGender(0);

    SelectedPerson = -1;
}

Interface::~Interface() {
    db.disconnect();
}

int Interface::Initialize() {
    if( db.connect() )
        return 1;
    return 0;
}

vector<Person> & Interface::getPeople( bool all ) {
    p.clear();

    if( all == false ) {
        if( db.readDatabase( p, sortPeople ) )
            return p;
    } else {
        if( db.readDatabase( p, NAME_ASC ) )
            return p;
    }


    if(!all)
        p = Filter(p);

    return p;
}

vector<Computer> & Interface::getComputers( bool all ) {
    c.clear();

    if( all == false ) {
        if( db.readDatabase( c, sortComputers ) )
            return c;
    } else {
        if( db.readDatabase( c, NAME_ASC ) )
            return c;
    }

    if(!all)
        c = Filter(c);

    if( (SelectedPerson != -1) && (all == false) ) {
        int index = 0;
        for(unsigned int x = 0; x < p.size(); x++) {
            if( p[x].getId() == SelectedPerson )
                index = x;
        }
        vector<int> ids;

        for( int x = 0; x < int(c.size()); x++ ) {
            bool added = false, exclude = false;

            for( int i = 0; i < p[index].getSize(); i++) {
                if( p[index].getComputer(i) == c[x].getId() )
                    exclude = true;
            }

            if( !exclude ) {
                for( unsigned int y = 0; y < ids.size(); y++ ) {
                    if( x == ids[y] )
                        added = true;
                }
            }

            if(!added && !exclude)
                ids.push_back(x);
        }

        for(int x = int(ids.size()) - 1; x >= 0; x--) {
            c.erase( c.begin() + ids[x] );
        }

    }

    return c;
}

vector<Person> Interface::Filter( vector<Person> & people ) {
    vector<Person> results;
    for( unsigned int x = 0; x < people.size(); x++) {    // Search each entry of list
        bool add = true;                                    // We say the entry should be added by default then exclude it based on the template person
        if( personSearch.getName() != "" )
            if( !people[x].getName().contains( personSearch.getName(), Qt::CaseInsensitive ) )
                add = false;

        if( personSearch.getGender() != 0 )
            if( !(people[x].getGender() == personSearch.getGender() ) )
                add = false;

        if( personSearch.getBirth().isValid() )
            if( !(people[x].getBirth() == personSearch.getBirth() ) )
                add = false;

        if( personSearch.getDeath().isValid() )
            if( !(people[x].getDeath() == personSearch.getDeath() ) )
                add = false;

        if(add)
            results.push_back( people[x] );
    }
    return results;
}

vector<Computer> Interface::Filter( vector<Computer> & computers ) {
    vector<Computer> results;
    for( unsigned int x = 0; x < computers.size(); x++) {    // Search each entry of list
        bool add = true;                                    // We say the entry should be added by default then exclude it based on the template person
        if( computerSearch.getName() != "" )
            if( !computers[x].getName().contains( computerSearch.getName(), Qt::CaseInsensitive ) )
                add = false;

        if( computerSearch.getType() != "" )
            if( !computers[x].getType().contains( computerSearch.getType() , Qt::CaseInsensitive ) )
                add = false;

        if( computerSearch.getWasBuilt() != 2 )
            if( !(computers[x].getWasBuilt() == computerSearch.getWasBuilt() ) )
                add = false;

        if( computerSearch.getYear() != "" )
            if( !(computers[x].getYear() == computerSearch.getYear() ) )
                add = false;

        if(add)
            results.push_back( computers[x] );
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

int Interface::selectPerson( int index ) {
    if( index < -1 || index >= int(p.size()) )
        return 1;
    if( index == -1 )
        SelectedPerson = -1;
    else
        SelectedPerson = p[index].getId();
    return 0;
}

void Interface::deletePerson( int index ) {
    db.removeEntry( p[index] );
}

void Interface::deleteComputer( int index ) {
    db.removeEntry( c[index] );
}

void Interface::sortPerson( int index ) {
    if( index == 0 ) {
        if( sortPeople == NAME_ASC )
            sortPeople = NAME_DESC;
        else
            sortPeople = NAME_ASC;
    } else if( index == 1 ) {
        if( sortPeople == GENDER_ASC )
            sortPeople = GENDER_DESC;
        else
            sortPeople = GENDER_ASC;
    } else if( index == 2 ) {
        if( sortPeople == BIRTH_ASC )
            sortPeople = BIRTH_DESC;
        else
            sortPeople = BIRTH_ASC;
    } else if( index == 3 ) {
        if( sortPeople == DEATH_ASC )
            sortPeople = DEATH_DESC;
        else
            sortPeople = DEATH_ASC;
    }
}

void Interface::sortComputer( int index ) {
    if( index == 0 ) {
        if( sortComputers == NAME_ASC )
            sortComputers = NAME_DESC;
        else
            sortComputers = NAME_ASC;
    } else if( index == 1 ) {
        if( sortComputers == TYPE_ASC )
            sortComputers = TYPE_DESC;
        else
            sortComputers = TYPE_ASC;
    } else if( index == 2 ) {
        if( sortComputers == CREATION_ASC )
            sortComputers = CREATION_DESC;
        else
            sortComputers = CREATION_ASC;
    } else if( index == 3 ) {
        if( sortComputers == CONSTRUCTED_ASC )
            sortComputers = CONSTRUCTED_DESC;
        else
            sortComputers = CONSTRUCTED_ASC;
    }
}
