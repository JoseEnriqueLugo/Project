int MenuDeVuelos();
int MenuVuelos();
int NuevoVuelo();
int EditarVuelos();
void CrearVuelo(char salida[],char llegada[],char tipoAvion);

int MenuDeVuelos(){
	int opcionMenu=0, regreso=0;

//Preguntar accion a realizar
	while(opcionMenu==0)
	{
		CLEAR 
		p("\n\tDeseas:");
		p("\n\t\t1. Dar de alta un vuelo\n");
		p("\n\t\t2. Editar un vuelo\n");
		p("\n\t\t3. Regresar al menu de administrador\n");
		p("\n\t\t4. Cerrar sesion\n ");
		s(" %i",&opcionMenu); FLUSH
		switch (opcionMenu)
		{
			case 1:        // Dar de alta vuelo
				regreso=NuevoVuelo();		
			break;
			case 2:        //Editar vuelo
				CLEAR
				regreso=EditarVuelos();
			break;
			case 3:        //Cerrar sesion
				opcionMenu=1;
			break;
			case 4:        //Cerrar sesion
				regreso=1;
			break;
			default:
			break;
		}

	}
	CLEAR
	return regreso;
}
				
int NuevoVuelo(){
	
	int opcionMenu, indice=0,intento=0, resultadoCierre=0, resultadoRepetir=0, resultadoComprobacion=0, salir=0, error=0;
	char caracter, aeropuertoSalida[100], aeropuertoLlegada[100], horaSalida[50],horaLlegada[50], diaSalida[50], diaLlegada[50];
	char tipoAvion='d', precio[20];
	
	FILE*listaVuelos = fopen ("CodigoVuelos.txt", "a+");

	system("gedit ./ListaDeAeropuertos.txt & disown -p");
	if(listaVuelos==NULL){
		p("\n\tHubo un problema al intentar dar de alta el vuelo.");
	}else{
		fclose(listaVuelos);
		while(salir==0){
			CLEAR
			p("\n\tNombre del aeropuerto de origen: ");        		//NOMBRE AEROPUERTO ORIGEN
			s(" %[^\n]%*c",&aeropuertoSalida); FLUSH
			resultadoComprobacion=FuncionComprobarAeropuerto(aeropuertoSalida);
			if(resultadoComprobacion!=1){
				p("\n\tNo existe dicho  aeropuerto de salida\n");
				p("\n\tIintente de nuevo\n");	
				getchar(); FLUSH CLEAR
			}else{
				p("\n\tNombre del aeropuerto de destino: ");                //NOMBRE AEROPUERTO DESTINO
				s(" %[^\n]%*c",&aeropuertoLlegada); FLUSH
				resultadoComprobacion=FuncionComprobarAeropuerto(aeropuertoLlegada);
				if(resultadoComprobacion!=1){
					p("\n\tNo existe el aeropuerto de destino ingresado\n");
					p("\n\tIntente de nuevo\n");
					getchar(); FLUSH CLEAR					
				}else{
					
					p("\n\tDia de salida: ");
					s(" %[^\n]%*c",&diaSalida); FLUSH
					p("\n\tHora de salida:  ");
					s(" %[^\n]%*c",&horaSalida); FLUSH
					p("\n\tDia de arribo:  ");
					s(" %[^\n]%*c",&diaLlegada); FLUSH
					p("\n\tHora de arribo:  ");
					s(" %[^\n]%*c",&horaLlegada); FLUSH
					p("\n\tPrecio: ");
					s(" %[^\n]%*c",&precio);
					p("\nTipo de avion (A o B):  ");
					tipoAvion='d';
					while((tipoAvion!='A'&&tipoAvion!='B')){
							s(" %c",&tipoAvion); FLUSH	
					}
					while(error!=1&&error!=2){
						p("\n\tDesea guardar el registro del vuelo: \n");
						p("\n\t\t1. Guardar vuelo.\n");
						p("\n\t\t2. No guardar vuelo.\n\n\t");
						s(" %i",&error); FLUSH CLEAR
					}
					p("\n\tsalio de seleccion");
					if(error==1){
						
						listaVuelos=fopen("CodigoVuelos.txt","a+");
					
						time_t rawtime;
						struct tm * timeinfo;
						char tiempo [128];

  						time (&rawtime);
  						timeinfo = localtime (&rawtime);

  						strftime (tiempo,128,"%Y%m%d%H%M",timeinfo);
	
						fprintf(listaVuelos,"%s",tiempo);  //CODIGO DE VUELO
						fprintf(listaVuelos,"%c",tipoAvion);
						fputc('-',listaVuelos);
						fprintf(listaVuelos,"%s",aeropuertoSalida);
						fputc('-',listaVuelos);
						fprintf(listaVuelos,"%s",aeropuertoLlegada);
						fputc('-',listaVuelos);
						fprintf(listaVuelos,"%s",diaSalida);
						fputc('-',listaVuelos);
						fprintf(listaVuelos,"%s",horaSalida);
						fputc('-',listaVuelos);
						fprintf(listaVuelos,"%s",diaLlegada);
						fputc('-',listaVuelos);
						fprintf(listaVuelos,"%s",horaLlegada);
						fputc('-',listaVuelos);
						fprintf(listaVuelos,"%s",precio);
						fputc('\n',listaVuelos);
						
						resultadoCierre=fclose(listaVuelos);
						if(resultadoCierre==0){
							p("\n\n\tREGISTRO EXITOSO");
							getchar(); CLEAR FLUSH
							CrearVuelo(tiempo,aeropuertoLlegada,tipoAvion);
						}else{
							p("\n\n\tERROR EN EL REGISTRO");
							getchar(); CLEAR FLUSH
	
						}	
					}
				}
			}
			while(resultadoRepetir!=1&&resultadoRepetir!=2){
				p("\n\n\tDeseas ingresar un vuelo: ");
				p("\n\t1. Si" );
				p("\n\t2. No\n\n\t");
				scanf(" %i", &resultadoRepetir); FLUSH CLEAR
			}
			if(resultadoRepetir == 2){
				CLEAR
				salir=1;
			}
			resultadoRepetir=0;
			error=0;	
		}	
	}
	return 0;
}


