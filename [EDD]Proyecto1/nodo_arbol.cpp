#include "nodo_arbol.h"
#include <string>

Nodo_Arbol::Nodo_Arbol(std::string imagen, std::string caracteristicas)
{
    this->derecho=0;
    this->izquierdo=0;
    this->Nombre_imagen=imagen;
    this->Caracteristicas=caracteristicas;
}

Nodo_Arbol::~Nodo_Arbol()
{
    //dtor
}
