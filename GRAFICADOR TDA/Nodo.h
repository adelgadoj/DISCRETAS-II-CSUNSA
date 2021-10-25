#ifndef NODO_H
#define NODO_H
#include "Grafo.h"
#include <iostream>
using namespace std;

class Nodo{
    private:
        int valor;
        Nodo *enlace;
    public:
        Nodo(int = 0,Nodo * =NULL);
        friend class Grafo;
};

#endif // NODO_H
