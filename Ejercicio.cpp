#include <iostream>
using namespace std;

struct  nodo{

char nombre;
int telefono;

nodo *sig;
};
nodo *cab, *pac, *pac2;
int registrar(){
   pac = ((struct nodo *) malloc (sizeof(struct nodo)));
   pac->codigo = 1;
   cout<<"ingrese su nombre: "<<endl;
   cin>>pac->nombre;
   pac->sig = NULL;
   cout<<"Direccion: "<<pac<<endl;
   if(!cab){
    cab = pac;
   } else {
    pac2 = cab;
    while(pac2->sig!=NULL)
        pac2 = pac2->sig;
    pac2->sig = pac;
   }
}
int mostra(){
     for(pac=cab; pac!=NULL; pac = pac->sig){
         
         cout<<"Nombre: "<<pac->nombre<<endl;
         cout<<"Telefono: "<<pac->telefono<<endl;
        
    }

}
int buscar(){
    
}

int main(){
    int opc=0;
    do {
        cout<<"1. Registrar"<<endl;
        cout<<"2. Mostrar"<<endl;
        cout<<"3. Buscar"<<endl;
        cin>>opc;
        switch (opc)
        {
        case 1: registrar();
            break;
        case 2: mostrar();
            break;
        }
        case 3: buscar();
            break;
        }

    } while(opc!=5);