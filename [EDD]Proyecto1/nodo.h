#ifndef NODO_H
#define NODO_H
#include <string>

class Nodo
{
    public:
        Nodo *siguiente;
        Nodo *atras;
        Nodo *arriba;
        Nodo *abajo;
        Nodo();
        virtual ~Nodo();

    protected:

    private:
};

#endif // NODO_H
