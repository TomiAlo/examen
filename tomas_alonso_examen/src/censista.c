/*
 * censista.c
 *
 *  Created on: 20 may. 2022
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "header.h"


int cargaForzadaCensistas(Censista* arrayCensistas, int limite){

	int retorno=-1;

	if(arrayCensistas!=NULL && limite>0){

		arrayCensistas[0].legajoCensista=100;
		strcpy(arrayCensistas[0].nombre,"Ana");
		arrayCensistas[0].edad=34;
		strcpy(arrayCensistas[0].telefono,"1203-23456");

		arrayCensistas[1].legajoCensista=101;
		strcpy(arrayCensistas[1].nombre,"Juan");
		arrayCensistas[1].edad=24;
		strcpy(arrayCensistas[1].telefono,"4301-54678");

		arrayCensistas[2].legajoCensista=102;
		strcpy(arrayCensistas[2].nombre,"Sol");
		arrayCensistas[2].edad=47;
		strcpy(arrayCensistas[2].telefono,"5902-37487");

		retorno=0;
	}

	return retorno;
}

void mostrarCensistas(Censista* list, int len){

	int i;

	for(i=0;i<len;i++){
		printf("Legajo: %d\n",list[i].legajoCensista);
		printf("Nombre: %s\n",list[i].nombre);
		printf("Edad: %d\n",list[i].edad);
		printf("Telefono: %s\n",list[i].telefono);
	}
}
