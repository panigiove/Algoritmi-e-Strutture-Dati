#include <iostream>
#include <fstream>
#include <vector>
#include <list>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, dim_visitato, indice_inizio=1, indice_fine, counter=0;
    in >> N;
    indice_fine=N-1;

    vector<char> fila_triangoli;
    vector<bool> isolato;

    fila_triangoli.resize(N);
    isolato.resize(N, true);

    for(int i=0; i<N; i++){
        in >> fila_triangoli[i];
    }

    if(fila_triangoli[0]=='s'){
        int k;
        for(k=0; fila_triangoli[k]=='s'; k++){
            counter++;
        }
        if(counter%2==0){
            indice_inizio=k+1;
            for(k=k-1; k>=0; k--){
                isolato[k]=false;
                N--;
            }
        } 
    }

    /*if(fila_triangoli[indice_fine]=='d'){
        int k;
        for(k=indice_fine; fila_triangoli[k]=='d'; k--);
        k++;
        if(k%0){
            indice_fine=k-2;
            for(k; k<N; k++){
                isolato[k]=false;
            }
        } 
    }*/

    for(int i=indice_inizio; i<indice_fine; i=i+2){
        isolato[i]=false;
        switch (fila_triangoli[i]){
            case 's':{
                if(fila_triangoli[i-1]=='d'){
                    isolato[i-1]=false;
                    N--;  
                }
                break;
            }
            case 'd':{
                if(fila_triangoli[i+1]=='s'){
                    isolato[i+1]=false;
                    N--;
                }
                break;
            }
            default:{
                break;
            }
        }
    }

    out << N << endl;

    for(int i=0; i<=indice_fine; i++){
        if(isolato[i]){
            out << i <<" ";
        }
    }
}