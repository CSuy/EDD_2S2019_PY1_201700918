#include "arbol_binario.h"
#include "lista_matriz.h"
#include "nodo.h"
#include "generador_html.h"
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

Nodo_Arbol* Arbol_Binario::insertar1(Nodo_Arbol *&raiz, Nodo_Arbol *nuevo)
{
    /*
    if (raiz==0){
        raiz=nuevo;
    }else if (nombre1.compare(nombre2)>0){
        raiz->derecho=insertar1(raiz->derecho,nuevo);
    }else if (nombre1.compare(nombre2)<=0){
        raiz->izquierdo=insertar1(raiz->izquierdo,nuevo);
    }*/
    if(raiz==0){
        raiz=nuevo;
    }else{
        std::string nombre1=nuevo->Nombre_imagen;
        std::string nombre2=raiz->Nombre_imagen;
        if(nombre1.compare(nombre2)>0){
            raiz->derecho=insertar1(raiz->derecho,nuevo);
        }else{
            raiz->izquierdo=insertar1(raiz->izquierdo,nuevo);
        }
    }
    return raiz;
}

void Arbol_Binario::insertar(std::string nombre, int alto_i, int ancho_i, int alto_p, int ancho_p, Nodo *matrix)
{
    Nodo_Arbol *nuevo_nodo = new Nodo_Arbol(nombre,alto_i, ancho_i, alto_p, ancho_p,matrix);
    nuevo_nodo=insertar1(this->Raiz,nuevo_nodo);
    return;
}

std::string Arbol_Binario::inorden(Nodo_Arbol *&raiz)
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

std::string Arbol_Binario::posorden(Nodo_Arbol *&raiz)
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

std::string Arbol_Binario::preorden(Nodo_Arbol *&raiz)
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

std::string Arbol_Binario::mostrar_lista1(Nodo_Arbol *raiz)
{
    std::string listado="";
    if(raiz!=0){
        mostrar_lista1(raiz->izquierdo);
        cout << id << "." << raiz->Nombre_imagen << endl;
        mostrar_lista1(raiz->derecho);
        this->id++;
    }
    return listado;
}

void Arbol_Binario::mostrar_lista(Nodo_Arbol *raices)
{
    if(raices!=0){
        if(id != 1){
            this->id=1;
        }
        mostrar_lista1(raices);
    }else{
        cout << "esta Vacio" << endl;
    }
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
        ruta+=archivo;
        lectura.open(ruta, ios::in);
        bool prueba = false;
        int temporal;
        for(std::string fila; std::getline(lectura,fila);){
            std::stringstream lineas(fila);
            std::string dato;
            if(prueba){
                for(int col=0; std::getline(lineas,dato,',');col++){
                    try{
                        temporal = std::stoi(dato);
                    //cout << "es un numero " << dato << endl;
                    }catch(exception){
                        cout << temporal << " " << dato << endl;
                    }
                }
                if(temporal==0){
                    lectura_config(nombre_imagen,dato);
                }else{
                    //lectura_capas(nueva_matriz,nombre_imagen,dato,std::to_string(temporal));
                    try{
                        ifstream lectura;
                        string ruta="CSV/";
                        ruta+=nombre_imagen;
                        ruta+="/";
                        ruta+=dato;
                        lectura.open(ruta, ios::in);
                        std::string layer;
                        std::string file;
                        int x; int y=0;
                        Nodo *raiz_p=nueva_matriz->crear_raiz(std::to_string(temporal));
                        for(std::string fila; std::getline(lectura,fila);){
                            std::stringstream lineas(fila);
                            std::string dato;
                            x=0;
                            for(int col=0; std::getline(lineas,dato,',');col++){
                                if(dato!="x" || dato!="X"){
                                    nueva_matriz->insertar_elemento(x,y,dato,raiz_p);
                                }
                                x++;
                            }
                            y++;
                        }
                        cout << "se ingreso con exito :)" << endl;
                    }catch(exception){
                        cout << "Se produjo un error al leer archivos" << endl;
                    }
                }
            }
            prueba=true;
        }
        //insertar(nombre_imagen,this->alto__i,this->ancho__i,this->alto__p,this->ancho__p,nueva_matriz->cabeza);
        cout << "Se cargo con exito" << endl;
    }catch(exception){
        cout << "Se produjo un error al leer archivos" << endl;
    }
    insertar(nombre_imagen,alto__i,ancho__i,alto__p,ancho__p,nueva_matriz->cabeza);
}

void Arbol_Binario::lectura_config(std::string carpeta,std::string archivo)
{
    try{
        ifstream lectura1;
        string ruta="CSV/";
        ruta+=carpeta;
        ruta+="/";
        ruta+=archivo;
        lectura1.open(ruta, ios::in);
        std::string nombre_especificacion;
        int tamanio;
        bool prueba = false;
        for(std::string fila; std::getline(lectura1,fila);){
            std::stringstream lineas(fila);
            std::string dato;
            if(prueba){
                for(int col=0; std::getline(lineas,dato,',');col++){
                    try{
                        tamanio=std::stoi(dato);
                    }catch(exception){
                        nombre_especificacion=dato;
                    }
                }
                if(nombre_especificacion=="image_width"){
                    this->ancho__i=tamanio;
                }else if(nombre_especificacion=="image_height"){
                    this->alto__i=tamanio;
                }else if(nombre_especificacion=="pixel_width"){
                    this->ancho__p=tamanio;
                }else if (nombre_especificacion=="pixel_height"){
                    this->alto__p=tamanio;
                }
                cout << tamanio << " " << nombre_especificacion << endl; 
            }
            prueba=true;
        }              
    }catch(exception){
        cout << "se produjo un error al leer el archivo .csv" << endl;
    }
}

void Arbol_Binario::lectura_capas(Lista_Matriz *lista,std::string carpeta,std::string archivo, std::string capa)
{
    /*try{
        ifstream lectura;
        string ruta="CSV/";
        ruta+=carpeta;
        ruta+="/";
        ruta+=archivo;
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
        cout << "se ingreso con exito :)" << endl;
    }catch(exception){
        cout << "Se produjo un error al leer archivos" << endl;
    }*/
}

void Arbol_Binario::matriz_auxiliar(std::string nombre_imagen)
{
    /*Nodo *aux = this->Raiz->matriz;
    Nodo *aux1=aux->abajo;
    Nodo *aux2 = aux1->siguiente;
    Nodo_Arbol *nombre = buscar(nombre_imagen);
    Lista_Matriz *copia = new Lista_Matriz();
    generador_html *nuevo = new generador_html();
    while (aux!=0)
    {
        while (aux1!=0)
        {
            while (aux2!=0)
            {
                copia->insertar_elemento(aux2->posX,aux2->posY,aux2->Color,copia->);
                aux2=aux2->siguiente;
            }
            aux1=aux1->abajo;
            aux2=aux1->siguiente;
        }
        aux=aux->adelante;
        aux1=aux->abajo;
        aux2=aux1->siguiente;
    }
    nuevo->generar_css(nombre,copia->cabeza);*/     
}

Nodo_Arbol* Arbol_Binario::buscar(std::string nombre_imagen)
{
    Nodo_Arbol *imagen=this->Raiz;
    while(true){
        buscar(imagen->izquierdo->Nombre_imagen);
        if(nombre_imagen==imagen->Nombre_imagen){
            return imagen;
            break;
        }
        buscar(imagen->derecho->Nombre_imagen);
    }
    return imagen;
}

Nodo_Arbol* Arbol_Binario::getRaiz()
{
    return this->Raiz;
}

Arbol_Binario::~Arbol_Binario()
{
    //dtor
}
