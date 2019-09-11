#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h> /*uso para printf y scanf cuando sera necesario */
#include <stdlib.h>
#include <fstream>
#include <sstream>

using namespace std;

void insertar_Imagen();
void comparar();
void ingresar(std::string archivo);


int main()
{
    /*char cadena1[]="arco";
    char cadena2[]="avion";
    int x1= strcmp(cadena1,cadena2); */
    bool menu=false;
    int opcion1;
    do
    {
        system("cls");
        comparar();
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
            printf("Esta es la seleccion de imagen");
            getwchar();
            getwchar();
            break;
        case 3:
            system("cls");
            printf("Aqui aplico filtros");
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
    string nombre;
        system("cls");
        cout << "---------- MENU PHOTGEN+++ ----------" << endl;
        cout << "Ingrese un nombre para la imagen" << endl;
        cin >> nombre;
        cout << "Ingrese el nombre del archivo .csv" << endl;
        cin >> opcion1;
        try{

        }catch(string archivo){

        }
}

void comparar()
{
    std::string cadena1="hola";
    std::string cadena2="holi";
    cout << cadena1.compare(cadena2) << endl; //-1
    cout << cadena2.compare(cadena1) << endl; //1
    cout << "\" hola \"" << endl;

}

void ingresar(std::string archivo)
{
    ifstream lectura;
    char hola[archivo.size()+1];
    strcpy(hola,archivo.c_str());
    try{
        lectura.open(hola,ios::in);
        for(std::string filas; std::getline(lectura, filas); ){
            std::stringstream registro(filas);
        }
    }catch(exception){
        cout << "Se produjo un error al leer archivos" << endl;
    }
}
