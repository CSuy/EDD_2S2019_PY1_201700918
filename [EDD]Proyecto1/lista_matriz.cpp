#include "lista_matriz.h"
#include <iostream>
#include <string>

using namespace std;

Lista_Matriz::Lista_Matriz()
{
    this->cabeza=0;
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
    return 0;
}
Nodo* Lista_Matriz::insertar_columna(Nodo *nuevo, Nodo *cabeza_columna)
{
    Nodo *temp=cabeza_columna;
    bool piv=false;
    while(true){
        //temp=temp->siguiente;
        if(temp->posX==nuevo->posX){
            temp->posY=nuevo->posY;
            temp->Color=nuevo->Color;
            return temp;
        }else if(temp->posX>nuevo->posX){
            piv=true;
            break;
        }
        if(temp->siguiente){
            temp=temp->siguiente;
        }else{
            break;
        }
    }
    if(piv){
        nuevo->siguiente=temp;
        temp->anterior->siguiente=nuevo;
        nuevo->anterior=temp->anterior;
        temp->anterior=nuevo;
    }else{
        temp->siguiente=nuevo;
        nuevo->anterior=temp;
    }
    return nuevo;
}
Nodo* Lista_Matriz::insertar_fila(Nodo *nuevo, Nodo *cabeza_fila)
{
    Nodo *temp=cabeza_fila;
    bool piv=false;
    while(true){
        //temp=temp->siguiente;
        if(temp->posY==nuevo->posY){
            temp->posX=nuevo->posX;
            temp->Color=nuevo->Color;
            return temp;
        }else if(temp->posY>nuevo->posY){
            piv=true;
            break;
        }
        if(temp->abajo){
            temp=temp->abajo;
        }else{
            break;
        }
    }
    if(piv){
        nuevo->abajo=temp;
        temp->arriba->abajo=nuevo;
        nuevo->arriba=temp->arriba;
        temp->arriba=nuevo;
    }else{
        temp->abajo=nuevo;
        nuevo->arriba=temp;
    }
    return nuevo;
}
Nodo* Lista_Matriz::nueva_columna(int x)
{
    Nodo *piv=cabeza;
    string col="C";
    col+=x;
    Nodo *columna=this->insertar_columna(new Nodo(x,-1,col), piv);
    return columna;
}

Nodo* Lista_Matriz::nueva_fila(int y)
{
    Nodo *piv=cabeza;
    string fil="F";
    fil+=y;
    Nodo *fila=this->insertar_fila(new Nodo(-1,y,fil), piv);
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

void Lista_Matriz::crear_raiz(std::string capa)
{
    Nodo *nuevo_nodo = new Nodo(-1,-1,capa);
    bool piv=false;
    if(this->cabeza==0){
        this->cabeza=nuevo_nodo;
    }else{
        Nodo *aux=this->cabeza;
        while (true){
            if(capa.compare(aux->Color)>0){
                piv=true;
                break;
            }
            if(aux->adelante!=0){
                aux=aux->adelante;
            }else{
                break;
            }
        }
        if(piv){
            nuevo_nodo->adelante=aux;
            aux->atras->adelante=nuevo_nodo;
            nuevo_nodo->atras=aux->atras;
            aux->atras=nuevo_nodo;
        }else{
            aux->adelante=nuevo_nodo;
            nuevo_nodo->atras=aux;
        }
    }
}

Lista_Matriz::~Lista_Matriz()
{
    //dtor
}
