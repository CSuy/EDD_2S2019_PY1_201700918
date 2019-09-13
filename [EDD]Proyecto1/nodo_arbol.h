#ifndef NODO_ARBOL_H
#define NODO_ARBOL_H
#include <string>
#include "nodo.h"


class Nodo_Arbol
{
    public:
        std::string Nombre_imagen;
        int alto_imagen;
        int ancho_imagen;
        int alto_pixel;
        int ancho_pixel;
        Nodo_Arbol *izquierdo;
        Nodo_Arbol *derecho;
        Nodo *matriz;
        Nodo_Arbol(std::string imagen, int alto_i, int ancho_i, int alto_p, int ancho_p, Nodo *matrix);
        virtual ~Nodo_Arbol();

    protected:

    private:
};

#endif // NODO_ARBOL_H
