#include <iostream>
using namespace std;

struct nodo {
    int value;
    
    nodo *izq;
    nodo *der;
}; 

nodo *raiz, *aux, *aux2; 
//Funcion Recursiva
int posicionar(){
    if(aux->value < aux2->value){
        if(aux2->izq == NULL){
            aux2->izq = aux;
        } else {
            aux2 = aux2->izq;
            posicionar();
        }
    } else {
        if(aux2->der == NULL){
            aux2->der = aux;
        } else {
            aux2 = aux2->der;
            posicionar();
        }
    }
}
int preorden(){
    cout<< "valor" <<aux >value<<endl;
    if(aux-> izq!=NULL){
    preorden(aux->izq);

    }
    if(aux-> der!=NULL){
    preorden(aux->der);

    }
    return=0
}
int registrar(){
    aux = ((struct nodo *) malloc (sizeof(struct nodo)));
    cout<<"Cual es el valor: "<<endl;
    cin>>aux->value;
    aux->izq = NULL;
    aux->der = NULL;
    if(!raiz){
        raiz = aux;
    } else {
        aux2 = raiz;
        //Recursividad
        posicionar();
    }
}
int mostrar(){
   aux = raiz;
   if (aux!=NULL){
     preorden(aux)

   }
  
   
   
}

main(){
    int opc=0;
    do {
        cout<<"1. Registrar"<<endl;
        cout<<"2. Mostrar"<<endl;
        cin>>opc;
        switch (opc)
        {
        case 1: registrar();
            break;
        }

    } while(opc!=5);
}