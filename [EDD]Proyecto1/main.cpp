#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h> /*uso para printf y scanf cuando sera necesario */
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include "lista_matriz.h"
#include "arbol_binario.h"
#include "generador_html.h"

using namespace std;

void insertar_Imagen();
void comparar();
void filtros();
void imagen_cargadas();
std::string imagen_en_proceso;
Arbol_Binario *arbol = new Arbol_Binario();


int main()
{
    bool menu=false;
    int opcion1;
    do
    {
        system("cls");
        //comparar();
        cout << "---------- MENU PHOTGEN+++ ----------" << endl;
        cout << "1. INSERTAR IMAGEN" << endl;
        cout << "2. SELECCIONAR IMAGEN" << endl;
        cout << "3. APLICAR FILTROS" << endl;
        cout << "4. EDICION MANUAL" << endl;
        cout << "5. EXPORTAR IMAGEN" << endl;
        cout << "6. REPORTES" << endl;
        cout << "7. SALIR" << endl;
        cin >> opcion1;
        switch(opcion1)
        {
        case 1:
            system("cls");
            insertar_Imagen();
            getwchar();
            getwchar();
            break;
        case 2:
            system("cls");
            imagen_cargadas();
            getwchar();
            getwchar();
            break;
        case 3:
            system("cls");
            filtros();
            getwchar();
            getwchar();
            break;
        case 4:
            system("cls");
            printf("Aqui hago una edicion manual");
            getwchar();
            getwchar();
            break;
        case 5:
            system("cls");
            printf("aqui vamos a exportar imagen");
            getwchar();
            getwchar();
            break;
        case 6:
            system("cls");
            printf("Aqui creamos reportes");
            getwchar();
            getwchar();
            break;
        case 7:
            system("cls");
            printf("Aqui vamos a cerrar el programa");
            menu=true;
            break;
        }

    }while(menu!=true);
        return 0;
}

void insertar_Imagen()
{
    string opcion1;
    string carpeta;
    string nombre;
        system("cls");
        cout << "---------- MENU PHOTGEN+++ ----------" << endl;
        cout << "Ingrese un nombre para la imagen" << endl;
        cin >> nombre;
        cout << "Ingrese el nombre del archivo .csv a utilizar" << endl;
        cin >> opcion1;
        try{
            arbol->leer_archivos(opcion1,nombre);
        }catch(string archivo){

        }
}

void comparar()
{
    generador_html nuevo;
    std::string cadena1="hola";
    std::string cadena2="holi";
    cout << cadena1.compare(cadena2) << endl; //-1
    cout << cadena2.compare(cadena1) << endl; //1
    cout << "\" hola \"" << endl;
    std::string prueba="hola";
    try{
        int a = std::stoi(prueba);
        if(a>=0){
            cout << "si se pudo" << endl;
        }else{
           cout << "no se pudo" << endl;
        }
    }catch(exception){
        cout << "no se pudo" << endl;
    }
    nuevo.generador_prueba();
    int x=0;
    while (true)
    {
        if(x>2){
            break;
        }else{
            cout << x << endl;
            x++;
        }
    }
    

}

void filtros()
{
    int eleccion, eleccion2;
    cout << "---------- Aplicacion de Filtros ----------" << endl;
    cout << "Filtros Disponibles" << endl;
    cout << "1. Negativo" << endl;
    cout << "2. Escala de Grises" << endl;
    cout << "3. Espejo eje x" << endl;
    cout << "4. Espejo eje y" << endl;
    cout << "5. Espejo en ambos ejes" << endl;
    cout << "6. Collage" << endl;
    cout << "7. Mosaico" << endl;
    cout << "" << endl;
    cout << "Cual desea aplicar:";
    cin >> eleccion;
    cout << "" << endl;
    cout << "A cual desea aplicar filtros:" << endl;
    cout << "1. Imagen Completa" << endl;
    cout << "2. A una capa especifica" << endl;
    cin >> eleccion2;
    switch (eleccion2)
    {
    case 1:
        
        cout << "Filtro Aplicado" << endl;
        break;
    case 2:
        
        cout << "Filtro Aplicado" << endl;
        break;
    }
}

void imagen_cargadas()
{
    std::string img;
    cout << "---------- Imagenes Cargadas ----------" << endl;
    cout << "Imagenes Disponibles" << endl;
    arbol->mostrar_lista();
    cout << "Escriba el nombre de la imagen que desea trabajar" << endl;
    cin >> img;
    imagen_en_proceso=img;
    cout << "Usted Selecciono: " << imagen_en_proceso << endl;
}