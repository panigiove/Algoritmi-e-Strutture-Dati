#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct nodo{
    vector<int> adj;
    int id_nodo = -1;
    int lowlink;
    bool onStack = false;
};

typedef vector<nodo> graph;

vector<int> stack;
graph grafo;

int id=0;
int max_comp_con=0;

// Algoritmo di Kosaraju, non è corretto al 100%
/*void componenti_connesse_dfs(graph& grafo, int counter, int nodo, vector<int>& num_comp_con){
    num_comp_con[nodo]=counter;
    for(int k : grafo[nodo]){
        if(num_comp_con[k]==0){
            componenti_connesse_dfs(grafo, counter, k, num_comp_con);
        }
    }
}

vector<int> componenti_connesse(graph& grafo, vector<int>& stack){
    vector<int> num_comp_con;
    num_comp_con.resize(grafo.size(), 0);
    int counter = 0;
    while(!stack.empty()){
        int nodo = stack.back();
        stack.pop_back();
        if(num_comp_con[nodo]==0){
            counter++;
            componenti_connesse_dfs(grafo, counter, nodo, num_comp_con);
        }
    }

    return num_comp_con;
}

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

graph trasposto(graph& grafo){
    graph grafo_trasposto;
    grafo_trasposto.resize(grafo.size());

    for(int i=0; i<grafo.size(); i++){
        for(int k : grafo[i]){
            grafo_trasposto[k].push_back(i);
        }
    }

    return grafo_trasposto;
}

vector<int> scc(graph grafo){
    vector<int> stack = topSort(grafo);
    graph grafo_trasposto = trasposto(grafo); 
    return componenti_connesse(grafo_trasposto, stack);
}*/

void tarjan(int nodo){
    stack.push_back(nodo);
    grafo[nodo].onStack = true;
    grafo[nodo].lowlink = grafo[nodo].id_nodo = id++;

    for(int k : grafo[nodo].adj){
        if(grafo[k].id_nodo==-1){
            tarjan(k);
            grafo[nodo].lowlink = min(grafo[k].lowlink, grafo[nodo].lowlink);
        }
        else if(grafo[k].onStack){
            grafo[nodo].lowlink = min(grafo[k].id_nodo, grafo[nodo].lowlink);
        }
    }

    if(grafo[nodo].lowlink == grafo[nodo].id_nodo){
        int n;
        int counter = 0;
        do {
            n = stack.back();
            stack.pop_back();
            grafo[n].onStack = false;
            counter++;
        } while(n != nodo);

        max_comp_con = max(max_comp_con, counter);
    }
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, M, inizio, fine;

    in >> N >> M;

    grafo.resize(N);

    while(in >> inizio >> fine){
        grafo[inizio].adj.push_back(fine);
    }

    //tarjan(grafo, max_comp_con);

    //vector<int> comp_con = scc(grafo);
    for(int i=0; i<N; i++){
        if(grafo[i].id_nodo==-1){
            tarjan(i);
        }
    }

    /*for(int i=0; i<comp_con.size(); i++){
        if(comp_con[i]>counter_comp_con.size()){
            counter_comp_con.push_back(0);
        }

        counter_comp_con[comp_con[i]-1]++;
    }

    for(int i=0; i<counter_comp_con.size(); i++){
        max_comp_con=max(max_comp_con, counter_comp_con[i]);
    }*/

    out << max_comp_con;

    return 0;
}