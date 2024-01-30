#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

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

struct Profesionales
{
    char apenom[60], tel[25];
    int dni, IdProf;
};
    FILE *Parch, *Tarch, *Prof;
    Pacientes pac;
    Turnos tur;
    Profesionales pro;
    fecha fec;

    //MENU
int menu(void){
    int opcion;
    system("cls");
    printf("\n\tModulo del Recepcionista");
    printf("\n\n\t========================");
    printf("\n\n\t1. Iniciar sesion");
    printf("\n\n\t2. Registrar Pacientes");
    printf("\n\n\t3. Agendar Turnos");
    printf("\n\n\t4. Listado de Atenciones por Profesional y Fecha");
    printf("\n\n\t5. SALIR");
    printf("\n\n\tINGRESE SU OPCION: ");
    scanf("%d", &opcion);
    _flushall();
    return opcion;
   
}
//PACIENTES
void pacientes(FILE *Parch, Pacientes pac, fecha fec)
{
    int sino = 0,c;
    Parch=fopen("Pacientes.dat","r+b");
    system("cls");
    if(Parch==NULL){
        printf("El archivo pacientes no existe");
        printf("\nDesea crear el archivo? (S/N):  "); 
         c=getch();
        if(c=='s'||c=='S'){
            Parch=fopen("Pacientes.dat","w+b");
            printf("\nARCHIVO CREADO\n");
            _flushall();
        }
    }else{
        printf("\nARCHIVO YA EXISTENTE\n");
        Parch=fopen("Pacientes.dat","a+b");
    }
    
    fwrite(&pac, sizeof(Pacientes), 1, Parch);
    do
    {
        printf("\n\n\tIngreso de datos del paciente:\n\n");
        printf("Apellido y Nombre: ");
        gets(pac.apenom);
        printf("Domicilio: ");
        gets(pac.domici);
        printf("DNI: ");
        scanf("%d", &pac.dni);
        _flushall();
        printf("Localidad en la que reside: ");
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
        fwrite(&pac, sizeof(Pacientes), 1, Parch);
        do
        {
            printf("\nDesea agregar otro paciente? (1 = Si/0 = No)");
            scanf("%d", &sino);
            _flushall();
            if (sino > 1 || sino < 0)
            {
                printf("Ingrese una opcion correcta...\n");
            }
        } while (sino > 1 || sino < 0);
    } while (sino == 1);
}

void turnoss(FILE *Tarch, FILE *Parch, FILE *Prof, Pacientes pac, fecha fec, Turnos tur, Profesionales pro)
{
    int sino = 0, b = 0;
    fwrite(&tur, sizeof(Turnos), 1, Tarch);
    do
    {
        printf("\n\n\tCarga de un Turno:\n\n");
        do
        {
            printf("ID del Profesional: ");
            scanf("%d", &tur.idProf);
            fseek(Prof, sizeof(Profesionales), SEEK_SET);
            fread(&pro, sizeof(Profesionales), 1, Prof);
            while (!feof(Prof) && b == 0)
            {
                if (tur.idProf == pro.IdProf)
                {
                    printf("\n\tBUSCANDO DATOS DEL PROFESIONAL \n");
                    system("pause");
                    printf("Nombre: %s", pro.apenom);
                    b = 1;
                }
                fread(&pro, sizeof(Profesionales), 1, Prof);
            }
            if (b == 0)
            {
                printf("\n\tBUSCANDO DATOS DEL PROFESIONAL \n");
                system("pause");
                printf("NO SE ENCONTRO EL PROFESIONAL...\n");
                printf("Corregir el ID...\n");
            }
        } while (b == 0);
        printf("\nFecha del turno (dd/mm/aaaa): ");
        do
        {
            printf("Dia: ");
            scanf("%d", &tur.fec.dia);
            if (tur.fec.dia > 31 || tur.fec.dia < 1)
            {
                printf("Ingrese una fecha valida...\n");
            }
        } while ((tur.fec.dia > 31 || tur.fec.dia < 1));
        do
        {
            printf("Mes: ");
            scanf("%d", &tur.fec.mes);
            if (tur.fec.mes > 12 || tur.fec.mes < 1)
            {
                printf("Ingrese una fecha valida...\n");
            }
        } while ((tur.fec.mes > 12 || tur.fec.mes < 1));
        do
        {
            printf("Anio: ");
            scanf("%d", &tur.fec.anio);
            if (tur.fec.anio > 2030 || tur.fec.anio < 2023)
            {
                printf("Ingrese una fecha valida...\n");
            }
        } while ((tur.fec.anio > 2030 || tur.fec.anio < 2023));
        b = 0;
        do
        {
            printf("Dni del Paciente: ");
            scanf("%d", &tur.dni);
            fseek(Parch, sizeof(Pacientes), SEEK_SET);
            fread(&pac, sizeof(Pacientes), 1, Parch);
            while (!feof(Parch) && b == 0)
            {
                if (tur.dni == pac.dni)
                {
                    printf("\n\tBUSCANDO DATOS DEL PACIENTE \n");
                    system("pause");
                    printf("Nombre: %s", pac.apenom);
                    b = 1;
                }
                fread(&pac, sizeof(Pacientes), 1, Parch);
            }
            if (b == 0)
            {
                printf("\n\tBUSCANDO DATOS DEL PACIENTE \n");
                system("pause");
                printf("NO SE ENCONTRO EL PACIENTE...\n");
                printf("Corregir el dni...\n");
            }
        } while (b == 0);
        _flushall();
        printf("\nDetalles de Atencion: ");
        gets(tur.detalles);
        fwrite(&tur, sizeof(Turnos), 1, Tarch);
        do
        {
            printf("\nDesea agendar otro turno? (1 = Si/0 = No)");
            scanf("%d", &sino);
            _flushall();
            if (sino > 1 || sino < 0)
            {
                printf("Ingrese una opcion correcta...\n");
            }
        } while (sino > 1 || sino < 0);
    } while (sino == 1);
}

void listado(FILE *Prof, FILE *Tarch, Profesionales pro, Turnos tur)
{
    int b=0;
    printf("\tLISTADO DE TURNOS POR PROFESIONAL:\n");
    fseek(Tarch, sizeof(Turnos), SEEK_SET);
    fread(&tur,sizeof(Turnos),1,Tarch);
    fseek(Prof, sizeof(Profesionales), SEEK_SET);
    fread(&pro,sizeof(Profesionales),1,Prof);
    while(!feof(Tarch)){
        if(tur.idProf==pro.IdProf){
            printf("\nID del Profeional: %d ", tur.idProf);
            printf("\nNombre del Profesional: %s ", pro.apenom);
            printf("\nFecha del Turno: %d/%d/%d", tur.fec.dia,tur.fec.mes,tur.fec.anio);
            b=1;
        }
        fread(&tur,sizeof(Turnos),1,Tarch);
        fread(&pro,sizeof(Profesionales),1,Prof);      
    }
    if (b==0){
        printf("\nNo hay turnos programados...\n");
    }
    
}
