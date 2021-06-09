#include "VecinoMasCercano.h"
#include "../../metaheuristicas/TabuSearchExploradas.cpp"

void imprimirSolucion(vector<int> v) {
    string res = " ";
    for (int i = 0; i < v.size(); i++){
        cout << v[i] << endl;
    }
}

int primeroNoIndefinido(int v, vector<vector<int>>& M) {
    for (int j = 0; j < M.size(); j++){
        if (M[v][j] != -1) {
            return j;
        }
    }
    return 0;
}

vector<int> minimoCosto(int v, vector<vector<int>>& M) {
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

vector<vector<int> > vecinoMasCercano(vector<vector<int>>& M){
    vector<vector<int> >M1 = M;
    int v = 1;
    vector<vector<int>> res = {};
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
    nc = {(int)h.size(), costo(M1,h)};
    res = { nc, h };
    return res;

}

tuple <int, int, vector<int> > heuristicaVecino(Grafo &G){
    vector<vector<int> > res = vecinoMasCercano(G);
    return make_tuple(res[0][0],res[0][1],res[1]);
}



