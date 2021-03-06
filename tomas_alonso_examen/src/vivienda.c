/*
 * vivienda.c
 *
 *  Created on: 20 may. 2022
 *      Author: Usuario
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn.h"
#include "header.h"



void cargaForzadaViviendas(Vivienda* list, int limite){
	int i;
	for(i=0;i<limite;i++){
		list[i].isEmpty=-1;
	}
}
int cargaForzadaTipoVivienda(TipoVivienda* arrayTipoVivienda, int limite){

	int retorno=-1;

	if(arrayTipoVivienda!=NULL && limite>0){
		arrayTipoVivienda[0].id=1;
		strcpy(arrayTipoVivienda[0].descripcion,"CASA");

		arrayTipoVivienda[1].id=2;
		strcpy(arrayTipoVivienda[1].descripcion,"DEPARTAMENTO");

		arrayTipoVivienda[2].id=3;
		strcpy(arrayTipoVivienda[2].descripcion,"CASILLA");

		arrayTipoVivienda[3].id=1;
		strcpy(arrayTipoVivienda[3].descripcion,"RANCHO");

		retorno=0;
	}
	return retorno;
}

int altaVivienda(Vivienda* list, int limite){

	int retorno=-1;
	int i;
	int espacioDisponible=0;
	int j;
	int v;
	int flagCalle;
	int flagPrimerAlta=0;
	int validacionCantPersonas;
	int validacionCantHabitaciones;
	int validacionTipoVivienda;
	int validacionLegajo;

	if(list!=NULL && limite>0 && limite<=MAX ){

		for(i=0;i<limite;i++){
			if(list[i].isEmpty==-1){
				espacioDisponible=i;
				break;
			}
		}

		if(list[espacioDisponible].isEmpty==-1){

			do{
				printf("ingrese calle: ");
				myGets(list[espacioDisponible].calle, ELEMENTS);
				for(j=0; j<strlen(list[j].calle);j++){
						if(!(isalpha(list[j].calle[j]))){
							printf("error al ingresar la calle\n");
							flagCalle=0;
							break;
						}
						else{
							flagCalle=1;
						}
					}

			}while(flagCalle==0);

			if(flagPrimerAlta==0){
				v=0;
				list[v].idVivienda=20000;
				flagPrimerAlta=1;
				v++;
			}

			if(flagPrimerAlta==1){
				list[v].idVivienda=list[v-1].idVivienda+1;
				v++;
			}

			do{
				validacionCantPersonas=utn_getNumeroEntero(&list[espacioDisponible].cantidadPersonas,"ingrese cantidad de personas: ","error, ",1,2);
			}while(validacionCantPersonas!=0);

			do{
				validacionCantHabitaciones=utn_getNumeroEntero(&list[espacioDisponible].cantidadHabitaciones,"ingrese cantidad de habitaciones: ","error, ",1,2);
			}while(validacionCantHabitaciones!=0);

			do{
				validacionTipoVivienda=utn_getNumeroEnteroConMaximo(&list[espacioDisponible].tipoVivienda,"ingrese tipo de vivienda 1.CASA ? 2.DEPARTAMENTO ? 3.CASILLA - 4.RANCHO: ","error, ",1, 4,2);
			}while(validacionTipoVivienda!=0);

			do{
				validacionLegajo=utn_getNumeroEnteroConMaximo(&list[espacioDisponible].legajoCensista,"ingrese legajo del censista: ","error, ",100,102,2);
			}while(validacionLegajo!=0);

			list[espacioDisponible].isEmpty=0;
		}
		else{
			printf("no hay mas espacio %d/%d\n",espacioDisponible,limite);
		}

		retorno=0;

	}
	return retorno;
}


int buscarViviendaporId(Vivienda* list, int len , int id){

	int retorno;
	int i;

	if(list!=NULL && len>0){
		for(i=0;i<len;i++){
			if(list[i].idVivienda==id && list[i].isEmpty==0){
				retorno = 0;
				break;
			}
			else {
				retorno=-1;
			}
		}
	}
	return retorno;
}

int modificarVivienda(Vivienda* list, int len, int id, int opcion){

	int retorno=-1;
	int i;
	int flagCalle;
	int validacionCantPersonas;
	int validacionCantHabitaciones;
	int validacionTipoVivienda;
	int validacionLegajo;

	if(list!=NULL && len>0){

		for(i=0;i<len;i++){
			if(list[i].idVivienda==id && list[i].isEmpty==0){
				switch(opcion){
				case 1:
					do{
						printf("ingrese calle: ");
						myGets(list[i].calle, ELEMENTS);
						for(i=0; i<strlen(list[i].calle);i++){
								if(!(isalpha(list[i].calle[i]))){
									printf("error al ingresar la calle\n");
									flagCalle=0;
									break;
								}
								else{
									flagCalle=1;
								}
							}

					}while(flagCalle==0);
					break;

				case 2:
					do{
						validacionCantPersonas=utn_getNumeroEntero(&list[i].cantidadPersonas,"ingrese cantidad de personas: ","error, ",1,2);
					}while(validacionCantPersonas!=0);
					break;

				case 3:
					do{
						validacionCantHabitaciones=utn_getNumeroEntero(&list[i].cantidadHabitaciones,"ingrese cantidad de habitaciones: ","error, ",1,2);
					}while(validacionCantHabitaciones!=0);
					break;

				case 4:
					do{
						validacionTipoVivienda=utn_getNumeroEnteroConMaximo(&list[i].tipoVivienda,"ingrese tipo de vivienda 1.CASA ? 2.DEPARTAMENTO ? 3.CASILLA - 4.RANCHO: ","error, ",1, 4,2);
					}while(validacionTipoVivienda!=0);
					break;

				case 5:
					do{
						validacionLegajo=utn_getNumeroEnteroConMaximo(&list[i].legajoCensista,"ingrese legajo del censista: ","error, ",100,102,2);
					}while(validacionLegajo!=0);
					break;
				}
				retorno = 0;
			}
		}
	}

	return retorno;
}

int bajaVivienda(Vivienda* list, int len , int id){

	int i;
	int retorno=-1;

	if(list!=NULL && len>0 && id>=20000){
		for(i=0;i<len;i++){
			if(list[i].idVivienda==id && list[i].isEmpty==0){
				list[i].isEmpty=-1;
				retorno = 0;
			}
		}
	}
	return retorno;
}

int ordenarViviendas(Vivienda* list, int limite){

	int retorno=-1;
	int k;
	int j;
	int flag=0;
	int i;
	int flagIgualdadCalle=0;
	char auxiliarCalle[limite][ELEMENTS];
	char bufferChar[limite][ELEMENTS];

	int auxiliarPersonas[limite];
	int bufferInt[limite];

	for(k=0;k<limite;k++){
		strcpy(auxiliarCalle[k]," ");
		auxiliarPersonas[k]=0;
	}

	if(list!=NULL && limite>0){
		for(k=0; k<limite; k++){
			if(list[k].isEmpty!=-1){
				flag=1;
				break;
			}
			if(flag==0){
				printf("no hay pasajeros cargados para ordenar");
				return -1;
			}
		}

		for(i=0;i<limite;i++){
			if(list[i].isEmpty!=-1){
				strcpy(auxiliarCalle[i],list[i].calle);
				auxiliarPersonas[i]=list[i].cantidadPersonas;
			}
		}

		if(flag==1){
			for(i=0; i<limite; i++){
				for(j=i+1; j<limite-1; j++){
					if(strcmp(auxiliarCalle[i],auxiliarCalle[j])!=0){
						if(strcmp(auxiliarCalle[i],auxiliarCalle[j])>0){

						strcpy(bufferChar[i],auxiliarCalle[i]);
						strcpy(auxiliarCalle[i],auxiliarCalle[j]);
						strcpy(auxiliarCalle[j],bufferChar[i]);

						bufferInt[i]=auxiliarPersonas[i];
						auxiliarPersonas[i]=auxiliarPersonas[j];
						auxiliarPersonas[j]=bufferInt[i];
						}
					}
					else if(strcmp(auxiliarCalle[i],auxiliarCalle[j])==0){
						flagIgualdadCalle=1;
						break;
						}
					}
				}
			}
		if(flagIgualdadCalle==0){
			printf("\nlista de viviendas ordenada por calle: \n");

			for(i=0;i<limite;i++){
				if(auxiliarPersonas[i]!=0){
					printf("Calle: %s / Cantidad de personas: %d\n",auxiliarCalle[i], auxiliarPersonas[i]);
				}
			}
			retorno=0;
		}

		else if(flagIgualdadCalle==1){
			for(i=0; i<limite; i++){
				for(j=i+1; j<limite-1; j++){
					if(auxiliarPersonas[i]>auxiliarPersonas[j]){
						bufferInt[i]=auxiliarPersonas[i];
						auxiliarPersonas[i]=auxiliarPersonas[j];
						auxiliarPersonas[j]=bufferInt[i];

						strcpy(bufferChar[i],auxiliarCalle[i]);
						strcpy(auxiliarCalle[i],auxiliarCalle[j]);
						strcpy(auxiliarCalle[j],bufferChar[i]);
					}
				}
			}
			printf("\nlista de calle por cantidad de personas: \n");

			for(i=0;i<limite;i++){
				if(auxiliarPersonas[i]!=0){
					printf("Cantidad de personas: %d / Calle: %s\n",auxiliarPersonas[i], auxiliarCalle[i]);
				}
			}
			retorno=0;
		}
	}
	return retorno;
}
