#include <iostream>
#include <fstream>
using namespace std;

int main(){
    ifstream in("input.txt");
    ofstream out("output.txt");
    int dim;
    in >> dim;
    int *array = new int[dim];
    
    if(dim==0){
        return 0;
    }

    for(int i=0; i<dim; i++){
        in >> array[i];
    }

    int maxTemp1=0, maxTemp2=0;
    for(int i=0; i<dim; i++){
        maxTemp1 = max(maxTemp1+array[i], 0);
        maxTemp2 = max(maxTemp1, maxTemp2);
    }

    out << maxTemp2;
    delete[] array;
    return 0;
}
    
    