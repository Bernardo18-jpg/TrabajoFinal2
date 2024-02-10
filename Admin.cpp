#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <administracion.h>

main()
{
    int opcion;
    do{
    opcion=menu();
    switch (opcion)
    {
        case 1:
            profesionales(Prof,pro);
            break;
        case 2:
            usuarios(Usua,usu);
            break;
        case 3:
            
            break;
        case 4:
            
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

