#ifndef NODO_CIRCULAR_H
#define NODO_CIRCULAR_H
#include <string>


class Nodo_Circular
{
    public:
        Nodo_Circular *siguiente;
        Nodo_Circular *anterior;
        std::string capa;
        std::string filtro;
        Nodo_Circular(std::string capa_aplicable, std::string tipo_filtro);
        virtual ~Nodo_Circular();

    protected:

    private:
};

#endif // NODO_CIRCULAR_H
