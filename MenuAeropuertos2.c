int OpcionDeAlta();
int AltaAeropuerto (int a);
int MenuAeropuertos();

int OpcionDeAlta(){

	int opcionMenu, regreso=0;

	while(opcionMenu==0){	//Preguntar accion a realizar
	
		p("\n\tDeseas:\n");
		p("\n\t1) Dar de alta un aeropuerto");
		p("\n\t2) Editar un aeropuerto");
		p("\n\t3) Regresar al menu de administrador");
		p("\n\t4) Cerrar sesion\n\n\t");	
 		s(" %i", &opcionMenu); FLUSH

		switch (opcionMenu){
			case 1:        // 1) Dar de alta
			
				regreso=AltaAeropuerto(opcionMenu);
			break;
			

			case 2:        //Editar
			
				CLEAR
				p("\n\n\topcion 2\n");
			break;
			


			case 3:        //Regresar a menu admin
				opcionMenu=1;
				CLEAR
			break;
			
			case 4:        //Cerrar sesion
	
				CLEAR
				p("\n\n\topcion 4\n");
				break;
			
			default:
							CLEAR
				FLUSH
				p("\n\n\tSelecciona una opcion de las indicadas\n");
				opcionMenu=0;
			break;
			
		}

	}
	return 0;
}

int AltaAeropuerto(int a){

	int opcionMenu, indice=0,intento=0, resultadoCierre=0, resultadoRepetir=1, error=0;
	char caracter, aeropuerto[100], pais[100], estado[100], municipio[100];

	system("gedit ./ListaDeAeropuertos.txt & disown");
	p("\n\tSe ha abierto la lista de aereopuertos\n");
	getchar(); CLEAR FLUSH
	while(resultadoRepetir==1){
		CLEAR
		FLUSH
		p("\n\tNombre del aeropuerto: ");        //NOMBRE AEROPUERTO
		s(" %[^\n]%*c",&aeropuerto); FLUSH
		p("\n\tPais: ");                //PAIS AEROPUERTO
		s(" %[^\n]%*c",&pais); FLUSH
		p("\n\tEstado: ");
		s(" %[^\n]%*c",&estado); FLUSH
		p("\n\tMunicipio: ");
		s(" %[^\n]%*c",&municipio); FLUSH
		error=0;
		while(error!=1&&error!=2){
			p("\n\tDesea guardar el registro del aeropuerto:\n");
			p("\n\t\t1. Guardar aeropuerto.\n");
			p("\n\t\t2. No guardar aeropuerto.\n\n\t");
			s(" %i",&error); FLUSH
		}
		if(error==1){
			FILE*ListaAeropuertos = fopen ("ListaDeAeropuertos.txt", "a+");
			fprintf(ListaAeropuertos,"%s:",aeropuerto);
			fprintf(ListaAeropuertos,"%s:",pais);
			fprintf(ListaAeropuertos,"%s:",estado);
			fprintf(ListaAeropuertos,"%s\n",municipio);
			resultadoCierre=fclose(ListaAeropuertos);
			if(resultadoCierre==0){
				p("\n\n\tREGISTRO EXITOSO");
			}else{
				p("\n\n\tERROR EN EL REGISTRO");
			}
		}
		FLUSH
		resultadoRepetir=0;
		while(resultadoRepetir!=1&&resultadoRepetir!=2){
			p("\n\n\tDeseas dar de alta otro aeropuerto: \n");
			p("\n\t\t1. Si" );
			p("\n\t\t2. No\n\n\t");
			s("%i", &resultadoRepetir); FLUSH
		}
		if(resultadoRepetir == 2){
			CLEAR
		}
	}

	return 0;
}

