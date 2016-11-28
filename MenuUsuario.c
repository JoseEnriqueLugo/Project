int MenuUsuario(int opcion){
	opcion=0;
    while(opcion==0){
	opcion=0;
	while(opcion!=1&&opcion!=2&&opcion!=3&&opcion!=4&&opcion!=5){
	        p("\n\tBienvenido al menu del usuario\n");
	        p("\n\t1. Comprar boletos de avion\n");
        	p("\n\t2. Mis reservaciones\n");
	        p("\n\t3. Modificar mis reservaciones\n");
        	p("\n\t4. Realizar comentarios de mis vuelos\n");
	        p("\n\t5. Salir de sesion\n");	
		s(" %i",&opcion); FLUSH
	}
        switch(opcion){
            case 1:
                p("\n\tMenu comprar boletos\n");
                //llama funcion
                opcion=ComprarVuelos();
            break;
            case 2:
                p("\n\tMenu mis reservaciones\n");
                //llama funcion
                opcion=0;
            break;
            case 3:
                p("\n\tModificar reservasiones\n");
                //llama funcion
		 opcion=0;
            break;
            case 4:
                p("\n\tComentar mis vuelos\n");
                //llama funcion
                opcion=0;
            break;
            case 5:
                p("\n\tSaliendo del menu del usuario\n");
                //sale de funcion
                opcion=5;
            break;
            default:
                p("\n\tOpcion incorrecta\n");
                opcion=0;
                //regresa a la misma funcion
        }
    }
    return 0;	
}

