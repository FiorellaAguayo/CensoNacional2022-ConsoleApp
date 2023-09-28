#ifndef VIVIENDA_H_INCLUDED
#define VIVIENDA_H_INCLUDED
#include "censista.h"

typedef struct
{
	int id;
	char calle[25];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda; //1. casa - 2. departamento - 3. casilla - 4. rancho
	int legajoCensista; // debe existir
	int isEmpty;
}eVivienda;


#endif // VIVIENDA_H_INCLUDED

int inicializarViviendas(eVivienda* lista, int tam);
int buscarEspacioLibre(eVivienda* lista, int tam);
int altaVivienda(eVivienda* listaViviendas, int tamVivienda, int* proxId, eCensista* listaCensistas, int tamCensistas);
int buscarViviendaPorId(eVivienda* lista, int tam, int id);
int modificarVivienda(eVivienda* listaViviendas, int tamViviendas, eCensista* listaCensistas, int tamCensistas);
int bajaVivienda(eVivienda* lista, int tam);
int mostrarListaViviendas(eVivienda* lista, int tam);
