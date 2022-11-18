//Programa Hecho en Code Blocks con el Compilador GNU GCC Compiler
//Por Horus Alejandro https://github.com/HorusAlejandro

#include <iostream>     //Librería principal para entrada/salida de datos
#include <stdio.h>      //Entre el uso del printf, scanf
#include <string.h>     //Es necesario para ingreso de respuestas largas
#include <string>
#include <wchar.h>      //Para añadir Caracteres especiales como acentos, cosa que CodeBlocks No permitía
#include <locale.h>     //Otra librería con soporte de caracteres para fecha, moneda, dinero
#include <fstream>      //Para la creación de archivos

using namespace std;

float IVA = 0.16; //Porcentaje de impuestos en México
int x;           //Opciones
int L=0;          //Control en la creación de elementos

struct Datos    //Declarando los datos que se recibirán
{
    string Nombre,Descripcion,Caracteristicas,Genero,Version;
    int Ano;
    float Precio,Impuesto,Total;
}Lista[100];

void Ingreso(int Opcion);
void Modificacion();
void GenerarLista();
void Eliminar();
void Archivo();

int main()
{
    /*Índice de variables:
    Nombre (Nombre de Artículo)
    Descripcion (Descripción de Artículo)
    Caracteristicas (Características de Artículo)
    Genero (Género de Artículo)
    Version (Versión del Artículo)
    Opcion (Selección del menú)
    Ano (de lanzamiento)
    Precio (Precio Unitario)
    IVA (México, 16%)
    Total (Total)
    */

    setlocale(LC_ALL, ""); //Establece el uso de caracteres de la propia máquina

    //Menú
    printf("\t ***TIENDA GAMERS*** \n \n");
    printf("Bienvenido, seleccione una opción \n \n");
    printf("1. Agregar Artículo \n");
    printf("2. Modificar Artículo \n");
    printf("3. Eliminar Artículo \n");
    printf("4. Lista de Artículos Vigentes \n");
    printf("5. Limpiar pantalla \n");
    printf("6. Salir \n \n");

    //Elección
    scanf("%d",&x);
    while (x < 1 || x > 6)
    {
        printf("La opción está fuera de rango\n");
        scanf("%d",&x);
    }
    /*
    scanf("%c",&O);
    while (O < 49 || O > 54) //Opciones incorrects
    {
        printf("La opción no es válida\n");
        if(O < 48 || O > 57)  //De pasarse de listo
        {
         printf("Aparte, deben ser valores numéricos \n");
        }
        cin.ignore();
        scanf("%c",&O);
    }
    int x = O - 48; //El valor de 0 es 48
    */

    //En base a la decisión, hacer acciones
    switch (x){

    //Añadido de artículos
    case 1:
        Ingreso(L);
        L = L+1;
        return main();
        break;

    //Modificación de artículos
    case 2:
        Modificacion();
        return main();
        break;

    //Eliminación de artículos
    case 3:
        Eliminar();
        return main();
        break;

    //Lista de Artículos Vigentes
    case 4:
        GenerarLista();
        return main();
        break;

    //Limpieza de pantalla
    case 5:
        system("cls");
        return main();
        break;

    //Finalización del programa
    case 6:
        Archivo();
        printf("Gracias por utilizar el programa \n");
        break;
    }
    return 0;
}

void Ingreso(int Opcion)
{
    printf("\nEscriba el nombre del videojuego \n");
    cin.ignore();                                            //Ignora espacios vacios al teclear Enter
    getline(cin, Lista[Opcion].Nombre);                      //Recibe la entrada con espacios incluidos
                                                             //Solo se necesita un cin.ignore() de poner más, se come la primera letra en loops
    printf("\nIngrese la versión del Juego \n");
    getline(cin, Lista[Opcion].Version);

    printf("\nIngrese la descripción del artículo \n");
    getline(cin, Lista[Opcion].Descripcion);

    printf("\nIngrese las características del artículo \n");
    getline(cin, Lista[Opcion].Caracteristicas);

    printf("\nIngrese el género \n");
    getline(cin, Lista[Opcion].Genero);

    printf("\nAño de Lanzamiento \n");
    scanf("%d",&Lista[Opcion].Ano);

    printf("\nTeclee el precio unitario \n");
    scanf("%f",&Lista[Opcion].Precio);
    Lista[Opcion].Impuesto = Lista[Opcion].Precio*IVA;
    Lista[Opcion].Total = Lista[Opcion].Precio + Lista[Opcion].Impuesto;
}

