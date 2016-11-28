int MenuAdministrador(){
	int opcion=0;      

	while (opcion==0){	 
		opcion=0;
		while(opcion!=1&&opcion!=2&&opcion!=3&&opcion!=4&&opcion!=5&&opcion!=6){
 			p("\n\tBienvenido al menu de administrador\n");	
			p("\n\t\t1. Dar de alta aeropuertos\n");
			p("\n\t\t2. Registrar nuevo(s) vuelo(s)\n");
			p("\n\t\t3. Registrar administrador\n");
			p("\n\t\t4. Ver historial de vuelos\n");
			p("\n\t\t5. Revisar calificaciones\n");
			p("\n\t\t6. Cerrar sesion\n");
			s(" %i",&opcion); FLUSH 
		}
	
		switch (opcion){
			case 1:
				CLEAR
				opcion=OpcionDeAlta();
				       
			break;
			case 2:
				CLEAR
				opcion=MenuDeVuelos();
			break;
			case 3:
				CLEAR 
				opcion=RegistrarAdministrador();
			break;
			case 4:
				CLEAR		
				opcion=RevisarVuelos();
			break;
			case 5:
			break;
			case 6:
				CLEAR
				opcion=1;
			break;
			default:
			break; 
		}
	}

	return opcion;
}
