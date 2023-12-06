#include<iostream>
#include <fstream>
#include <vector>
using namespace std;

bool puntofisso(vector<int>& array, int start, int end){
    if(start>end){
        return false;
    }
    int mid=(start+end)/2;
    if(array[mid]==mid){
        return true;
    }
    else if(array[mid]>mid){
        return puntofisso(array, start, mid-1);
    }
    else{
        return puntofisso(array, mid+1, end);
    }
}

int main(){
    ifstream in("input.txt");

    int n, index=0;
    vector<int> array;
    while(in >> n){
        array.push_back(n);
    }

    bool A = puntofisso(array, 0, array.size()-1);

    return 0;
}