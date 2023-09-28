#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
#include "vivienda.h"
#include "censista.h"

#define TAM_VIVIENDAS 100
#define TAM_CENSISTAS 3

int main()
{
    int seguir = 1;
    eVivienda listaViviendas[TAM_VIVIENDAS];
    eCensista listaCensistas[TAM_CENSISTAS] = { { 100, "Ana", 34, 12032345 }, { 101, "Juan", 24, 430154678 }, { 102, "Sol", 47, 590237487 } };

    int proxId = 20000;

    if(!inicializarViviendas(listaViviendas, TAM_VIVIENDAS))
    {
        printf("\nHubo un problema al inicializar las viviendas.");
    }

    while(seguir == 1)
    {
        switch(menu())
        {
            case 1:
                switch(altaVivienda(listaViviendas, TAM_VIVIENDAS, &proxId, listaCensistas, TAM_CENSISTAS))
                {
                    case 0:
                        printf("\n\nHubo un problema al hacer el alta.");
                        break;
                    case 1:
                        printf("\n\nAlta exitosa!");
                        break;
                    case 2:
                        printf("\n\nNo hay espacio para mas viviendas.");
                        break;
                }
                break;

            case 2:
                switch(modificarVivienda(listaViviendas, TAM_VIVIENDAS, listaCensistas, TAM_CENSISTAS))
                {
                    case 0:
                        printf("\n\nHubo un problema al hacer la modificacion.");
                        break;
                    case 1:
                        printf("\n\nModificacion exitosa!");
                        break;
                    case 2:
                        printf("\n\nNo existe vivienda con ese Id.");
                        break;
                    case 3:
                        printf("\n\nSe cancelo la modificacion.");
                        break;
                }
                break;

            case 3:
                switch(bajaVivienda(listaViviendas, TAM_VIVIENDAS))
                {
                    case 0:
                        printf("\n\nHubo un problema al hacer la baja.");
                        break;
                    case 1:
                        printf("\n\nBaja exitosa!");
                        break;
                    case 2:
                        printf("\n\nNo existe vivienda con ese Id.");
                        break;
                    case 3:
                        printf("\n\nSe cancelo la baja.");
                        break;
                }
                break;

            case 4:
                if(hacerListado(listaViviendas, TAM_VIVIENDAS))
                {
                    printf("\n\nListado de viviendas exitoso.");
                }
                else
                {
                    printf("\n\nHubo un problema al mostrar el listado de viviendas.");
                }
                break;

            case 5:
                if(mostrarListaCensistas(listaCensistas, TAM_CENSISTAS))
                {
                    printf("\n\nListado de censistas exitoso.");
                }
                else
                {
                    printf("\n\nHubo un problema al mostrar el listado de censistas.");
                }
                break;

            case 6:
                if(censosPorCensista(listaViviendas, TAM_VIVIENDAS ,listaCensistas, TAM_CENSISTAS))
                {
                    printf("\n\nListado censos por censista exitoso.");
                }
                else
                {
                    printf("\n\nHubo un problema al mostrar datos del censista.");
                }
                break;

            case 7:
                mostrarCensistaConMasCensos(listaViviendas, TAM_VIVIENDAS, listaCensistas, TAM_CENSISTAS);
                break;

            case 8:
                printf("\n\nGracias por utilizar este programa!");
                seguir = 0;
                break;
        }
    }
    return 0;
}
