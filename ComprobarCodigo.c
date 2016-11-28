int ComprobarCodigo(char codigo[]);


int ComprobarCodigo(char codigo[]){

	FILE *archivo;
	archivo=fopen("CodigoVuelos.txt","r");
	char arreglo[200][200], segmentos[200][200], cadena[200];
	int indiceR=0, indice=0, indiceC=0,posicion=0, indiceRseg=0, subcadena=0, regreso=0;

	if(archivo==NULL){

	}else{
		p("\n\tAbrio archivo");
		fseek(archivo,0, SEEK_END);
		posicion=ftell(archivo);
		rewind(archivo);

		while(feof(archivo)==0&&ftell(archivo)!=posicion){


			fgets(cadena,200,archivo);
			for(indice=0; indice<strlen(cadena); indice++){
				
				arreglo[indiceR][indice]=cadena[indice];

			}
			indiceR++;
			indiceC=0;
			indiceRseg=0;
			for(indice=0; indice<strlen(cadena); indice++){
				if(cadena[indice]=='-'&&indice!=0){

					segmentos[indiceRseg][indiceC]='\0';
					indiceRseg++;
					indiceC=0;
				}else{

					segmentos[indiceRseg][indiceC]=cadena[indice];
					indiceC++;
				}
			
			}	
			subcadena=indiceRseg;
			segmentos[indiceRseg][indiceC]='\0';
			for(indiceRseg=0; indiceRseg<=subcadena; indiceRseg++){
				//printf("\n\tCadena %i: %s\n",indiceRseg,segmentos[indiceRseg]);
				/*p("\n\tAeropuerto de salida: %s",segmentos);
				p("\n\tAeropuerto de llegada: %s",);
				p("\n\tDia de salida: %s",);
				p("\n\tHora de salida: %s");
				p("\n\tDia de llegada: %s");
				p("\n\tHora de llegada: %s");
				p("\n\tPrecio: %s");
				p("\n\tTipo avion: %S");*/
			}
			if(strcmp(segmentos[0],codigo)==0){
				regreso=1;
			}
				



		}
	





	}
	return regreso;
}
