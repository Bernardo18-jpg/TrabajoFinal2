#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//gol
struct Profesionales
{
    char apenom[60], tel[25];
    int dni, IdProf;
};

struct Usuarios
{
    char apenom[60];
    char usuario[10];
    char contrase[10];
};

void profesionales(FILE *Prof, Profesionales pro);
void usuarios(FILE *Usua, Usuarios usu);
bool verifUsuario(char usuar[10], FILE *Usua, Usuarios usu);

main()
{
    FILE *Prof, *Usua;
    int opcion;
    Profesionales pro;
    Usuarios usu;
    Prof = fopen("Profesionales.dat", "a+b");
    Usua = fopen("Usuarios.dat", "a+b");
    if (Prof == NULL)
    {
        printf("\nError al abrir el archivo Profesionales\n");
        exit(1);
    }
    if (Usua == NULL)
    {
        printf("\nError al abrir el archivo Usuarios\n");
        exit(1);
    }
    //profesionales(Prof, pro);
    usuarios(Usua, usu);
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
        scanf("%d", &pro.IdProf);
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

void usuarios(FILE *Usua, Usuarios usu)
{
    int sino = 0;
    char usuar[10], contra[10];
    bool u;
    fwrite(&usu, sizeof(Usuarios), 1, Usua);
    do
    {
        do{
            _flushall();
            printf("\n\n\tNuevo Usuario:\n\n");
            printf("Apellido y Nombre: ");
            gets(usu.apenom);
            printf("Usuario: ");
            gets(usuar);
            printf("Contrasena: ");
            gets(contra);
            u = verifUsuario(usuar,Usua,usu);
        }while (u==true);    
        strcpy(usu.usuario, usuar);

        fwrite(&usu, sizeof(Usuarios), 1, Usua);
        do
        {
            printf("\nDesea agregar otro Usuario? (1 = Si/0 = No)");
            scanf("%d", &sino);
            _flushall();
            if (sino > 1 || sino < 0)
            {
                printf("Ingrese una opcion correcta...\n");
            }
        } while (sino > 1 || sino < 0);
    } while (sino == 1);
}

bool verifUsuario(char usuar[10], FILE *Usua, Usuarios usu)
{
    bool b = false;
    int cdigit=0, cmayus=0;
    fseek(Usua, sizeof(Usuarios), SEEK_SET);
    fread(&usu, sizeof(Usuarios), 1, Usua);
    while (!feof(Usua))
    {
        if ((strcmp(usu.usuario, usuar) == 0))
        {
            printf("Usuario incorrecto...YA EXISTE %s\n",usuar);
            b = true;
        }
        fread(&usu, sizeof(Usuarios), 1, Usua);
    }
    if (strlen(usuar) < 6)
    {
        printf("Usuario incorrecto...DEMASIADO CORTO\n");
        b = true;
    }
    else if (strlen(usuar) > 10)
    {
        printf("Usuario incorrecto...DEMASIADO LARGO\n");
        b = true;
    }
    if (usuar[0] < 'a' || usuar[0] > 'z')
    {
        printf("Usuario incorrecto...INICIAR EN MINUSCULA\n");
        b = true;
    }

    for (int i = 1; i < strlen(usuar) ; i++)
    {
        if (usuar[i]>='0' && usuar[i]<='9'){
            cdigit++;
        }
        if (usuar[i] >='A' && usuar[i]<='Z'){
            cmayus++;
        }
    }
    if (cdigit>3){
        printf("Usuario incorrecto...HASTA TRES DIGITOS NUMERICOS\n");
        b = true;
    }
    if (cmayus<2){
        printf("Usuario incorrecto...ALMENOS DOS MAYUSCULAS\n");
        b=true;
    }
    return b;
}

bool verifContrase(char contra[10], FILE *Usua, Usuarios usu)
{
    bool b = false;
    