#include "la_sombra_de_mac.h"
#include "ascii_art.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// Constantes utilizadas para dar formato al texto impreso por pantalla
#define ROJO "\x1b[31m"
#define VERDE "\x1b[32;1m"
#define AMARILLO "\x1b[33m"
#define AZUL "\x1b[34;1m"
#define MAGENTA "\x1b[35m"
#define GRIS "\x1b[90m"
#define NORMAL "\x1b[0m"
#define FLECHA_DERECHA "→"
#define FLECHA_IZQUIERDA "←"
#define DIAMANTE "♦"
#define LLAVE "\u26BF"
#define CORAZON "\u2764"
#define INTERRUPTOR "\u29BF"
#define INDICADOR "\u2BD0"
#define ESTRELLA "\u2605"
#define MAX_BORDES 105

void calcular_coordenada_inicio_sombra(coordenada_t* ref_arranque_sombra, coordenada_t arranque_personaje) {
    ref_arranque_sombra->fila = arranque_personaje.fila;
    ref_arranque_sombra->col = MAX_COLUMNAS - (arranque_personaje.col + 1);
}

void inicializar_jugadores(personaje_t* ref_mac, sombra_t* ref_blue) {
    coordenada_t arranque_personaje;
    arranque_personaje = coordenada_aleatoria(MAX_COLUMNAS, MAX_FILAS);  

    inicializar_personaje(ref_mac, arranque_personaje);

    coordenada_t arranque_sombra;
    calcular_coordenada_inicio_sombra(&arranque_sombra, arranque_personaje);
    inicializar_sombra(ref_blue, arranque_sombra);
}

void imprimir_borde_titulos() {
    for (int k = 0; k < MAX_BORDES; k++) {
        printf(NORMAL "=");
    }
    printf("\n");    
}

void imprimir_banner_juego() {
    imprimir_borde_titulos();
    printf("%s", BANNER);
    imprimir_borde_titulos();
}

void imprimir_titulo_status() {
    imprimir_borde_titulos();
    printf(STATUS);
    imprimir_borde_titulos();
}

void imprimir_titulo_terreno(){
    imprimir_borde_titulos();
    printf(TITULO_TABLERO);
    imprimir_borde_titulos();
}

void saludo_blue() {
    printf("%s", DIBUJOS_SALUDO);
}

void imprimir_personaje(personaje_t personaje) {
    printf(VERDE FLECHA_DERECHA " " FLECHA_DERECHA " " FLECHA_DERECHA);
    printf(" M A C ");
    printf(FLECHA_IZQUIERDA " " FLECHA_IZQUIERDA " " FLECHA_IZQUIERDA"\n");
    printf("=================\n" NORMAL);
    printf(VERDE DIAMANTE NORMAL " Posición: " VERDE INDICADOR NORMAL " Fila: %.2i, Columna: %.2i\n",
    personaje.posicion.fila + 1, personaje.posicion.col + 1);
    printf(VERDE DIAMANTE NORMAL " Vidas:" ROJO);
    for (int i = 0; i < personaje.vida ; i++) {
       printf(CORAZON);
    }
    printf("\n");
    printf(VERDE DIAMANTE NORMAL " Puntos: %i\n", personaje.puntos);
    printf(VERDE DIAMANTE NORMAL " Llave: %s" LLAVE "\n", 
    personaje.tiene_llave? AMARILLO : GRIS);
    printf(VERDE DIAMANTE NORMAL " Interruptor: %s" INTERRUPTOR "\n", 
    personaje.interruptor_apretado? MAGENTA : GRIS);
    printf("\n");
}

void imprimir_sombra(sombra_t sombra) {
    printf(AZUL FLECHA_DERECHA " " FLECHA_DERECHA " " FLECHA_DERECHA);
    printf(" B L U E ");
    printf(FLECHA_IZQUIERDA " " FLECHA_IZQUIERDA " " FLECHA_IZQUIERDA "\n");
    printf("===================\n" NORMAL);
    printf(AZUL DIAMANTE NORMAL " Posición: " AZUL INDICADOR NORMAL " Fila: %.2i, Columna: %.2i\n",
    sombra.posicion.fila + 1, sombra.posicion.col + 1);
    printf(AZUL DIAMANTE NORMAL " Vida: %s" ESTRELLA NORMAL "\n", 
    sombra.esta_viva? AMARILLO : GRIS);
    printf(NORMAL "\n");
}

