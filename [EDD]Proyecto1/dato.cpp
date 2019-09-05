#include "dato.h"

Dato::Dato(int posX, int posY, std::string color)
{
    this->Color=color;
    this->posX=posX;
    this->posY=posY;
}

Dato::~Dato()
{
    //dtor
}
