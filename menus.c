#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "inputs.h"

int menu()
{
	int opcion;

	printf("\n\n-------------------------");
	printf("\n         MENU            ");
	printf("\n-------------------------");
	printf("\n\n1. Alta de vivienda.   ");
	printf("\n2. Modificar vivienda.   ");
	printf("\n3. Baja de vivienda.     ");
	printf("\n4. Listar viviendas.     ");
	printf("\n5. Listar censistas.     ");
	printf("\n6. Censos realizados por censista.");
	printf("\n7. Censista con mas censos.");
	printf("\n8. Finalizar programa.   ");

	pedirEntero(&opcion, "\nIngrese una opcion: ", "\nLa opcion no es valida. Reingrese: ", 1, 8);

	return opcion;
}

int menuModificacion()
{
	int opcion;

	printf("\n¿Qué desea modificar?        ");
	printf("\n\n1. Calle.                  ");
	printf("\n2. Cantidad de personas.     ");
	printf("\n3. Cantidad de habitaciones. ");
	printf("\n4. Tipo de vivienda.         ");
	printf("\n5. Legajo de censista.       ");
	printf("\n6. Volver al menu.           ");

	pedirEntero(&opcion, "\nIngrese una opcion: ", "\nLa opcion no es valida. Reingrese: ", 1, 6);

	return opcion;
}