int EditarVuelos(){
	char codigo[50];
	int regreso=0, categoria=0;

	while(regreso==0){	
		p("\n\tPara comenzar a editar un vuelo\n\n\tIngrese el codigo del vuelo: ");
		s(" %s",&codigo);
		regreso=ComprobarCodigo(codigo);
		if(regreso==1){
			while(categoria!=1&&categoria!=2&&categoria!=3&&categoria!=4&&categoria!=5&&categoria!=6&&categoria!=7&&categoria!=8){
				p("\n\tEliga lacategoria para editar:\n");
				p("\n\t\t1. Aeropuerto de salida.\n");
				p("\n\t\t2. Aeropuerto de destino.\n");
				p("\n\t\t3. Dia de salida.\n");
				p("\n\t\t4. Hora de salida.\n'");
				p("\n\t\t5. Dia de llegada.\n");
				p("\n\t\t6. Hora de llegada.\n");
				p("\n\t\t7. Precio.\n");
				p("\n\t\t8. Tipo de Avion.\n");
				s(" %s",&categoria);
			}
			switch(categoria){

				case 1:
					p("\n\tLa opcion a cambia es aeropuerto de salida");
				break;
				case 2:
		
				break;
				case 3:

				break;
				case 4:

				break;
				case 5:

				break;
				case 6:

				break;
				case 7:

				break;
				case 8:

				break;
				
			




			}

		}	
	}
	






	return 0;

}