void imprimir_status_personajes(personaje_t personaje, sombra_t sombra) {
    imprimir_titulo_status();
    imprimir_personaje(personaje);
    imprimir_sombra(sombra);
}


int main() {

    srand ((unsigned)time(NULL));

    personaje_t mac;
    sombra_t blue;
    inicializar_jugadores(&mac, &blue);    

    system("clear");
    imprimir_banner_juego();
    imprimir_status_personajes(mac, blue);
    saludo_blue();
    getchar(); 

    juego_t juego;
    juego.personaje = mac;
    juego.sombra = blue;
    char jugada = 0;
        
    for (int i = 0; i < 5; i++) {  // no tengo la condición de corte, así que solo pide 5 movimientos y finaliza 
        system("clear");
        imprimir_status_personajes(juego.personaje, juego.sombra);
        imprimir_titulo_terreno();   
        imprimir_terreno(juego);
        pedir_movimiento(&jugada);
        mover_personaje(&juego.personaje, &juego.sombra, jugada);
    }
    
    // CREO que Manuel había pedido en clase (o eso fue lo que entendí) que estuvieran probadas de alguna forma estas que no se usaron
    //Lo dejé comentado porque en sí no forman parte del juego. Lo dejé parecido a como está en CHANUTRON2021(PP). 

    /*
    printf("PRUEBAS DEL BOOL coordenadas_iguales:\n");   
    coordenada_t primera_coordenada = {.fila = 0, .col = 0};
    coordenada_t segunda_coordenada = {.fila = 0, .col = 0};
    bool resultado_comparacion1 = coordenadas_iguales(primera_coordenada, segunda_coordenada);
    printf(DIAMANTE " Si comparo 2 coordenadas iguales, el resultado %s devuelve true\n" NORMAL, 
    (resultado_comparacion1 == true)? VERDE "SÍ" : ROJO "NO");    // resultado esperado true
    
    coordenada_t tercera_coordenada = {.fila = 0, .col = 0};
    coordenada_t cuarta_coordenada = {.fila = 1, .col = 1};
    bool resultado_comparacion2 = coordenadas_iguales(tercera_coordenada, cuarta_coordenada);
    printf(DIAMANTE " Si comparo 2 coordenadas distintas, el resultado %s devuelve false\n\n" NORMAL, 
    (resultado_comparacion2 == false)? VERDE "SÍ" : ROJO "NO");    // resultado esperado false


    printf("PRUEBAS DE LA FUNCIÓN buscar_elemento:\n");
    elemento_t elementos[MAX_ELEMENTOS];
    int tope = 0;
    for (int i = 0; i < 10; i++) {
        elementos[i].posicion.fila = i;
        elementos[i].posicion.col = i + 1;
        tope++; 
    }
    // prueba para buscar una coordenada que está en el vector
    coordenada_t posicion1 = {.fila = 5, .col = 6};
    int ubicacion1 = buscar_elemento(elementos, tope, posicion1);
    int ubicacion_pos1 = 5;    // resultado esperado de la función
    printf(DIAMANTE " Al buscar una coordenada ubicada en la 5ta posición, la función %s devuelve la 5ta posición\n" NORMAL,
    (ubicacion1 == ubicacion_pos1)? VERDE "SÍ" : ROJO "NO");    

    // prueba para buscar una coordenada que NO está en el vector
    coordenada_t posicion2 = {.fila = 20, .col = 20};
    int ubicacion2 = buscar_elemento(elementos, tope, posicion2);
    int ubicacion_pos2 = -1; 
    printf(DIAMANTE " Al buscar una coordenada que no está en el vector, la función %s devuelve -1\n" NORMAL,
    (ubicacion2 == ubicacion_pos2)? VERDE "SÍ" : ROJO "NO");

    // prueba para buscar una coordenada que está repetida en el vector
    elementos[4].posicion.fila = 5;
    elementos[4].posicion.col = 6;
    coordenada_t posicion3 = {.fila = 5, .col = 6};
    int ubicacion3 = buscar_elemento(elementos, tope, posicion3);
    int ubicacion_pos3 = 4;
    printf(DIAMANTE " Al buscar una coordenada repetida en la 4ta y 5ta posición, la función %s devuelve la primera posición encontrada (la 4ta)\n\n" NORMAL,
    (ubicacion3 == ubicacion_pos3)? VERDE "SÍ" : ROJO "NO");  // esta opción no la había probado en la primera entrega
    */      

    return 0;
}
