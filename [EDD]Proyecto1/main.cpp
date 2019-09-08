#include <iostream>
#include <string>
#include <stdio.h> /*uso para printf y scanf cuando sera necesario */
#include <stdlib.h>
#include <fstream>

using namespace std;

void insertar_Imagen();

int main()
{
    bool menu=false;
    int opcion1;
    do
    {
        system("cls");
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
        system("cls");
        cout << "---------- MENU PHOTGEN+++ ----------" << endl;
        cout << "Ingrese el nombre del archivo .csv" << endl;
        cin >> opcion1;
        try{

        }catch(string archivo){
            
        }
}

