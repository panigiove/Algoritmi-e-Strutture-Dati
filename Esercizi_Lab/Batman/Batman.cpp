#include <iostream>
#include <vector>
#include <fstream>
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

/*void ts_dfs(graph& grafo, int i, vector<bool>& visitato, vector<int>& stack){
    visitato[i] = true;
    for(int k : grafo[i].adj){
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
}*/

void Batman_aux(int S, int& D, int& comb_enemy, int& first_enemy, bool& enemy){
    grafo[S].onStack=true;
    if(S==D){
        if(enemy){
            comb_enemy++;
            return;
        }
    }
    for(int i : grafo[S].adj){
        if(!grafo[i].onStack){
            if(grafo[S].lowlink!=grafo[i].lowlink && first_enemy==-1){
                enemy=true;
                first_enemy=S;
            }
            Batman_aux(i, D, comb_enemy, first_enemy, enemy);
            if(first_enemy==S){
                enemy=false;
                first_enemy=-1;
            }
            grafo[i].onStack=false;
        }
    }
}

int Batman(int S, int& D){
    int P, comb_enemy=0, first_enemy=-1;
    bool enemy = false;
    Batman_aux(S, D, comb_enemy, first_enemy, enemy);
    return comb_enemy;
}

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
            grafo[nodo].lowlink = min(grafo[k].lowlink, grafo[nodo].lowlink);
        }
    }

    if(grafo[nodo].lowlink == grafo[nodo].id_nodo){
        int n;
        do {
            n = stack.back();
            stack.pop_back();
            grafo[n].onStack = false;
        } while(n != nodo);
    }
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, M, S, D, start, end;
    in >> N >> M >> S >> D;

    grafo.resize(N);

    while(in >> start >> end){
        grafo[start].adj.push_back(end);
    }

    tarjan(S);

    int comb_enemy=Batman(S, D);

    out << comb_enemy;

    return 0;
}
