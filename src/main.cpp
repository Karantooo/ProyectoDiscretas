#include <iostream>
#include <vector>
#include "HashmapCiudad.h"
#include "constants.h"
using namespace std;

struct node{
    int numeracion;
    vector<node*> nodos_adyacentes;
};

int main(){
    auto ola = coordenada_string_cartesiana("Carrera 890");
    cout << ola.first << " " << ola.second;
    node grafo_concepcion[112];
    
    return 0;
}

