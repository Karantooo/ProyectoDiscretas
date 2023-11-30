#include <iostream>
#include <vector>
#include "HashmapCiudad.h"
#include "dijkstra.h"
using namespace std;

struct node{
    int numeracion;
    vector<node*> nodos_adyacentes;
};

int main(){
    dijkstra(5);
    return 0;
}

