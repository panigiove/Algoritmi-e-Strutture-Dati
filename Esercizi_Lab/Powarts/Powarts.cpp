#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct node{
    vector<pair<int, int>> adj;
    int peso_totale;
};

vector<node> grafo;

typedef vector<node> grafo;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int N, M, W;
    in >> N >> M;
}