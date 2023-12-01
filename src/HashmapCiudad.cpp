#include <iostream>
#include <unordered_map>
#include <cstring>
#include <vector>
using namespace std;

int coordenada_cartesiana_nodo(int x, int y){
    return 14 * x + y;
}

vector<pair<int,int>> coordenada_string_cartesiana(string input){
    unordered_map<string, int> mapa_calles_x;
    unordered_map<string, int> mapa_calles_y;
    pair<int,int> par_horizontales1, par_horizontales2;
    pair<int,int> par_verticales1, par_verticales2;
    
    vector<pair<int, int>> vectores_horizontales;
    vector<pair<int, int>> vectores_verticales;

    //Caso de no encontrar la calle
    int x1_horizontales = -1;
    int y1_horizontales = -1;
    int x1_verticales = -1;
    int y1_verticales = -1;

    int x2_horizontales = -1;
    int y2_horizontales = -1;
    int x2_verticales = -1;
    int y2_verticales = -1;

    size_t pos = input.rfind(' ');
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

    //Hacemos un set de coordenadas para las calles verticales y diagonal
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
    mapa_calles_y["Diagonal Pedro Aguirre Cerda"] = 14;

    auto iterator_x = mapa_calles_x.find(nombre_calle);
    auto iterator_y = mapa_calles_y.find(nombre_calle);

    if (stoi(numero) > 0) {
        if(iterator_x != mapa_calles_x.end()) {
        x1_horizontales = iterator_x->second;                                       // Para las coordenadas de calles horizontales, 
        x2_horizontales = iterator_x->second;                                       // el segundo parámetro será la cuadra

        y1_horizontales = (std::stoi(numero)) / 100;                                // Establecemos una coordenada para la cuadra actual
        y2_horizontales = ((std::stoi(numero)) / 100) + 1;                          // y la siguiente

            if(nombre_calle == "Barros Arana" && 700 < stoi(numero) && stoi(numero) < 900 ){
                y1_horizontales = -1;
            }
            par_horizontales1 = make_pair(x1_horizontales,y1_horizontales);
            par_horizontales2 = make_pair(x2_horizontales,y2_horizontales);
            vectores_horizontales.push_back(par_horizontales1);
            vectores_horizontales.push_back(par_horizontales2);
            return vectores_horizontales;
        }
        if(iterator_y != mapa_calles_y.end()) {
            y1_verticales = iterator_y->second;                                     // Para las coordenadas de calles verticales,
            y2_verticales = iterator_y->second;                                     // el primer parámetro será la cuadra

            x1_verticales = (std::stoi(numero)) / 100;                              // Establecemos una coordenada para la cuadra actual
            x2_verticales = ((std::stoi(numero)) / 100) + 1;                        // y la siguiente

            if((nombre_calle == "Anibal Pinto" && 400 < stoi(numero) && stoi(numero) < 600)  ||
                (nombre_calle == "Diagonal Pedro Aguirre Cerda" && 300 < stoi(numero))){
                x1_verticales = -1;
            }
            par_verticales1 =make_pair(x1_verticales,y1_verticales);
            par_verticales2 =make_pair(x2_verticales,y2_verticales);
            vectores_verticales.push_back(par_verticales1);
            vectores_verticales.push_back(par_verticales2);
            return vectores_verticales;
        }
    } 
    x1_horizontales = -1;           
    x2_horizontales = -1;           
    y1_horizontales = -1;           
    y2_horizontales = -1;
    par_horizontales1 = make_pair(x1_horizontales,y1_horizontales);
    par_horizontales2 = make_pair(x2_horizontales,y2_horizontales);
    vectores_horizontales = {par_horizontales1, par_horizontales2};
    return vectores_horizontales;
}

pair<int, int> coordenada_nodo_cartesiana(int numero_nodo){
    pair<int, int> coordenadas_cartesianas;
    coordenadas_cartesianas.first = numero_nodo % 14;
    coordenadas_cartesianas.second = numero_nodo / 14;
    return coordenadas_cartesianas;
}

int retornaNumeroDeString(string input){
    size_t pos = input.rfind(' ');
    string nombre_calle = input.substr(0, pos);
    string numero = input.substr(pos + 1);

    int respuesta = stoi(numero);
    return respuesta;
}