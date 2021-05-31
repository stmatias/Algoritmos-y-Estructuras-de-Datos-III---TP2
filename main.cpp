#include "./heuristicas/golosas/VecinoMasCercano.cpp"
#include "./heuristicas/agm/AGM.cpp"
#include "grafo.cpp"
using namespace std;



int main() {
	
	//Asumiremos que -1 es indefinido o ya agregado
	Grafo M = { {-1, 1,2 ,100},
				{1, -1, 1,2},
				{2, 1, -1,1},
				{100, 2, 1,-1},
	};
	imprimirGrafo(M);
	Grafo res = vecinoMasCercano(M);
	//imprimirSolucion(res[1]);
	
	//cout << "El resultado es: " << " n: " << res[0][0] << " Costo: " << res[0][1] << " La solucion es: " << endl;
	return 0;
}