void CrearVuelo(char tiempo[],char llegada[],char tipoAvion){
	FILE *asientosVuelo;
	char nombreArchivo[150]="./VuelosAsientos/Vuelo";
	char filasA[5]={'A','B','0','C','D'}, hileraCaracter[2], filasB[]={'A','0','B','C','D','0','E','F'};
        int indiceR=0, indiceC=0, hilera=0, indiceFila=0;
	//Crean archivos de asientos con nombre de vuelos en un directorio
	strcat(nombreArchivo,tiempo);
	if(tipoAvion=='A'){
	
		strcat(nombreArchivo,"A.txt");
	}else{
		strcat(nombreArchivo,"B.txt)");
	}
	asientosVuelo=fopen(nombreArchivo,"a+");

        switch (tipoAvion){
                case 'A':
                        for(indiceR=0; indiceR<40; indiceR++){
				p("\n\t");
				hilera++;
                                for(indiceC=0; indiceC<5; indiceC++){
					if(hilera<10){
						if(indiceC==2){
							p(CYN"[pasillo]  "RESET);
							fprintf(asientosVuelo,"pasillo:");
						}else{
							sprintf(hileraCaracter,"%d",hilera);
							p(GRN"[ ");
							p("%s",hileraCaracter);
							fprintf(asientosVuelo,"%s",hileraCaracter);
						}
					}else{
						if(indiceC==2){
							p(CYN"[pasillo]  "RESET);
							fprintf(asientosVuelo,"pasillo:");
						}else{
							sprintf(hileraCaracter,"%d",hilera);
							p(GRN"[%s",hileraCaracter);
							fprintf(asientosVuelo,"%s",hileraCaracter);	
						}
					}
					if(indiceC==2){
					}else{
						p("%c]  "RESET,filasA[indiceC]);
						fprintf(asientosVuelo,"%c:",filasA[indiceC]);
						
					}
				}
				fprintf(asientosVuelo,"\n");
                       	}

                break;
                case 'B':
								
			for(indiceR=0; indiceR<10; indiceR++){
				p("\n\t");
				hilera++;
				for(indiceC=0; indiceC<3; indiceC++){
					if(hilera<10){
						if(indiceC==1){
							p(CYN "[pasillo] "RESET);
							fprintf(asientosVuelo,"pasillo:");
						}else{	
							sprintf(hileraCaracter,"%d",hilera);
							p(GRN"[   ");
							p("%s",hileraCaracter);	
							fprintf(asientosVuelo,"%s",hileraCaracter);					
						}
					}else{
						if(indiceC==1){
							p(CYN "[pasillo] "RESET);
							fprintf(asientosVuelo,"pasillo:");
						}else{
							sprintf(hileraCaracter,"%d",hilera);
							p(GRN"[  %s",hileraCaracter);
							fprintf(asientosVuelo,"%s",hileraCaracter);
						}
					}
					if(indiceC==1){
					}else{
						p("%c  ] "RESET,filasB[indiceC]);
						fprintf(asientosVuelo,"%c:",filasB[indiceC]);
					}
				}
				fprintf(asientosVuelo,"\n");

			}
			hilera=0;
			for(indiceR=0; indiceR<7; indiceR++){
				p("\n\t");
				hilera++;
				for(indiceC=3; indiceC<8; indiceC++){
					if(indiceC==5){
						p(CYN"[pasillo] "RESET);
						fprintf(asientosVuelo,"pasillo:");
					}else{
						sprintf(hileraCaracter,"%d",hilera);
						p(GRN"[%s",hileraCaracter);
						fprintf(asientosVuelo,"%s",hileraCaracter);
					}
					if(indiceC==5){				
					}else{
						p("%c] "RESET,filasB[indiceC]);
						fprintf(asientosVuelo,"%c:",filasB[indiceC]);
					}

				
				}
				fprintf(asientosVuelo,"\n");
			}	
	
                break;                      
	}
	p("\n");
	fclose(asientosVuelo);

	
}


