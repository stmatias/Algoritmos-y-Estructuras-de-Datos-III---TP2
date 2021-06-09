#ifndef INSERCION_H_
#define INSERCION_H_

#include "vector"
#include <tuple>
#include "iostream"
#include <climits>
#include "../../grafo.h"
#include "../../metaheuristicas/TabuSearchExploradas.h"
using namespace std;


int elegir(Grafo &G, vector<bool> &visitados, vector<int> &H);
void insertar(int elegido, Grafo &G, vector<bool> &visitados, vector<int> &H);
vector<int> hamiltonianoInsercion(Grafo &G);
tuple <int, int, vector<int>> heurisitcaInsercion(Grafo &G);


#endif