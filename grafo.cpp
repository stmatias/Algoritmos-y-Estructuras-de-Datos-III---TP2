#include "grafo.h"

Grafo leerGrafo(ifstream& inputFile) {
    int n, m;
    inputFile >> n >> m;
    Grafo G(n, vector<Peso>(n, -1));

    for (int i = 0; i < m; i++) {
        int v, w, peso;
        inputFile >> v >> w >> peso;
        
		G[v][w] = peso;
        G[w][v] = peso;
    }
    for(int i = 0; i < G.size(); i++) {
        G[i][i] = -1;
    }
    inputFile.close();
    return G;

}

void imprimirGrafo(Grafo &G) {
	cout << "   ";
	for(int i = 0; i< G.size(); i++) {
		cout << i << "\t";
	}
	cout << "\n";
	cout << "  ";
	
	cout << "\n";

    for (int i = 0; i < G.size(); i++){
        cout << i << "  ";
        for (int j = 0; j < G[i].size(); j++){
            cout << G[i][j] << "\t\n"[j == G.size() - 1];
        }
    }
}
