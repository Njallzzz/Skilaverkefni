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
