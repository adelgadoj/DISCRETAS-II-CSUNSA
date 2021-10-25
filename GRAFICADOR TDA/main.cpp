#include "Nodo.h"
#include "Grafo.h"
#include "Enlace.h"
#include "cstdlib"
#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, char *argv[])
{
    Grafo *grafoA;
    grafoA = new Grafo();
    int option;
    while(true){
        cout << "\n\t\tMAQUINA DE GRAFOS v.0.1" << endl;
        cout << "1)Crear un grafo\n";
        cout << "2)Insertar Vertice\n";
        cout << "3)Insertar Arista\n";
        cout << "4)Mostrar Vertices & Aristas\n";
        cout << "5)Visualizar GRAFO\n";
        cout << "6)Salir\n";
        cout << "R: ";
        int v,v1,v2;
        cin >> option;
        switch (option)
        {
            case 1:
                cout << "---------------"<<endl;
                grafoA -> crearGrafo();
                system("Pause && cls");
                break;
            case 2:
                cout << "---------------" << endl;
                cout << "INSERTA VERTICE: ";
                cin >>v;
                grafoA -> verificar(v);
                system( "Pause && cls" );
                break;
            case 3:
                cout << "---------------" << endl;
                cout << "INSERTA ARISTA: "<<endl;
                cout << "V1: "; cin >> v1;
                cout << "V2: "; cin >> v2;
                grafoA->verificar(v1);
                grafoA->verificar(v2);
                grafoA->ingresarE(v1,v2);
                cout << "SE INGRESO: "<<v1<<" -- "<<v2<<endl;
                system("Pause && cls");
                break;
            case 4:
                cout << "---------------" << endl;
                cout << "DATOS:\n";
                cout << "Vertices: ";
                grafoA->mostrarV();
                cout << "\nAristas: "<<endl;
                grafoA->mostrarE();
                system("Pause && cls");
                break;
            case 5:
                grafoA->graficar();
                cout <<"\nSE GRAFICO"<<endl;
                system("Pause && cls");
                break;

            case 6:
                delete grafoA;
                system("cls");
                exit(1);
                break;

            default: 
                cout<<"Elige opcion valida\n";
                system("Pause && cls");
                break;
        }
    }

    

    return 0;
}
