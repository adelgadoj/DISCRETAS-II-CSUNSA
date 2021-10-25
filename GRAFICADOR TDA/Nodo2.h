#ifndef NODO2_H
#define NODO2_H

#include "Grafo.h"
#include "Enlace.h"
#include <iostream>
#include <fstream>
using namespace std;

class Nodo2
{
private:
    int v1;
    int v2;
    Nodo2 *sig;

public:
    Nodo2(int = 0, int = 0, Nodo2 * = NULL);
    friend class Grafo;
    
    friend class Enlaces;
};

#endif // NODO2_H
