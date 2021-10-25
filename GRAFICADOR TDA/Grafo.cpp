#include "Grafo.h"
//#include "fstream"
void Grafo::crearGrafo()
{
    cabeza = NULL;
    vertices = 0;
    E = NULL;
    E = new Enlaces();
    archivo.open("D:/toro/DISCRETAS/GRAFOS/Graphviz/bin/grafico.dot");
    archivo.close();
    cout<<"SE CREO EL GRAFO...!!"<<endl;
}

Grafo::Grafo() {
	cabeza = NULL;
    vertices = 0;
    E = NULL; 
    E = new Enlaces();

}

Grafo::~Grafo()
{
	Nodo *temp = cabeza;
	Nodo *borrar;
	while(temp != NULL)
	{
		borrar = temp;
		temp = temp->enlace;
		delete borrar;
	}
	cabeza = NULL;
}

void Grafo::getNV(){
    cout<<"\nTIENES:"<<vertices<<"!!"<<endl;
}

void Grafo::ingresarVertice(int x){
    Nodo *nuevo = new Nodo();
    nuevo -> valor = x;
    Nodo *aux1 = cabeza;
    Nodo *aux2;

    while(aux1 != NULL){
        aux2 = aux1;
        aux1 = aux1->enlace;
    }
    if(cabeza == aux1){
        cabeza = nuevo;
        vertices++;
    }
    else{
        aux2->enlace = nuevo;
        vertices++;
    }
    nuevo->enlace = aux1;
}
void Grafo::mostrarV(){
    Nodo *aux = cabeza;
    if(aux==NULL){
        cout<<"NO TIENE VERTICES..."<<endl;

    }
    while(aux!=NULL){
        cout<< "\n" << aux->valor <<" ";
        aux=aux->enlace;
    }
    
}
void Grafo::ingresarE(int x1, int x2){
    E->insertarEnlace(x1,x2);
}
void Grafo::mostrarE(){
    E->imprimir();
}
void Grafo::graficaV()
{
    Nodo *aux = cabeza;
    while (aux != NULL)
    {
        archivo << aux->valor <<";\n";
        cout << aux->valor << " " << endl;
        aux = aux->enlace;
    }
}
void Grafo::graficaE()
{
    E->graficar();
}
void Grafo::graficar()
{
    archivo.open("D:/toro/DISCRETAS/GRAFOS/Graphviz/bin/grafico.dot");
    archivo << "graph A {" << endl;
    graficaV();
    archivo.close();
    graficaE();
    archivo.open("D:/toro/DISCRETAS/GRAFOS/Graphviz/bin/grafico.dot", ios::app);
    archivo << "\n}";
    archivo.close();
    system("cls & D: & cd toro & cd DISCRETAS & cd GRAFOS & cd Graphviz & cd bin & dot -Tjpg grafico.dot -o grafico.jpg & grafico.jpg");
}

void Grafo::verificar(int n){
    cout<<"VERIFICANDO...";
    Nodo *aux = cabeza;
    bool existe = false;
    while (aux != NULL)
    {
        if(aux->valor == n){
            existe = true;
        }
        aux = aux->enlace;
    } 
    if( existe == false){
        ingresarVertice(n);
        cout<<"Se agrego "<<n<<" a los VERTICES"<<endl;
    }
}

