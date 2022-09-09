//Programa Hecho en Code Blocks con el Compilador GNU GCC Compiler
//Por Horus Alejandro https://github.com/HorusAlejandro

#include <iostream>     //Librer�a principal para entrada/salida de datos
#include <string.h>     //Es necesario para ingreso de respuestas largas
#include <string>
#include <wchar.h>      //Para a�adir Caracteres especiales como acentos, cosa que CodeBlocks No permit�a
#include <locale.h>     //Otra librer�a con soporte de caracteres para fecha, moneda, dinero

using namespace std;

int main()
{
    //�ndice de variables:
    //N (Nombre de Art�culo)
    //D (Descripci�n de Art�culo)
    //C (Caracter�sticas de Art�culo)
    //G (G�nero de Art�culo)
    //ID (N�mero de Art�culo)
    //O (Selecci�n del men�)
    //A (A�o)
    //P (Precio Unitario)
    //IVA (M�xico, 16%)
    //T (Total)

    string N,D,C,G;
    int ID,O,A;
    float P,IVA,T;

    setlocale(LC_ALL, ""); //Establece el uso de caracteres de la propia m�quina

    //Men�
    cout << "\t ***TIENDA GAMERS*** \n \n";
    cout << "Bienvenido, seleccione una opci�n \n \n";
    cout << "1. Agregar Art�culo \n";
    cout << "2. Modificar Art�culo \n";
    cout << "3. Eliminar Art�culo \n";
    cout << "4. Lista de Art�culos Vigentes \n";
    cout << "5. Limpiar pantalla \n";
    cout << "6. Salir \n \n";
    //Elecci�n
    cin >> O;

    //En base a la decisi�n, hacer acciones
    switch (O){

    //A�adido de art�culos
    case 1:
        cout << "Agregue el n�mero de art�culo \n";
        cin >> ID;
        cout << "\nEscriba el nombre del videojuego \n";
        cin.ignore(); //Ignora espacios vacios al teclear Enter
        getline(cin, N); //Recibe la entrada con espacios incluidos
        cout << "\nIngrese la descripci�n del art�culo \n";
        cin.ignore();
        getline(cin, D);
        cout << "\nIngrese las caracter�sticas del art�culo \n";
        cin.ignore();
        getline(cin, C);
        cout << "\nIngrese el g�nero \n";
        cin.ignore();
        getline(cin, G);
        cout << "\n�Cu�l es el a�o de lanzamiento? \n";
        cin >> A;
        cout << "\nTeclee el precio unitario \n";
        cin >> P;
        IVA = P * 0.16;
        T = P*1.16;
        return main();
        break;

    //A�n sin implementar, Modificaci�n de art�culos
    case 2:
        return main();
        break;

    //A�n sin implementar, Eliminaci�n de art�culos
    case 3:
        return main();
        break;

    //A�n sin implementar, Lista de Art�culos Vigentes
    case 4:
        return main();
        break;

    //Limpieza de pantalla
    case 5:
        system("cls");
        return main();
        break;

    //Finalizaci�n del programa
    case 6:
        cout << "Gracias por utilizar el programa \n";
        break;

    //Opciones Inv�lidas
    default:
        cout << "Ingrese una opcion correcta \n";
        return main();
    }
    return 0;
}