void Modificacion()
{
    int x;
    if(L==0)
    {
        printf("Aún no se ingresa ningún artículo en la lista\n\n");    //No puede modificar el artículo sin artículos
    }
    else
    {
        printf("Seleccione el artículo a modificar\n");
        scanf("%d",&x);
        x = x - 1;
        while (x < 0 || x > L-1)
        {
            printf("La opción se encuentra fuera de rango\nVuelva a ingresar la opcion\n");   //No puede elegir artículo fuera de los vigentes
            scanf("%d",&x);
            x = x - 1;
        }
        Ingreso(x);    //Procede al proceso de ingreso para modificación, pero sin agregar nuevo contenido, sobreescribe el artículo seleccionado
    }
}

void GenerarLista()
{
    if(L>0)
    {
        int X,S,Menor=0,Mayor=0,i=0,j=0,Posicion=0,Orden[L];
        printf("\nOpciones: \n\n");
        printf("1. Lista Normal por Artículos \n2. Lista por Nombres\n3. Lista por Género\n\n");
        scanf("%d",&X);
        switch(X)
        {
        case 1:
            for (int i=0;i<L;i++)  //Generación de lista con formato preliminar en el archivo
            {
                printf("\n[Artículo %d]\n",i+1);
                printf("%s\n",Lista[i].Nombre.c_str());
                printf("Versión: \n%s \n",Lista[i].Version.c_str());
                printf("Fecha de lanzamiento: \n%d \n",Lista[i].Ano);
                printf("Descripción:\n%s \n",Lista[i].Descripcion.c_str());
                printf("Características:\n%s \n",Lista[i].Caracteristicas.c_str());
                printf("Género:\n%s \n",Lista[i].Genero.c_str());
                printf("Precio Neto: \n%f \n",Lista[i].Precio);
                printf("Precio Total: \n%f \n",Lista[i].Total);
            }
            break;

        case 2:
            for (i=0;i<L;i++)
            {
                for(j=0;j<L;j++)
                {
                    S=Lista[j].Nombre[0];
                    if(S > Menor && S < Mayor)
                    {
                        Mayor = S;
                        Posicion = j;
                    }
                }
                Orden[i]=Posicion;
                Menor = Mayor;
                Mayor = 255;
            }
            for(i=0;i<L;i++)
            {
                printf("\n[Artículo %d]\n",Orden[i]+1);
                printf("%s\n",Lista[Orden[i]].Nombre.c_str());
                printf("Versión: \n%s \n",Lista[Orden[i]].Version.c_str());
                printf("Fecha de lanzamiento: \n%d \n",Lista[Orden[i]].Ano);
                printf("Descripción:\n%s \n",Lista[Orden[i]].Descripcion.c_str());
                printf("Características:\n%s \n",Lista[Orden[i]].Caracteristicas.c_str());
                printf("Género:\n%s \n",Lista[Orden[i]].Genero.c_str());
                printf("Precio Neto: \n%f \n",Lista[Orden[i]].Precio);
                printf("Precio Total: \n%f \n",Lista[Orden[i]].Total);
            }
        break;

        case 3:
            for (i=0;i<L;i++)
            {
                for(j=0;j<L;j++)
                {
                    S=Lista[j].Genero[0];
                    if(S > Menor && S < Mayor)
                    {
                        Mayor = S;
                        Posicion = j;
                    }
                }
                Orden[i]=Posicion;
                Menor = Mayor;
                Mayor = 255;
            }
            for(i=0;i<L;i++)
            {
                printf("\n[Artículo %d]\n",Orden[i]+1);
                printf("%s\n",Lista[Orden[i]].Nombre.c_str());
                printf("Versión: \n%s \n",Lista[Orden[i]].Version.c_str());
                printf("Fecha de lanzamiento: \n%d \n",Lista[Orden[i]].Ano);
                printf("Descripción:\n%s \n",Lista[Orden[i]].Descripcion.c_str());
                printf("Características:\n%s \n",Lista[Orden[i]].Caracteristicas.c_str());
                printf("Género:\n%s \n",Lista[Orden[i]].Genero.c_str());
                printf("Precio Neto: \n%f \n",Lista[Orden[i]].Precio);
                printf("Precio Total: \n%f \n",Lista[Orden[i]].Total);
            }
        break;

        default:
            printf("\n\nNo selecciono alguna opción válida, saliendo al menu principal\n\n");
        break;
        }

    }
    else
    {
        printf("\nNecesitas ingresar artículos para mostrar resultados\n");   //No muestra sin artículos
    }
}

