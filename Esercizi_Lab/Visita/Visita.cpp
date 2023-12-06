#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, M, S;
    vector<vector<int>> grafo;
    vector<bool> nodi_raggiungibili;

    in >> N >> M >> S;

    grafo.resize(N);
    nodi_raggiungibili.resize(N, false);

    int start, end;

    while(in >> start >> end){
        cout << start << end;
        grafo[start].push_back(end);
    }

    nodi_raggiungibili[S] = true;

    queue<int> nodi_visitati;
    nodi_visitati.push(S);

    while(!nodi_visitati.empty()){
        int nodo = nodi_visitati.front();
        for(int i : grafo[nodo]){
            if(!nodi_raggiungibili[i]){
                nodi_raggiungibili[i]=true;
                nodi_visitati.push(i);
            }
        }
        nodi_visitati.pop();
    }

    int sum = 0;

    for(int i=0; i<N; i++){
        if(nodi_raggiungibili[i]){
            sum++;
        }
    }

    out << sum;

    return 0;
}