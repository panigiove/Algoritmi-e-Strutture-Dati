#include <iostream>
#include <fstream>
#include <cassert>
#include <vector>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int numero_parentesi, tipologie_parentesi, numero_casi;
    vector<int> parentesi_quantiche;

    assert(in >> numero_casi);
    for(int i=0; i<numero_casi; i++){
        assert(in >> numero_parentesi >> tipologie_parentesi);
        for(int k=0; k<numero_parentesi; k++){
            int parentesi;
            assert(in >> parentesi);
            if(parentesi_quantiche.empty() || parentesi_quantiche.back()!=parentesi){
                parentesi_quantiche.push_back(parentesi);
            }
            else{
                parentesi_quantiche.pop_back();
            }
        }

        if(parentesi_quantiche.empty()){
            out << 1 << endl;
        }
        else{
            out << 0 << endl;
        }

        while(!parentesi_quantiche.empty()){
            parentesi_quantiche.pop_back();
        }

    }
    return 0;
}