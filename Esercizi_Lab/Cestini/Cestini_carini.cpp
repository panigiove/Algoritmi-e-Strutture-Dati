#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<int>> cestini;

void inizia(int numero_oggetti, int numero_cestini){
    cestini.resize(numero_cestini);
    for(int i=0; i<numero_oggetti; i++){
        cestini[0].push_back(i);
    }
}

void sposta(int indice_partenza, int indice_arrivo){
    int temp = cestini[indice_partenza].back();
    cestini[indice_partenza].pop_back();
    cestini[indice_arrivo].push_back(temp);
}

int controlla(int indice_cestino, int indice_dal_fondo){
    if(cestini[indice_cestino].size()<indice_dal_fondo+1){
        return -1;
    }
    else{
        return cestini[indice_cestino][indice_dal_fondo];
    }
}