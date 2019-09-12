#include "nodo_arbol.h"
#include "nodo.h"
#include <string>

Nodo_Arbol::Nodo_Arbol(std::string imagen, std::string caracteristicas, Nodo *matrix)
{
    this->derecho=0;
    this->izquierdo=0;
    this->Nombre_imagen=imagen;
    this->Caracteristicas=caracteristicas;
    this->matriz=matrix;
}

Nodo_Arbol::~Nodo_Arbol()
{
    //dtor
}
