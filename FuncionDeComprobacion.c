int FuncionDeComprobacion(char nickname[],char contrasenia[]){
	
	FILE *archivoComprobar;
	archivoComprobar=fopen("UsuariosYContrasenias.txt","r+");
	int posicion=0,indice=0, indiceR=0, indiceC=0, subcadena, regreso;
	char cadena[100], segmentoAdmin[100][100], segmentoUser[100][100];
	
	

	if(archivoComprobar!=NULL){
		fseek(archivoComprobar,0,SEEK_END);
		posicion=ftell(archivoComprobar);
		rewind(archivoComprobar);
		while(feof(archivoComprobar)==0&&(ftell(archivoComprobar)!=posicion)){
			fgets(cadena,100,archivoComprobar);
			indiceR=0;
			indiceC=0;
			switch(cadena[0]){
				case ';':
					for(indice=0; indice<strlen(cadena); indice++){
						if(cadena[indice]==';'){
							if(indice==0){
									
							}else{
								segmentoAdmin[indiceR][indiceC]='\0';
								indiceC=0;
								indiceR++;
							}
						}else{
							if(cadena[indice]=='\n'){
							}else{
							segmentoAdmin[indiceR][indiceC]=cadena[indice];
							indiceC++;}
						}	

					}
					segmentoAdmin[indiceR][indiceC]='\0';
					subcadena=indiceR;
					for(indiceR=0; indiceR<=subcadena; indiceR++){
						if(strcmp(segmentoAdmin[indiceR],nickname)==0){
							if(strcmp(segmentoAdmin[indiceR+1],contrasenia)==0){
								regreso=2;
							}
						}	

					}	
				
			        break;
		                case ':':
					for(indice=0; indice<strlen(cadena); indice++){
						if(cadena[indice]==':'){
							if(indice==0){
							}else{
								segmentoUser[indiceR][indiceC]='\0';
								indiceC=0;
								indiceR++;
							}
						}else{
							if(cadena[indice]=='\n'){
							}else{
							segmentoUser[indiceR][indiceC]=cadena[indice];
							indiceC++;}							
						}
					}
					segmentoUser[indiceR][indiceC]='\0';
					subcadena=indiceR;
					for(indiceR=0; indiceR<=subcadena; indiceR++){
						if(strcmp(segmentoUser[indiceR],nickname)==0){
							if(strcmp(segmentoUser[indiceR+1],contrasenia)==0){
								regreso=1;
							}
						}	
						
					}
						
			        break;		
			}
		}
	}
	fclose(archivoComprobar);
	return regreso;		
}
