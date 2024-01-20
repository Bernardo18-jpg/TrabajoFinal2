#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct fecha
{
    int dia, mes, anio;
};

struct Pacientes
{
    char apenom[60];
    char domici[60];
    int dni;
    char locali[60];
    fecha fec;
    char tel[25];
};

struct Turnos
{
    int idProf;
    fecha fec;
    int dni;
    char detalles[380];
};

void pacientes(FILE *arch, Pacientes pac, fecha fec);

main()
{
    FILE *arch;
    int opcion;
    Pacientes pac;
    fecha fec;
    arch = fopen("Pacientes.dat", "a+b");
    if (arch == NULL)
    {
        printf("\nError al abrir el archivo\n");
        exit(1);
    }

    do
    {
        system("cls");
        printf("\n\tModulo del Recepcionista");
        printf("\n\n\t========================");
        printf("\n\n\t1. Iniciar sesion");
        printf("\n\n\t2. Registrar Pacientes");
        printf("\n\n\t3. Registrar Turnos");
        printf("\n\n\t4. Listado de Atenciones por Profesional y Fecha");
        printf("\n\n\t5. SALIR");
        printf("\n\n\tINGRESE SU OPCION: ");
        scanf("%d", &opcion);
        _flushall();
        switch (opcion)
        {
        case 1:

            break;
        case 2:
            system("cls");
            printf("\tRegistrar Pacientes");
            pacientes(arch, pac, fec);

            break;
        case 3:
            system("cls");
            printf("\nOPCION 3");
            break;
        case 4:
            printf("\nOPCION 4");
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

void pacientes(FILE *arch, Pacientes pac, fecha fec)
{
    int sino=0;
    fwrite(&pac, sizeof(Pacientes), 1, arch);
    do
    {
        _flushall();
        printf("\n\n\tIngreso de datos del paciente:\n\n");
        printf("Apellido y Nombre: ");
        gets(pac.apenom);
        printf("Domicilio: ");
        gets(pac.domici);
        printf("DNI: ");
        scanf("%d", &pac.dni);
        _flushall();
        printf("Localidad en la que reside:");
        gets(pac.locali);
        printf("Fecha de Nacimiento (dd/mm/aaaa): ");
        do
        {
            printf("Dia: ");
            scanf("%d", &fec.dia);
            if (fec.dia > 31 || fec.dia < 1)
            {
                printf("Ingrese una fecha valida...\n");
            }
        } while ((fec.dia > 31 || fec.dia < 1));
        do
        {
            printf("Mes: ");
            scanf("%d", &fec.mes);
            if (fec.mes > 12 || fec.mes < 1)
            {
                printf("Ingrese una fecha valida...\n");
            }
        } while ((fec.mes > 12 || fec.mes < 1));
        do
        {
            printf("Anio: ");
            scanf("%d", &fec.anio);
            if (fec.anio > 2024 || fec.anio < 1900)
            {
                printf("Ingrese una fecha valida...\n");
            }
        } while ((fec.anio > 2024 || fec.anio < 1900));
        _flushall();
        printf("Numero de telefono: ");
        gets(pac.tel);
        fwrite(&pac, sizeof(Pacientes), 1, arch);
        do{
            printf("\nDesea agregar otro paciente? (1 = Si/0 = No)"); scanf("%d",&sino);
            if(sino > 1 || sino < 0){
                printf("Ingrese una opcion correcta...\n");
            }
        }while (sino > 1 || sino < 0);
    } while (sino == 1);
}