int FuncionDePrimerAdministrador(){
        FILE *archivo;
        archivo=fopen("UsuariosYContrasenias.txt","a+");
        char nickname[100], contrasenia[100], opcion;
        int vacio=0, finalizado=0;

        while(finalizado==0){
                if(archivo!=NULL){

                        fseek(archivo,0,SEEK_END);
                        vacio=ftell(archivo);
                        if(vacio>0){
                                finalizado=1;
                        }else{
				CLEAR
                                p("\n\tEsta es la primera ejecucion del programa\n");
                                p("\n\tSe requiere de un primer administrador para el lanzamiento del programa\n");
                                p("\n\tIngrese su nickname\n\n\t");
                                s(" %s",&nickname); FLUSH
                                p("\n\tIngrese su contrasenia\n\n\t");
                                s(" %s",&contrasenia); FLUSH CLEAR
                                p("\n\tDesea crear el administrador con nickname: %s y contrasenia: %s  [S/N]: ",nickname,contrasenia);
                                s(" %c",&opcion); FLUSH
                                if(opcion=='S'||opcion=='s'||opcion=='Y'||opcion=='y'){

	                                fprintf(archivo,";%s;",nickname);
	                                fprintf(archivo,"%s\n",contrasenia);
                                        finalizado=1;
                                        fclose(archivo);

                                }
                        }
                }
        }
        return 0;
}

