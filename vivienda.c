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

int ordenarViviendas(eVivienda* lista, int tam, int order)
{
    int todoOk = 0;
    eVivienda auxVivienda;

    if(lista != NULL && tam > 0)
    {
		for(int i = 0; i < tam - 1; i++)
		{
			for(int j = i + 1; j < tam; j++)
			{
				if(order == 1) //ascendente
				{
					if((strcmp(lista[i].calle, lista[j].calle) > 0) || ((strcmp(lista[i].calle, lista[j].calle) == 0) && lista[i].cantidadPersonas > lista[j].cantidadPersonas))
					{
						auxVivienda = lista[i];
						lista[i] = lista[j];
						lista[j] = auxVivienda;
					}
				}
				else
				{
					if(order == 2) //descendente
					{
						if((strcmp(lista[i].calle, lista[j].calle) < 0) || ((strcmp(lista[i].calle, lista[j].calle) == 0) && lista[i].cantidadPersonas < lista[j].cantidadPersonas))
						{
							auxVivienda = lista[i];
							lista[i] = lista[j];
							lista[j] = auxVivienda;
						}
					}
				}
			}
		}
	   todoOk = 1;
    }

    return todoOk;
}

int hacerListado(eVivienda* lista, int tam)
{
	int todoOk = 0;
	int opcion;
	if(lista != NULL && tam > 0)
	{
        pedirEntero(&opcion, "\n¿En qué órden quiere la lista?\n   1. Ascendente\n   2. Decendente\n   3. Atras.\nIngrese opcion: ", "\nLa opcion no es valida. Reingrese: ", 1, 3);
        if(opcion == 1)
        {
            ordenarViviendas(lista, tam, opcion);
            mostrarListaViviendas(lista, tam);
            todoOk = 1;
        }
        else if(opcion == 2)
        {
            ordenarViviendas(lista, tam, opcion);
            mostrarListaViviendas(lista, tam);
            todoOk = 1;
        }
        todoOk = 2;
    }
    return todoOk;
}

int censosPorCensista(eVivienda* listaViviendas, int tamViviendas, eCensista* listaCensistas, int tamCensistas)
{
    int todoOk = 0;
    if(listaViviendas != NULL && tamViviendas > 0 && listaCensistas != NULL && tamCensistas > 0)
    {
        for(int i = 0; i < tamCensistas; i++)
        {
            mostrarTituloCensista();
            mostrarUnCensista(listaCensistas[i]);
            printf("\n");
            mostrarTituloVivienda();
            for(int j = 0; j < tamViviendas; j++)
            {
                if(listaCensistas[i].legajo == listaViviendas[j].legajoCensista)
                {
                    mostrarUnaVivienda(listaViviendas[j]);
                }
            }
            printf("\n\n");
        }
        todoOk = 1;
    }
    return todoOk;
}

int obtenerCensistaConMasCensos(eVivienda* listaViviendas, int tamViviendas, eCensista* listaCensistas, int tamCensistas)
{
    int todoOk = 0;
    int contAna = 0;
    int contJuan = 0;
    int contSol = 0;
    int legajo;

    if(listaViviendas != NULL && tamViviendas > 0 && listaCensistas != NULL && tamCensistas > 0)
    {
        for(int i = 0; i < tamViviendas; i++)
        {
            if(listaViviendas[i].legajoCensista == listaCensistas[0].legajo)
            {
                contAna++;
            }
            else if(listaViviendas[i].legajoCensista == listaCensistas[1].legajo)
            {
                contJuan++;
            }
            else if(listaViviendas[i].legajoCensista == listaCensistas[2].legajo)
            {
                contSol++;
            }
        }

        if(contAna > contJuan && contAna > contSol)
        {
            legajo = listaCensistas[0].legajo;
        }
        else if(contJuan > contSol)
        {
            legajo = listaCensistas[1].legajo;
        }
        else
        {
            legajo = listaCensistas[2].legajo;
        }
        todoOk = 1;
    }
    return legajo;
}

void mostrarCensistaConMasCensos(eVivienda* listaViviendas, int tamViviendas, eCensista* listaCensistas, int tamCensistas)
{
    int legajo = obtenerCensistaConMasCensos(listaViviendas, tamViviendas, listaCensistas, tamCensistas);

    for(int i = 0; i < tamCensistas; i++)
    {
        if(listaCensistas[i].legajo == legajo)
        {
            printf("\nEl censista con mas censos realizados es: %s", listaCensistas[i].nombre);
            break;
        }
    }
}
