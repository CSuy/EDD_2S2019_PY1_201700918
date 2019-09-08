#include "nodo.h"

Nodo::Nodo(int posx, int posy, std::string color)
{
    this->siguiente=0;
    this->anterior=0;
    this->abajo=0;
    this->arriba=0;
    this->adelante=0;
    this->atras=0;
    this->posX=posx;
    this->posY=posy;
    this->Color=color;
}

Nodo::~Nodo()
{
    //dtor
}
