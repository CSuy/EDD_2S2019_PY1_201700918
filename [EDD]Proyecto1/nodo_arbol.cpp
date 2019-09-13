#include "nodo_arbol.h"
#include "nodo.h"
#include <string>

Nodo_Arbol::Nodo_Arbol(std::string imagen, int alto_i, int ancho_i, int alto_p, int ancho_p, Nodo *matrix)
{
    this->derecho=0;
    this->izquierdo=0;
    this->Nombre_imagen=imagen;
    this->alto_imagen=alto_i;
    this->ancho_imagen=ancho_i;
    this->alto_pixel=alto_p;
    this->ancho_pixel=ancho_p;
    this->matriz=matrix;
}

Nodo_Arbol::~Nodo_Arbol()
{
    //dtor
}
