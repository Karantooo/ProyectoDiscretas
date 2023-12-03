#include <iostream>
#include <vector>
#include <cstdlib>
#include "HashmapCiudad.h"
#include "dijkstra.h"
#include "constants.h"
using namespace std;

// TODO ir y hacer que no puedan poner de input calles mas grandes del limite
// implementar la calle parada (idea bucle)
// retornar de nodo a calle 

int main(){
    cout << "Bienvenido/a a nuestro Buscador de Rutas por el centro de Concepcion. " << endl;
    cout << "Por favor, seleccione la direccion de partida: ";

    string calle_partida, calle_destino, calle_parada = "none";
    getline(cin, calle_partida);

    cout << "Por favor, seleccione la direccion de destino: ";
    getline(cin, calle_destino);

    cout << "¿Desea hacer una parada? [y/n]: ";
    string respuesta;
    getline(cin, respuesta);
    

    if(respuesta[0] == 'y' || respuesta[0] == 'Y'){
        cout << "Por favor, ingrese la calle donde desea parar: ";
        getline(cin, calle_parada);
        swap(calle_destino, calle_parada);
    }

    bool se_repite_loop = false;
    int nodo_partida = -1, nodo_llegada = -1;
    vector<int> nodos_partida, nodos_llegada;
    vector<vector<int>> respuesta_mas_corta, auxiliar;
    do{

        vector<pair<int,int>> calle_partida_xy = coordenada_string_cartesiana(calle_partida);
        vector<pair<int,int>> calle_destino_xy = coordenada_string_cartesiana(calle_destino);

        bool cond1 = (calle_partida_xy[0].first == -1);
        bool cond2 = (calle_partida_xy[0].second == -1);
        bool cond3 = (calle_partida_xy[1].first == -1);
        bool cond4 = (calle_partida_xy[1].second == -1);

        if (cond1 || cond2 || cond3 || cond4){
            cout << "Ha ocurrido un error en el ingreso de datos: Calle de partida invalida. ";
            exit(-1);
        }

        cond1 = (calle_destino_xy[0].first == -1);
        cond2 = (calle_destino_xy[0].second == -1);
        cond3 = (calle_destino_xy[1].first == -1);
        cond4 = (calle_destino_xy[1].second == -1);

        if (cond1 || cond2 || cond3 || cond4){
            cout << "Ha ocurrido un error en el ingreso de datos: Calle de destino invalida. ";
            exit(-1);
        }

        int nodo_partida1 = coordenada_cartesiana_nodo(calle_partida_xy[0].first, calle_partida_xy[0].second);
        int nodo_partida2 = coordenada_cartesiana_nodo(calle_partida_xy[1].first, calle_partida_xy[1].second);
        int nodo_destino1 = coordenada_cartesiana_nodo(calle_destino_xy[0].first, calle_destino_xy[0].second);
        int nodo_destino2 = coordenada_cartesiana_nodo(calle_destino_xy[1].first, calle_destino_xy[1].second);
        
        vector<vector<int>> vector_resultado = dijkstra(nodo_partida1, nodo_destino1);

        vector<vector<int>> resultado_dijkstra;
        int respuesta1;
        int menor_distancia = INT_MAX;
        // Verificar Dijkstra nodo_partida1 a nodo_destino1
        if(matriz[nodo_partida2][nodo_partida1] && matriz[nodo_destino1][nodo_destino2]){
            resultado_dijkstra = dijkstra(nodo_partida1, nodo_destino1);
            respuesta1 = resultado_dijkstra[1][nodo_destino1] +
                            (retornaNumeroDeString(calle_destino) % 100) +
                            ((retornaNumeroDeString(calle_partida) % 100));
            if(respuesta1 < menor_distancia){
                menor_distancia = respuesta1;
                respuesta_mas_corta = resultado_dijkstra;
                nodo_partida = nodo_partida1;
                nodo_llegada = nodo_destino1;
            } 
        }

        // Verificar Dijkstra nodo_partida1 a nodo_destino2
        if(matriz[nodo_partida2][nodo_partida1] && matriz[nodo_destino2][nodo_destino1]){
            resultado_dijkstra = dijkstra(nodo_partida1, nodo_destino2);
            respuesta1 = resultado_dijkstra[1][nodo_destino1] +
                            (100 - (retornaNumeroDeString(calle_destino) % 100)) +
                            ((retornaNumeroDeString(calle_partida) % 100));
            if(respuesta1 < menor_distancia){
                menor_distancia = respuesta1;
                respuesta_mas_corta = resultado_dijkstra;
                nodo_partida = nodo_partida1;
                nodo_llegada = nodo_destino2;
            } 
        }

        // Verificar Dijkstra nodo_partida2 a nodo_destino1
        if(matriz[nodo_partida1][nodo_partida2] && matriz[nodo_destino1][nodo_destino2]){
            resultado_dijkstra = dijkstra(nodo_partida2, nodo_destino1);
            respuesta1 = resultado_dijkstra[1][nodo_destino1] +
                            (retornaNumeroDeString(calle_destino) % 100) +
                            (100 - (retornaNumeroDeString(calle_partida) % 100));
            if(respuesta1 < menor_distancia){
                menor_distancia = respuesta1;
                respuesta_mas_corta = resultado_dijkstra;
                nodo_partida = nodo_partida2;
                nodo_llegada = nodo_destino1;
            } 
        }

        // Verificar Dijkstra nodo_partida2 a nodo_destino2
        if(matriz[nodo_partida1][nodo_partida2] && matriz[nodo_destino2][nodo_destino1]){
            resultado_dijkstra = dijkstra(nodo_partida2, nodo_destino2);
            respuesta1 = resultado_dijkstra[1][nodo_destino1] +
                            (100 - (retornaNumeroDeString(calle_destino) % 100)) +
                            (100 - (retornaNumeroDeString(calle_partida) % 100));
            if(respuesta1 < menor_distancia){
                menor_distancia = respuesta1;
                respuesta_mas_corta = resultado_dijkstra;
                nodo_partida = nodo_partida2;
                nodo_llegada = nodo_destino2;
            } 
        }
        se_repite_loop = false;
        if (respuesta[0] == 'y' || respuesta[0] == 'Y'){
            respuesta = "n";
            calle_partida = calle_destino;
            calle_destino = calle_parada;
            se_repite_loop = true;
            auxiliar = respuesta_mas_corta;
            nodos_partida.push_back(nodo_partida);
            nodos_llegada.push_back(nodo_llegada);
        }
    }while(se_repite_loop);
    
    auxiliar.insert(auxiliar.end(), respuesta_mas_corta.begin(), respuesta_mas_corta.end());
    respuesta_mas_corta = auxiliar;

    cout << "El nodo inicial es: " << nodo_partida << " y el nodo final es: " << nodo_llegada << endl;
    for (int i = 0; i < respuesta_mas_corta[0].size(); i++){
        cout << i << " " << respuesta_mas_corta[0][i] << endl; 
    }

    return 0;
}

