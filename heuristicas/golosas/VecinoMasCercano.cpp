#include "VecinoMasCercano.h"
//HAY QUE REFACTORIZAR ESTE CODIGO.

/*La entrada consistira de una primera linea con dos enteros n, m indicando la cantidad de
vertices y aristas del grafo. Luego le sucederan m lineas con 2 enteros i, j, c, indicando que
la arista (i; j) tiene costo c asociado.
Para la salida se debe imprimir una primera linea que contenga dos enteros n, c que indican
la cantidad de vertices y el costo de la solucion optima. Luego continuara una linea con la
secuencia de vertices optima (sin incluir la repeticion del primer vertice).*/


//Por ser el grafo completo M es O(n^2)
// Matriz de adyacencia es O(n^2)
// Lista de incidencia es O(n^2)
// Lista de adyacencia es O(n^2)
//Heuristica golosa 1. Vecino más cercano. seria O(n^3) utilizando una lista de adyacencia.
										//seria  O(n^3) utilizando una matriz de adyacencia
										//seria O(n^3) utilizando la lista de incidencia


//Voy a utilizar una matriz de adyacencia
/*
vecinoMasCercano(G)
entrada: G = (V, X) de n vertices y l : X -> R
salida: H un circuito hamiltoniano
	v = un nodo cualquiera			//O(1)
	H = [v]							//O(1)
	mientras |H| = n hacer			//O(N)
		w = arg min{l(v,w),w en V \ H} //Recorrer todas las aristas que todavia no están en H con origen en v y quedarme con la mínima eso es O(M)
		H = H + w
		v = w
	fin mientras
retornar H
*/

//hay que observar que los elementos de la diagonal no deben ser evaluados, ya que el grafo no tendra dichas aristas.
//Se asume que el vector devuelto tiene en el primer vector,en el elemento 0 la cantidad de vertices agregados
//En el segundo tiene el costo minimo y luego todos los valores correspondientes a la secuencia de recorrido optima segun este algoritmo.

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

Grafo vecinoMasCercano(Grafo& M) {
	int v = 0;
	Grafo res = {};
	vector<int> nc = { 1,0 };
	vector<int> h = { v };

	while (h.size() < M.size()) {
		vector<int>valores = minimoCosto(v, M);
		int costo = valores[0];
		nc[1] += costo;
		int w = valores[1];
		nc[0]++;
		h.push_back(w);
		v = w;
	}
	nc[1] += M[0][v];
	res = { nc, h };
	return res;

}


void imprimirSolucion(vector<int> v) {
	string res = " ";
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
}
