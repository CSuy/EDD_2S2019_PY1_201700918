#include "lista_circular.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;

Lista_Circular::Lista_Circular()
{
    this->cabeza=0;
    this->tam=0;
}

/*con este metodo insertamos a la lista doblemente circular*/
void  Lista_Circular::insertar(std::string capa, std::string filtro){
    Nodo_Circular *nuevo = new Nodo_Circular(capa,filtro);
    if(this->estaVacia()){
        this->cabeza=nuevo;
        this->tam++;
    }else{
        Nodo_Circular *&aux=this->cabeza;
        while (aux->siguiente!=0)
        {
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
        this->tam++;        
    }
}

/*con este metodo borramos la lista circular*/
/*el comando delete, nos ayuda a liberar memoria elimiando los punteros*/
void Lista_Circular::borrar(){
    if(this->estaVacia()!=true){
        Nodo_Circular *aux=this->cabeza;
        while (true)
        {
            if(aux->siguiente!=0){
                aux=aux->siguiente;
                delete aux->anterior;
            }else{
                delete aux;
                break;
            }
        }
    }
}

std::string Lista_Circular::g_circular(Nodo_Circular *&raiz, int tamanio){
    std::string cuerpo="";
    Nodo_Circular *aux=raiz;
    for(int i=0; i<tamanio;i++){
        cuerpo+="nodo";
        cuerpo+=std::to_string(i);
        cuerpo+="[label=\"";
        cuerpo+=aux->filtro;
        cuerpo+="\"]; \n";
        aux=aux->siguiente;
    }
    for(int i=0; i<tamanio-1;i++){
        cuerpo+="nodo";
        cuerpo+=std::to_string(i);
        cuerpo+= " -> ";
        cuerpo+= "nodo";
        cuerpo+=std::to_string(i+1);
        cuerpo+=" [dir=both];\n";
    }
    cuerpo+="nodo0 -> nodo";
    cuerpo+=std::to_string(tamanio-1);
    cuerpo+="[dir=both];\n";
    return cuerpo;
}

/*con este metodo realizamos la grafica de la lista*/
void Lista_Circular::graficar(){
    ofstream archivo;
    archivo.open("Lista_circular.dot",ios::out);
    if (archivo.fail()){
        cout << "se produjo un error al generar el recorrido inorden" << endl;
    }else{
        archivo<<"digraph inorden{\n rankdir=LR;\n node[shape = record]; \n "<<g_circular(this->cabeza,this->tam)<<" \n}";
        archivo.close();
    }
    try{
        system("dot -Tjpg Lista_circular.dot -o Lista_circular.jpg");
    }catch(exception e){
        cout << "Se produjo un error al correr el .dot" << endl;
    }
}

void Lista_Circular::mostrar(){
    Nodo_Circular *aux=this->cabeza;
    for(int k=0; k<this->tam;k++){
        cout << k+1 << "." <<  aux->filtro << endl;
        aux=aux->siguiente;
    }
}

bool Lista_Circular::estaVacia(){
    if(this->cabeza==0){
        return true;
    }else{
        return false;
    }
}

Lista_Circular::~Lista_Circular()
{
    //dtor
}
