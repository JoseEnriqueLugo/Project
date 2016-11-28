int RegistrarAdministrador();

int RegistrarAdministrador(){

	int opcion=0, salir=0, error=0,adminExistente=0;
	char nickname[20], contrasenia[20], nombre[50];
	FILE *datosUsuarios;
	FILE *datosAdministrador;
	while(salir==0){
		while(opcion!=1&&opcion!=2){
			p("\n\t1. Registrar administrador\n");
			p("\n\t2. Regresar a menu administrador\n\n\t");
			s(" %i",&opcion); FLUSH
		}
		if(opcion==1){
			CLEAR
			p("\n\tBienvenido al Menu de Registro\n");
			p("\n\tIngresar nombre completo\n\t");
			s(" %[^\n]%*c",&nombre); FLUSH
			p("\n\tIngresar nickname usuario\n\t");
			s(" %[^\n]%*c",&nickname); FLUSH
			p("\n\tIngresar contrasenia\n\t");
			s(" %[^\n]%*c",&contrasenia); FLUSH
			adminExistente=FuncionDeComprobacion(nickname,contrasenia);
			if(adminExistente==0){
				error=0;
				while(error!=1&&error!=2){
					p("\n\tDesea registrar el administrador\n");
					p("\n\t\t1. Guardar cambios\n");
					p("\n\t\t2. No registrar usuario\n\n\t");
					s(" %i",&error); FLUSH CLEAR			
				}	
				if(error=1){
				
					datosAdministrador=fopen("DatosAdministrador.txt","a+");					
					datosUsuarios=fopen("UsuariosYContrasenias.txt","a+");
					if(datosUsuarios!=NULL&&datosAdministrador!=NULL){
						fprintf(datosUsuarios,";%s;", nickname);
						fprintf(datosUsuarios,"%s\n",contrasenia);
						fprintf(datosAdministrador,"%s:%s\n",nickname,nombre);
					}
					fclose(datosAdministrador);
					fclose(datosUsuarios);
				}
		
			}else{
				p("\n\tEl administrador %s ya existe dentro de nustros registros, intente de nuevo\n",nickname);
				getchar(); CLEAR FLUSH 
				opcion=0;
			}
	
		
		}else{
			salir=1;
			CLEAR
		}
		opcion=0;
	}

	
	return 0;
}
