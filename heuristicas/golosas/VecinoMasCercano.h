#ifndef VECINO_MAS_CERCANO_H_
#define VECINO_MAS_CERCANO_H_

#include "vector"

#include "iostream"
#include "../../grafo.h"
using namespace std;


int primeroNoIndefinido(int v, Grafo& M);
vector<int> minimoCosto(int v, Grafo& M);
Grafo vecinoMasCercano(Grafo& M);
void imprimirSolucion(vector<int> v);


#endif