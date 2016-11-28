int MenuRegistro();

#define p printf
#define s scanf
#define CLEAR system("clear");
#define FLUSH    setbuf(stdin,NULL);
int MenuRegistro(){
    FILE *datosInicio;
    FILE *datosUsuario;	
    char caracter;
    int opcion=0;
    datosInicio=fopen("UsuariosYContrasenias.txt","a+");
    datosUsuario=fopen("Datos del Usuario.txt","a+");	
    char correo[100], nombre[100], domicilio[100], tarjeta[19], finalizar;
    int edad;
    char  nickname[20], contrasenia[20];
    int indiceRegistro=0, usuarioExistente=0, contraseniaExistente=0, errorRegistro=0, regreso=0, salir=0;
   
    while(regreso==0){
	opcion=0;
	while(opcion!=1&&opcion!=2){
		p("\n\t\t1. Registrarse\n");
		p("\n\t\t2. Regresar a Menu Principal\n\n\t\t");
		s(" %i",&opcion); FLUSH CLEAR

		if(opcion==2){
			salir=1;
			regreso=1;
		}
	}
	
	if(salir==0){
	    if(datosInicio==NULL||datosUsuario==NULL){
	        p("\n\tHubo un problema al arbir el archivo\n");
	    }
	    else{	
		if(errorRegistro==0){
			p("\n\tBienvenido al Menu de Registro\n"); 
		}
		else{
			if(errorRegistro==1){
				salir=0; 
				p("\n\tSi desea registrarse nuevamente ingrese sus datos y un usuario diferente\n\n");
				getchar(); FLUSH CLEAR
				
				
				
			}else{
				p("\n\tPuede comenzar con el nuevo registro\n\n");
				getchar(); FLUSH CLEAR
			}
		}
			regreso=0;
		        p("\n\tIngrese nombre\n\n\t");
		        s(" %[^\n]%*c",&nombre); FLUSH 
		    	p("\n\tIngrse nickname\n\n\t");  
			s(" %[^\n]%*c",&nickname); FLUSH
			usuarioExistente=FuncionDeComprobacion(nickname,contrasenia);
			if(usuarioExistente==3){
				CLEAR
				p("\n\tEl usuario %s ya existe dentro de nuestros registros, intente con otro\n",nickname);
				getchar(); CLEAR FLUSH
				errorRegistro=1;
			}else{
			    	p("\n\tIngrese contrasenia\n\n\t"); FLUSH 
			        s(" %[^\n]%*c",&contrasenia);
				p("\n\tIngrese correo electronico\n\n\t");
			  	s(" %[^\n]%*c",&correo); FLUSH 
			       	p("\n\tIngrese  edad\n\n\t");
			        s(" %i",&edad); FLUSH 					
			       	p("\n\tIngrese  tarjeta de credito o debito separada por guiones cada 4 digitos\n\n\t");
			        s(" %[^\n]%*c",&tarjeta); FLUSH 
			        p("\n\tIngrese  domicilio\n\n\t");
			     	s(" %[^\n]%*c",&domicilio); FLUSH  
				p("\n\tDesea guardar los datos [S/N]\n\n\t");
				s(" %c",&finalizar);
				getchar();
				if(finalizar=='s'||finalizar=='S'||finalizar=='Y'||finalizar=='y'){
					fprintf(datosInicio,":%s:",nickname);
					fprintf(datosInicio,"%s",contrasenia);
					fputc('\n',datosInicio);
					
					fprintf(datosUsuario,"%s:",nombre);
					fprintf(datosUsuario,"%s:",correo);
					fprintf(datosUsuario,"%i:",edad);
					fprintf(datosUsuario,"%s:",tarjeta);
					fprintf(datosUsuario,"%s\n",domicilio);
					regreso=1;	
			
			
	
				}else{
					errorRegistro=2;
				}
			  }
		}
	  }
     }		  	        	     						 	
    fclose(datosInicio);
    fclose(datosUsuario);
    return 1;
}

