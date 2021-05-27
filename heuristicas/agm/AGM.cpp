#include <vector>
#include <iostream>
#include <utility>
#include <limits>

using namespace std;

pair<vector<int>, vector<int>> dfs(vector<vector<int>> grafo, int root, int n) {
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
	while (!stack.empty())
	{
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

pair<int, int>minEdge(vector<vector<int> >grafo, vector<int>visitados) {
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

//u es el vertince donde iniciamos. El grafo es una matriz de adyacencia. n es la cantidad de vertices
vector<pair<int, int>> AGM(vector<vector<int>> grafo, int u, int n) {
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