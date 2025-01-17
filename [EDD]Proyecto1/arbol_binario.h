#ifndef ARBOL_BINARIO_H
#define ARBOL_BINARIO_H
#include "nodo_arbol.h"
#include "nodo.h"
#include "lista_matriz.h"
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;


class Arbol_Binario
{
    public:
        void insertar(std::string nombre_img, int alto_i, int ancho_i, int alto_p, int ancho_p, Nodo *matrix);
        void Grafica_inorden();
        void Grafica_preorden();
        void Grafica_posorden();
        void Grafica_arbol();
        void mostrar_lista(Nodo_Arbol *raices);
        void matriz_auxiliar(std::string nombre_imagen);
        void leer_archivos(std::string archivo, std::string nombre_imagen);
        void lectura_config(std::string carpeta,std::string archivo);
        void lectura_capas(Lista_Matriz *lista,std::string carpeta, std::string archivo, std::string capa);
        void graficar_matriz(std::string nombre_imagen);
        Nodo *Buscar(std::string nombre_imagen, int filtro);
        void matriz_auxiliar1(Nodo *&raiz, std::string nombre_imagen);
        void graficar_matriz_filtro(Nodo *&raiz, std::string nombre_imagen);
        int id;
        int alto__i;
        int ancho__i;
        int alto__p;
        int ancho__p;
        std::string nombre__i;
        Nodo_Arbol *getRaiz();
        Arbol_Binario();
        virtual ~Arbol_Binario();

    protected:


    private:
        Nodo_Arbol *Raiz;
        Nodo_Arbol *insertar1(Nodo_Arbol *&raiz, Nodo_Arbol *&nuevo);
        std::string inorden(Nodo_Arbol *&raiz);
        std::string preorden(Nodo_Arbol *&raiz);
        std::string posorden(Nodo_Arbol *&raiz);
        std::string g_arbol(Nodo_Arbol *&raiz, int id);
        Nodo_Arbol *buscar(Nodo_Arbol *&raiz,std::string nombre_imagen);
        std::string mostrar_lista1(Nodo_Arbol *raiz);
};

#endif // ARBOL_BINARIO_H
