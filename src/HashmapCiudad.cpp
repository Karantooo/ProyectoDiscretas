#include <iostream>
#include <unordered_map>
#include <cstring>
#include "HashmapCiudad.h"
using namespace std;

int coordenada_cartesiana_nodo(int x, int y){
    return 14 * y + x;
}

pair<int, int> coordenada_string_cartesiana(string input){
    unordered_map<string, int> mapa_calles_x;
    unordered_map<string, int> mapa_calles_y;

    //Caso de no encontrar la calle
    int x = -1;
    int y = -1;

    size_t pos = input.find(' ');
    string nombre_calle = input.substr(0, pos);
    string numero = input.substr(pos + 1);

    //Hacemos un set de coordenadas para las calles horizontales
    
    mapa_calles_x["Carrera"] = 0;
    mapa_calles_x["Maipu"] = 1;
    mapa_calles_x["Freire"] = 2;
    mapa_calles_x["Barros Arana"] = 3;
    mapa_calles_x["O'higgins"] = 4;
    mapa_calles_x["San Martin"] = 5;
    mapa_calles_x["Cochrane"] = 6;
    mapa_calles_x["Chacabuco"] = 7;

    //Hacemos un set de coordenadas para las calles verticales
    mapa_calles_y["Arturo Prat"] = 0;
    mapa_calles_y["Serrano"] = 1;
    mapa_calles_y["Salas"] = 2;
    mapa_calles_y["Angol"] = 3;
    mapa_calles_y["Lincoyan"] = 4;
    mapa_calles_y["Rengo"] = 5;
    mapa_calles_y["Caupolican"] = 6;
    mapa_calles_y["Anibal Pinto"] = 7;
    mapa_calles_y["Colo Colo"] = 8;
    mapa_calles_y["Castellon"] = 9;
    mapa_calles_y["Tucapel"] = 10;
    mapa_calles_y["Orompello"] = 11;
    mapa_calles_y["Ongolmo"] = 12;
    mapa_calles_y["Paicavi"] = 13;

    auto iterator_x = mapa_calles_x.find(nombre_calle);
    auto iterator_y = mapa_calles_y.find(nombre_calle);

    if(iterator_x != mapa_calles_x.end()) {
        x = iterator_x->second;
        y = std::stoi(numero);
    }
    if(iterator_y != mapa_calles_x.end()) {
        y = iterator_y->second;
        x = std::stoi(numero);
    }

    return make_pair(x,y);
}

pair<int, int> coordenada_nodo_cartesiana(int numero_nodo){
    pair<int, int> coordenadas_cartesianas;
    coordenadas_cartesianas.first = numero_nodo % 14;
    coordenadas_cartesianas.second = numero_nodo / 14;
    return coordenadas_cartesianas;
}
