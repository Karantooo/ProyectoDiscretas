#include <iostream>
#include <vector>
#include "constants.h"
using namespace std;

int minima_distancia(vector<int> distancias, vector<bool> nodos_visitados) {
    int indice = -1, minimo = INT_MAX;
    for (int i = 0; i < distancias.size(); i++) {
        if (!nodos_visitados[i] && minimo >= distancias[i]) {
            indice = i;
            minimo = distancias[i];
        }
    }
    return indice;
}
void dijkstra(int nodo_inicio) {
    vector<int> distancia_a_nodo(112);
    vector<bool> nodos_explorados(112);
    vector<int> nodos_previos(112);

    for (int i = 0; i < 112; i++) {
        distancia_a_nodo[i] = INT_MAX;
        nodos_explorados[i] = false;
        nodos_previos[i] = -1;
    }

    distancia_a_nodo[nodo_inicio] = 0;

    for (int i = 0; i < 111; i++) {
        int nodo_visitado = minima_distancia(distancia_a_nodo, nodos_explorados);
        
        nodos_explorados[nodo_visitado] = true;

        for (int j = 0; j < 112; j++) {
            if (matriz[nodo_visitado][j] != 0 && !nodos_explorados[j] && distancia_a_nodo[nodo_visitado] != INT_MAX && distancia_a_nodo[nodo_visitado] + 100 < distancia_a_nodo[j]) {
                distancia_a_nodo[j] = distancia_a_nodo[nodo_visitado] + 100;
                nodos_previos[j] = nodo_visitado;
            }
        }
    }
}