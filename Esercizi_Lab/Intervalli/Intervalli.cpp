#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

bool function (pair<int, int> i, pair<int, int> j){
    if(i.first==j.first){
        return i.second<j.second;
    }
    else{
        return i.first<j.first;
    }
}

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");

    int numero_intervalli;
    in >> numero_intervalli;

    vector<pair<int, int>> intervalli;
    int inizio, fine, lunghezza;

    for(int i=0; i<numero_intervalli; i++){
        in >> inizio >> fine;
        intervalli.push_back(make_pair(inizio, fine));
    }

    sort(intervalli.begin(), intervalli.end(), function);

    pair<int, int> max_intervallo_coperto, min_intervallo_scoperto;

    max_intervallo_coperto.first=intervalli[0].first;
    max_intervallo_coperto.second=intervalli[0].second;

    min_intervallo_scoperto.first=0;
    min_intervallo_scoperto.second=0;
    lunghezza=min_intervallo_scoperto.second-min_intervallo_scoperto.first;

    for(int i=1; i<intervalli.size(); i++){
        if(intervalli[i].first<=max_intervallo_coperto.second){
            max_intervallo_coperto.second=max(intervalli[i].second, max_intervallo_coperto.second);
        }
        else if(intervalli[i].first>max_intervallo_coperto.second){
            if(intervalli[i].first-max_intervallo_coperto.second>lunghezza){
                min_intervallo_scoperto.first=max_intervallo_coperto.second;
                min_intervallo_scoperto.second=intervalli[i].first;
                lunghezza=min_intervallo_scoperto.second-min_intervallo_scoperto.first;
            }
            max_intervallo_coperto.second=intervalli[i].second;
        }
    }

    if(lunghezza==0){
        out << 0;
    }
    else{
        out << min_intervallo_scoperto.first << " " << min_intervallo_scoperto.second;
    }
    return 0;
}