int InicioDeSesion(int a);
#define FLUSH    setbuf(stdin,NULL);
#define CLEAR system("clear");
int InicioDeSesion(int a){
    int regresoComprobacion=0, error=0, opcion=0, regreso=0;
    char nickname[20],contrasenia[20];


    while(regreso==0){
        if(error==0){
            p("\n\t1. Iniciar sesion\n");
            p("\n\t2. Regresar a menu principal\n\n\t");
            s(" %i",&opcion); FLUSH }
        else{
            CLEAR FLUSH
            p("\n\t Error en el nickname o contrasenia\n");
        getchar();
            CLEAR
            p("\n\t1. Volver a intentar a iniciar\n");
            p("\n\t2. Regresar a menu principal\n");
            s(" %i",&opcion); FLUSH
            }
               
        switch (opcion){   
	        case 1:
		    CLEAR	
        	    p("\n\tIngrese nickname: ");      
	            s(" %s",&nickname); FLUSH          
        	    p("\n\tIngrese contrasenia: "); //Valor 1 es para usuario
	            s(" %s",&contrasenia); FLUSH //Se evalua contrasena
	            regresoComprobacion=FuncionDeComprobacion(nickname,contrasenia); //Se evalua primeramente para nickname
	
	        switch (regresoComprobacion){ //Con switch se elige si fue usuario, administrador o ninguno
	            case 1:
	                    getchar(); CLEAR FLUSH    
	                    p("\n\tContrasenia usuario correcta\n");
	                    regreso=1; // regreso es igua 
        	    break;
	            case 2: //entro a 2 porque el valor regresado de nickname es 2 significa es administrador
        	            p("\n\tContrasenia administrador correcta\n");
			    getchar(); CLEAR FLUSH
	            break;
	            default:
        	        getchar(); CLEAR FLUSH
	                p("\n\tNo se encontro ningun usuario\n"); 
			getchar(); CLEAR FLUSH
	                error+=1;
        	}
                   
        	break;
	        case 2:
     		    getchar(); FLUSH
	            p("\n\tSe esta saliendo de menu de inicio de sesion\n");
		    getchar(); CLEAR FLUSH
        	    regreso=3;
        	break;
	        default:
        	    error=0;
	            CLEAR FLUSH
        	    p("\n\tEsta opcion no es disponible\n"); getchar();
		    getchar(); CLEAR FLUSH
		break;
        	}




    }


    return regreso;
}   


