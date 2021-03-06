/*
 * utn.c
 *
 *  Created on: 20 may. 2022
 *      Author: Usuario
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define ELEMENTS 25

/**
 *
 * \brief transforma los caracteres obtenidos a numeros enteros
	\param pResultado Puntero al espacio de memoria donde se dejara el resultado de la funcion
	\return Retorna 0 (EXITO) si se obtiene un numero entero y -1 (ERROR) si no
 */
static int getInt(int* pResultado);

/**
 *\brief verifica que se ingresen numeros
 * @param cadena Puntero al espacio de memoria donde se verifica lo ingresado
 * @return retorna 0 si se ejecuto correctamente
 */

static int esNumerica(char* cadena);





int utn_getNumero(int* pResultado,char* mensaje, int minimo, int maximo)
{
	int retorno=-1;
	int bufferInt;

		if(pResultado != NULL && mensaje != NULL && minimo <= maximo)
		{
			printf("%s", mensaje);

			if(getInt(&bufferInt) == 0 && bufferInt >= minimo && bufferInt <= maximo)
			{
				*pResultado = bufferInt;
				retorno = 0;
			}
		}
		return retorno;
}

int utn_getNumeroEntero(int* pResultado, char* mensaje, char* mensajeError,int minimo,int reintentos){
	int retorno = -1;

	int buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL){
		do{
			printf("%s",mensaje);
			if(getInt(&buffer)==0 && (buffer >= minimo)){
				*pResultado = buffer;
				retorno=0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

int myGets(char* cadena, int longitud)
{
	int retorno=-1;
	char bufferString[4096];
	if(cadena != NULL && longitud>0)
	{
	    fflush(stdin);
	    if(fgets(bufferString,sizeof(bufferString),stdin) != NULL)
	    {
	        if(bufferString[strnlen(bufferString,sizeof(bufferString))-1] == '\n'){
	             bufferString[strnlen(bufferString,sizeof(bufferString))-1]='\0';
			}
	        if(strnlen(bufferString,sizeof(bufferString))<=longitud){
			   strncpy(cadena, bufferString, longitud);
			   retorno=0;
			}
	    }
	}
	return retorno;
}

int utn_getNumeroEnteroConMaximo(int* pResultado, char* mensaje, char* mensajeError,int minimo, int maximo ,int reintentos){
	int retorno = -1;

	int buffer;
	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo){
		do{
			printf("%s",mensaje);
			if(getInt(&buffer)==0 && (buffer >= minimo && buffer <= maximo)){
				*pResultado = buffer;
				retorno=0;
				break;
			}
			printf("%s", mensajeError);
			reintentos--;
		}while(reintentos>=0);
	}
	return retorno;
}

static int esNumerica(char* cadena)
{
	int retorno = 1;
	int i=0;

	if(cadena[0]=='-')
	{
		i=1;
	}

	for(; cadena[i] != '\0';i++)
	{

		if(cadena[i] > '9' || cadena[i] < '0')
		{
			retorno = 0;
			break;
		}
	}

	return retorno;
}

static int getInt(int* pResultado)
{
	int retorno = -1;
	char buffer[4096];

	if(myGets(buffer,sizeof(buffer))==0 && esNumerica(buffer)) //verifica si son numeros
	{
		retorno = 0;
		*pResultado = atoi(buffer); //los transforma
	}

	return retorno;
}
