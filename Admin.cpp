#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
bool verifContrase(char contra[10], FILE *Usua, Usuarios usu);

main()
{
    int opcion;
    do{
    opcion=menu();
    switch (opcion)
    {
        printf("\nError al abrir el archivo Profesionales\n");
        exit(1);
    }
    if (Usua == NULL)
    {
        printf("\nError al abrir el archivo Usuarios\n");
        exit(1);
    }
    // profesionales(Prof, pro);
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
    bool u, c;
    fwrite(&usu, sizeof(Usuarios), 1, Usua);
    do
    {
        _flushall();
        printf("\n\n\tNuevo Usuario:\n\n");
        printf("Apellido y Nombre: ");
        gets(usu.apenom);
        do
        {
            printf("Usuario: ");
            gets(usuar);
            u = verifUsuario(usuar, Usua, usu);
        } while (u == true);
        do
        {
            printf("Contrasena: ");
            gets(contra);
            c = verifContrase(contra, Usua, usu);
        } while (c == true);
        strcpy(usu.usuario, usuar);
        strcpy(usu.contrase, contra);
        fwrite(&usu, sizeof(Usuarios), 1, Usua);
        do
        {
            printf("\nDesea agregar otro Usuario? (1 = Si/0 = No): ");
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
    int cdigit = 0, cmayus = 0;
    fseek(Usua, sizeof(Usuarios), SEEK_SET);
    fread(&usu, sizeof(Usuarios), 1, Usua);
    while (!feof(Usua))
    {
        if ((strcmp(usu.usuario, usuar) == 0))
        {
            printf("Usuario incorrecto...YA EXISTE %s\n", usuar);
            b = true;
        }
        printf("\n\n");
        system("pause");
    } while (opcion != 5);

    for (int i = 1; i < strlen(usuar); i++)
    {
        if (usuar[i] >= '0' && usuar[i] <= '9')
        {
            cdigit++;
        }
        if (usuar[i] >= 'A' && usuar[i] <= 'Z')
        {
            cmayus++;
        }
    }
    if (cdigit > 3)
    {
        printf("Usuario incorrecto...HASTA TRES DIGITOS NUMERICOS\n");
        b = true;
    }
    if (cmayus < 2)
    {
        printf("Usuario incorrecto...ALMENOS DOS MAYUSCULAS\n");
        b = true;
    }
    return b;
}

bool verifContrase(char contra[10], FILE *Usua, Usuarios usu)
{
    bool b = false;
    int cdigit = 0, cmayus = 0, cminus = 0;

    for (int i = 1; i < strlen(contra); i++)
    {
        if (contra[i] >= '0' && contra[i] <= '9')
        {
            cdigit++;
            if (contra[i + 1] >= '0' && contra[i + 1] <= '9')
            {
                if (contra[i + 2] >= '0' && contra[i + 2] <= '9')
                {
                    if (contra[i + 3] >= '0' && contra[i + 3] <= '9')
                    {
                        b = true;
                        printf("Contrasena incorrecta...NO PUEDEN HABER MAS DE 3 NUMEROS CONSECUTIVOS\n");
                    }
                }
            }
        }
        if (contra[i-1] >= 'A' && contra[i-1] <= 'Z')
        {
            cmayus++;
        }
        if (contra[i] >= 'a' && contra[i] <= 'z')
        {
            cminus++;
        }
        if (((contra[i] < 'a' || contra[i] > 'z') && (contra[i] < 'A' || contra[i] > 'Z') && (contra[i] < '0' || contra[i] > '9')))
        {
            printf("Contrasena incorrecta...SOLO CARACTERES ALFANUMERICOS\n");
            b = true;
        }
    }
    if (cdigit < 1)
    {
        printf("Contrasena incorrecta...MINIMO UN DIGITO NUMERICO\n");
        b = true;
    }
    if (cmayus < 1)
    {
        printf("Contrasena incorrecta...MINIMO UNA MAYUSCULA\n");
        b = true;
    }
    if (cminus < 1)
    {
        printf("Contrasena incorrecta...MINIMO UNA MINUSCULA\n");
        b = true;
    }

    if (strlen(contra) < 6)
    {
        printf("Contrasena incorrecta...DEMASIADO CORTA\n");
        b = true;
    }
    else if (strlen(contra) > 32)
    {
        printf("Contrasena incorrecta...DEMASIADO LARGA\n");
        b = true;
    }

    return b;
}
