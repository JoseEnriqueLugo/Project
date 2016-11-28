#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define p printf
#define RED "\x1B[31m"
#define GRN "\x1B[32m"
#define CYN  "\x1B[36m"
#define RESET "\x1B[0m"

void main(){
	
        FILE *asientosVuelo;
        char nombreArchivo[150]="./VuelosAsientos/VueloEjemplo.txt";
        //Crean archivos de asientos con nombre de vuelos en un directorio
        asientosVuelo=fopen(nombreArchivo,"a+");
        char filasA[5]={'A','B','0','C','D'}, hileraCaracter[2], filasB[]={'A','0','B','C','D','0','E','F'};
        int indiceR=0, indiceC=0, hilera=0, indiceFila=0;
	char tipoAvion='A';

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
							//p("\t[ 0");
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
