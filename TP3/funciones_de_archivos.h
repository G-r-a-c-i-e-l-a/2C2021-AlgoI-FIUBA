#ifndef _FUNCIONES_DE_ARCHIVOS_H_
#define _FUNCIONES_DE_ARCHIVOS_H_

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "la_sombra_de_mac.h"

#define ERROR -1  
#define MAX_NOMBRE 100


typedef struct partida {
    char jugador[MAX_NOMBRE];
    int nivel_llegado;
    int puntos;
    int vidas_restantes;
    bool gano;
} partida_t;


/*  
 *  Precondiciones: -
 *  Postcondiciones: imprime las partidas del archivo_partidas en el archivo_auxiliar y agrega ordenadamente una nueva a la lista, cuyos datos 
 *  son cargados por consola mediante el usuario. 
 */
void agregar_partida(FILE* archivo_partidas, FILE* archivo_auxiliar);


/*  
 *  Precondiciones: -
 *  Postcondiciones: imprime las partidas del archivo_partidas en el archivo_auxiliar, excepto la que corresponde al jugador a eliminar.
 */
void eliminar_partida(FILE* archivo_partidas, FILE* archivo_auxiliar, char jugador_a_eliminar[MAX_NOMBRE]);


/*  
 *  Precondiciones: -
 *  Postcondiciones: ordena e imprime las partidas del archivo_partidas en el archivo_auxiliar.
 */
void ordenar_partidas(FILE* archivo_partidas, FILE* archivo_auxiliar);


/*  
 *  Precondiciones: -
 *  Postcondiciones: carga las configuraciones del juego. En caso de no requerirse o no encontrarse 
 *  el archivo de configuraciones, se juega igual con las estandares.
 */
void cargar_configuraciones(bool configuraciones, parametros_t* parametros);


#endif
