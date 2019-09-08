#ifndef NODO_ARBOL_H
#define NODO_ARBOL_H
#include <string>


class Nodo_Arbol
{
    public:
        std::string Nombre_imagen;
        Nodo_Arbol *izquierdo;
        Nodo_Arbol *derecho;
        Nodo_Arbol(std::string imagen);
        virtual ~Nodo_Arbol();

    protected:

    private:
};

#endif // NODO_ARBOL_H
