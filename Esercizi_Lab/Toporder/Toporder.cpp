#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

typedef vector<vector<int>> graph;

void ts_dfs(graph& grafo, int i, vector<bool>& visitato, vector<int>& stack){
    visitato[i] = true;
    for(int k : grafo[i]){
        if(!visitato[k]){
            ts_dfs(grafo, k, visitato, stack);
        }
    }
    stack.push_back(i);
}

vector<int> topSort(graph& grafo){
    vector<int> stack;
    vector<bool> visitato;
    visitato.resize(grafo.size(), false);
    for(int i=0; i<grafo.size(); i++){
        if(!visitato[i]){
            ts_dfs(grafo, i, visitato, stack);
        }
    }
    return stack;
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    graph grafo;
    int N, M, inizio, fine;

    in >> N >> M;
    grafo.resize(N);

    while(in >> inizio >> fine){
        grafo[inizio].push_back(fine);
    }

    vector<int> ord_topologico = topSort(grafo);

    for(int i=ord_topologico.size()-1; i>=0; i--){
        out << ord_topologico[i] <<" ";
    }

    return 0;
}