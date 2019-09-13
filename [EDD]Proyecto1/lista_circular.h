#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H
#include <string>
#include "nodo_circular.h"


class Lista_Circular
{
    public:
        void insertar(std::string capa, std::string filtro);
        void borrar();
        void graficar();
        Nodo_Circular *cabeza;
        Lista_Circular();
        virtual ~Lista_Circular();

    protected:

    private:
    bool estaVacia();
};

#endif // LISTA_CIRCULAR_H
