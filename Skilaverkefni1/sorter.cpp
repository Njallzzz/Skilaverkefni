#include "sorter.h"

Sorter::Sorter()
{

}
Sorter::Sorter(vector<Person> & theList){
    list = theList;
}
void Sorter::sortByName(vector<Person> & list, int left, int right){
    int i = left, j = right;
    Person tmp;
    QString pivot = list[(left + right) / 2].name;

    while (i <= j){
        while(list[i].name < pivot){
            i++;
        }
        while(list[j].name > pivot){
            j--;
        }
        if(i <= j){
            tmp = list[i];
            list[i] = list[j];
            list[j] = tmp;
            i++;
            j--;
        }
    };

    if(left < j){
        sortByName(list, left, j);
    }
    if(i < right){
        sortByName(list, i, right);
    }
}

void Sorter::sortByBirth(vector<Person> &list, int left, int right){
    int i = left, j = right;
    Person tmp;
    QDate pivot = list[(left + right) / 2].birth;

    while (i <= j){
        while(list[i].birth < pivot){
            i++;
        }
        while(list[j].birth > pivot){
            j--;
        }
        if(i <= j){
            tmp = list[i];
            list[i] = list[j];
            list[j] = tmp;
            i++;
            j--;
        }
    };

    if(left < j){
        sortByBirth(list, left, j);
    }
    if(i < right){
        sortByBirth(list, i, right);
    }
}

void Sorter::sortByDeath(vector<Person> &list, int left, int right){
    int i = left, j = right;
    Person tmp;
    QDate pivot = list[(left + right) / 2].death;

    while (i <= j){
        while(list[i].death < pivot){
            i++;
        }
        while(list[j].death > pivot){
            j--;
        }
        if(i <= j){
            tmp = list[i];
            list[i] = list[j];
            list[j] = tmp;
            i++;
            j--;
        }
    };

    if(left < j){
        sortByDeath(list, left, j);
    }
    if(i < right){
        sortByDeath(list, i, right);
    }
}
