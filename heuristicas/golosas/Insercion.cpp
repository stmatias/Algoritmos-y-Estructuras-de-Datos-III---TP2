#include "Insercion.h"



int elegir(Grafo &G, vector<bool> &visitados, vector<int> &H) {
	int res = -1;
	
	int dist_res = int_max;
	int dist_cur = int_max;

	for (int i = 0; i < H.size(); i++) {
		int curNear = -1;
		for (int j = 0; j < G.size(); j++){
			if(!visitados[j] && (curNear == -1 || G[i][j] < G[i][curNear])){
            	curNear = j;
        	}
		}
		
		dist_cur = G[i][masCercanoAlActual];
		
		if(dist_cur < dist_res) {
			res = dist_cur;
			dist_res = dist_cur;
		}
	}
	return res;
}


void insertar(int elegido, Grafo &G, vector<bool> &visitados, vector<int> &H) {
	int totl = INT_MAX;
	int curl;
	int prev;
	int next;

	for (int i = 0; i < H.size() - 1; i++) {
		curl = G[H[i]][elegido] + G[elegido][H[i+1]] - G[H[i]][H[i+1]];
		if(curl < totl) {
			totl = curl;
			prev = i;
			next = i+1;
		}
	}
	curl =  G[H[H.size()-1]][H[0]];
	if(curl < totl) {
		totl = curl;
		prev = H.size()-1;
		next = 0;
	}
	H.push_back(elegido);

	for (int i = H.size() - 1; i > next; i--){
		int aux = v[i-1];
		v[i-1] = v[i];
		v[i] = aux;	
	}
}



vector<int> heuristicaInsercion(Grafo &G) {
	vector<bool> visitados(G.size(), false);
	vector<int> H; 
	for (int i = 0; i < 3; ++i){
		visitados[i] = true;
		H.push_back(i);
	}
	while(H.size()<=G.size()){ 
		int elegido = elegir(G, visitados, H);
		visitados[elegido] = true;
		insertar(elegido, G, visitados, H);
	}

	return H;
}