#include "arbol_binario.h"
#include <cstring>

/* prueba de strcmp() para comparar cadenas
    char cadena1[]="balon";
    char cadena2[]="avion";
    int x1= strcmp(cadena1,cadena2);1
    int x2=strcmp(cadena2,cadena1);-1
*/
Arbol_Binario::Arbol_Binario()
{
    this->Raiz=0;
}

Nodo_Arbol* Arbol_Binario::insertar(Nodo_Arbol *raiz, std::string nombre)
{
    std::string nombre1=nombre;
    char cadena1[nombre1.size()+1];
    strcpy(cadena1,nombre1.c_str());
    std::string nombre2=raiz->Nombre_imagen;
    char cadena2[nombre2.size()+1];
    strcpy(cadena2,nombre2.c_str());
    if (raiz==0){
        raiz=new Nodo_Arbol(nombre);
    }else if (strcmp(cadena1,cadena2)>0){
        raiz->derecho=insertar(raiz->derecho,nombre);
    }else if (strcmp(cadena1,cadena2)<=0){
        raiz->izquierdo=insertar(raiz->izquierdo,nombre);
    }
    return raiz;
}

void Arbol_Binario::insertar(std::string nombre)
{
    insertar(this->Raiz,nombre);
}

Arbol_Binario::~Arbol_Binario()
{
    //dtor
}
