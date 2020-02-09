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
#include "nodo.h"
#include "lista_circular.h"

using namespace std;

void insertar_Imagen();
void comparar();
void filtros();
void imagen_cargadas();
void exportar_imagen();
void reportes();
void IMPORTED_IMAGES_REPORT();
void IMAGE_LAYER_REPORT();
void LINEAR_MATRIX_REPORT();
void TRAVERSAL_REPORT();
void FILTERS_REPORT();
void todos_reportes();
void reportes_filtros();
std::string imagen_en_proceso;
int filtro_a;
Arbol_Binario *arbol = new Arbol_Binario();
Lista_Circular *lista = new Lista_Circular();
Nodo *Matriz_filtro1 = 0;
Nodo *Matriz_filtro2 = 0;
Nodo *Matriz_filtro3 = 0;
Nodo *Matriz_filtro4 = 0;
Nodo *Matriz_filtro5 = 0;
Nodo *Matriz_filtro6 = 0;
Nodo *Matriz_filtro7 = 0;


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
            exportar_imagen();
            getwchar();
            getwchar();
            break;
        case 6:
            system("cls");
            printf("Aqui creamos reporte");
            //arbol->graficar_matriz(imagen_en_proceso);
            reportes();
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
        if(eleccion==1){
            lista->insertar("Todas","Negativo");
            Matriz_filtro1=arbol->Buscar(imagen_en_proceso,1);
        }else if(eleccion == 2){
            lista->insertar("Todas","Escala de Grises");
            Matriz_filtro2=arbol->Buscar(imagen_en_proceso,2);
        }else if(eleccion == 3){
            lista->insertar("Todas","Espejo en eje X");
            Matriz_filtro3=arbol->Buscar(imagen_en_proceso,3);
        }else if(eleccion == 4){
            lista->insertar("Todas","Espejo en eje Y");
            Matriz_filtro4=arbol->Buscar(imagen_en_proceso,4);
        }else if(eleccion == 5){
            lista->insertar("Todas","Espejo en ambos ejes");
            Matriz_filtro5=arbol->Buscar(imagen_en_proceso,5);
        }else if(eleccion == 6){
            lista->insertar("Todas","Collage");

        }else if(eleccion == 7){
            lista->insertar("Todas","Mosaico");

        }
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
    arbol->mostrar_lista(arbol->getRaiz());
    cout << "Escriba el nombre de la imagen que desea trabajar" << endl;
    cin >> img;
    imagen_en_proceso=img;
    cout << "Usted Selecciono: " << imagen_en_proceso << endl;
    lista->borrar();
}

void exportar_imagen()
{
    std::string opcion;
    cout << "desea Exportar la imagen original o con filtro" << endl;
    cout << "Si desea importar con filtro, escriba que filtro desea exportar." << endl;
    lista->mostrar();
    cin >> opcion;
    if(opcion=="Original"){
        arbol->matriz_auxiliar(imagen_en_proceso);
    }else if(opcion == "Negativo"){
        arbol->matriz_auxiliar1(Matriz_filtro1,imagen_en_proceso);
    }else if(opcion == "Grises"){
        arbol->matriz_auxiliar1(Matriz_filtro2,imagen_en_proceso);
    }else if(opcion == "X"){
        arbol->matriz_auxiliar1(Matriz_filtro3,imagen_en_proceso);
    }else if(opcion == "Y"){
        arbol->matriz_auxiliar1(Matriz_filtro4,imagen_en_proceso);
    }else if(opcion == "Ambos"){
        arbol->matriz_auxiliar1(Matriz_filtro5,imagen_en_proceso);
    }
}

void reportes(){
    int opcion;
    cout << "---------- Reportes ----------" << endl;
    cout << "1. IMPORTED IMAGES REPORT" << endl;
    cout << "2. IMAGE LAYER REPORt" << endl;
    cout << "3. LINEAR MATRIX REPORT " << endl;
    cout << "4. TRAVERSAL REPORT " << endl;
    cout << "5. FILTERS REPORT " << endl;
    cout << "Cual reporte desea realizar?" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        system("cls");
        todos_reportes();
        getwchar();
        getwchar();
        break;
    case 2:
        system("cls");
        IMAGE_LAYER_REPORT();
        getwchar();
        getwchar();
        break;
    case 3:
        /* code */
        break;
    case 4:
        /* code */
        break;
    case 5:
        system("cls");
        reportes_filtros();
        getwchar();
        getwchar();
        break;
    }
}

void IMPORTED_IMAGES_REPORT()
{

}
void reportes_filtros(){
    int opcion;
    cout << "---------- Reportes ----------" << endl;
    cout << "1. Lista Circular" << endl;
    cout << "2. Lista de Filtros" << endl;
    cin >> opcion ;
    switch (opcion)
    {
    case 1:
        lista->graficar();
        break;
    case 2:
        lista->mostrar();
        std::string eleccion2;
        cout << "A cual filtro desea reportar" << endl;
        cin >> eleccion2;
        if(eleccion2=="Negativo"){
            arbol->graficar_matriz_filtro(Matriz_filtro1,imagen_en_proceso);
            arbol->matriz_auxiliar1(Matriz_filtro1,imagen_en_proceso);
        }else if(eleccion2=="Grises"){
            arbol->graficar_matriz_filtro(Matriz_filtro2,imagen_en_proceso);
            arbol->matriz_auxiliar1(Matriz_filtro2,imagen_en_proceso);
        }else if(eleccion2=="X"){
            arbol->graficar_matriz_filtro(Matriz_filtro3,imagen_en_proceso);
            arbol->matriz_auxiliar1(Matriz_filtro3,imagen_en_proceso);
        }else if(eleccion2=="Y"){
            arbol->graficar_matriz_filtro(Matriz_filtro4,imagen_en_proceso);
            arbol->matriz_auxiliar1(Matriz_filtro4,imagen_en_proceso);
        }else if(eleccion2=="Ambos"){
            arbol->graficar_matriz_filtro(Matriz_filtro5,imagen_en_proceso);
            arbol->matriz_auxiliar1(Matriz_filtro5,imagen_en_proceso);
        }
        break;

    }
}

void todos_reportes(){
    int opcion;
    cout << "---------- Reportes ----------" << endl;
    cout << "1. Arbol completo" << endl;
    cout << "2. Recorrido Preorden" << endl;
    cout << "3. Recorrido PosOrden " << endl;
    cout << "4. Recorrido InOrden " << endl;
    cout << "Cual reporte desea ver?" << endl;
    cin >> opcion;
    switch (opcion)
    {
    case 1:
        arbol->Grafica_arbol();
        cout << "Reporte generado" << endl;
        break;
    case 2:
        arbol->Grafica_preorden();
        cout << "Reporte generado" << endl;
        break;
    case 3:
        arbol->Grafica_posorden();
        cout << "Reporte generado" << endl;
        break;
    case 4:
        arbol->Grafica_inorden();
        cout << "Reporte generado" << endl;
        break;
    }

}

void IMAGE_LAYER_REPORT()
{
    std::string img;
    cout << "---------- Imagenes Cargadas ----------" << endl;
    cout << "Imagenes Disponibles" << endl;
    arbol->mostrar_lista(arbol->getRaiz());
    cout << "Escriba el nombre de la imagen que desea realizar reporte" << endl;
    cin >> img;
    imagen_en_proceso=img;
    cout << "Usted Selecciono: " << imagen_en_proceso << endl;
    arbol->graficar_matriz(imagen_en_proceso);
    cout << "Reporte generado" << endl;
}
