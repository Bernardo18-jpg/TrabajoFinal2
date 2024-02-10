it #include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctime>
main(){
	bool b = false;
	int opcion;
	do{
	opcion=menu();
	system("cls");
	switch(opcion){
		case 1:
			b = iniciarsesion(arch);
			break;
		case 2:

			if(b == true)
			{
				Lista(pac,turn);
			}
			else
			{
				printf("Porfavor Inicie sesion antes de relizar esta operacion...\n");
			}
		 
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
	}while(opcion!=4);
	
	 
}

