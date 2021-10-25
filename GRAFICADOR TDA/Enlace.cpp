#include "Enlace.h"

Enlaces::Enlaces()
{
    head = NULL;
    tam = 0;
}

Enlaces::~Enlaces()
{
    Nodo2 *temp = head;
    Nodo2 *borrar;
    while (temp != NULL)
    {
        borrar = temp;
        temp = temp->sig;
        delete borrar;
    }
    head = NULL;
}

void Enlaces::insertarEnlace(int x1, int x2)
{
    Nodo2 *nuevo = new Nodo2();
    nuevo->v1 = x1;
    nuevo->v2 = x2;
    Nodo2 *aux1 = head;
    Nodo2 *aux2;
    while (aux1 != NULL)
    {
        aux2 = aux1;
        aux1 = aux1->sig;
    }
    if (head == aux1)
    {
        head = nuevo;
        tam++;
    }
    else
    {
        aux2->sig = nuevo;
        tam++;
    }
    nuevo->sig = aux1;
}

void Enlaces::imprimir()
{
    Nodo2 *temp = head;
    if(temp == NULL)
    {
        cout<<"NO HAY ARISTAS..."<<endl;
    }
    while (temp != NULL)
    {
        cout <<temp->v1 << "--" << temp->v2<<endl;
        temp = temp->sig;
    }
    cout << "\n";
}

void Enlaces::graficar()
{
    file.open("D:/toro/DISCRETAS/GRAFOS/Graphviz/bin/grafico.dot", ios::app);
    Nodo2 *temp = head;
    while (temp != NULL)
    {
        file << temp->v1 << "--" << temp->v2 << ";" << endl;
        temp = temp->sig;
    }
    file.close();
}