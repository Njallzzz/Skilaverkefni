#include "sorter.h"

//Sort a list by name
void sortByName(vector<Person> & list){
    nameSort(list, 0, list.size() - 1);         //Call the sorting function
}

//Recursive algorithm that sorts a list by name
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

    //Recursive step
    if(left < j){
        nameSort(list, left, j);
    }
    if(i < right){
        nameSort(list, i, right);
    }
}

//Sort a list by Birth date
void sortByBirth(vector<Person> & list){
    birthSort(list, 0, list.size() - 1);
}

//Recursive algorithm that sorts a list by Birthday
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

    //Recursive step
    if(left < j){
        birthSort(list, left, j);
    }
    if(i < right){
        birthSort(list, i, right);
    }
}

//Sort a list by death date
void sortByDeath(vector<Person> & list){
    deathSort(list, 0, list.size() - 1);
}

//Recursive algorithm that sorts a list by deathdate
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

    //Recursive step
    if(left < j){
        deathSort(list, left, j);
    }
    if(i < right){
        deathSort(list, i, right);
    }
}

//Sort a list by gender
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
