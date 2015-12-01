#include <vector>
#include "person.h"
#include <QDate>
#include <QString>

using namespace std;

void sortByName(vector<Person> & list);
void nameSort(vector<Person> & list, int left, int right);
void sortByBirth(vector<Person> & list);
void birthSort(vector<Person> & list, int left, int right);
void sortByDeath(vector<Person> & list);
void deathSort(vector<Person> & list, int left, int right);
void genderSort(vector<Person> & list, int left, int right);

void sortByName(vector<Person> & list){
    nameSort(list, 0, list.size() - 1);
}

void nameSort(vector<Person> & list, int left, int right){
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
        nameSort(list, left, j);
    }
    if(i < right){
        nameSort(list, i, right);
    }
}

void sortByBirth(vector<Person> & list){
    birthSort(list, 0, list.size() - 1);
}

void birthSort(vector<Person> &list, int left, int right){
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
        birthSort(list, left, j);
    }
    if(i < right){
        birthSort(list, i, right);
    }
}

void sortByDeath(vector<Person> & list){
    deathSort(list, 0, list.size() - 1);
}

void deathSort(vector<Person> &list, int left, int right){
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
        deathSort(list, left, j);
    }
    if(i < right){
        deathSort(list, i, right);
    }
}

void genderSort(vector<Person> & list, int left, int right){
    int i = left, j = right;
    Person tmp;
    int pivot = list[(left + right) / 2].gender;

    while (i <= j){
        while(list[i].gender < pivot){
            i++;
        }
        while(list[j].gender > pivot){
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
        genderSort(list, left, j);
    }
    if(i < right){
        genderSort(list, i, right);
    }
}
