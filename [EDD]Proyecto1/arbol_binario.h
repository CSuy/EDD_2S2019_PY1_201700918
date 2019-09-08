#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H
#include "nodo_arbol.h"


class Arbol_Binario
{
    public:
        void insertar(std::string nombre_img);
        Arbol_Binario();
        virtual ~Arbol_Binario();

    protected:

    private:
        Nodo_Arbol *Raiz;
        Nodo_Arbol *insertar(Nodo_Arbol *raiz, std::string nombre_img);
};

#endif // ARBOL_BINARIO_H
