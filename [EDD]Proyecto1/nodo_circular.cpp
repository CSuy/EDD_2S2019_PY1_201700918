#include "nodo_circular.h"

Nodo_Circular::Nodo_Circular(std::string capa_aplicable, std::string tipo_filtro)
{
    this->capa=capa_aplicable;
    this->filtro=tipo_filtro;
    this->anterior=0;
    this->siguiente=0;
}

Nodo_Circular::~Nodo_Circular()
{
    //dtor
}
