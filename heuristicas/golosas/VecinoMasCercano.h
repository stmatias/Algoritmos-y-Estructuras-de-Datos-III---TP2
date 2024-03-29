#ifndef VECINO_MAS_CERCANO_H_
#define VECINO_MAS_CERCANO_H_

#include "vector"
#include <tuple>

#include "iostream"
#include "../../grafo.h"
using namespace std;


int primeroNoIndefinido(int v, vector<vector<int>>& M);
vector<int> minimoCosto(int v, vector<vector<int>>& M);
vector<vector<int>> vecinoMasCercano(vector<vector<int>>& M);
tuple <int, int, vector<int> > heuristicaVecino(Grafo &G);
void imprimirSolucion(vector<int> v);


#endif