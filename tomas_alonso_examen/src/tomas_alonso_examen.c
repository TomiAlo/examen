/*
 ============================================================================
 Name        : tomas_alonso_examen.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#include "header.h"
#include "utn.h"

#define CENSISTAS 3
#define TIPOS_VIVIENDA 4
#define MAX 10

int main(void) {
	setbuf(stdout, NULL);

	Censista arrayCensista[CENSISTAS];
	TipoVivienda arrayTipoVivienda[TIPOS_VIVIENDA];
	Vivienda arrayViviendas[MAX];

	int opcion;
	int opcionModificar;
	int id;
	int respuesta;
	int validacionCargaForzada;
	int validacionCargaTipoVivienda;
	int validacionAltaVivienda;
	int validacionBusca;
	int validacionModificar;
	int validacionBaja;
	int validacionListar;

	validacionCargaTipoVivienda=cargaForzadaTipoVivienda(arrayTipoVivienda, TIPOS_VIVIENDA);
	validacionCargaForzada=cargaForzadaCensistas(arrayCensista,CENSISTAS);
	cargaForzadaViviendas(arrayViviendas, MAX);

	if(validacionCargaTipoVivienda == 0 && validacionCargaForzada == 0){
		do{
			respuesta=utn_getNumero(&opcion, "1-Alta. \n2-Modificar. \n3-Baja. \n4-Listar viviendas. \n5-Listar censistas. \n6-Listado de datos. \n7-Censistas con mas censos realizados. \n8-Salir. \n",0,8);
			if(respuesta==0){
				switch(opcion){
					case 1:
						validacionAltaVivienda=altaVivienda(arrayViviendas, MAX);

						break;

					case 2:
						if(validacionAltaVivienda==0){
							utn_getNumero(&id,"Que id quiere modificar: ", 20000, 99999);
							validacionBusca=buscarViviendaporId(arrayViviendas, MAX, id);
							if(validacionBusca==0){
								utn_getNumero(&opcionModificar,"\n1-Calle. \n2-Cantidad de personas. \n3-Cantidad de habitaciones. \n4-Tipo de vivienda. \n5-Legajo de censista. \n", 0, 5);
								validacionModificar=modificarVivienda(arrayViviendas, MAX, id, opcionModificar);
							}
							if(validacionModificar==0){
								printf("Vivienda modificada correctamente\n");
							}
						}
						break;

					case 3:
						if(validacionAltaVivienda==0){
							utn_getNumero(&id,"Que id quiere dar de baja: ", 20000, 99999);
							validacionBusca=buscarViviendaporId(arrayViviendas, MAX, id);
							if(validacionBusca!=-1){
								validacionBaja=bajaVivienda(arrayViviendas, MAX, id);
							}
							if(validacionBaja==0){
								printf("Vivienda dada de baja correctamente\n");
							}
						}
						break;

					case 4:
						validacionListar=ordenarViviendas(arrayViviendas, MAX);
						break;

					case 5:
						mostrarCensistas(arrayCensista, CENSISTAS);
						break;

					case 6:
						mostrarCensistasConViviendas(arrayCensista, CENSISTAS, arrayViviendas, MAX);
						break;

					case 7:
						mostrarCensistasConMasCensos(arrayCensista, CENSISTAS, arrayViviendas, MAX);
						break;
				}
			}

		}while(opcion!=8);

	}

	return EXIT_SUCCESS;
}
