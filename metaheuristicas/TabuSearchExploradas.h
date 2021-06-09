#ifndef TP2_ALGO3_TABUSEARCHEXPLORADAS_H
#define TP2_ALGO3_TABUSEARCHEXPLORADAS_H

#include "../grafo.h"
#include "vector"

#endif

typedef vector<int> Ciclo;

Ciclo intercambiar(Ciclo &ciclo, int i, int j);

int costo(vector <vector<int>> &M, Ciclo &ciclo);

vector <Ciclo> obtenerSubVecindad(vector <vector<int>> &M, Ciclo &ciclo, int porcentajeVecinos);

//Funciona con la precondicion: ciclo1.size() == ciclo2.size()
bool ciclosIguales(Ciclo &ciclo1, Ciclo &ciclo2);

bool pertenece(Ciclo &ciclo, vector <Ciclo> &memoria);

//Pre: vecinos.size()>0
Ciclo obtenerMejor(vector <vector<int>> &M, vector <Ciclo> &vecinos, vector <Ciclo> &memoria);

tuple <int, int, vector<int>>  tabuSearchExploradas(vector <vector<int>> &M, int t, int maxIteraciones, int porcentajeVecinos);


