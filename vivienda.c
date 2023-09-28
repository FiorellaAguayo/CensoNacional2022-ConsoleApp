#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vivienda.h"
#include "inputs.h"
#include "censista.h"

static void mostrarTituloVivienda();
static void mostrarUnaVivienda(eVivienda vivienda);

int inicializarViviendas(eVivienda* lista, int tam)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarEspacioLibre(eVivienda* lista, int tam)
{
    int espacioLibre = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 1)
            {
                espacioLibre = i;
                break;
            }
        }
    }
    return espacioLibre;
}

int altaVivienda(eVivienda* listaViviendas, int tamVivienda, int* proxId, eCensista* listaCensistas, int tamCensistas)
{
    int todoOk = 0;
    if(listaViviendas != NULL && tamVivienda > 0 && proxId != NULL)
    {
        printf("\n-------------------- ALTA VIVIENDA --------------------\n");
        int indiceLibre = buscarEspacioLibre(listaViviendas, tamVivienda);
        if(indiceLibre >= 0)
        {
            eVivienda auxVivienda;

            auxVivienda.id = *proxId;
            (*proxId)++;

            pedirCadena(auxVivienda.calle, "\nIngrese el nombre de la calle (solo letras): ", "\nLa calle ingresada no es valida. Reingrese (solo letras): ", 50);
            pedirEntero(&auxVivienda.cantidadPersonas, "\nIngrese la cantidad de personas (1-10): ", "\nLa cantidad de personas no es valida. Reingrese (1-10): ", 1, 10);
            pedirEntero(&auxVivienda.cantidadHabitaciones, "\nIngrese la cantidad de habitaciones (1-8): ", "\nLa cantidad de habitaciones no es valida. Reingrese (1-8): ", 1, 8);
            pedirEntero(&auxVivienda.tipoVivienda, "\nIngrese el tipo de vivienda...\n\n1. Casa\n2. Departamento\n3. Casilla\n4. Rancho\n\nOpcion: ", "\nEl tipo de vivienda elegido no es valida. Reingrese el tipo de vivienda...\n\n1. Casa\n2. Departamento\n3. Casilla\n4. Rancho\n\nOpcion: ", 1, 4);

            mostrarListaCensistas(listaCensistas, tamCensistas);
            pedirEntero(&auxVivienda.legajoCensista, "\n\nIngrese legajo del censista: ", "\nEl legajo no existe. Reingrese: ", 100, 102);

            auxVivienda.isEmpty = 0;
            listaViviendas[indiceLibre] = auxVivienda;

            todoOk = 1;
        }
        else
        {
            todoOk = 2;
        }
    }
    return todoOk;
}

static void mostrarTituloVivienda()
{
    printf("\n------------------------------------------------------------------------------------------------");
    printf("\n Id    | Calle      | Cant. personas | Cant. habitaciones | Tipo de vivienda | Legajo censista |");
    printf("\n------------------------------------------------------------------------------------------------");

}

static void mostrarUnaVivienda(eVivienda vivienda)
{
    printf("\n %-7d %-12s %-16d %-20d %-18d %d", vivienda.id, vivienda.calle, vivienda.cantidadPersonas, vivienda.cantidadHabitaciones, vivienda.tipoVivienda, vivienda.legajoCensista);
}

