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
        Nodo *aux=matriz_aux->abajo ; /*Fila*/
        Nodo *aux1=aux->siguiente; /*Columna*/
        std::string nombre_archivo=matrix->Nombre_imagen;
        string ruta="CSV/";
        nombre_archivo+=".css";
        ruta+=matrix->Nombre_imagen;
        ruta+="/";
        ruta+=nombre_archivo;
        int x=1;
        int x_pixel=0;
        ofstream archivo;
        archivo.open(ruta,ios::out);
        if(archivo.fail()){
            cout << "hubo un erro al crear el archivo css" << endl;
        }else{
            archivo << "body{\n background: #333333; \n height: 100vh; \n display: flex; \n justify-content: center; \n align-items: center; \n } \n";
            archivo << ".canvas{ \n width: " << matrix->ancho_imagen*matrix->ancho_pixel << "; \n";
            archivo << "height: " << matrix->alto_imagen*matrix->alto_pixel << "; \n } \n";
            archivo << ".pixel{ \n width: " << matrix->ancho_pixel << "; \n";
            archivo << "height: " << matrix->alto_pixel << "\n float: left; \n } \n";
        }
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
    archivo.open("CSV/Ave/Ave.html",ios::out);
    if(archivo.fail()){
        cout << "hubo un erro al crear el archivo html" << endl;

    }else{
        archivo << "<!DOCTYPE html> \n <html> \n <head> \n <link rel=\"stylesheet\"  href=\"";
        archivo << nombre_css;
        archivo << "\" > \n </head> \n <body> \n <div class=\"canvas\">";
        for(int fila=0; fila<matrix->alto_imagen;fila++){
            for(int col=0; col<matrix->ancho_imagen;col++){
                archivo << "<div class=\"pixel\"></div> \n";
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
