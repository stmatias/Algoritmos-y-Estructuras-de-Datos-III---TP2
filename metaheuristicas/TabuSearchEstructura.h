#ifndef TP2_ALGO3_TABUSEARCHESTRUCTURA_H
#define TP2_ALGO3_TABUSEARCHESTRUCTURA_H

#endif

typedef vector<int> Ciclo;
typedef tuple<int, int> Swap;

Ciclo intercambiar(Ciclo &ciclo, int i, int j);

int costo(vector <vector<int>> &M, Ciclo &ciclo);

bool pertenece(Swap &swap, vector<tuple<Ciclo, Swap>> &memoria)

vector<tuple<Ciclo, Swap>> obtenerSubVecindad(vector<vector<int> > &M, Ciclo &ciclo, int porcentajeVecinos);

tuple<Ciclo, Swap> obtenerMejor(vector<vector<int> > &M, vector<tuple<Ciclo, Swap>> &vecinos, vector<Swap> &memoria);

vector<vector<int>> tabuSearchEstructura(vector<vector<int> > &M, int t, int maxIteraciones, int porcentajeVecinos);



