#include <vector>
#include <iostream>
#include <utility>
#include <limits>
#include<tuple>
#include <stack>
using namespace std;


pair<vector<int>, vector<int>> dfs(Grafo grafo, int root, int n) {
	int next = 1;
	vector<int>visitados(n);
	stack<int> stack;
	vector<int>pred(n);
	vector<int>orden(n);
	visitados[root] = 1;
	pred[root] = 0;
	orden[root] = next;
	stack.push(root);
	pair<vector<int>, vector<int>>res;
	
	while (!stack.empty()){
		root = stack.top();
		bool hayNodo = false;

		for (int i = 0; i < n; i++) {
			if (grafo[root][i] >= 0 && visitados[i] == 0) {
				visitados[i] = 1;
				pred[i] = root;
				next++;
				orden[i] = next;
				stack.push(i);
				hayNodo = true;
				
				break;
			}
		}
		if (!hayNodo)stack.pop();
	}
	
	res.first = pred;
	res.second = orden;
	
	return res;
}

pair<int, int>minEdge(Grafo grafo, vector<int>visitados) {
	pair<int, int>res;

	int min = std::numeric_limits<int>::max();

	for (int i = 0; i < visitados.size(); i++) {
		if (visitados[i] == 1) {

			for (int j = 0; j < grafo[i].size(); j++) {
				if (grafo[i][j] > -1 && visitados[j] == 0 && grafo[i][j] < min) {
					min = grafo[i][j];
					res.first = i;
					res.second = j;
				}
			}
		}


	}
	return res;
}

int arg(int a,vector<int>l){
	for(int i = 0;i<l.size();i++)
		if(l[i]==a)return i;
}
//u es el vertince donde iniciamos. El grafo es una matriz de adyacencia. n es la cantidad de vertices
vector<pair<int, int>> AGM(Grafo grafo, int u, int n) {
	int i = 1;


	vector<pair<int, int>> aristas;
	vector<int> visitados(grafo.size());
	visitados[u] = 1;

	while (i < n) {
		pair<int, int> v_e = minEdge(grafo, visitados);//Devuelve vertice y arista

		visitados[v_e.second] = 1;

		aristas.push_back(v_e);
		
		i++;
	}

	return aristas;

}

tuple <int, int, vector<int>> heuristicaAGM(Grafo grafo){
    tuple <int, int, vector<int>> res;

    vector<pair<int, int>> aristas_agm = AGM(grafo, 0, grafo.size());

    vector<vector<int>>arbol_minimo(grafo.size());
    for(int i=0;i<grafo.size();i++){
        for(int j=0;j<grafo.size();j++){
        	arbol_minimo[i].push_back(-1);
        }
    }


    for(int i=0;i<aristas_agm.size();i++){
        unsigned int a = aristas_agm[i].first;
        unsigned int b = aristas_agm[i].second;
        arbol_minimo[a][b]=1;
        arbol_minimo[b][a]=1;


    }
   

    pair<vector<int>, vector<int>> final_path = dfs(arbol_minimo, 0, grafo.size());

    unsigned  int cost=0;
    for(int i=0; i<final_path.second.size()-1; i++){
    	int v = arg(i+1,final_path.second);
    	int w = arg(i+2,final_path.second);
    	
    	cost+=grafo[v][w];
    }
    int v = arg(final_path.second.size(),final_path.second);

    int w = arg(0,final_path.second);
    cost+=grafo[v][w];
    
    res= make_tuple(final_path.second.size(),cost,final_path.second);


    return res;

}


