#ifndef LISTA_CIRCULAR_H
#define LISTA_CIRCULAR_H
#include <string>
#include "nodo_circular.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;


class Lista_Circular
{
    public:
        void insertar(std::string capa, std::string filtro);
        void borrar();
        void graficar();
        void mostrar();
        Nodo_Circular *cabeza;
        int tam;
        Lista_Circular();
        virtual ~Lista_Circular();

    protected:

    private:
    std::string g_circular(Nodo_Circular *&raiz, int tamanio);
    bool estaVacia();
};

#endif // LISTA_CIRCULAR_H
