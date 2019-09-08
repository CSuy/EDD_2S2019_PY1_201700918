#include "lista_matriz.h"
#include <iostream>
#include <string>

using namespace std;

Lista_Matriz::Lista_Matriz()
{
    this->cabeza=new Nodo(-1,-1,"Matriz");
}
/** metodo que va a devolver la cabecera de la fila**/
Nodo* Lista_Matriz::buscarF(int y)
{
    Nodo *aux=cabeza;
    while(aux != 0){
        if(aux->posY == y){
            return aux;
        }
        aux=aux->abajo;
    }
    delete aux;
    return 0;
}
/** metodo que va a devolver la cabecera de la columna**/
Nodo* Lista_Matriz::buscarC(int x)
{
    Nodo *aux=cabeza;
    while(aux != 0){
        if(aux->posX==x){
            return aux;
        }
        aux=aux->siguiente;
    }
    delete aux;
    return 0;
}
Nodo* Lista_Matriz::insertar_columna(Nodo *nuevo, Nodo *cabeza_columna)
{
    Nodo *temp=cabeza_columna;
    while(temp->siguiente!=0){
        temp=temp->siguiente;
    }
    temp->siguiente=nuevo;
    nuevo->anterior=temp;
    delete temp;
    return nuevo;
}
Nodo* Lista_Matriz::insertar_fila(Nodo *nuevo, Nodo *cabeza_fila)
{
    Nodo *temp=cabeza_fila;
    while(temp->abajo!=0){
        temp=temp->abajo;
    }
    temp->abajo=nuevo;
    nuevo->arriba=temp;
    delete temp;
    return nuevo;
}
Nodo* Lista_Matriz::nueva_columna(int x)
{
    Nodo *piv=cabeza;
    string col="C";
    col+=x;
    Nodo *columna=this->insertar_columna(new Nodo(x,-1,col), piv);
    if(columna != 0){
        delete piv;
    }
    return columna;
}

Nodo* Lista_Matriz::nueva_fila(int y)
{
    Nodo *piv=cabeza;
    string fil="F";
    fil+=y;
    Nodo *fila=this->insertar_fila(new Nodo(-1,y,fil), piv);
    if(fila != 0){
        delete piv;
    }
    return fila;
}
/** Metodo para poder insertar a la matriz dispersa **/
void Lista_Matriz::insertar_elemento(int x, int y, std::string color){
/** se presenta los casos mas normales**/
    Nodo *nuevo = new Nodo(x,y,color);
    Nodo *nodo_Columna = this->buscarC(x);
    Nodo *nodo_Fila = this->buscarF(y);
/**Caso 1**/
    if(nodo_Columna == 0 && nodo_Fila==0){
        nodo_Columna = this->nueva_columna(x);
        nodo_Fila = this->nueva_fila(y);
        nuevo=this->insertar_columna(nuevo, nodo_Fila);
        nuevo=this->insertar_fila(nuevo, nodo_Columna);
        return;
    }
/**Caso 2**/
    else if(nodo_Columna == 0 && nodo_Fila!=0){
        nodo_Columna = this->nueva_columna(x);
        nuevo=this->insertar_columna(nuevo, nodo_Fila);
        nuevo=this->insertar_fila(nuevo, nodo_Columna);
        return;
    }
/**Caso 3**/
    else if(nodo_Columna != 0 && nodo_Fila == 0){
        nodo_Fila = this->nueva_fila(y);
        nuevo=this->insertar_columna(nuevo, nodo_Fila);
        nuevo=this->insertar_fila(nuevo, nodo_Columna);
        return;
    }
/**Caso 4**/
    else if(nodo_Columna != 0 && nodo_Fila !=0 ){
        nuevo=this->insertar_columna(nuevo, nodo_Fila);
        nuevo=this->insertar_fila(nuevo, nodo_Columna);
        return;
    }
    else{
        cout << "Se podrujo un error al insertar el nuevo nodo" << endl;
    }
}

Lista_Matriz::~Lista_Matriz()
{
    //dtor
}
