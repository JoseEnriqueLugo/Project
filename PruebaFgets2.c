#include<stdio.h>
#include<string.h>



int main(){
	FILE *archivo;
	archivo=fopen("ListaDeAeropuertos.txt","r");
	char cadena[200], arreglo[200][200], segmentoDeCadena[200][200];
	int indiceR=0, indice=0, indiceRsegmento=0, indiceCsegmento=0, subcadenas=0, ultimaCadena=0;
	int posicion=0;

	if(archivo!=NULL){
		fseek(archivo,0,SEEK_END);
		posicion=ftell(archivo);
		rewind(archivo);
		printf("\nPosicion: %i\n",posicion);
	//	printf("\n\tSe abrio archivo\n");
		while(feof(archivo)==0){
			//printf("\n\tSi entro a while feof\n");
		
			fgets(cadena,200,archivo);
			if(cadena[0]==EOF){
				
				printf("\ni*********************Fin de algo");
			}
			printf("\nCadena: %s**\n",cadena);
			//posicion=ftell(archivo);
			printf("\nPosicion: %i\n",posicion);
						ultimaCadena++;
			for(indice=0; indice<strlen(cadena); indice++){
				arreglo[indiceR][indice]=cadena[indice];
			}
		
				printf("\n\tCadena: %s de renglon %i\n",arreglo[indiceR],indiceR);	
				indiceR++;
				//////////////
				indiceRsegmento=0;
				indiceCsegmento=0;
                        for(indice=0; indice<strlen(cadena); indice++){
                                if((cadena[indice]=='-')&&indice!=0){
                                        segmentoDeCadena[indiceRsegmento][indiceCsegmento]='\0';
                                        indiceRsegmento++;
                                        indiceCsegmento=0;
                                }else{
                                        segmentoDeCadena[indiceRsegmento][indiceCsegmento]=cadena[indice];
                                        indiceCsegmento++;
                                }
                        }
			segmentoDeCadena[indiceRsegmento][indiceCsegmento]='\0';
                        subcadenas=indiceRsegmento;
                        for(indiceRsegmento=0; indiceRsegmento<=subcadenas; indiceRsegmento++){
                                printf("\n\tCadena %i: %s\n",indiceRsegmento, segmentoDeCadena[indiceRsegmento]);
                        }
		}
				//COMPARAR con otro archivo
				//cambiar nombres etc
		
	}
			
		

	return 0;
}
