#include <iostream>
#include <vector>
#include "constants.h"
#include "generar_grafo.h"
using namespace std;

struct node{
    int numeracion;
    vector<node*> nodos_adyacentes;
}grafo_concepcion[112];

int main(){
    for (int i = 0; i < matriz.size(); i++) {
        for (int j = 0; j < matriz[i].size(); j++) {
            if (matriz[i][j] == 1) {
                grafo_concepcion[i].nodos_adyacentes.push_back(&grafo_concepcion[j]);
            }
        }
        grafo_concepcion[i].numeracion = i;
    }
    for (const auto &nodo : grafo_concepcion) {
        cout << "Nodo " << nodo.numeracion << ": ";
        for (const auto &adyacente : nodo.nodos_adyacentes) {
            cout << adyacente->numeracion << ' ';
        }
        cout << '\n';
    }
    return 0;
}