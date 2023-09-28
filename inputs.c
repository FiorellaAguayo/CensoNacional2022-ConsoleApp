#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "inputs.h"

static void imprimirMensaje(char mensaje[]);
static void pedirDato(char cadena[]);
static int ValidarSoloLetras(char cadena[]);
static int ordenarCadena(char cadena[]);

/**
 * @brief Imprime un mensaje en la consola.
 * Esta función imprime el mensaje proporcionado en la consola si no es NULL.
 * @param mensaje El mensaje que se imprimirá.
 */
static void imprimirMensaje(char mensaje[])
{
    if(mensaje != NULL)
    {
        printf(mensaje);
    }
}

/**
 * @brief Lee una cadena de caracteres desde la consola.
 * Esta función lee una cadena de caracteres desde la consola y la almacena en el búfer proporcionado.
 * @param cadena El búfer donde se almacenará la cadena de entrada.
 */
static void pedirDato(char cadena[])
{
    if(cadena != NULL)
    {
        char buffer[256];
        fflush(stdin);
        fgets(buffer, sizeof(buffer), stdin);
        buffer[strlen(buffer) - 1] = '\0';
        strcpy(cadena, buffer);
    }
}

/**
 * @brief Valida si una cadena representa un número entero.
 * Esta función verifica si la cadena proporcionada se puede convertir en un número entero.
 * @param enteroAValidar La cadena que se va a validar.
 * @return Devuelve 1 si la cadena es un número entero válido, 0 en caso contrario.
 */
int validarEntero(char enteroAValidar[])
{
    int todoOk = 1;
    if(strlen(enteroAValidar) > 0)
    {
        for(int i = 0; i < strlen(enteroAValidar); i++)
        {
            if(isdigit(enteroAValidar[i]) == 0)
            {
                if(i == 0 && enteroAValidar[0] == '-')
                {
                    todoOk = 1;
                }
                else
                {
                    todoOk = 0;
                }
            }
        }
    }
    else
    {
        todoOk = 0;
    }
    return todoOk;
}

/**
 * @brief Solicita al usuario que ingrese un número entero dentro de un rango específico.
 * Esta función muestra un mensaje al usuario, solicita una entrada y valida si el valor ingresado es un número entero válido
 * dentro del rango especificado.
 * @param enteroValidado Puntero a la variable donde se almacenará el número entero validado.
 * @param mensaje El mensaje que se muestra como indicación.
 * @param mensajeError El mensaje de error que se muestra para una entrada no válida.
 * @param minimo El valor mínimo permitido para el entero.
 * @param maximo El valor máximo permitido para el entero.
 * @return Devuelve 1 si se ingresa un número entero válido dentro del rango, 0 en caso contrario.
 */
int pedirEntero(int* enteroValidado, char mensaje[], char mensajeError[], int minimo, int maximo)
{
    int todoOk = 0;
    if(enteroValidado != NULL && mensaje != NULL && mensajeError != NULL && minimo < maximo)
    {
        char auxEntero[150];
        imprimirMensaje(mensaje);
        pedirDato(auxEntero);

        while(validarEntero(auxEntero) == 0 || atoi(auxEntero) > maximo || atoi(auxEntero) < minimo)
        {
            imprimirMensaje(mensajeError);
            pedirDato(auxEntero);
        }

        *enteroValidado = atoi(auxEntero);
        todoOk = 1;
    }
    return todoOk;
}

static int ValidarSoloLetras(char cadena[])
{
	int soloHayLetras = 1;
	int i = 0;
	if (cadena != NULL)
	{
		while (cadena[i] != '\0')
		{
			if (cadena[i] != ' ' && (cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z'))
			{
				soloHayLetras = 0;
			}
			i++;
		}
	}
	return soloHayLetras;
}

static int ordenarCadena(char cadena[])
{
	int todoOk = 0;
	if (cadena != NULL)
	{
		strlwr(cadena);
		cadena[0] = toupper(cadena[0]);

		for (int i = 0; cadena[i] != '\0'; i++)
		{
			if (cadena[i] == ' ')
				cadena[i + 1] = toupper(cadena[i + 1]);
		}
		todoOk = 1;
	}
	return todoOk;
}

int pedirCadena(char* cadenaValidada, char mensaje[], char mensajeError[], int maximo)
{
    int todoOk = 0;
    if(cadenaValidada != NULL && mensaje != NULL && mensajeError != NULL && maximo > 0)
    {
        char auxCadena[256];
		imprimirMensaje(mensaje);
		pedirDato(auxCadena);

		while(strlen(auxCadena) > maximo || ValidarSoloLetras(auxCadena) == 0 || auxCadena[0] == 0)
        {
            imprimirMensaje(mensajeError);
		    pedirDato(auxCadena);
        }
        strcpy(cadenaValidada, auxCadena);
        ordenarCadena(cadenaValidada);

        todoOk = 1;
    }
    return todoOk;
}

int pedirId(int* enteroValidado, char mensaje[], char mensajeError[], int minimo)
{
    int todoOk = 0;
    if(enteroValidado != NULL && mensaje != NULL && mensajeError != NULL)
    {
        char auxEntero[150];
        imprimirMensaje(mensaje);
        pedirDato(auxEntero);

        while(validarEntero(auxEntero) == 0 || atoi(auxEntero) < minimo)
        {
            imprimirMensaje(mensajeError);
            pedirDato(auxEntero);
        }

        *enteroValidado = atoi(auxEntero);
        todoOk = 1;
    }
    return todoOk;
}

int pedirCaracter(char *charValidado, char mensaje[], char mensajeError[], char primerChar, char segundoChar)
{
	int todoOk = -1;
	char auxCaracter;

	if (mensaje != NULL && mensajeError != NULL)
	{
		imprimirMensaje(mensaje);
		fflush(stdin);
		scanf("%c", &auxCaracter);

		while (auxCaracter != primerChar && auxCaracter != segundoChar)
		{
			imprimirMensaje(mensajeError);
			fflush(stdin);
			scanf("%c", &auxCaracter);
		}

		*charValidado = auxCaracter;
		todoOk = 1;
	}
	return todoOk;
}
