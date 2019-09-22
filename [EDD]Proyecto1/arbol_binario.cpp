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

Nodo_Arbol* Arbol_Binario::insertar1(Nodo_Arbol *&raiz, Nodo_Arbol *&nuevo)
{
    if(raiz==0){
        raiz=nuevo;
    }else{
        std::string nombre1=nuevo->Nombre_imagen;
        std::string nombre2=raiz->Nombre_imagen;
        if(nombre1.compare(nombre2)>0){
            insertar1(raiz->derecho,nuevo);
        }else{
            insertar1(raiz->izquierdo,nuevo);
        }
    }
    return raiz;
}

void Arbol_Binario::insertar(std::string nombre, int alto_i, int ancho_i, int alto_p, int ancho_p, Nodo *matrix)
{
    Nodo_Arbol *nuevo_nodo = new Nodo_Arbol(nombre,alto_i, ancho_i, alto_p, ancho_p,matrix);
    insertar1(this->Raiz,nuevo_nodo);
}

std::string Arbol_Binario::inorden(Nodo_Arbol *&raiz)
{
    std::string cuerpo="";
    if(raiz!=0){
        if(raiz->izquierdo!=0){
                cuerpo+=preorden(raiz->izquierdo);
                cuerpo+=" -> ";
            }
            cuerpo+="\n \"";
            cuerpo+= raiz->Nombre_imagen;
            cuerpo+="\n Imagen: ";
            cuerpo+= std::to_string(raiz->ancho_imagen);
            cuerpo+= "X";
            cuerpo+= std::to_string(raiz->alto_imagen);
            cuerpo+="\n Pixel: ";
            cuerpo+= std::to_string(raiz->ancho_pixel);
            cuerpo+= "X";
            cuerpo+= std::to_string(raiz->alto_pixel);
            cuerpo+= "px \" ->";
            if(raiz->derecho!=0){
                cuerpo+=preorden(raiz->derecho);
            }
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
        archivo<<"digraph inorden{\n rankdir=LR;\n node [shape = circle, style=filled, fillcolor=seashell2];"<<inorden(this->Raiz)<<"; \n}";
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
        if(raiz->izquierdo!=0){
            cuerpo+=preorden(raiz->izquierdo);
            cuerpo+=" -> ";
        }
        if(raiz->derecho!=0){
            cuerpo+=preorden(raiz->derecho);
            cuerpo+=" -> ";
        }
        cuerpo+="\n \"";
        cuerpo+= raiz->Nombre_imagen;
        cuerpo+="\n Imagen: ";
        cuerpo+= std::to_string(raiz->ancho_imagen);
        cuerpo+= "X";
        cuerpo+= std::to_string(raiz->alto_imagen);
        cuerpo+="\n Pixel: ";
        cuerpo+= std::to_string(raiz->ancho_pixel);
        cuerpo+= "X";
        cuerpo+= std::to_string(raiz->alto_pixel);
        cuerpo+= "px \"";
    }
    return cuerpo;
}

void Arbol_Binario::Grafica_posorden()
{
    ofstream archivo;
    archivo.open("Recorrido_posorden.dot",ios::out);
    if (archivo.fail()){
        cout << "se produjo un error al generar el recorrido inorden" << endl;
    }else{
        archivo<<"digraph inorden{\n rankdir=LR;\n node [shape = circle, style=filled, fillcolor=seashell2];"<<posorden(this->Raiz)<<"; \n}";
        archivo.close();
    }
    try{
        system("dot -Tjpg Recorrido_posorden.dot -o busqueda_posorden.jpg");
    }catch(exception e){
        cout << "Se produjo un error al correr el .dot" << endl;
    }
}

