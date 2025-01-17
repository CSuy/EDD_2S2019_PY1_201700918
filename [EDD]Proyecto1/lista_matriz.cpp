#include "lista_matriz.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

Lista_Matriz::Lista_Matriz()
{
    this->cabeza=0;
}
/** metodo que va a devolver la cabecera de la fila**/
Nodo* Lista_Matriz::buscarF(int y, Nodo *raiz)
{
    Nodo *aux=raiz;
    while(aux != 0){
        if(aux->posY == y){
            return aux;
        }
        aux=aux->abajo;
    }
    return 0;
}
/** metodo que va a devolver la cabecera de la columna**/
Nodo* Lista_Matriz::buscarC(int x, Nodo *raiz)
{
    Nodo *aux=raiz;
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
Nodo* Lista_Matriz::nueva_columna(int x, Nodo *raiz)
{
    Nodo *piv=raiz;
    string col="C";
    col+=std::to_string(x);
    Nodo *columna=this->insertar_columna(new Nodo(x,-1,col), piv);
    return columna;
}

Nodo* Lista_Matriz::nueva_fila(int y, Nodo *raiz)
{
    Nodo *piv=raiz;
    string fil="F";
    fil+=std::to_string(y);
    Nodo *fila=this->insertar_fila(new Nodo(-1,y,fil), piv);
    return fila;
}
/** Metodo para poder insertar a la matriz dispersa **/
void Lista_Matriz::insertar_elemento(int x, int y, std::string color, Nodo *raiz)
{
/** se presenta los casos mas normales**/
    Nodo *nuevo = new Nodo(x,y,color);
    Nodo *nodo_Columna = this->buscarC(x,raiz);
    Nodo *nodo_Fila = this->buscarF(y, raiz);
/**Caso 1**/
    if(nodo_Columna == 0 && nodo_Fila==0){
        nodo_Columna = this->nueva_columna(x, raiz);
        nodo_Fila = this->nueva_fila(y,raiz);
        nuevo=this->insertar_columna(nuevo, nodo_Fila);
        nuevo=this->insertar_fila(nuevo, nodo_Columna);
        return;
    }
/**Caso 2**/
    else if(nodo_Columna == 0 && nodo_Fila!=0){
        nodo_Columna = this->nueva_columna(x,raiz);
        nuevo=this->insertar_columna(nuevo, nodo_Fila);
        nuevo=this->insertar_fila(nuevo, nodo_Columna);
        return;
    }
/**Caso 3**/
    else if(nodo_Columna != 0 && nodo_Fila == 0){
        nodo_Fila = this->nueva_fila(y,raiz);
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

Nodo* Lista_Matriz::insertar_raiz(Nodo *nuevo, Nodo *raiz)
{
    bool piv=false;
    if(this->cabeza==0){
        this->cabeza=nuevo;
    }else{
        Nodo *aux=this->cabeza;
        while (aux!=0){
            if(raiz->Color.compare(aux->Color)>0){
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
            nuevo->adelante=aux;
            aux->atras->adelante=nuevo;
            nuevo->atras=aux->atras;
            aux->atras=nuevo;
        }else{
            aux->adelante=nuevo;
            nuevo->atras=aux;
        }
    }
    return nuevo;
}

Nodo* Lista_Matriz::crear_raiz(std::string capa)
{
    Nodo *nuevo_nodo = new Nodo(-1,-1,capa);
    nuevo_nodo=this->insertar_raiz(nuevo_nodo,this->cabeza);
    return nuevo_nodo;
}

void Lista_Matriz::Graficar(Nodo *&raiz, std::string ruta_1)
{
    try{
        Nodo *aux3 = raiz;
        Nodo *aux = raiz;
        Nodo *aux1 = raiz;
        int x=1;
        ofstream archivo;
        while(aux3!=0){
            aux=aux3;
            aux1=aux3;
            std::string ruta=ruta_1;
            std::string img=ruta_1;
            img+="Capa";
            img+=std::to_string(x);
            img+=".jpg";
            ruta+="Capa";
            ruta+=std::to_string(x);
            ruta+=".dot";
            archivo.open(ruta,ios::out);
            if(archivo.fail()){
                cout << "se produjo un error al generar la grafica" << endl;
            }else{
                archivo << "digraph MatrizCapa{ \n node[shape=box] \n rankdir=UD; \n {rank=min; \n";
                while(aux!=0){
                    archivo << "nodo" << aux->posX+1 << aux->posY+1 << "[label=\"" << aux->Color << "\" ,rankdir=LR,group=" << aux->posX+1 << "]; \n"; 
                    aux=aux->siguiente;
                }
                archivo << "} \n";
                while(aux1!=0){
                    aux=aux1;
                    archivo << "{rank=same; \n";
                    while(aux!=0){
                        archivo << "nodo" << aux->posX+1 << aux->posY+1 << "[label=\"" << aux->Color << "\" ,group=" << aux->posX+1 << "]; \n";
                        aux=aux->siguiente;
                    }
                    archivo << "} \n";
                    aux1=aux1->abajo;
                }
                aux1=aux3;
                while(aux1!=0){
                    aux=aux1;
                    while(aux->siguiente!=0){
                        archivo << "nodo" << aux->posX+1 << aux->posY+1 << " -> " << "nodo" << aux->siguiente->posX+1 << aux->siguiente->posY+1 << " [dir=both];\n";
                        aux=aux->siguiente;
                    }
                    aux1=aux1->abajo;
                }
                aux1=aux3;
                while(aux1!=0){
                    aux=aux1;
                    while(aux->abajo!=0){
                        archivo << "nodo" << aux->posX+1 << aux->posY+1 << " -> " << "nodo" << aux->abajo->posX+1 << aux->abajo->posY+1 << " [dir=both];\n";
                        aux=aux->abajo;
                    }
                    aux1=aux1->siguiente;
                }
                archivo << "}";
            }
            archivo.close();
            std::string codigo_cmd="dot -Tjpg ";
            codigo_cmd+=ruta;
            codigo_cmd+=" -o ";
            codigo_cmd+=img;
            char j[codigo_cmd.size()+1];
            strcpy(j,codigo_cmd.c_str());
            cout << j << endl;
            system(j);
            aux3=aux3->adelante;
            x=x+1;
        }
    }catch(exception){
            
    }
}

Lista_Matriz::~Lista_Matriz()
{
    //dtor
}
