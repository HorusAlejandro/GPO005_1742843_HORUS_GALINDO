//Programa Hecho en Code Blocks con el Compilador GNU GCC Compiler
//Por Horus Alejandro https://github.com/HorusAlejandro

#include <iostream>     //Librería principal para entrada/salida de datos
#include <string.h>     //Es necesario para ingreso de respuestas largas
#include <string>
#include <wchar.h>      //Para añadir Caracteres especiales como acentos, cosa que CodeBlocks No permitía
#include <locale.h>     //Otra librería con soporte de caracteres para fecha, moneda, dinero

using namespace std;

int main()
{
    //Índice de variables:
    //N (Nombre de Artículo)
    //D (Descripción de Artículo)
    //C (Características de Artículo)
    //G (Género de Artículo)
    //ID (Número de Artículo)
    //O (Selección del menú)
    //A (Año)
    //P (Precio Unitario)
    //IVA (México, 16%)
    //T (Total)

    string N,D,C,G;
    int ID,O,A;
    float P,IVA,T;

    setlocale(LC_ALL, ""); //Establece el uso de caracteres de la propia máquina

    //Menú
    cout << "\t ***TIENDA GAMERS*** \n \n";
    cout << "Bienvenido, seleccione una opción \n \n";
    cout << "1. Agregar Artículo \n";
    cout << "2. Modificar Artículo \n";
    cout << "3. Eliminar Artículo \n";
    cout << "4. Lista de Artículos Vigentes \n";
    cout << "5. Limpiar pantalla \n";
    cout << "6. Salir \n \n";
    //Elección
    cin >> O;

    //En base a la decisión, hacer acciones
    switch (O){

    //Añadido de artículos
    case 1:
        cout << "Agregue el número de artículo \n";
        cin >> ID;
        cout << "\nEscriba el nombre del videojuego \n";
        cin.ignore(); //Ignora espacios vacios al teclear Enter
        getline(cin, N); //Recibe la entrada con espacios incluidos
        cout << "\nIngrese la descripción del artículo \n";
        cin.ignore();
        getline(cin, D);
        cout << "\nIngrese las características del artículo \n";
        cin.ignore();
        getline(cin, C);
        cout << "\nIngrese el género \n";
        cin.ignore();
        getline(cin, G);
        cout << "\n¿Cuál es el año de lanzamiento? \n";
        cin >> A;
        cout << "\nTeclee el precio unitario \n";
        cin >> P;
        IVA = P * 0.16;
        T = P*1.16;
        return main();
        break;

    //Aún sin implementar, Modificación de artículos
    case 2:
        return main();
        break;

    //Aún sin implementar, Eliminación de artículos
    case 3:
        return main();
        break;

    //Aún sin implementar, Lista de Artículos Vigentes
    case 4:
        return main();
        break;

    //Limpieza de pantalla
    case 5:
        system("cls");
        return main();
        break;

    //Finalización del programa
    case 6:
        cout << "Gracias por utilizar el programa \n";
        break;

    //Opciones Inválidas
    default:
        cout << "Ingrese una opcion correcta \n";
        return main();
    }
    return 0;
}
