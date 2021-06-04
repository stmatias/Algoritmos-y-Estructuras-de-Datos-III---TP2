#ifndef GRAFO_H_
#define GRAFO_H_

using namespace std;
#include <fstream>

typedef int Peso;
typedef vector<vector<Peso>> Grafo;

Grafo leerGrafo();
void imprimirGrafo(Grafo &g);


#endif