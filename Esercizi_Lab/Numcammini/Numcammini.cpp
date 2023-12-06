#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

void numeroCammini(vector<vector<int>> grafo, const int& S, const int& T, const int& N, int distanza, int& distanza_max, int& numero_cammini){
    queue<int> nodi_da_visitare;
    queue<int> nodi_da_checkare;
    nodi_da_visitare.push(S);

    vector<bool> nodi_visitati;
    nodi_visitati.resize(N, false);

    while(!nodi_visitati[T]){
        int size = nodi_da_visitare.size();

        for(int i=0; i<size; i++){
            int nodo = nodi_da_visitare.front();

            if(!nodi_visitati[nodo]){
                for(int k : grafo[nodo]){
                    nodi_da_visitare.push(k);
                }
            }

            nodi_da_checkare.push(nodo);
            nodi_da_visitare.pop();
        }

        distanza++;

        for(int i=0; i<size; i++){
            int nodo = nodi_da_checkare.front();
            if(nodo == T){
                distanza_max=distanza;
                numero_cammini++;
            }
            nodi_visitati[nodo] = true;
            nodi_da_checkare.pop();
        }
    }
}

/*void distanza(vector<vector<int>> grafo, const int& S, const int& T, int* distance, const int& N){
    queue<int> nodi_da_visitare;
    nodi_da_visitare.push(S);

    for(int i=0; i<N; i++){
        if(i!=S){
            distance[i]=-1;
        }
    }
    distance[S]=0;

    while(!nodi_da_visitare.empty()){
        int nodo = nodi_da_visitare.front();
        for(int k : grafo[nodo]){
            if(distance[k]==-1){
                distance[k]=distance[nodo]+1;
                nodi_da_visitare.push(k);
            }
        }

        nodi_da_visitare.pop();
    }
}*/

int main(){

    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, M, S, T, inizio, fine, distanza_max=0, num_cammini=0, *distance, distanza=-1;
    
    in >> N >> M >> S >> T;

    //distance = new int[N];

    vector<vector<int>> grafo;

    grafo.resize(N);

    while(in >> inizio >> fine){
        grafo[inizio].push_back(fine);
    }

    numeroCammini(grafo, S, T, N, distanza, distanza_max, num_cammini);

    //distanza(grafo, S, T, distance, N);

    /*for(int k=0; k<N; k++){
        if(distanza_max=distance[k]){
            num_cammini++;
        }
        else{
            distanza_max=max(distanza_max, distance[k]);
        }
    }*/

    out << distanza_max <<" " << num_cammini;
}