#ifndef LISTA_MATRIZ_H
#define LISTA_MATRIZ_H
#include "nodo.h"
#include <fstream>
#include <iostream>
#include <string.h>


class Lista_Matriz
{
    public:
        Nodo *cabeza;
        Lista_Matriz();
        void insertar_elemento(int x, int y, std::string color,Nodo *raiz);
        Nodo *nueva_columna(int x, Nodo *raiz);
        Nodo *nueva_fila(int y, Nodo *raiz);
        Nodo *insertar_fila(Nodo *nuevo, Nodo *cabeza_fila);
        Nodo *insertar_columna(Nodo *nuevo, Nodo *cabeza_columna);
        Nodo *buscarF(int y, Nodo *raiz);
        Nodo *buscarC(int x, Nodo *raiz);
        Nodo *insertar_raiz(Nodo *nuevo, Nodo *raiz);
        Nodo* crear_raiz(std::string nombre_capa);
        void Graficar(Nodo *&raiz, std::string ruta);
        virtual ~Lista_Matriz();

    protected:

    private:
};

#endif // LISTA_MATRIZ_H
