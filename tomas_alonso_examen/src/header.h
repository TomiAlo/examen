/*
 * header.h
 *
 *  Created on: 20 may. 2022
 *      Author: Usuario
 */

#ifndef HEADER_H_
#define HEADER_H_
#define ELEMENTS 25
#define MAX 10


typedef struct
{
	int idVivienda;
	char calle[ELEMENTS];
	int cantidadPersonas;
	int cantidadHabitaciones;
	int tipoVivienda;//id de TipoVivienda
	int legajoCensista;
	int isEmpty;
}Vivienda;

typedef struct
{
	int id;
	char descripcion[20];
}TipoVivienda;


typedef struct
{
	int legajoCensista;
	char nombre[ELEMENTS];
	int edad;
	char telefono[10];
}Censista;


void cargaForzadaViviendas(Vivienda* list, int limite);

int cargaForzadaCensistas(Censista* arrayCensistas, int limite);

int cargaForzadaTipoVivienda(TipoVivienda* arrayTipoVivienda, int limite);

int altaVivienda(Vivienda* list, int limite);

int modificarVivienda(Vivienda* list, int len , int id, int opcion);

int buscarViviendaporId(Vivienda* list, int len , int id);

int bajaVivienda(Vivienda* list, int len , int id);

void mostrarCensistas(Censista* list, int len);

int ordenarViviendas(Vivienda* list, int limite);

#endif /* HEADER_H_ */