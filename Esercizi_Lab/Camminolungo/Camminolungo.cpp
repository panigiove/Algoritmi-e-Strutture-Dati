#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
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

vector<int> topSort(graph& grafo, int nodo_iniziale){
    vector<int> stack;
    vector<bool> visitato;
    visitato.resize(grafo.size(), false);
    if(!visitato[nodo_iniziale]){
        ts_dfs(grafo, nodo_iniziale, visitato, stack);
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

int camminolungo(graph& grafo, vector<int>& nodi_iniziali){
    vector<int> top_sort;
    vector<int> distanze;
    int max_dist=0;

    distanze.resize(grafo.size(), -1);

    //top_sort.resize(nodi_iniziali.size());

    for(int i=0; i<nodi_iniziali.size(); i++){
        top_sort = topSort(grafo, nodi_iniziali[i]);
        distanze[top_sort.back()] = 0;
        while(!top_sort.empty()){
            int nodo = top_sort.back();
            for(int i : grafo[nodo]){
                if(distanze[nodo]>=distanze[i]){
                    distanze[i] = distanze[nodo] + 1;
                }
            }

            top_sort.pop_back();
        }

        for(int i=0; i<distanze.size(); i++){
            max_dist = max(max_dist, distanze[i]);
            distanze[i] = -1;
        }
    }

    return max_dist;
}


//algoritmo giusto teoricamente, ma spreca troppa memoria
/*int camminolungo(graph& grafo, vector<int>& nodi_iniziali){
    queue<int> nodi_da_visitare;
    int max_dist=0, max_temp=0;
    bool check;

    vector<int> nodi_isolati;

    //for(int i=0; i<grafo.size(); i++){
    //    if(grafo[i].size()==0){
    //        nodi_isolati.push_back(i);
    //    }
    //}

    //graph grafo_trasporto = trasposto(grafo);

    //for(int i : nodi_isolati){
    for(int k : nodi_iniziali){
        max_temp=0;
        nodi_da_visitare.push(k);
        while(!nodi_da_visitare.empty()){
            int size = nodi_da_visitare.size();
            check = false;

            for(int i=0; i<size; i++){
                int nodo = nodi_da_visitare.front();

                // if(grafo_trasporto[i].size()!=0){
                //     for(int k : grafo_trasporto[nodo]){
                //         nodi_da_visitare.push(k);
                //         check = true;
                //     }
                // }

                if(grafo[nodo].size()!=0){
                    for(int j : grafo[nodo]){
                        nodi_da_visitare.push(j);
                        check = true;
                    }
                }


                nodi_da_visitare.pop();
            }

            if(check){
                max_temp++;
            }
        }

        max_dist=max(max_dist, max_temp);
    }

    return max_dist;
}*/

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    graph grafo;
    vector<bool> visitati;
    vector<int> nodi_iniziali;
    int N, M, inizio, fine;

    in >> N >> M;
    grafo.resize(N);
    visitati.resize(N, true);

    while(in >> inizio >> fine){
        grafo[inizio].push_back(fine);
        if(visitati[fine]){
            visitati[fine]=false;
        }
    }

    for(int i=0; i<visitati.size(); i++){
        if(visitati[i]){
            nodi_iniziali.push_back(i);
        }
    }

    int max_lunghezza_cammino = camminolungo(grafo, nodi_iniziali);

    out << max_lunghezza_cammino;

    return 0;
}