void Eliminar()
{
    if(L==0)
    {
        printf("Aún no ingresa datos que eliminar");   //No elimina sin artículos
    }
    else
    {
        int S;
        printf("Seleccione un dato de la lista a eliminar \n");
        scanf("%d",&S);
        S = S-1;
        while (S < 0 || S > L-1)
        {
            printf("Seleccione dentro del rango de la lista\n");   //Tiene que ser de los artículos vigentes
            scanf("%d",&S);
            S = S-1;
        }
        for(int i=S;i<L;i++)  //Mueve todos los artículos desde la posición seleccionada una posición menos
        {
            Lista[S].Caracteristicas = Lista[S+1].Caracteristicas;
            Lista[S].Nombre = Lista[S+1].Nombre;
            Lista[S].Ano = Lista[S+1].Ano;
            Lista[S].Genero = Lista[S+1].Genero;
            Lista[S].Descripcion = Lista[S+1].Descripcion;
            Lista[S].Precio = Lista[S+1].Precio;
            Lista[S].Impuesto = Lista[S+1].Impuesto;
            Lista[S].Total = Lista[S+1].Total;
            Lista[S].Version = Lista[S+1].Version;
            S = S+1;
        }
        Lista[L].Caracteristicas = "a";         //Al último dato fuera de la lista, se le sobreescribe valores mínimos
        Lista[L].Nombre = "a";
        Lista[L].Ano = 0;
        Lista[L].Genero = "a";
        Lista[L].Descripcion = "a";
        Lista[L].Precio = 0;
        Lista[L].Impuesto = 0;
        Lista[L].Total = 0;
        Lista[L].Version = "a";
        L = L-1;
    }
}

void Archivo()
{
    ofstream archivos;
    string nombre;

    nombre = "Lista_de_Juegos.txt";
    archivos.open(nombre.c_str(), ios::out);

    if(archivos.fail())
    {
        printf("ERROR NO SE GENERO EL ARCHIVO \n");
        system("pause");
        exit(1);
    }

    archivos << "\t \t INFORMACION \n";
    for(int i=0;i<L;i++)
    {
        archivos << "|--------------|\n\n";
        archivos << "[Artículo: " << i+1 << "]";
        archivos << "\n\n[Nombre:] \n" << Lista[i].Nombre.c_str();
        archivos << "\n\n[Versión:] \n" << Lista[i].Version.c_str();
        archivos << "\n\n[Año:]\n" << Lista[i].Ano;
        archivos << "\n\n[Descripción:]\n" << Lista[i].Descripcion.c_str();
        archivos << "\n\n[Características:]\n" << Lista[i].Caracteristicas.c_str();
        archivos << "\n\n[Precio Neto:]\n" << Lista[i].Precio;
        archivos << "\n\n[Impuesto:]\n" << Lista[i].Impuesto;
        archivos << "\n\n[Precio Total:]\n" << Lista[i].Total << endl << endl;
    }
    archivos.close();
}
