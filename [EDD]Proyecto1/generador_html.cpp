#include "generador_html.h"
#include <fstream>
#include <iostream>

generador_html::generador_html()
{
    //ctor
}

void generador_html::generar_css(Nodo_Arbol *&matrix, Nodo *&matriz_aux)
{
    try{
        Nodo *aux3 = matriz_aux;
        Nodo *aux; /*Fila*/
        Nodo *aux1;/*Columna*/
        std::string nombre_archivo=matrix->Nombre_imagen;
        string ruta="CSV/";
        nombre_archivo+=".css";
        ruta+=matrix->Nombre_imagen;
        ruta+="/";
        ruta+=nombre_archivo;
        int x=1, y=0;
        int x_pixel=0, y_pixel=0;
        ofstream archivo;
        archivo.open(ruta,ios::out);
        if(archivo.fail()){
            cout << "hubo un erro al crear el archivo css" << endl;
        }else{
            archivo << "body{\n background: #333333; \n height: 100vh; \n display: flex; \n justify-content: center; \n align-items: center; \n } \n";
            archivo << ".canvas{ \n width: " << matrix->ancho_imagen*matrix->ancho_pixel << "px; \n";
            archivo << "height: " << matrix->alto_imagen*matrix->alto_pixel << "px; \n } \n";
            archivo << ".pixel{ \n width: " << matrix->ancho_pixel << "px; \n";
            archivo << "height: " << matrix->alto_pixel << "px; \n float: left; \n } \n";
            while(aux3!=0){
                aux=aux3->abajo;
                while(aux!=0){
                    aux1=aux->siguiente;
                    while(aux1!=0){
                        if(aux1->posY==y){
                            for(int p=0;p<matrix->ancho_imagen;){
                                if(aux1!=0){
                                    if(p==aux1->posX){
                                        std::string color =aux1->Color;
                                        int j = color.size() + 1;
                                        char prueba[j];
                                        strcpy(prueba,color.c_str());
                                        for(int i=0; i<j;i++){
                                            if(prueba[i]=='-'){
                                                prueba[i]=',';
                                            }
                                        }
                                        archivo << "    .pixel:nth-child(" << x << "){ background: rgb(" << prueba << "); }\n";
                                        aux1=aux1->siguiente;
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
                            x=x+matrix->ancho_imagen;
                        }
                    }
                    aux=aux->abajo;
                    y++;
                }
                aux3=aux3->adelante;
                y=0;
                x=1;
            }
        generar_html(matrix,matrix->Nombre_imagen);
        }
        /*
        while(aux3!=0){
            cout << aux3->Color << endl;
            aux=aux3->abajo;
            while(aux!=0){
                cout << aux->Color << endl;
                aux1=aux->siguiente;
                while(aux1!=0){
                    //cout << aux1->Color << " " << aux1->posX << "," << aux1->posY << endl;
                    if(aux1->posY==y){
                        for(int p=0;p<matrix->ancho_imagen;){
                            if(aux1!=0){
                                if(p==aux1->posX){
                                    cout << x << endl;
                                    aux1=aux1->siguiente;
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
                        x=x+matrix->ancho_imagen;
                    }
                }
                aux=aux->abajo;
                y++;
            }
            aux3=aux3->adelante;
            y=0;
            x=1;
        }*/
        //generar_html(matrix, nombre_archivo);
    }catch(exception){
        cout << "error aqui 1" << endl;
    }

}

void generador_html::generar_html(Nodo_Arbol *&matrix, std::string nombre_css)
{
    //Nodo *aux=matrix->matriz;
    std::string nombre_archivo=matrix->Nombre_imagen;
    nombre_archivo+=".html";
    ofstream archivo;
    std::string ruta="CSV/";
    ruta+=matrix->Nombre_imagen;
    ruta+="/";
    ruta+=nombre_archivo;
    archivo.open(ruta,ios::out);
    if(archivo.fail()){
        cout << "hubo un erro al crear el archivo html" << endl;

    }else{
        archivo << "<!DOCTYPE html> \n <html> \n <head> \n <link rel=\"stylesheet\"  href=\"";
        archivo << nombre_css << ".css";
        archivo << "\" > \n </head> \n <body> \n <div class=\"canvas\"> \n";
        for(int fila=0; fila<matrix->alto_imagen;fila++){
            for(int col=0; col<matrix->ancho_imagen;col++){
                archivo << "    <div class=\"pixel\"></div> \n";
            }
        }
        archivo << "</div> \n </body> \n </html> \n";
        archivo.close();
    }
}

void generador_html::generador_prueba()
{
    ofstream archivo;
    archivo.open("Ave/prueba.css",ios::out);
    if (archivo.fail())
    {
        cout << "se produjo un error al crear el css" << endl;
    }else
    {
        archivo << "body{ \n aqui va un algoritmo \n }";
        cout <<"archivo creado" << endl;
        archivo.close();
    }

}

generador_html::~generador_html()
{
    //dtor
}
