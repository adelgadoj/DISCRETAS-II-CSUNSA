#include <iostream>
#include <fstream>
using namespace std;
void ingresarDatos( int A[][6] ,int t){
    ifstream f;
    f.open("C:/Users/ALEX/Desktop/matriz.txt");
    for(int i=0;i<t;i++){
         for(int j=0;j<t;j++)
            f>>A[i][j];
    }
    f.close();
}

void mAdyacencia( int t, int A[][6]){
    cout<<"\nLA MATRIZ DE ADYACENCIA DEL GRAFO ES:"<<endl;
    for(int i=0;i<t;i++)
    {
        for(int j=0;j<t;j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
}

void grado(int A[][6], int t){
    cout<<"\nGRADOS"<<endl;
    int cont=0;
    for(int i=0;i<t;i++){
         for(int j=0;j<t;j++)
        {
            if(A[i][j]==1){
                cont++;
            }
        }
        cout<<"GRADO VERTICE  "<<i <<" = "<<cont<<endl;
        cont=0;
    }
}

void aristas(int A[][6] ,int t){
    int aux=0;
    int sum=0;
    for(int i=0; i<t ; i++){
        for(int j=aux; j<t ; j++){
            if(A[i][j]==1){
                sum++;
            }
        }
        aux++;
    }
    cout<<"\nARISTAS: "<<sum<<endl;
}
void llenarmatriz(int A[][6], int t){
    for(int i=0; i<t; i++){
        for(int j=0; j<t; j++)
            A[i][j]=0;
    }
}

void mostrarmatriz(int A[][6], int t){
    for(int i=0; i<t; i++){
        for(int j=0; j<t; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
}

void multimatriz(int A[][6],int B[][6], int t){
    for(int i = 0; i<t; i++){
        for(int j =0; j<t; j++){
            for(int k = 0; k<t ; k++)
                    B[i][j]=B[i][j]+A[i][k] * A[k][j];
        }
    }
    mostrarmatriz(B,t);
}

void incidencia(){
    ifstream f;

    int e=7,v=5;
    int E[e][v];
    //LLENAR E[e][v]
    for(int i=0; i<e; i++){
        for(int j=0; j<v; j++)
            E[i][j]=0;}
    int v1,v2;
    f.open("C:/Users/ALEX/Desktop/enlaces.txt");
    for(int i =0 ; i<e ; i++){
        cout<<"\nDATOS E"<<i+1<<" ==> ";
        f>>v1;
        f>>v2;
        cout<<"v1: "<<v1<<"  ";
        cout<<"v2: "<<v2;
        E[i][v1-1]=1;
        E[i][v2-1]=1;
    }
    f.close();
    //mostrarmatriz(E,e);
    cout<<"\n\nMATRIZ INCIDENCIA:"<<endl;
    cout<<"    e1   e2   e3   e4   e5   e6   e7"<<endl;
    for(int i=0 ; i<v ; i++){
        cout<<"V"<<i+1<<"  ";
        for(int j=0; j<e ; j++)
            cout<<E[j][i]<<"    ";
        cout<<endl;
    }
}

int main(int argc, char *argv[])
{
    cout<<"////EJERCIO 1// MATRIZ ADYACENCIA"<<endl;
    const int tam=6;
    int M[tam][tam];
    ingresarDatos(M, tam);
    mAdyacencia(tam,M);

    cout<<"\n\n////EJERCIO 2// GRADO DE UNA MATRIZ CUADRADA"<<endl;
    grado(M,tam);

    cout<<"\n\n////EJERCIO 3// ARISTAS DE UNA MATRIZ CUADRADA"<<endl;
    aristas(M,tam);

    cout<<"\n\n////EJERCIO 4// MULTIPLICACION DE MATRIZ"<<endl;
    int N[tam][tam];
    llenarmatriz(N,tam);
    multimatriz(M,N,tam);

    cout<<"\n\n////EJERCIO 5// MATRIZ INCIDENCIA"<<endl;
    incidencia();
    return 0;
}

