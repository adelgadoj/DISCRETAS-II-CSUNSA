#include <iostream>
#include <fstream>
using namespace std;
struct letras
{
    char letra;
    int num;
};
struct nodo
{
    char letra;
    int frecuencia;
    struct nodo *sig;
    struct nodo *izq, *der;
};
typedef struct nodo *Inicio;

struct arbol
{
    nodo *head;
};


void agregarletra(char letra, letras dicionario[52]){

    for(int i=0 ; i<52 ; i++)
    {
        if (letra == dicionario[i].letra)
            dicionario[i].num++;
    }
}
void verFrecuencias(letras dicionario[52]){
    cout<<"\n\nFRECUENCIAS:"<<endl;
    for(int i=0; i<52 ; i++){
        if (dicionario[i].num > 0){
            cout << dicionario[i].letra << " -> ";
            cout << dicionario[i].num << endl;
        }
    }
}
//ORDENAMIENTO DE LA LISTA DE FRECUENCIAS
void ordenar(letras lista[52]){

    letras aux1;

    for(int i = 0 ; i <52 ; i++){
        for(int j= 0 ; j <52; j++){
            if(lista[j].num > lista[j+1].num){ //SI EL SIGUIENTE ES MAYOR SE INSTERCAMBIA
                aux1 = lista[j];
                lista[j] = lista[j+1];
                lista[j+1] = aux1;
            }
        }
    }
}
void llenarLetras(letras v[52]){
    

    for (int i = 0; i < 26; i++)
    {
        v[i].letra = i + 97;
        v[i].num = 0;
    }
    for (int j = 0 ; j < 26; j++)
    {
        v[j+26].letra = j + 65;
        v[j+26].num = 0;
    }
}

void insertarNodo(arbol *Tree, letras diccionario){
    nodo *nuevo = new nodo(); //CREAMOS UN NODO NUEVO 
    nuevo->letra = diccionario.letra;
    nuevo->frecuencia = diccionario.num;
    nuevo->sig = NULL;
    nuevo->izq = NULL;
    nuevo->der = NULL;
    nodo *aux1 = Tree->head; //CREAMOS UN NODO AUXILIAR QUE APUNTE A LA CABEZA
    nodo *aux2;
    while (aux1 != NULL)    
    {
        aux2 = aux1;
        aux1 = aux1->sig;
    }
    if (Tree->head == aux1)
    {
        Tree->head = nuevo;
    }
    else
    {
        aux2->sig = nuevo;
    }
    nuevo->sig = aux1;

}


void agregarLetrasArbol(arbol *Tree, letras diccionario[52]){
    for (int i = 0; i < 52; i++)
    {
        int cont=0;
        if (diccionario[i].num > 0)
        { 
                insertarNodo(Tree,diccionario[i]);
        }
    }
    
}

void verArbol(arbol *Tree){
    cout<<"\nARBOL: "<<endl;
    nodo *aux = Tree->head;
    if (aux == NULL)
    {
        cout << "NO TIENE NODOS..." << endl;
    }
    while (aux != NULL)
    {
        cout << aux->letra << "|" << aux->frecuencia<< " --> ";
        aux = aux->sig;
    }
}

void insertarNuevo(arbol *Arbol){

    nodo *nuevo = new nodo();
    nodo *a1 = Arbol->head;
    nodo *a2 = Arbol->head->sig;
    nuevo->frecuencia = a1->frecuencia + a2->frecuencia;
    nuevo->der = a2;
    nuevo->izq = a1;
    nodo *aux1 = Arbol->head; // CREAMOS UN NODO AUXILIAR QUE APUNTE A LA CABEZA
    nodo *aux2;
    while ((aux1 != NULL) && (aux1->frecuencia < nuevo->frecuencia))
    {
        aux2 = aux1;
        aux1 = aux1->sig;
    }
    if (Arbol->head == aux1)
    {
        Arbol->head = nuevo;
    }
    else
    {
        aux2->sig = nuevo;
    }
    nuevo->sig = aux1;
    Arbol->head = Arbol->head->sig->sig;
    a1->sig = NULL;
    a2->sig = NULL;
}
 
void enOrden(nodo *Cabeza) //MOSTRAR EL ARBOL EN ORDEN
{
    if (Cabeza != NULL)
    {
        enOrden(Cabeza->izq);
        cout << Cabeza->frecuencia << " "<<Cabeza->letra <<" ";
        enOrden(Cabeza->der);
    }
}

void mostrarArbol(nodo *cabeza, int num)
{
    if (cabeza == NULL)
        return;
    mostrarArbol(cabeza->der, num + 1);

    for (int i = 0; i < num; i++)
        cout << "   ";

    cout << cabeza->frecuencia << cabeza->letra << " " <<endl;

    mostrarArbol(cabeza->izq, num + 1);
}

int main()
{
    char c;
    int t = 52;
    letras v[t];
    llenarLetras(v); // construyendo lista de frecuencias vacia
    ifstream fe;
    fe.open("datos.txt");
    
    while(true){ 
        fe>>c;
        if (fe.eof()){break;} 
        cout << c <<" ";
        agregarletra(c, v); // Sumamos 1 por cada caracter
    }

    fe.close();
    ordenar(v); //ordenamos la lista de frecuencias 
    verFrecuencias(v);
    arbol *huffman; //creamos un arbol
    huffman = new arbol();
    agregarLetrasArbol(huffman,v); //creamos una lista enalazada de las letras
    verArbol(huffman); //mostramos la lista que hicimos en  el arbol
    while (huffman->head->sig != NULL)
    {
        insertarNuevo(huffman); //Creamos un nuevo nodo con la suma de los 2 primeros y lo agregamos a la lista
    }
    cout<<"\n::::::ARBOL:::::"<<endl;
    mostrarArbol(huffman->head,0);
    return 0;
}