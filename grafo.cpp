#include "grafo.h"



Grafo leerGrafo() {
    int n, m;
    cin >> n >> m;
    Grafo G(n, vector<Peso>(n, -1));

    for (int i = 0; i < m; i++) {
        int v, w, peso;
        cin >> v >> w >> peso;
		G[v][w] = peso;
        G[v][w] = peso;
    }
    for(int i = 0; i < G.size(); i++) {
        G[i][i] = 0;
    }
    return G;
}

void imprimirGrafo(Grafo &g) {
	cout << "   ";
	for(int i = 0; i< g.size(); i++) {
		cout << i << "\t";
	}
	cout << "\n";
	cout << "  ";
	for(int i = 0; i< (g.size()-1)*4; i++) {
		cout << "__";
	}
	cout << "\n";

    for (int i = 0; i < g.size(); i++)
    {
        cout << i << "| ";
        for (int j = 0; j < g[i].size(); j++)
        {
            cout << g[i][j] << "\t\n"[j == g.size() - 1];
        }
    }
}
