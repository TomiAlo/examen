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

void mostrarCensistasConViviendas(Censista* listCensistas, int limiteCensistas, Vivienda* listViviendas, int limiteViviendas){

	int i;
	int k;

	if(listCensistas!=NULL && listViviendas!=NULL && limiteCensistas>0 && limiteViviendas>0){

		for(i=0;i<limiteCensistas;i++){

			printf("Legajo: %d ",listCensistas[i].legajoCensista);
			printf("Nombre: %s ",listCensistas[i].nombre);
			printf("Edad: %d ",listCensistas[i].edad);
			printf("Telefono: %s \n",listCensistas[i].telefono);

			if(listViviendas[i].legajoCensista==100){
				for(k=0;k<limiteViviendas;k++){
					if(listViviendas[k].isEmpty==0 && listViviendas[k].legajoCensista==100){
						printf("Id vivienda: %d \n", listViviendas[k].idVivienda);
						printf("Calle: %s \n", listViviendas[k].calle);
						printf("Cantidad de personas: %d \n", listViviendas[k].cantidadPersonas);
						printf("Cantidad de habitaciones: %d \n", listViviendas[k].cantidadHabitaciones);
					}
				}
			}
			else if(listViviendas[i].legajoCensista==101){
				for(k=0;k<limiteViviendas;k++){
					if(listViviendas[k].isEmpty==0 && listViviendas[k].legajoCensista==101){
						printf("Id vivienda: %d \n", listViviendas[k].idVivienda);
						printf("Calle: %s \n", listViviendas[k].calle);
						printf("Cantidad de personas: %d \n", listViviendas[k].cantidadPersonas);
						printf("Cantidad de habitaciones: %d \n", listViviendas[k].cantidadHabitaciones);
					}
				}
			}
			else if(listViviendas[i].legajoCensista==102){
				for(k=0;k<limiteViviendas;k++){
					if(listViviendas[k].isEmpty==0 && listViviendas[k].legajoCensista==102){
						printf("Id vivienda: %d \n", listViviendas[k].idVivienda);
						printf("Calle: %s \n", listViviendas[k].calle);
						printf("Cantidad de personas: %d \n", listViviendas[k].cantidadPersonas);
						printf("Cantidad de habitaciones: %d \n", listViviendas[k].cantidadHabitaciones);
					}
				}
			}
		}
	}
}

void mostrarCensistasConMasCensos(Censista* listCensistas, int limiteCensistas, Vivienda* listViviendas, int limiteViviendas){

	int i;
	int legajoAna=0;
	int legajoJuan=0;
	int legajoSol=0;
	int maximo=0;

	for(i=0;i<limiteViviendas;i++){
		switch(listViviendas[i].legajoCensista){
			case 100:
				legajoAna++;
				break;
			case 101:
				legajoJuan++;
				break;
			case 102:
				legajoSol++;
				break;
		}
	}
	maximo=legajoAna;
	if(maximo<legajoJuan){
		maximo=legajoJuan;
	}
	if(maximo<legajoSol){
		maximo=legajoSol;
	}

	if(maximo==legajoAna && maximo!=0){
		printf("Censista con mas censos: %s %d\n",listCensistas[0].nombre, maximo);
	}
	else if(maximo==legajoJuan && maximo!=0){
		printf("Censista con mas censos: %s %d\n",listCensistas[1].nombre, maximo);
	}
	else if(maximo==legajoSol && maximo!=0){
		printf("Censista con mas censos: %s %d\n",listCensistas[2].nombre, maximo);
	}
	else if(maximo==0){
		printf("No hay censos cargados");
	}
}
