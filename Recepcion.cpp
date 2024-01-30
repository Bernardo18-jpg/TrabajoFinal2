#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <recepcion.h>
main()
{
    int opcion;
    do{
    opcion=menu();
    switch (opcion)
    {
        case 1:
            inicioSesion(usuarios,us);
            break;
        case 2:
            system("cls");
            printf("\tRegistrar Pacientes");
            pacientes(Parch, pac, fec);
            break;
        case 3:
            system("cls");
            printf("\tAgendar Turnos");
            turnoss(Tarch, Parch, Prof, pac, fec, tur, pro);
            break;
        case 4:
            listado(Prof, Tarch, pro, tur);
            break;
        case 5:
            printf("\n\nUsted esta cerrando la aplicacion...\n");
            break;
        default:
            printf("\nNO ES UNA OPCION CORRECTA...");
            break;
        }
        printf("\n\n");
        system("pause");
    } while (opcion != 5);
   
}

