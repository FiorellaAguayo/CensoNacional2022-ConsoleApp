#include <stdio.h>
#include <stdlib.h>
#include "censista.h"

static void mostrarTituloCensista();
static void mostrarUnCensista(eCensista censista);

static void mostrarTituloCensista()
{
    printf("\n-------------------------------------");
    printf("\n Legajo | Nombre | Edad | Telefono  |");
    printf("\n-------------------------------------");
}

static void mostrarUnCensista(eCensista censista)
{
    printf("\n %-8d %-8s %-6d %d", censista.legajo, censista.nombre, censista.edad, censista.telefono);
}

int mostrarListaCensistas(eCensista* lista, int tam)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        mostrarTituloCensista();
        for(int i = 0; i < tam; i++)
        {
            mostrarUnCensista(lista[i]);
        }
        todoOk = 1;
    }
    return todoOk;
}
