#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

void distanza(vector<vector<int>> grafo, int r, int* distance, const int& N){
    queue<int> nodi_da_visitare;
    nodi_da_visitare.push(r);

    for(int i=0; i<N; i++){
        if(i!=r){
            distance[i]=-1;
        }
    }
    distance[r]=0;

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
}

int main(){

    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, M, inizio, fine, distanza_max=0, *distance;
    
    in >> N >> M;

    distance = new int[N];

    vector<vector<int>> grafo;

    grafo.resize(N);

    while(in >> inizio >> fine){
        grafo[inizio].push_back(fine);
        grafo[fine].push_back(inizio);
    }

    for(int i=0; i<N; i++){
        distanza(grafo, i, distance, N);

        for(int k=0; k<N; k++){
            distanza_max=max(distanza_max, distance[k]);
        }
    }

    out << distanza_max;
}