std::string Arbol_Binario::preorden(Nodo_Arbol *&raiz)
{
    std::string cuerpo="";
    if(raiz!=0){
        cuerpo+="\n \"";
            cuerpo+= raiz->Nombre_imagen;
            cuerpo+="\n Imagen: ";
            cuerpo+= std::to_string(raiz->ancho_imagen);
            cuerpo+= "X";
            cuerpo+= std::to_string(raiz->alto_imagen);
            cuerpo+="\n Pixel: ";
            cuerpo+= std::to_string(raiz->ancho_pixel);
            cuerpo+= "X";
            cuerpo+= std::to_string(raiz->alto_pixel);
            cuerpo+= "px \"";
            if(raiz->izquierdo!=0){
                cuerpo+=" -> ";
                cuerpo+=preorden(raiz->izquierdo);
            }
            if(raiz->derecho!=0){
                cuerpo+=" -> ";
                cuerpo+=preorden(raiz->derecho);
            }
    }
    return cuerpo;
}

void Arbol_Binario::Grafica_preorden()
{
    ofstream archivo;
    archivo.open("Recorrido_preorden.dot",ios::out);
    if (archivo.fail()){
        cout << "se produjo un error al generar el recorrido inorden" << endl;
    }else{
        archivo<<"digraph inorden{\n rankdir=LR;\n node [shape = circle, style=filled, fillcolor=seashell2];"<<preorden(this->Raiz)<<"; \n}";
        archivo.close();
    }
    try{
        system("dot -Tjpg Recorrido_preorden.dot -o busqueda_preorden.jpg");
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
        this->id++;
        mostrar_lista1(raiz->derecho);
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
                        int x=0; int y=0;
                        Nodo *raiz_p=nueva_matriz->crear_raiz(std::to_string(temporal));
                        for(std::string fila; std::getline(lectura,fila);){
                            std::stringstream lineas(fila);
                            std::string dato;
                            for(int col=0; std::getline(lineas,dato,',');col++){
                                if(dato.compare("x")==0 || dato.compare("X")==0){
                                }else{
                                    nueva_matriz->insertar_elemento(x,y,dato,raiz_p);
                                }
                                x++;
                            }
                            x=0;
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

Nodo_Arbol* Arbol_Binario::buscar(Nodo_Arbol *&raiz, std::string nombre_imagen)
{
    if(raiz!=0){
        if(raiz->Nombre_imagen==nombre_imagen){
            return raiz;
        }else{
            if(nombre_imagen.compare(raiz->Nombre_imagen)>0){
                return buscar(raiz->derecho,nombre_imagen);
            }else{
                return buscar(raiz->izquierdo,nombre_imagen);
            }
        }
    }else{
        return 0;
    }
}

void Arbol_Binario::matriz_auxiliar(std::string nombre_imagen)
{
    try{
        Nodo_Arbol *aux=buscar(this->Raiz,nombre_imagen);
        generador_html *nuevo;
        if(aux!=0){
            cout << "no hubo problema xD " << aux->Nombre_imagen << endl;
            Nodo *&copia=aux->matriz;
            nuevo->generar_css(aux,copia);
        }else{
            cout << "no se encontro el nodo" << endl;
        }

    }catch(exception){
        cout << "aqui en matrix auxiliar hubo error" << endl;
    }

}

void Arbol_Binario::graficar_matriz(std::string nombre_imagen)
{
    try{
        Nodo_Arbol *aux=buscar(this->Raiz,nombre_imagen);
        Lista_Matriz *nuevo_1;
        generador_html *nuevo;
        if(aux!=0){
            cout << "no hubo problema xD " << aux->Nombre_imagen << endl;
            Nodo *&copia=aux->matriz;
            std::string ruta="CSV/";
            ruta+=aux->Nombre_imagen;
            ruta+="/";
            nuevo_1->Graficar(copia,ruta);
        }else{
            cout << "no se encontro el nodo" << endl;
        }

    }catch(exception){
        cout << "aqui en matrix auxiliar hubo error" << endl;
    }
}

void Arbol_Binario::graficar_matriz_filtro(Nodo *&raiz, std::string nombre_imagen)
{
    try{
        Nodo_Arbol *aux=buscar(this->Raiz,nombre_imagen);
        Lista_Matriz *nuevo_1;
        generador_html *nuevo;
        if(aux!=0){
            cout << "no hubo problema xD " << aux->Nombre_imagen << endl;
            Nodo *&copia=raiz;
            std::string ruta="CSV/";
            ruta+=aux->Nombre_imagen;
            ruta+="/";
            nuevo_1->Graficar(copia,ruta);
        }else{
            cout << "no se encontro el nodo" << endl;
        }

    }catch(exception){
        cout << "aqui en matrix auxiliar hubo error" << endl;
    }
}

Nodo* Arbol_Binario::Buscar(std::string nombre_imagen, int filtros)
{
    try{
        int r,g=1,b, g2, r_gris;
        double r2;
        std::string r1,g1,b1, color1;
        Arbol_Binario *a = new Arbol_Binario();
        Nodo_Arbol *aux4=buscar(this->Raiz,nombre_imagen);
        Lista_Matriz *copia = new Lista_Matriz();
        a->Raiz=aux4;
        Nodo *aux3=a->Raiz->matriz;
        Nodo *aux;
        Nodo *aux1;
        Nodo *filtro;
        Nodo *raiz_p;
        int x=1, y=0;
        if(filtros==1){
            while(aux3!=0){
                raiz_p=copia->crear_raiz(aux3->Color);
                aux=aux3->abajo;
                while(aux!=0){
                    aux1=aux->siguiente;
                    while(aux1!=0){
                        if(aux1->posY==y){
                            for(int p=0;p<aux4->ancho_imagen;){
                                if(aux1!=0){
                                    if(p==aux1->posX){
                                        std::string color =aux1->Color;
                                        int j = color.size() + 1;
                                        char prueba[j];
                                        strcpy(prueba,color.c_str());
                                        for(int i=0; i<j;i++){
                                            if(prueba[i]=='-'){
                                                b=std::stoi(r1);
                                                if(b>=255){
                                                    r=0;
                                                }else{
                                                    r=255-b;
                                                }
                                                color1+=std::to_string(r);
                                                color1+=prueba[i];
                                                r1="";
                                            }else{
                                                r1+=prueba[i];
                                            }
                                        }
                                        r=255-std::stoi(r1);
                                        if(r<0){
                                            r=0;
                                        }
                                        color1+=std::to_string(r);
                                        copia->insertar_elemento(aux1->posX,aux1->posY,color1,raiz_p);
                                        aux1=aux1->siguiente;
                                        color1="";
                                        r1="";
                                        x=x+1;
                                    }else{
                                        x=x+1;
                                    }
                                }else{
                                    x=x+1;
                                }
                                p=p+1;
                            }
                        }else{
                            y++;
                            x=x+aux4->ancho_imagen;
                        }
                    }
                    aux=aux->abajo;
                    y++;
                }
                aux3=aux3->adelante;
                y=0;
                x=1;
            }
            filtro=copia->cabeza;
        }else if(filtros==2){
            while(aux3!=0){
                raiz_p=copia->crear_raiz(aux3->Color);
                aux=aux3->abajo;
                while(aux!=0){
                    aux1=aux->siguiente;
                    while(aux1!=0){
                        if(aux1->posY==y){
                            for(int p=0;p<aux4->ancho_imagen;){
                                if(aux1!=0){
                                    if(p==aux1->posX){
                                        std::string color =aux1->Color;
                                        int j = color.size() + 1;
                                        char prueba[j];
                                        strcpy(prueba,color.c_str());
                                        for(int i=0; i<j;i++){
                                            if(prueba[i]=='-' && g==1){
                                                r=std::stoi(r1);
                                                r1="";
                                                g++;
                                            }else if(prueba[i]=='-' && g==2){
                                                g2=std::stoi(r1);
                                                r1="";
                                            }else{
                                                r1+=prueba[i];
                                            }
                                        }
                                        b=std::stoi(r1);
                                        r2=r*0.3+g2*0.59+b*0.11;
                                        if(r2<0){
                                            r2=0;
                                        }
                                        r_gris=(int) r2;
                                        color1=std::to_string(r_gris);
                                        color1+="-";
                                        color1+=std::to_string(r_gris);
                                        color1+="-";
                                        color1+=std::to_string(r_gris);
                                        copia->insertar_elemento(aux1->posX,aux1->posY,color1,raiz_p);
                                        aux1=aux1->siguiente;
                                        color1="";
                                        r1="";
                                        x=x+1;
                                    }else{
                                        x=x+1;
                                    }
                                }else{
                                    x=x+1;
                                }
                                p=p+1;
                            }
                        }else{
                            y++;
                            x=x+aux4->ancho_imagen;
                        }
                    }
                    aux=aux->abajo;
                    y++;
                }
                aux3=aux3->adelante;
                y=0;
                x=1;
            }
            filtro=copia->cabeza;
        }
        return filtro;
    }catch(exception){

    }
    return 0;
}

void Arbol_Binario::matriz_auxiliar1(Nodo *&raiz, std::string nombre_imagen)
{
    try{
        Nodo_Arbol *aux=buscar(this->Raiz,nombre_imagen);
        generador_html *nuevo;
        if(aux!=0){
            cout << "no hubo problema xD " << aux->Nombre_imagen << endl;
            Nodo *&copia=raiz;
            nuevo->generar_css(aux,copia);
        }else{
            cout << "no se encontro el nodo" << endl;
        }

    }catch(exception){
        cout << "aqui en matrix auxiliar hubo error" << endl;
    }
}

std::string Arbol_Binario::g_arbol(Nodo_Arbol *&raiz, int id)
{
    std::string cuerpo="";
    int id1=id;
    if(raiz!=0){
            cuerpo+="\n \"";
            cuerpo+= raiz->Nombre_imagen;
            cuerpo+="\n Imagen: ";
            cuerpo+= std::to_string(raiz->ancho_imagen);
            cuerpo+= "X";
            cuerpo+= std::to_string(raiz->alto_imagen);
            cuerpo+="\n Pixel: ";
            cuerpo+= std::to_string(raiz->ancho_pixel);
            cuerpo+= "X";
            cuerpo+= std::to_string(raiz->alto_pixel);
            cuerpo+= "px ";
            cuerpo+="\" ;";
            id1++;
        if(raiz->izquierdo!=0){
            cuerpo+="\n \"";
            cuerpo+= raiz->Nombre_imagen;
            cuerpo+="\n Imagen: ";
            cuerpo+= std::to_string(raiz->ancho_imagen);
            cuerpo+= "X";
            cuerpo+= std::to_string(raiz->alto_imagen);
            cuerpo+="\n Pixel: ";
            cuerpo+= std::to_string(raiz->ancho_pixel);
            cuerpo+= "X";
            cuerpo+= std::to_string(raiz->alto_pixel);
            cuerpo+= "px ";
            cuerpo+="\" ";
            id1++;
            cuerpo+= " -> \n";
            cuerpo+=g_arbol(raiz->izquierdo,id1);
        }
        if(raiz->derecho!=0){
            cuerpo+="\n \"";
            cuerpo+= raiz->Nombre_imagen;
            cuerpo+="\n Imagen: ";
            cuerpo+= std::to_string(raiz->ancho_imagen);
            cuerpo+= "X";
            cuerpo+= std::to_string(raiz->alto_imagen);
            cuerpo+="\n Pixel: ";
            cuerpo+= std::to_string(raiz->ancho_pixel);
            cuerpo+= "X";
            cuerpo+= std::to_string(raiz->alto_pixel);
            cuerpo+= "px ";
            cuerpo+="\" ";
            id1++;
            cuerpo+= " -> \n";
            cuerpo+=g_arbol(raiz->derecho,id1);
        }
    }
    return cuerpo;
}

void Arbol_Binario::Grafica_arbol()
{
    ofstream archivo;
    int x=1;
    archivo.open("Arbol.dot",ios::out);
    if (archivo.fail()){
        cout << "se produjo un error al generar el recorrido inorden" << endl;
    }else{
        archivo<<"digraph inorden{ \n node [shape = circle, style=filled, fillcolor=seashell2];"<< g_arbol(this->Raiz,x) <<" \n}";
        archivo.close();
    }
    try{
        system("dot -Tjpg Arbol.dot -o Arbol_ABB.jpg");
    }catch(exception e){
        cout << "Se produjo un error al correr el .dot" << endl;
    }
}

Nodo_Arbol* Arbol_Binario::getRaiz()
{
    return this->Raiz;
}

Arbol_Binario::~Arbol_Binario()
{
    //dtor
}
