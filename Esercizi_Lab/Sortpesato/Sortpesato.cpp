#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

void minTurni(int& turni, vector<int> array_min_scambio, const int& lunghezza){
    for(int i=0; i<lunghezza; i++){
        while(array_min_scambio[i]!=i){
            turni++;
            swap(array_min_scambio[i], array_min_scambio[array_min_scambio[i]]);
        }
    }
}

void minCosto(vector<int> array_min_peso, int& costo, const int& lunghezza){
    int costo1, costo2;
    
    for(int i=0; i<lunghezza; i++){
        costo1 = 0;
        int j, k;
        if(array_min_peso[i]!=i){
            for(j=i; array_min_peso[j]!=i; j++);
        }

        costo2 = 2*(array_min_peso[j]+2);

        while(array_min_peso[i]!=i){
            for(k=0; array_min_peso[k]!=j; k++);
            costo1 += array_min_peso[k]+array_min_peso[j]+2;
            costo2 += array_min_peso[k]+2;
            swap(array_min_peso[j], array_min_peso[k]);
            j=k;
        }

        costo += min(costo1, costo2);
    }
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int lunghezza, costo=0, turni=0;
    in >> lunghezza;

    vector<int> array_min_scambio;
    vector<int> array_min_peso;
    array_min_scambio.resize(lunghezza, 0);
    array_min_peso.resize(lunghezza, 0);

    for(int i=0; i<lunghezza; i++){
        in >> array_min_peso[i];
        array_min_peso[i]--;
        array_min_scambio[i]=array_min_peso[i];
    }

    minTurni(turni, array_min_scambio, lunghezza);

    minCosto(array_min_peso, costo, lunghezza);

    /*for(int i=0; i<lunghezza; i++){
        int j, k;
        if(array_min_peso[i]!=i){
            for(j=i; array_min_peso[j]!=i; j++);
        }

        while(array_min_peso[i]!=i){
            for(k=0; array_min_peso[k]!=j; k++);
            costo += array_min_peso[k]+array_min_peso[j]+2;
            turni++;
            swap(array_min_peso[j], array_min_peso[k]);
            j=k;
        }
    }*/

    out << turni <<" " << costo;

    return 0;
}