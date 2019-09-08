#ifndef LISTA_MATRIZ_H
#define LISTA_MATRIZ_H
#include "nodo.h"


class Lista_Matriz
{
    public:
        Nodo *cabeza;
        Lista_Matriz();
        void insertar_elemento(int x, int y, std::string color);
        Nodo *nueva_columna(int x);
        Nodo *nueva_fila(int y);
        Nodo *insertar_fila(Nodo *nuevo, Nodo *cabeza_fila);
        Nodo *insertar_columna(Nodo *nuevo, Nodo *cabeza_columna);
        Nodo *buscarF(int y);
        Nodo *buscarC(int x);
        virtual ~Lista_Matriz();

    protected:

    private:
};

#endif // LISTA_MATRIZ_H
