#ifndef CENSISTA_H_INCLUDED
#define CENSISTA_H_INCLUDED

typedef struct
{
	int legajo;
	char nombre[20];
	int edad;
	int telefono;
	int isEmpty;
}eCensista;


#endif // CENSISTA_H_INCLUDED

int mostrarListaCensistas(eCensista* lista, int tam);
int menuModificacion();
