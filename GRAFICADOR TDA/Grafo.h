#ifndef GRAFO_H
#define GRAFO_H
#include "Nodo.h"
#include "Enlace.h"
#include <iostream>
#include <fstream>
using namespace std;
class Nodo;
class Enlaces;
class Grafo{
    private:
        Nodo *cabeza;
        int vertices;
        Enlaces *E;
        ofstream archivo;

    public:
        Grafo();
		~Grafo();
        void crearGrafo();
        void ingresarVertice(int);
        void ingresarE(int, int);
        void mostrarV();
        void mostrarE();
        void getNV();
        void graficar();
        void graficaV();
        void graficaE();
        void verificar(int);
};  
#endif // GRAFO_H
