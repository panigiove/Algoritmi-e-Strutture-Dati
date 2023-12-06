#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int VetUniMod_aux(vector<int>& array, int start, int end){
    int mid=(start+end)/2;

    if(array[mid-1] > array[mid] && array[mid] < array[mid+1]){
        return array[mid];
    }
    else if(array[mid-1] > array[mid]){
        return VetUniMod_aux(array, mid+1, end);
    }
    else{
        return VetUniMod_aux(array, start, mid);
    }
}

int VetUniMod(vector<int>& array){
    if(array.size()==1){
        return array[0];
    }
    else{
        if(array[0]<array[1]){
            return array[0];
        }
        else if(array[array.size()-1] < array[array.size()-2]){
            return array[array.size()-1];
        }
        else{
            return VetUniMod_aux(array, 0, array.size()-1);
        }
    }
}

int main(){
    ifstream in("input.txt");
    vector<int> array;

    int n;
    while(in >> n){
        array.push_back(n);
    }

    int res = VetUniMod(array);

    cout << res;
}