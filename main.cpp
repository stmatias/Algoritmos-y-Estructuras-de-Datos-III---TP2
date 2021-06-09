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
	else if(heuristica == 3){
	    res = tabuSearchExploradas(G, 10, 10, 10);
	}

	cout<<"\n"<<get<0>(res)<<"\n"<<get<1>(res)<<"\n";
	
	for (int i = 0; i < get<2>(res).size(); i++){
		cout<<(get<2>(res))[i]<<",";
	}
	cout<<"\n";
	return 0;
}
