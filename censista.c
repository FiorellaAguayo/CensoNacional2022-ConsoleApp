#include <stdio.h>
#include <stdlib.h>
#include "censista.h"
#include "vivienda.h"

void mostrarTituloCensista()
{
    printf("\n-------------------------------------");
    printf("\n Legajo | Nombre | Edad | Telefono  |");
    printf("\n-------------------------------------");
}

void mostrarUnCensista(eCensista censista)
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
