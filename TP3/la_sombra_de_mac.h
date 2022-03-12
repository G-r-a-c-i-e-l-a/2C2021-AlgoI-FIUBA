#ifndef __LA_SOMBRA_DE_MAC__
#define __LA_SOMBRA_DE_MAC__

#include <stdbool.h>

#define MAX_FILAS 20
#define MAX_COLUMNAS 25
#define MAX_ELEMENTOS 500
#define MAX_PAREDES 200 
#define MAX_NIVELES 3
#define MAX_OBJETOS 4

typedef struct coordenada {
    int fila;
    int col;
}coordenada_t;

typedef struct personaje {
    coordenada_t posicion;
    int vida;
    int puntos;
    bool tiene_llave;
    bool interruptor_apretado;
}personaje_t;

typedef struct sombra {
    coordenada_t posicion;
    bool esta_viva;
}sombra_t;

typedef struct elemento {
    char tipo;
    coordenada_t coordenada;
}elemento_t;

typedef struct nivel {
    int numero_nivel;
    coordenada_t paredes[MAX_PAREDES];
    int tope_paredes;
    elemento_t obstaculos[MAX_ELEMENTOS];
    int tope_obstaculos;
    elemento_t herramientas[MAX_ELEMENTOS];
    int tope_herramientas;
}nivel_t;

typedef struct juego {
    personaje_t personaje;
    sombra_t sombra;
    nivel_t niveles[MAX_NIVELES];
    int nivel_actual;
}juego_t;

typedef struct objetos {
    char tipo;
    int cant_por_nivel[MAX_NIVELES]; 
} objetos_t; 


typedef struct parametros {
    objetos_t obstaculos[MAX_OBJETOS];
    objetos_t herramientas[MAX_OBJETOS];
} parametros_t;



/*  
 *  Precondiciones: la cantidad de cada elementos en total cargados en los parámetros, cuando no se juega en modalidad estandar, 
 *  tiene ser menor a la cantidad de casilleros del tablero y específicamente las escaleras en una cantidad menor a la cantidad de paredes. 
 *  Postcondiciones: permite jugar 1 partida en su totalidad. 
 */
void jugar_partida(parametros_t parametros);


#endif