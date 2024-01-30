#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Usuarios{
	
 	char Usuario[10];
 	char Contrasena[10];
 	char ApellidoyNombre[60];
};

struct Profecionales{
		
 	char Usuario[10];
 	char Contrasena[10];
 	char ApellidoyNombre[60];
};



bool iniciarsesion(FILE *arch, Profecionales Pro);
bool validacionusuario(FILE *arch,char Contrasena[32],char Usuario[10], Profecionales Pro);
bool verificacioncontrasena(FILE *arch,char Contrasena[32],Profecionales Pro);

main(){
	
	FILE *arch;
    Profecionales Pro;
	int opc=0;
	bool b = false;
	arch=fopen("Profecionales.dat","a+b");
	
	do{
	printf("Modulo Consultorios\n\n");
	printf("=========================\n\n");
	printf("1.- Iniciar Sesion\n");
	printf("2.- Visualizar Lista de Espera de Turnos (informe)\n");
	printf("3.- Registrar Historia Clinica\n");
	printf("4.- Cerrar la aplicacion.\n\n");
	
	printf("Ingrese una opcion: ");
	scanf("%d",&opc);
	
	system("cls");
	switch(opc){
		
		case 1:
			
			b = iniciarsesion(arch, Pro);
			
			break;
			
		case 2:
		 
			break;
			
		case 3:
			
			break;
			
		case 4:
			
			break;
			
		default:
			
			printf("Ingrese un opcion CORRECTA porfavor...\n");
			break;
	}
	system("pause");
	system("cls");
	}while(opc!=4);
	
	 fclose(arch); 
}

bool iniciarsesion(FILE *arch, Profecionales Pro){

	//Usuarios user;
	char Usuario[10];
	char Contrasena[32];
	
	bool b;
	
	printf("\nIngrese el nombre de Usuario: ");
	scanf("%s",&Usuario);

	printf("\nIngrese su contrasena: ");
	scanf("%s",&Contrasena);
	
	b = validacionusuario(arch,Contrasena,Usuario, Pro);
	
	return b;

}

bool validacionusuario(FILE *arch,char Contrasena[32],char Usuario[10], Profecionales Pro)
{

	bool B=false,Band=false;

		if(strlen(Usuario)<6)
		{
			printf("Usuario incorrecto...DEMACIADO CORTO\n");
		}
		else
		{
			if(strlen(Usuario)>10)
			{
				printf("Usuario incorrecto...DEMACIADO LARGO\n");
		    }
			else
			{
				
				fread(&Pro,sizeof(Profecionales),1,arch);
				
				while(!feof(arch) && Band == false)
				{
					if(strcmp(Pro.Usuario, Usuario) == 0)
					{
						Band = true;
					}
					fread(&Pro,sizeof(Profecionales),1,arch);
				}
			
				if (Band == false)
				{
  		 		       printf("Usuario no encontrado...\n");
			   	}
			}
		}
        

   	if (Band == true)
	{
   	  B = verificacioncontrasena(arch,Contrasena, Pro);
   	}

   	
   	return B;

}

bool verificacioncontrasena(FILE *arch,char Contrasena[32], Profecionales Pro)
{
	
	int min=0,may=0,num=0,i=0;
	bool B=false;
	
	for(i;i<32;i++)
	{
		
		if(Contrasena[i] >= 'a' && Contrasena[i] <= 'z')
		{
			
			min++;
			
			if (Contrasena[i] >= 'A' && Contrasena[i] <= 'Z')
			{
				may++;
				
				if(Contrasena[i] >= '0' && Contrasena[i] <= '9')
				{
					num++;
				}
			}
		}
	}

	fseek(arch,-sizeof(Profecionales),SEEK_CUR);
	
	if(min<1 || may<1 || num<1 || strlen(Contrasena)<6 || strlen(Contrasena)>32 || strcmp(Pro.Contrasena,Contrasena)!=0)
	{
		printf("Contrasena incorrecta... ");
		
			if(min<1)
			{
				printf("\n *DEBE CONTENER 1 MINUSCULA");
			}
			if(may<1)
			{
			printf("\n *DEBE CONTENER 1 MAYUSCULA");
			}
			if(num<1)
			{
				printf("\n *DEBE CONTENER 1 NUMERO");
			}
			if(strlen(Contrasena)<6)
			{
				printf("\n *DEMACIADO CORTA");
			}
			if(strlen(Contrasena)>32)
			{
				printf("\n *DEMACIADO LARGA");
			}
			if(strcmp(Pro.Contrasena,Contrasena) != 0)
			{
				printf("\n *No coincide");
			}
	}
	else
	{
		B = true;
	}
	return B;
} 
    
