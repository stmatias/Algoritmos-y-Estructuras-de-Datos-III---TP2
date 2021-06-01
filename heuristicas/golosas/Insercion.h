#ifndef INSERCION_H_
#define INSERCION_H_

#include "vector"

#include "iostream"
#include "../../grafo.h"
using namespace std;


int elegir(Grafo &G, vector<bool> &visitados, vector<int> &H);
void insertar(int elegido, Grafo &G, vector<bool> &visitados, vector<int> &H);
vector<int> heuristicaInsercion(Grafo &G);

#endif