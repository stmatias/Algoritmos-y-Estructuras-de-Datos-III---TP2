#include "./heuristicas/golosas/VecinoMasCercano.cpp"
#include "./heuristicas/golosas/Insercion.cpp"
#include "./heuristicas/agm/AGM.cpp"
#include "grafo.cpp"
using namespace std;
/*
int main(int argc, char  **argv){
	if (argc != 3 ){
		cout<<"ERROR";
		return 1;
	}
	
	int heuristica = atoi(argv[1]); 
	char* input = argv[2];

	
	ifstream fileInput;
    fileInput.open(input);

	Grafo G = leerGrafo(fileInput);
	imprimirGrafo(G);
	tuple <int, int, vector<int>> res;

	if(heuristica == 0){
		res = heurisitcaInsercion(G);
	}else if (heuristica == 1){
		res = heuristicaAGM(G);
	}

	cout<<"\n"<<get<0>(res)<<"\n"<<get<1>(res)<<"\n";
	
	for (int i = 0; i < get<2>(res).size(); i++){
		cout<<(get<2>(res))[i]<<",";
	}
	cout<<"\n";
	return 0;
}
*/

int main() {
	
	//Asumiremos que -1 es indefinido o ya agregado
	Grafo M = { {-1, 3,2 ,4},
				{2, -1, 1,2},
				{2, 1, -1,1},
				{100, 2, 1,-1},
	};
	imprimirGrafo(M);
	Grafo res = vecinoMasCercano(M);
	cout << "El resultado es: " << " n: " << res[0][0] << " Costo: " << res[0][1] << " La solucion es: " << endl;
    imprimirSolucion(res[1]);
	return 0;
}
