#include "./heuristicas/golosas/VecinoMasCercano.cpp"
#include "./heuristicas/golosas/Insercion.cpp"
#include "./heuristicas/agm/AGM.cpp"
#include "./metaheuristicas/TabuSearchExploradas.h"
#include "grafo.cpp"

using namespace std;


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
	tuple <int, int, vector<int>> res;

	if(heuristica == 0){
		res = heuristicaVecino(G);
	}else if (heuristica == 1){
		res = heurisitcaInsercion(G);
	}else if (heuristica == 2){
		res = heuristicaAGM(G);
	}

	cout<<"\n"<<get<0>(res)<<"\n"<<get<1>(res)<<"\n";
	
	for (int i = 0; i < get<2>(res).size(); i++){
		cout<<(get<2>(res))[i]<<",";
	}
	cout<<"\n";
	return 0;
}
/*

int main() {

    //Asumiremos que -1 es indefinido o ya agregado
    vector<vector<int >> M = {
            {-1, 1, 2, 100},
            {1, -1, 1, 2},
            {2, 1, -1, 1},
            {100, 2, 1, -1},
    };

    //imprimirGrafo(M);
    //vector<vector<int> > res = vecinoMasCercano(M);
    //cout << "El resultado es: " << " n: " << res[0][0] << " Costo: " << res[0][1] << " La solucion es: " << endl;
    vector<vector<int> > res2 = tabuSearchExploradas(M, 2, 20, 50);
    imprimirSolucion(res2[1]);
    cout << res2[0][1] << endl;
    return 0;
}*/
