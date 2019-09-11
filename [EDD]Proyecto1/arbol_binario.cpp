#include "arbol_binario.h"
#include <cstring>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
using namespace std;


/* prueba de strcmp() para comparar cadenas
    char cadena1[]="balon";
    char cadena2[]="avion";
    int x1= strcmp(cadena1,cadena2);1
    int x2=strcmp(cadena2,cadena1);-1
*/
Arbol_Binario::Arbol_Binario()
{
    this->Raiz=0;
    this->id=1;
}

Nodo_Arbol* Arbol_Binario::insertar(Nodo_Arbol *raiz, std::string nombre, std::string caracteristicas)
{
    std::string nombre1=nombre;
    std::string nombre2=raiz->Nombre_imagen;
    if (raiz==0){
        raiz=new Nodo_Arbol(nombre,caracteristicas);
    }else if (nombre1.compare(nombre2)>0){
        raiz->derecho=insertar(raiz->derecho,nombre,caracteristicas);
    }else if (nombre1.compare(nombre2)<=0){
        raiz->izquierdo=insertar(raiz->izquierdo,nombre,caracteristicas);
    }
    return raiz;
}

void Arbol_Binario::insertar(std::string nombre, std::string caracteristicas)
{
    insertar(this->Raiz,nombre,caracteristicas);
}

std::string Arbol_Binario::inorden(Nodo_Arbol *raiz)
{
    std::string cuerpo;
    if(raiz!=0){
        inorden(raiz->izquierdo);
        cuerpo="\"";
        cuerpo+=raiz->Nombre_imagen;
        cuerpo+=", \n";
        cuerpo+=raiz->Caracteristicas;
        cuerpo+="\"";
        cuerpo+=" -> \n";
        inorden(raiz->derecho);
    }
    return cuerpo;
}

void Arbol_Binario::Grafica_inorden()
{
    ofstream archivo;
    archivo.open("Recorrido_inorden.dot",ios::out);
    if (archivo.fail()){
        cout << "se produjo un error al generar el recorrido inorden" << endl;
    }else{
        archivo<<"digraph inorden{\n rankdir=LR;\n node [shape = circle, style=filled, fillcolor=seashell2];"<<inorden(this->Raiz)<<" \n}";
        archivo.close();
    }
    try{
        system("dot -Tjpg Recorrido_inorden.dot -o busqueda_inorden.jpg");
    }catch(exception e){
        cout << "Se produjo un error al correr el .dot" << endl;
    }
}

std::string Arbol_Binario::posorden(Nodo_Arbol *raiz)
{
    std::string cuerpo;
    if(raiz!=0){
        posorden(raiz->izquierdo);
        posorden(raiz->derecho);
        cuerpo="\"";
        cuerpo+=raiz->Nombre_imagen;
        cuerpo+=", \n";
        cuerpo+=raiz->Caracteristicas;
        cuerpo+="\"";
        cuerpo+=" -> \n";
    }
    return cuerpo;
}

void Arbol_Binario::Grafica_posorden()
{
    ofstream archivo;
    archivo.open("Recorrido_inorden.dot",ios::out);
    if (archivo.fail()){
        cout << "se produjo un error al generar el recorrido inorden" << endl;
    }else{
        archivo<<"digraph inorden{\n rankdir=LR;\n node [shape = circle, style=filled, fillcolor=seashell2];"<<posorden(this->Raiz)<<" \n}";
        archivo.close();
    }
    try{
        system("dot -Tjpg Recorrido_inorden.dot -o busqueda_inorden.jpg");
    }catch(exception e){
        cout << "Se produjo un error al correr el .dot" << endl;
    }
}

std::string Arbol_Binario::preorden(Nodo_Arbol *raiz)
{
    std::string cuerpo;
    if(raiz!=0){
        cuerpo="\"";
        cuerpo+=raiz->Nombre_imagen;
        cuerpo+=", \n";
        cuerpo+=raiz->Caracteristicas;
        cuerpo+="\"";
        cuerpo+=" -> \n";
        preorden(raiz->izquierdo);
        preorden(raiz->derecho);
    }
    return cuerpo;
}

void Arbol_Binario::Grafica_preorden()
{
    ofstream archivo;
    archivo.open("Recorrido_inorden.dot",ios::out);
    if (archivo.fail()){
        cout << "se produjo un error al generar el recorrido inorden" << endl;
    }else{
        archivo<<"digraph inorden{\n rankdir=LR;\n node [shape = circle, style=filled, fillcolor=seashell2];"<<preorden(this->Raiz)<<" \n}";
        archivo.close();
    }
    try{
        system("dot -Tjpg Recorrido_inorden.dot -o busqueda_inorden.jpg");
    }catch(exception e){
        cout << "Se produjo un error al correr el .dot" << endl;
    }
}

std::string Arbol_Binario::mostrar_lista(Nodo_Arbol *raiz)
{
    std::string listado;
    if(raiz!=0){
        mostrar_lista(raiz->izquierdo);
        listado+=this->id;
        listado+=raiz->Nombre_imagen;
        listado+="\n";
        mostrar_lista(raiz->derecho);
    }
    this->id++;
    return listado;
}

void Arbol_Binario::mostrar_lista()
{
    if(this->id != 1){
        this->id=1;
    }
    mostrar_lista(this->Raiz);
}

Arbol_Binario::~Arbol_Binario()
{
    //dtor
}
