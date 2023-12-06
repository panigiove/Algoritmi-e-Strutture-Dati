#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int righe, colonne;
    in >> righe >> colonne;

    int *vettore = new int[colonne];
    int **matrice = new int*[righe];
    int **matrice_supporto = new int*[righe];
    for(int i=0; i<righe; i++){
        matrice[i] = new int[colonne];
        matrice_supporto[i] = new int[colonne];
    }

    /* const int righe=4;
    const int colonne=5;
    int matrice[4][5]={
        {1, 8, -1, 6, 10},
        {2, 16, -3, 4, -11},
        {-4, 7, -15, 5, 12},
        {5, -2, 18, 3, 9}
    };

    int matrice_supporto[4][5]={}; */


    for(int i=0; i<righe; i++){
        int somma_riga=0;
        for(int j=0; j<colonne; j++){
            in >> matrice[i][j];
            somma_riga += matrice[i][j];
            matrice_supporto[i][j] = somma_riga;
        }
    }

    int soluzione=-1;
    for(int colonna1 = 0; colonna1<colonne; colonna1++){
        for(int colonna2 = colonna1; colonna2<colonne; colonna2++){
            int totale = 0;
            for(int i=0; i<righe; i++){
                if(colonna1-1<0){
                    int cur = matrice_supporto[i][colonna2];
                    totale = max(cur, cur+totale);
                    soluzione = max(soluzione, totale);
                }
                else{
                    int cur = matrice_supporto[i][colonna2]-matrice_supporto[i][colonna1-1];
                    totale = max(cur, cur+totale);
                    soluzione = max(soluzione, totale);
                }
            }
        }
    }

    out << soluzione;
    //cout << soluzione;
    for(int i=0; i<righe; i++){
        delete matrice[i]; 
        delete matrice_supporto[i];
    }
    delete[] matrice;
    delete[] matrice_supporto;
    return 0;
}
    