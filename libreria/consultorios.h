#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>

struct Usuarios{
	
 	char Usuario[10];
 	char Contrasena[32];
 	char ApellidoyNombre[60];
};

struct fecha
{
    int dia, mes, anio;
};

struct Turnos
{
    int idProf;
    fecha fec;
    int dni;
    char detalles[380];
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
FILE *arch,*pac,*turn,*med;
Usuarios User;

fecha turno(){
    system("cls");
    turn=fopen("Turnos.dat","r+b");
    if(arch==NULL){
        printf("\nARCHIVO NO ENCONTRADO\n");
        printf("\nCARGUE PACIENTES EN EL PANEL ADMINISTRATIVO\n");
    }else{
	time_t t;
	t = time(NULL);
	struct tm *fec;
	fec = localtime(&t);
	fecha aux;
	aux.anio= fec->tm_year+1900;
	aux.mes= fec->tm_mon+1;
	aux.dia= fec->tm_mday;

	return aux;
    }
}
<<<<<<< HEAD
=======

bool validacionusuario(FILE *arch,char Contrasena[32],char Usuario[10]);
bool verificacioncontrasena(FILE *arch,char Contrasena[32]); 

>>>>>>> 0ccf6e642f2468f321bfb5064d3277cc59671e0a
int menu(void){
    int opcion;
    system("cls");
    printf("Modulo Consultorios\n\n");
	printf("=========================\n\n");
	printf("1.- Iniciar Sesion\n");
	printf("2.- Visualizar Lista de Espera de Turnos (informe)\n");
	printf("3.- Registrar Historia Clinica\n");
	printf("4.- Cerrar la aplicacion.\n\n");
	
	printf("Ingrese una opcion: ");
	scanf("%d",&opcion);
    _flushall();
    return opcion;
}
	char historia_clinica;
	//med=fopen("HistoriaClinica.dat","a+b");
bool iniciarsesion(FILE *arch){
    system("cls");
    arch=fopen("Usuarios.dat","r+b");
    if(arch==NULL){
        printf("\nARCHIVO NO ENCONTRADO\n");
        printf("\nCARGUE USUARIOS EN EL PANEL ADMINISTRATIVO\n");
    }else{
	char Usuario[10];
	char Contrasena[32];
	bool b;
	printf("\nIngrese el nombre de Usuario: ");
	scanf("%s",&Usuario);

	printf("\nIngrese su contrasena: ");
	scanf("%s",&Contrasena);
	
	b = validacionusuario(arch,Contrasena,Usuario);
	return b;
    }
}

bool validacionusuario(FILE *arch,char Contrasena[32],char Usuario[10])
{

	bool B=false,Band=false;

				rewind(arch);
				
				fread(&User,sizeof(Usuarios),1,arch);
				
				while(!feof(arch) && Band == false)
				{
						
					if(strcmp(User.Usuario,Usuario)==0)
					{
						Band = true;
					}
					
					fread(&User,sizeof(Usuarios),1,arch);
				}
			
				if (Band == false)
				{
  		 		       printf("Usuario no encontrado...\n");
			   	}
				else
				{
   	  				B = verificacioncontrasena(arch,Contrasena);
   				}

   	
   	return B;

}

bool verificacioncontrasena(FILE *arch,char Contrasena[32])
{
	
	int min=0,may=0,num=0,i=0;
	bool B=false;

	const long int tamanio = sizeof(Usuarios);
	
	fseek(arch,-tamanio,SEEK_CUR);
	fseek(arch,-tamanio,SEEK_CUR);
	
	fread(&User,sizeof(Usuarios),1,arch);
	
		
			if(strcmp(User.Contrasena,Contrasena)!=0)
			{
				
				printf("Contrasena incorrecta...\n ");
				printf("\n *No coincide");
			}
			else
			{
				B = true;
			}
			
	return B;
} 
    
void Lista(FILE *pac, FILE *turn) {
    int i = 1;
    Pacientes aux;
    Turnos aux2;
    fecha hoy;
    system("cls");
    pac=fopen("Pacientes.dat","r+b");
    if(arch==NULL){
        printf("\nARCHIVO NO ENCONTRADO\n");
        printf("\nCARGUE PACIENTES EN EL PANEL ADMINISTRATIVO\n");
    }else{
    hoy = turno();

    printf("TURNO\t PACIENTE \t\t\t DNI \t\t\t\t \n");

    fread(&aux, sizeof(Pacientes), 1, pac);
    fread(&aux2, sizeof(Turnos), 1, turn);

    while (!feof(turn)) {
        if (hoy.anio == aux2.fec.anio && hoy.mes == aux2.fec.mes && hoy.dia == aux2.fec.dia) {
            printf("%d", i);
            printf("\t\t");
            printf("%s", aux.apenom);
            printf("\t\t\t");
            printf("%d", aux.dni);
            printf("\n");
            fread(&aux, sizeof(Pacientes), 1, pac);
        }

        fread(&aux2, sizeof(Turnos),1, turn);
        }
    }
}
