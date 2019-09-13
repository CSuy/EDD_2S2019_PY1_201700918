#include "lista_circular.h"

Lista_Circular::Lista_Circular()
{
    this->cabeza=0;
}

/*con este metodo insertamos a la lista doblemente circular*/
void  Lista_Circular::insertar(std::string capa, std::string filtro){
    Nodo_Circular *nuevo = new Nodo_Circular(capa,filtro);
    if(this->estaVacia()){
        this->cabeza=nuevo;
        this->cabeza->anterior=nuevo;
        this->cabeza->siguiente=nuevo;
    }else{
        Nodo_Circular *aux=this->cabeza;
        while (aux->siguiente!=0)
        {
            aux=aux->siguiente;
        }
        aux->siguiente=nuevo;
        nuevo->anterior=aux;
        nuevo->siguiente=this->cabeza;
        this->cabeza->anterior=nuevo;        
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

/*con este metodo realizamos la grafica de la lista*/
void Lista_Circular::graficar(){
    
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
