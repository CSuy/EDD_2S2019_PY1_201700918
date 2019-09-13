#ifndef GENERADOR_HTML_H
#define GENERADOR_HTML_H
#include "nodo.h"
#include "nodo_arbol.h"
#include "arbol_binario.h"
#include <iostream>


class generador_html
{
    public:
        void generar_css(Nodo_Arbol *hoja);
        void generar_cssFiltros(Nodo_Arbol *hoja);
        void generar_html(Nodo_Arbol *hoja, std::string nombre_css);
        void generador_prueba();
        generador_html();
        virtual ~generador_html();

    protected:

    private:
};

#endif // GENERADOR_HTML_H
