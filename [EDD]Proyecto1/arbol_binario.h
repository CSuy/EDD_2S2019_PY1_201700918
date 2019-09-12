#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H
#include "nodo_arbol.h"
#include "nodo.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;


class Arbol_Binario
{
    public:
        void insertar(std::string nombre_img, std::string caracteristicas, Nodo *matrix);
        void Grafica_inorden();
        void Grafica_preorden();
        void Grafica_posorden();
        void mostrar_lista();
        int id;
        Arbol_Binario();
        virtual ~Arbol_Binario();

    protected:

    private:
        Nodo_Arbol *Raiz;
        Nodo_Arbol *insertar(Nodo_Arbol *raiz, std::string nombre_img, std::string caracteristicas, Nodo *matrix);
        std::string inorden(Nodo_Arbol *raiz);
        std::string preorden(Nodo_Arbol *raiz);
        std::string posorden(Nodo_Arbol *raiz);
        std::string mostrar_lista(Nodo_Arbol *raiz);
};

#endif // ARBOL_BINARIO_H
