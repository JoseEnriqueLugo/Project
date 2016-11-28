int ComprarVuelos();

int ComprarVuelos(){
	FILE *listaVuelos;

	char aeropuertoSalida[100], aeropuertoLlegada[100];
	int resultadoComprobacion=0;

	
	p("\n\tBienvenido al sistema de compra\n");
	p("\n\tA continuacion se presentaran los vuelos disponibles\n");
	p("\n\tPara conocer vuelos, ingrese aeropuerto de salida:\n\n\t");
	s(" %[^\n]%*c",&aeropuertoSalida); FLUSH
        resultadoComprobacion=FuncionComprobarAeropuerto(aeropuertoLlegada);
	p("\n\tIngresar aeropuerto de llegada\n\n\t");
	s(" %[^\n]%*c",&aeropuertoLlegada); FLUSH
	resultadoComprobacion=FuncionComprobarAeropuerto(aeropuertoLlegada);
	

	
	return 0;
}
