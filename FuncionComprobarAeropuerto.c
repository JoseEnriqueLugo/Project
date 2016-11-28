int FuncionComprobarAeropuerto(char aeropuerto[]);

int FuncionComprobarAeropuerto(char aeropuerto[]){

	FILE *listaAeropuertos;
	listaAeropuertos=fopen("ListaDeAeropuertos.txt","r");
	char cadena[200], arregloDeCadena[200][200], segmentoDeCadena[200][200];
	int indiceR=0, indice=0, indiceRsegmento=0, indiceCsegmento=0, subcadenas=0, posicion=0, aeropuertoExistente=0, regreso=0;

	

	//p("\n\tSe logro transferencia de: %s\n",aeropuerto);

		
	if(listaAeropuertos==NULL){
	
	}else{
		fseek(listaAeropuertos,0,SEEK_END);
		posicion=ftell(listaAeropuertos);
		rewind(listaAeropuertos);

		while(feof(listaAeropuertos)==0&&ftell(listaAeropuertos)!=posicion){
			
			fgets(cadena,200,listaAeropuertos);
			for(indice=0; indice<strlen(cadena); indice++){
				arregloDeCadena[indiceR][indice]=cadena[indice];
			}		
			//p("\n\tCadena: %s**\n",arregloDeCadena[indiceR]);
			indiceR++;
			indiceRsegmento=0;
			indiceCsegmento=0;	
			for(indice=0; indice<strlen(cadena); indice++){
				if(cadena[indice]==':'&&indice!=0){
					segmentoDeCadena[indiceRsegmento][indiceCsegmento]='\0';
					indiceRsegmento++;
					indiceCsegmento=0;
				}else{
					segmentoDeCadena[indiceRsegmento][indiceCsegmento]=cadena[indice];
					indiceCsegmento++;
				}
			}
			subcadenas=indiceRsegmento;
			segmentoDeCadena[indiceRsegmento][indiceCsegmento]='\0';
			for(indiceRsegmento=0; indiceRsegmento<=subcadenas; indiceRsegmento++){
				//p("\n\tCadena %i: %s\n",indiceRsegmento, segmentoDeCadena[indiceRsegmento]);
			}
			if(strcmp(segmentoDeCadena[0],aeropuerto)==0){
				regreso=1;
				//p("\n\tSe ha sumado 1 a regreso por existencia de aeropuerto\n");
			}
		}	
	}
	fclose(listaAeropuertos);
	return regreso;
}
