#include <iostream>
using namespace std;

void evaluar(int a,int v){
    int r;
    r=(v*(v-1)/2);
    if( a==r){
        cout<<"\n!!! EL GRAFO ES COMPLETO !!!"<<endl;
        cout<<"\n";
        for(int i=0; i<v; i++){
            cout<<"Grado del Vertice V"<<i+1<<" : "<<(v-1)<<endl;
        }
    }
    else
        cout<<"!!! NO ES UN GRAFO COMPLETO :( !!!"<<endl;
}


int main()
{
    int v,a;
    cout << "Ingrese cantidad de vertices del grafo" << endl;
    cin>>v;
    cout << "Ingrese cantidad de aristas del grafo" << endl;
    cin>>a;
    evaluar(a,v);

    return 0;
}
