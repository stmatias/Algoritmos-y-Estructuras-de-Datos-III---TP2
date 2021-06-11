#include "TabuSearchExploradas.h"
#include "vector"
#include "../heuristicas/golosas/VecinoMasCercano.h"

Ciclo intercambiar(Ciclo &ciclo, int i, int j) {
    Ciclo res = ciclo;
    for (int k = 0; k < j - i; k++) {
        int temp = res[i + k];
        res[i + k] = res[j - k];
        res[j - k] = temp;
    }
    return res;
}


int costo(vector<vector<int> > &M, Ciclo &ciclo) {
    int costo = 0;
    for (int i = 0; i < ciclo.size(); i++) {
        if (i == ciclo.size() - 1) {
            costo = costo + M[ciclo[i] - 1][ciclo[0] - 1];
        } else {
            costo = costo + M[ciclo[i] - 1][ciclo[i + 1] - 1];
        }
    }
    return costo;
}

bool pertenece(Ciclo &ciclo, vector<Ciclo> &memoria) {
    for (int i = 0; i < memoria.size(); i++) {
        if (ciclosIguales(ciclo, memoria[i])) {
            return true;
        }
    }
    return false;
}

vector<Ciclo> obtenerSubVecindad(vector<vector<int> > &M, Ciclo &ciclo, int porcentajeVecinos, vector<Ciclo> &memoria) {
    vector<Ciclo> temp = {};
    for (int i = 0; i < ciclo.size(); i++) {
        for (int j = i + 1; j < ciclo.size(); j++) {
            Ciclo actual = intercambiar(ciclo, i, j);   
            if(!pertenece(actual, memoria)){
                temp.push_back(actual);
            }
        }
    }
    vector<Ciclo> res = {};
    for (int i = 0; i < temp.size() * porcentajeVecinos / 100; i++) {
        res.push_back(temp[i]);
    }
    return res;
}

//Funciona con la precondicion: ciclo1.size() == ciclo2.size()
bool ciclosIguales(Ciclo &ciclo1, Ciclo &ciclo2) {
    for (int i = 0; i < ciclo1.size(); i++) {
        if (ciclo1[i] != ciclo2[i]) {
            return false;
        }
    }
    return true;
}

//Pre: vecinos.size()>0
Ciclo obtenerMejor(vector<vector<int> > &M, vector<Ciclo> &vecinos) {
    Ciclo cicloMejor = vecinos[0];
    for (int i = 0; i < vecinos.size(); i++) {
        Ciclo cicloAct = vecinos[i];
        if (costo(M, cicloAct) < costo(M, cicloMejor)) {
            cicloMejor = cicloAct;
        }
    }
    return cicloMejor;
}


tuple<int, int, vector<int>>
tabuSearchExploradas(vector<vector<int> > &M, int t, int maxIteraciones, int porcentajeVecinos) {
    vector<vector<int>> M1 = M;
    vector<int> ciclo = vecinoMasCercano(M1)[1];
    vector<int> mejorCiclo = ciclo;
    vector<Ciclo> memoria = {};
    int i = 0;
    while (i <= maxIteraciones) {
        vector<Ciclo> vecinos = obtenerSubVecindad(M, ciclo, porcentajeVecinos, memoria);
        if (vecinos.size() > 0) {
            ciclo = obtenerMejor(M, vecinos);
            if (memoria.size() < t) {
                memoria.push_back(ciclo);
            }
            if (ciclo.size() != 0) {
                if (costo(M, ciclo) < costo(M, mejorCiclo)) {
                    mejorCiclo = ciclo;
                }
            }
        }
        i++;
    }
    vector<int> nc = {(int) mejorCiclo.size(), costo(M, mejorCiclo)};
    return make_tuple(nc[0], nc[1], mejorCiclo);
}