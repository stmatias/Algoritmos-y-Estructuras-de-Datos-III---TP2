#include "TabuSearchEstructura.h"
#include "vector"
#include<tuple>
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
        }
        else{
            costo = costo + M[ciclo[i] - 1][ciclo[i + 1] - 1];
        }
    }
    return costo;
}


bool pertenece(Swap &swap, vector<tuple<Ciclo, Swap>> &memoria) {
    for (int i = 0; i < memoria.size(); i++) {
        Swap memorySwap = get<1>(memoria);
        if (get<0>(swap) == get<0>(memorySwap) && get<1>(swap) == get<1>(memorySwap)) {
            return true;
        }
    }
    return false;
}

//tuple <int, int, vector<int>> res
vector<tuple<Ciclo, Swap>> obtenerSubVecindad(vector<vector<int> > &M, Ciclo &ciclo, int porcentajeVecinos) {
    vector<tuple<Ciclo, Swap>> temp = {};
    for (int i = 0; i < ciclo.size(); i++) {
        for (int j = i + 1; j < ciclo.size(); j++) {
            temp.push_back(make_tuple(intercambiar(ciclo, i, j), make_tuple(j, i)));
        }
    } 
    vector<tuple<Ciclo, Swap>> res = {};
    for (int i = 0; i < temp.size() * porcentajeVecinos / 100; i++) {
        res.push_back(temp[i]);
    }
    return res;
}

tuple<Ciclo, Swap> obtenerMejor(vector<vector<int> > &M, vector<tuple<Ciclo, Swap>> &vecinos, vector<Swap> &memoria) {
    vector<tuple<Ciclo, Swap>> vecinosNoVisitados = {};
    for (int i = 0; i < vecinos.size(); i++) {
        if (!pertenece(get<1>(vecinos[i]), memoria)) { //get<1>(vecinos[i]) = swap
            vecinosNoVisitados.push_back(vecinos[i]);
        }
    }
    if(vecinosNoVisitados.size()==0){
        return {};
    }
    else{
        tuple<Ciclo, Swap> cicloMejor = vecinosNoVisitados[0];
        for (int i = 0; i < vecinosNoVisitados.size(); i++) {
            tuple<Ciclo, Swap> cicloAct = vecinosNoVisitados[i];
            if (costo(M, get<0>(cicloAct)) < costo(M, get<0>(cicloMejor))) {
                cicloMejor = cicloAct;
            }
        }
        return cicloMejor;
    }

}


vector<vector<int>> tabuSearchEstructura(vector<vector<int> > &M, int t, int maxIteraciones, int porcentajeVecinos) {
    vector<vector<int> > M1 = M;
    vector<int> ciclo = vecinoMasCercano(M1)[1];
    vector<int> mejorCiclo = ciclo;
    vector<Swap> memoria = {};
    int i = 0;
    while (i < maxIteraciones) {
        vector<tuple<Ciclo, Swap>> vecinos = obtenerSubVecindad(M, ciclo, porcentajeVecinos); //[ {ciclo, swap} ]
        if (vecinos.size() > 0) {
            tuple<Ciclo, Swap> mejor = obtenerMejor(M, vecinos, memoria);
            ciclo = get<0>(mejor);
            if (memoria.size() < t) {
                memoria.push_back(mejor);
            }
            if(ciclo.size() != 0){
                if (costo(M, ciclo) < costo(M, mejorCiclo)) {
                    mejorCiclo = ciclo;
                }
            }
        }
        i++;
    }
    vector<int> nc = {(int) mejorCiclo.size(), costo(M, mejorCiclo)};
    return {nc, mejorCiclo};
}

