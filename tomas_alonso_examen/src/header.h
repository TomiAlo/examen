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

/**
 * Hace una carga forzada del isEmpty a -1 para verificar que estan todos los espacios vacios
 * param array de viviendas
 * param limite del array
 */
void cargaForzadaViviendas(Vivienda* list, int limite);


/**
 * hace una carga forzada de los censistas
 * param array de los censistas
 * param limite del array
 * retorna 0 si todo salio ok
 */
int cargaForzadaCensistas(Censista* arrayCensistas, int limite);

/**
 * hace una carga forzada de los tipos de vivienda
 * param array de tipos de viviendas
 * param limite del array
 * retorna 0 si todo salio ok
 */
int cargaForzadaTipoVivienda(TipoVivienda* arrayTipoVivienda, int limite);

/**
 * agrega una vivienda al array de viviendas
 * param array de viviendas
 * param limite del array
 * retorna 0 si todo salio ok
 */
int altaVivienda(Vivienda* list, int limite);

/**
 * modifica una vivienda cargada anteriormente
 * param array de viviendas
 * param limte del array
 * param id de la vivienda a modificar
 * param opcion es que quiere modificar de la vivienda
 * retorna 0 si todo salio ok
 */
int modificarVivienda(Vivienda* list, int len , int id, int opcion);

/**
 * busca una vivienda por idVivienda
 * param array de viviendas
 * param limite del array
 * param id de la vivienda a buscar
 * retorna 0 si todo salio ok
 *  */
int buscarViviendaporId(Vivienda* list, int len , int id);

/**
 *hace una baja logica de vivienda hace
 *param array de viviendas
 *param limite del array
 *param id de la vivienda que quiere dar de baja
 *retorna 0 si todo salio ok
 */
int bajaVivienda(Vivienda* list, int len , int id);

/**
 * muestra todos los censistas cargados
 * param array de los censistas
 * param limite del array

 */
void mostrarCensistas(Censista* list, int len);

/**
 * ordena las viviendas por calle o ante igualdad de calle por numeros de personas
 * param array de viviendas
 * param limite del array
 * retorna 0 si todo salio ok
 */
int ordenarViviendas(Vivienda* list, int limite);

void mostrarCensistasConViviendas(Censista* listCensistas, int limiteCensistas, Vivienda* listViviendas, int limiteViviendas);

void mostrarCensistasConMasCensos(Censista* listCensistas, int limiteCensistas, Vivienda* listViviendas, int limiteViviendas);
#endif /* HEADER_H_ */