int mostrarListaViviendas(eVivienda* lista, int tam)
{
    int todoOk = 0;
    if(lista != NULL && tam > 0)
    {
        mostrarTituloVivienda();
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].isEmpty == 0)
            {
                mostrarUnaVivienda(lista[i]);
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int buscarViviendaPorId(eVivienda* lista, int tam, int id)
{
    int indice = -1;
    if(lista != NULL && tam > 0)
    {
        for(int i = 0; i < tam; i++)
        {
            if(lista[i].id == id)
            {
                indice = i;
                break;
            }
        }
    }
    return indice;
}

int modificarVivienda(eVivienda* listaViviendas, int tamViviendas, eCensista* listaCensistas, int tamCensistas)
{
    int todoOk = 0;
    int id;

    char auxCalle[25];
    int auxCantidadPersonas;
    int auxCantidadHabitaciones;
    int auxTipoVivienda;
    int auxLegajoCensista;

    if(listaViviendas != NULL && tamCensistas > 0 && listaCensistas != NULL && tamCensistas > 0)
    {
        printf("\n---------- MODIFICAR VIVIENDA -----------");
        mostrarListaViviendas(listaViviendas, tamViviendas);
        do
        {
            pedirId(&id, "\n\nIngrese un Id (20.000+): ", "\nEl Id no es valido. Reingrese (20.000+): ", 20000);
            int indice = buscarViviendaPorId(listaViviendas, tamViviendas, id);
            if(indice == -1)
            {
                todoOk = 2;
            }
            else
            {
                mostrarTituloVivienda();
                mostrarUnaVivienda(listaViviendas[indice]);
                char caracter;
                pedirCaracter(&caracter, "\nEsta vivienda se modificara. ¿Estas seguro? (s = si | n = no): ", "La respuesta no es valida. Reingrese (s = si | n = no): ", 's', 'n');
                if(caracter == 's')
                {
                    int opcion = menuModificacion();
                    switch(opcion)
                    {
                        case 1:
                            pedirCadena(auxCalle, "\nIngrese el nombre de la nueva calle (solo letras): ", "\nLa calle ingresada no es valida. Reingrese (solo letras): ", 50);
                            strcpy(listaViviendas[indice].calle, auxCalle);
                            break;
                        case 2:
                            pedirEntero(&auxCantidadPersonas, "\nIngrese la nueva cantidad de personas (1-10): ", "\nLa cantidad de personas no es valida. Reingrese (1-10): ", 1, 10);
                            listaViviendas[indice].cantidadPersonas = auxCantidadPersonas;
                            break;
                        case 3:
                            pedirEntero(&auxCantidadHabitaciones, "\nIngrese la nueva cantidad de habitaciones (1-8): ", "\nLa cantidad de habitaciones no es valida. Reingrese (1-8): ", 1, 8);
                            listaViviendas[indice].cantidadHabitaciones = auxCantidadHabitaciones;
                            break;
                        case 4:
                            pedirEntero(&auxTipoVivienda, "\nIngrese el tipo de vivienda...\n\n1. Casa\n2. Departamento\n3. Casilla\n4. Rancho\n\nOpcion: ", "\nEl tipo de vivienda elegido no es valida. Reingrese el tipo de vivienda...\n\n1. Casa\n2. Departamento\n3. Casilla\n4. Rancho\n\nOpcion: ", 1, 4);
                            listaViviendas[indice].tipoVivienda = auxTipoVivienda;
                            break;
                        case 5:
                            mostrarListaCensistas(listaCensistas, tamCensistas);
                            pedirEntero(&auxLegajoCensista, "\n\nIngrese legajo del nuevo censista: ", "\nEl legajo no existe. Reingrese: ", 100, 102);
                            listaViviendas[indice].legajoCensista = auxLegajoCensista;
                            break;
                        case 6:
                            break;
                    }
                    todoOk = 1;
                }
                else
                {
                    todoOk = 3;
                }
            }
        }while(todoOk == 2);
    }
    return todoOk;
}

int bajaVivienda(eVivienda* lista, int tam)
{
    int todoOk = 0;
    int id;
    char caracter;
    if(lista != NULL && tam > 0)
    {
        printf("\n---------- BAJA VIVIENDA -----------");

        do
        {
            mostrarListaViviendas(lista, tam);
            pedirId(&id, "\n\nIngrese un Id (20.000+): ", "\nEl Id no es valido. Reingrese (20.000+): ", 20000);
            int indice = buscarViviendaPorId(lista, tam, id);

            if(indice == -1)
            {
                todoOk = 2;
            }
            else
            {
                mostrarTituloVivienda();
                mostrarUnaVivienda(lista[indice]);
                pedirCaracter(&caracter, "\nEsta vivienda se eliminara. ¿Estas seguro? (s = si | n = no): ", "La respuesta no es valida. Reingrese (s = si | n = no): ", 's', 'n');
                if(caracter == 's')
                {
                    lista[indice].isEmpty = 1;
                    todoOk = 1;
                }
                else
                {
                    todoOk = 3;
                }
            }
        }while(todoOk == 2);
    }
    return todoOk;
}
