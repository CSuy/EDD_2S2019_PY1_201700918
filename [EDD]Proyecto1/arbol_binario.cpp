#include "arbol_binario.h"
#include "lista_matriz.h"
#include "nodo.h"
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

Nodo_Arbol* Arbol_Binario::insertar(Nodo_Arbol *raiz, std::string nombre, int alto_i, int ancho_i, int alto_p, int ancho_p, Nodo *matrix)
{
    std::string nombre1=nombre;
    std::string nombre2=raiz->Nombre_imagen;
    if (raiz==0){
        raiz=new Nodo_Arbol(nombre,alto_i, ancho_i, alto_p, ancho_p,matrix);
    }else if (nombre1.compare(nombre2)>0){
        raiz->derecho=insertar(raiz->derecho,nombre,alto_i, ancho_i, alto_p, ancho_p,matrix);
    }else if (nombre1.compare(nombre2)<=0){
        raiz->izquierdo=insertar(raiz->izquierdo,nombre,alto_i, ancho_i, alto_p, ancho_p,matrix);
    }
    return raiz;
}

void Arbol_Binario::insertar(std::string nombre, int alto_i, int ancho_i, int alto_p, int ancho_p, Nodo *matrix)
{
    insertar(this->Raiz,nombre,alto_i, ancho_i, alto_p, ancho_p,matrix);
}

std::string Arbol_Binario::inorden(Nodo_Arbol *raiz)
{
    std::string cuerpo;
    if(raiz!=0){
        inorden(raiz->izquierdo);
        cuerpo="\"";
        cuerpo+=raiz->Nombre_imagen;
        cuerpo+=", \n";
        //cuerpo+=raiz->Caracteristicas;
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
        //cuerpo+=raiz->Caracteristicas;
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
        //cuerpo+=raiz->Caracteristicas;
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
        listado+=".";
        listado+=raiz->Nombre_imagen;
        cout << listado << endl;
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

void Arbol_Binario::leer_archivos(std::string archivo, std::string nombre_imagen)
{
    this->nombre__i=nombre_imagen;
    Lista_Matriz *nueva_matriz = new Lista_Matriz();
    try{
        ifstream lectura;
        string ruta="CSV/";
        ruta+=nombre_imagen;
        ruta+="/";
        ruta=archivo;
        lectura.open(ruta, ios::in);
        std::string layer;
        std::string file;
        std::string capas="";
        while (lectura.good())
        {
            getline(lectura, layer, ',');
            getline(lectura, file, '\n');
            try{
                int numero=std::stoi(layer);
                if(numero==0){
                    lectura_config(nombre_imagen,file);
                }else{
                    lectura_capas(nueva_matriz,nombre_imagen,file,layer);
                }
            }catch(exception){

            }
        }
        lectura.close();
        insertar(nombre_imagen,this->alto__i,this->ancho__i,this->alto__p,this->ancho__p,nueva_matriz->cabeza);
    }catch(exception){
        cout << "Se produjo un error al leer archivos" << endl;
    }
}

void Arbol_Binario::lectura_config(std::string carpeta,std::string archivo)
{
    try{
        ifstream lectura1;
        string ruta="CSV/";
        ruta+=carpeta;
        ruta+="/";
        ruta=archivo;
        lectura1.open(ruta, ios::in);
        std::string nombre_especificacion;
        std::string tamanio;
        while (lectura1.good())
        {
            getline(lectura1,nombre_especificacion, ',');
            getline(lectura1,tamanio,'\n');
            try{
                if(nombre_especificacion=="image_width"){
                    this->ancho__i=std::stoi(tamanio);
                }else if(nombre_especificacion=="image_height"){
                    this->alto__i=std::stoi(tamanio);
                }else if(nombre_especificacion=="pixel_width"){
                    this->ancho__p=std::stoi(tamanio);
                }else if (nombre_especificacion=="pixel_height"){
                    this->alto__p=std::stoi(tamanio);
                }
                
            }catch(exception){

            }
        }               
    }catch(exception){
        cout << "se produjo un error al leer el archivo .csv" << endl;
    }
}

void Arbol_Binario::lectura_capas(Lista_Matriz *lista,std::string carpeta,std::string archivo, std::string capa)
{
    try{
        ifstream lectura;
        string ruta="CSV/";
        ruta+=carpeta;
        ruta+="/";
        ruta=archivo;
        lectura.open(ruta, ios::in);
        std::string layer;
        std::string file;
        int x; int y=0;
        lista->crear_raiz(capa);
        for(std::string fila; std::getline(lectura,fila);){
            std::stringstream lineas(fila);
            std::string dato;
            x=0;
            for(int col=0; std::getline(lineas,dato,',');col++){
                if(dato!="x" || dato!="X"){
                    lista->insertar_elemento(x,y,dato);
                }
                x++;
            }
            y++;
        }

        lectura.close();
    }catch(exception){
        cout << "Se produjo un error al leer archivos" << endl;
    }
}

Arbol_Binario::~Arbol_Binario()
{
    //dtor
}
