#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int chimanca_aux(vector<int>& array, int start, int end){
    if(start == end){
        return start;
    }
    int mid = (start+end)/2;

    if(array[mid] == mid){
        return chimanca_aux(array, mid+1, end);
    }
    else{
        return chimanca_aux(array, start, mid);
    }
}

int chimanca(vector<int> array){
    if(array.back() == array[array.size()-1]){
        return array.back()+2;
    }
    else{
        return chimanca_aux(array, 0, array.size()-1)+1;
    }
}

int main(){
    ifstream in("input.txt");

    int n;
    vector<int> array;
    while(in >> n){
        array.push_back(n-1);
    }

    int res = chimanca(array);

    cout << res+1;

    return 0;
}