#include "generador_html.h"
#include <fstream>
#include <iostream>

generador_html::generador_html()
{
    //ctor
}

void generador_html::generar_css(Nodo_Arbol *matrix)
{
    Nodo *aux=matrix->matriz->abajo; /*Fila*/
    Nodo *aux1=aux->siguiente; /*Columna*/
    std::string nombre_archivo=matrix->Nombre_imagen;
    nombre_archivo+=".css";
    int x=1;
    int x_pixel=1;
    ofstream archivo;
    archivo.open(nombre_archivo,ios::out);
    if(archivo.fail()){
        cout << "hubo un erro al crear el archivo css" << endl;
    }else{
        archivo << "body{\n background: #333333; \n height: 100vh; \n display: flex; \n justify-content: center; \n align-items: center; \n }";
        archivo << ".canvas{ \n";
        archivo << "width: ";
        archivo << matrix->ancho_imagen*matrix->ancho_pixel;
        archivo << "; \n";
        archivo << "width: ";
        archivo << matrix->ancho_imagen*matrix->ancho_pixel;
        archivo << "; \n";
        archivo << "height: ";
        archivo << matrix->alto_imagen*matrix->alto_pixel;
        archivo << "; \n }";
        archivo << ".pixel{ \n";
        archivo << "width: ";
        archivo << matrix->ancho_pixel;
        archivo << "; \n";
        archivo << "width: ";
        archivo << matrix->ancho_pixel;
        archivo << "; \n";
        archivo << "height: ";
        archivo << matrix->alto_imagen*matrix->alto_pixel;
        archivo << "\n float: left;";
        archivo << "\n } \n";
        /*colocar el ciclo con el cual se le otorga el color a cada pixel */
        while(aux!=0){
            while (aux1!=0){
                if(aux1->posX+1==x_pixel){
                    std::string color=aux1->Color;
                    int j=color.size()+1;
                    char auxiliar[j];
                    for (int i=0; i<j; i++)
                    {
                        if(auxiliar[i]=='-'){
                            auxiliar[i]=',';
                        }
                    }
                    archivo << ".pixel:nth-child(";
                    archivo << x;
                    archivo << "){ \n background: rgb(";
                    archivo << auxiliar;
                    archivo << ") \n }";
                    aux1=aux1->siguiente;
                }else{
                    x_pixel++;
                    x++;
                }
            }
           aux=aux->abajo;
           aux1=aux->siguiente;
           x_pixel=1;
        }
        archivo.close();
    }
    generar_html(matrix, nombre_archivo);

}

void generador_html::generar_html(Nodo_Arbol *matrix, std::string nombre_css)
{
    //Nodo *aux=matrix->matriz;
    std::string nombre_archivo=matrix->Nombre_imagen;
    nombre_archivo+=".html";
    ofstream archivo;
    archivo.open(nombre_archivo,ios::out);
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
    archivo.open("prueba.css",ios::out);
    if (archivo.fail())
    {
        cout << "se produjo un error al crear el css" << endl;
    }else
    {
        archivo << "body{ \n }";
        cout <<"archivo creado" << endl;
        archivo.close();
    }

}

generador_html::~generador_html()
{
    //dtor
}
