#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Profesionales
{
    char apenom[60],tel[25];
    int dni,IdProf;
};

void profesionales(FILE *Prof, Profesionales pro);

main()
{
    FILE *Prof;
    int opcion;
    Profesionales pro;
    Prof = fopen("Profesionales.dat", "a+b");
    if (Prof == NULL)
    {
        printf("\nError al abrir el archivo\n");
        exit(1);
    }
    profesionales(Prof,pro);
    fclose(Prof);
}

void profesionales(FILE *Prof, Profesionales pro)
{
    int sino = 0;
    fwrite(&pro, sizeof(Profesionales), 1, Prof);
    do
    {
        printf("\n\n\tIngreso de datos del Profesional:\n\n");
        printf("Apellido y Nombre: ");
        gets(pro.apenom);
        printf("Id del profesional: ");
        scanf("%d",&pro.IdProf);
        printf("DNI: ");
        scanf("%d", &pro.dni);
        _flushall();
        printf("Numero de telefono: ");
        gets(pro.tel);
        fwrite(&pro, sizeof(Profesionales), 1, Prof);
        do
        {
            printf("\nDesea agregar otro profesional? (1 = Si/0 = No)");
            scanf("%d", &sino);
            _flushall();
            if (sino > 1 || sino < 0)
            {
                printf("Ingrese una opcion correcta...\n");
            }
        } while (sino > 1 || sino < 0);
    } while (sino == 1);
}