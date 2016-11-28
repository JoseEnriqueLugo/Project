/*    
    Este programa es para menu de inicio */ 


#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h> 
#define p printf
#define s scanf
#define FLUSH    setbuf(stdin,NULL);
#define CLEAR system("clear");
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define CYN  "\x1B[36m"
#define RESET "\x1B[0m"
#include"InicioSesion.c"
#include"Registro.c"
#include"FuncionDeComprobacion.c"
#include"RegistrarVueloChido.c"
#include"MenuUsuario.c"
#include"MenuAdministrador.c"
#include"MenuAeropuertos2.c"
#include"FuncionComprobarAeropuerto.c"
#include"FuncionPrimerAdministrador.c"
#include"ComprobarCodigo.c"
#include"RegistrarAdministrador.c"
#include"RevisarVuelos.c"
#include"ComprarVuelos.c"
	
int MenuRegistro();//Definir relacion a a
int InicioDeSesion(int a);//definir relacon a a
int MenuUsuario(int a);//definir relacion a a
int MenuAdministrador();//definir relacion a a
int FuncionDeComprobacion(char nickname[],char contrasenia[]);
int FuncionDePrimerAdministrador();

int  main(){
	    
    int opcion=0, regreso=0, primeraEjecucion=0;
    
    FuncionDePrimerAdministrador();	
    CLEAR getchar(); FLUSH 
    while(opcion==0){
	while(opcion!=1&&opcion!=2&&opcion!=3){
		CLEAR
	        p("\n\tBienvenido a la Aerolinea FP1122\n");
	        p("\n\t\t1. Registrarse\n");
	        p("\n\t\t2. Iniciar sesion\n");
	        p("\n\t\t3. Cerrar Programa\n\n\t");
	        s(" %i", &opcion); FLUSH    
        }
	switch (opcion){
            
           case 1:
                FLUSH
                CLEAR
                regreso=MenuRegistro(opcion);    
		CLEAR FLUSH
		opcion=0;
           break;

           case 2:    
                FLUSH
                CLEAR
                regreso=InicioDeSesion(opcion);
                CLEAR FLUSH
		opcion=0; 
           break;
            default:
                CLEAR
                regreso=3;
	    break;
        }      
       switch(regreso){
		case 0:
			opcion=0;
		break;
		case 1:
			opcion=MenuUsuario(opcion);

		break;
		case 2:
			MenuAdministrador();
			opcion=0;
		break;
		default:
			opcion=1;
		break;
	

	}
    }       
    return 0;
}
