#ifndef NODO_ARBOL_H
#define NODO_ARBOL_H
#include <string>


class Nodo_Arbol
{
    public:
        std::string Nombre_imagen;
        std::string Caracteristicas;
        Nodo_Arbol *izquierdo;
        Nodo_Arbol *derecho;
        Nodo_Arbol(std::string imagen, std::string caracteristicas);
        virtual ~Nodo_Arbol();

    protected:

    private:
};

#endif // NODO_ARBOL_H
