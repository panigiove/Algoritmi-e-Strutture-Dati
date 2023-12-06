#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int *array_appoggio;

void merge(int *array, int first, int last, int mid){
    int i=first, j=mid+1, k=first, h;
    array_appoggio = new int[last];
    while(i<=mid && j<=last){
        if(array[i]<=array[j]){
            array_appoggio[k]=array[i];
            i++;
        }
        else{
            array_appoggio[k]=array[j];
            j++;
        }
        k++;
    }

    j=last;
    for(h=mid; h>=i; h--){
        array[j]=array[h];
        j--;
    }

    for(j=first; j<k; j++){
        array[j]=array_appoggio[j];
    }

    delete[] array_appoggio;
}

void mergeSort(int *array, int first, int last){
    if(first<last){
        int mid = (first+last)/2;
        mergeSort(array, first, mid);
        mergeSort(array, mid+1, last);
        merge(array, first, last, mid);
    }
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n;
    in >> n;
    int *array = new int[n];

    for(int i=0; i<n; i++){
        in >> array[i];
    }

    mergeSort(array, 0, n-1);

    for(int i=0; i<n; i++){
        out << array[i] <<" ";
    }

    delete[] array;

    return 0;
}