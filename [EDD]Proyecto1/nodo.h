#ifndef NODO_H
#define NODO_H
#include <string>

class Nodo
{
    public:
        Nodo *siguiente;
        Nodo *anterior;
        Nodo *arriba;
        Nodo *abajo;
        Nodo *adelante;
        Nodo *atras;
        std::string Color;
        int posX, posY;
        Nodo(int posx, int posy, std::string color);
        virtual ~Nodo();

    protected:

    private:
};

#endif // NODO_H
