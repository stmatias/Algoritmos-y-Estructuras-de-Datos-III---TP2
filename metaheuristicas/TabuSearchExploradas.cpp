#include "TabuSearchExploradas.h"
#include "vector"
#include "iostream"
#include "../grafo.h"
#include "../heuristicas/golosas/VecinoMasCercano.h"

typedef vector<int> Ciclo;


Ciclo intercambiar(Ciclo ciclo, int i, int j) {
    Ciclo res = ciclo;
    for (int k = i; k < j; k++) {
        res[k] = res[j + 1 - k];
    }
    return res;
}

int costo(Grafo M, Ciclo ciclo) {
    int costo = 0;
    for (int i = 0; i < ciclo.size(); i++) {
        costo = costo + M[ciclo[i] - 1][ciclo[i + 1] - 1];
        if (i == ciclo.size() - 1) {
            costo = costo + M[ciclo[i] - 1][ciclo[0] - 1];
        }
    }
    return costo;
}

vector<Ciclo> obtenerSubVecindad(Grafo M, Ciclo ciclo, int porcentajeVecinos) {
    vector<Ciclo> temp;
    for (int i = 0; i < ciclo.size(); i++) {
        for (int j = 0; j < ciclo.size(); j++) {
            temp.push_back(intercambiar(ciclo, i, j));
        }
    }
    vector<Ciclo> res = {};
    for (int i = 0; i < temp.size()*porcentajeVecinos/100; i++){
        res.push_back(temp[i]);
    }
    return res;
}

Ciclo obtenerMejor();

vector<vector<int> > tabuSearchExploradas(Grafo M, int t, int maxIteraciones, int porcentajeVecinos) {
    vector<int> ciclo = vecinoMasCercano(M)[1];
    vector<int> mejorCiclo = ciclo;
    vector<Ciclo> memoria = {};
    int i = 0;
    while (i < maxIteraciones) {
        vector<Ciclo> vecinos = obtenerSubVecindad(M, ciclo, porcentajeVecinos);
        ciclo = obtenerMejor(vecinos, memoria); // Ver el de menor costo sin contar ciclos ya vistos
        //memoria.recordar(ciclo); // Agregar a la lista, pero con un tope de t elementos
        //if (costo(ciclo) < costo(mejorCiclo)) {
        //    mejorCiclo = ciclo;
        //}
    }

}