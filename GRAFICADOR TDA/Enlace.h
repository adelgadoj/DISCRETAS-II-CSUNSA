#ifndef ENLACE_H
#define ENLACE_H

#include "Nodo2.h"
#include "fstream"
#include <iostream>
using namespace std;
class Nodo2;
class Enlaces
{
private:
    Nodo2 *head;
    int tam;
    ofstream file;

public:
    Enlaces();
    ~Enlaces();
    void insertarEnlace(int, int);
    void imprimir();
    void graficar();

};

#endif
