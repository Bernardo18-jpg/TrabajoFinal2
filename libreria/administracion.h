#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

struct fecha
{
    int dia, mes, anio;
};
struct Profesionales
{
    char apenom[60], tel[25];
    int dni, IdProf, atencion;
};
struct Usuarios
{
    char apenom[60];
    char usuario[10];
    char contrase[10];
};
struct Atencion
{
    int cant;
    fecha fec;
};

int menu(void){
    int opcion;
    system("cls");
    printf("\n\tModulo Administracion");
    printf("\n\n\t========================");
    printf("\n\n\t1. Registrar Profesionales");
    printf("\n\n\t2. Registrar usuario recepcionista");
    printf("\n\n\t3. Atencion por Profesional");
    printf("\n\n\t4. Ranking de Profesionales por Atenciones");
    printf("\n\n\t5. SALIR");
    printf("\n\n\tINGRESE SU OPCION: ");
    scanf("%d", &opcion);
    _flushall();
    return opcion;
}
bool verifUsuario(char usuar[10], FILE *Usua, Usuarios usu)
{
    bool b = false;
    int cdigit = 0, cmayus = 0;
    fseek(Usua, sizeof(Usuarios), SEEK_SET);
    fread(&usu, sizeof(Usuarios), 1, Usua);

    if(Usua!=0){

    fseek(Usua, sizeof(Usuarios), SEEK_SET);
    fread(&usu, sizeof(Usuarios), 1, Usua);
    while (!feof(Usua))
    {
        if ((strcmp(usu.usuario, usuar) == 0))
        {
            printf("Usuario incorrecto...YA EXISTE %s\n", usuar);
            b = true;
        }
        fread(&usu, sizeof(Usuarios), 1, Usua);
    }
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
        printf("Usuario incorrecto...MINIMO DOS MAYUSCULAS\n");
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
FILE *Prof;
Profesionales pro;
Usuarios usu;
void profesionales(FILE *Prof, Profesionales pro, Usuarios usu)
{
    int sino,c;
    Prof=fopen("Profesionales.dat", "r+b");
    system("cls");
    if(Prof==NULL){
        printf("El archivo Profesionales no existe");
        printf("\nDesea crear el archivo? (S/N):  "); 
        c=getch();
        if(c=='s'||c=='S'){
            Prof=fopen("Profesionales.dat","w+b");
            printf("\nARCHIVO CREADO\n");
        }
    }else{
        printf("\nARCHIVO YA EXISTENTE\n");
        Prof=fopen("Profesionales.dat","a+b");
    }
    do
    {
        fread(&pro, sizeof(Profesionales), 1, Prof);
        printf("\n\n\tIngreso de datos del Profesional:\n\n");
        printf("\nApellido y Nombre: ");
        gets(pro.apenom);
        usu.apenom=pro.apenom;
        printf("\nId del profesional: ");
        scanf("%d", &pro.IdProf);_flushall();
        usu.usuario=pro.IdProf;
        printf("\nDNI: ");
        scanf("%d", &pro.dni);_flushall();     
        usu.contrase=pro.dni;   
        printf("\nNumero de telefono: ");
        gets(pro.tel);
        pro.atencion=0;
        fwrite(&pro, sizeof(Profesionales), 1, Prof);
        fwrite(&usu, sizeof(Usuarios), 1, Prof);
        printf("\nDesea cargar otro Profesional? (S/N):  "); 
        sino=getch();_flushall();
        while(sino!='s'&& sino!='S'&&sino!='n'&& sino!='N'){
            printf("\nIngrese una opcion correcta\n");
            printf("\nDesea cargar otro Profesional? (S/N):  "); 
            sino=getch();_flushall();
        }
    } while (sino=='s'|| sino=='S');
    fclose(Prof);
}
FILE *Usua;
void usuarios(FILE *Usua, Usuarios usu)
{   
    int sino = 0,a;
    char usuar[10], contra[10];
    bool u, c;
    
    do
    {
        fread(&usu, sizeof(Usuarios), 1, Usua);
        _flushall();
        printf("\n\n\tNuevo Usuario:\n\n");
        printf("Apellido y Nombre: ");
        gets(usu.apenom);
        do
        {
            printf("\nUsuario: ");
            gets(usuar);
            u = verifUsuario(usuar, Usua, usu);
        } while (u == true);
        do
        {
            printf("\nContrasena: ");
            gets(contra);
            c = verifContrase(contra, Usua, usu);
        } while (c == true);
        strcpy(usu.usuario, usuar);
        strcpy(usu.contrase, contra);
        fwrite(&usu, sizeof(Usuarios), 1, Usua);
        printf("\nDesea cargar otro Usuario? (S/N):  "); 
        sino=getch();_flushall();
        while(sino!='s'&& sino!='S'&&sino!='n'&& sino!='N'){
            printf("\nIngrese una opcion correcta\n");
            printf("\nDesea cargar otro Usuario? (S/N):  "); 
            sino=getch();_flushall();
        }
    } while (sino=='s'|| sino=='S');
    fclose(Usua);
}
FILE *Atencion;
Atencion aten;
void atencion(FILE *Atencion, Atencion aten)
{
    printf("De que profesional desea ingresar la cantidad de atenciones? ");
    printf("Ingrese el Id del profesional: ");
    scanf("%d",&)
}
void ranking()
{
    
}

