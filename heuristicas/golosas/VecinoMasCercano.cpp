#include "VecinoMasCercano.h"

void imprimirSolucion(vector<int> v) {
    string res = " ";
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
}

int primeroNoIndefinido(int v, Grafo& M) {
    for (int j = 0; j < M.size(); j++){
        if (M[v][j] != -1) {
            return j;
        }
    }
    return 0;
}

vector<int> minimoCosto(int v, Grafo& M) {
    int w = primeroNoIndefinido(v, M);
    int min = M[v][w];
    for (int j = 0; j < M.size(); j++){
        if (M[v][j] != -1 && M[v][j] <= min) {
            min = M[v][j];
            w = j;
        }
    }

    for (int i = 0; i < M.size(); i++){
        M[i][v] = -1;
    }

    vector<int> res = { min, w };
    return res;
}

vector<vector<int> > vecinoMasCercano(Grafo& M){
    int v = 1;
    Grafo res = {};
    vector<int> nc = { 1,0 };
    vector<int> h = { v };

    while (h.size() < M.size()) {
        vector<int>valores = minimoCosto(v - 1, M);
        int costo = valores[0];
        nc[1] += costo;
        int w = valores[1] + 1;
        nc[0]++;
        h.push_back(w);
        v = w;
    }
    nc[1] += M[0][v - 1];
    res = { nc, h };
    return res;

}



