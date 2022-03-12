#include "la_sombra_de_mac.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NORMAL "\x1b[0m"
#define VERDE "\x1b[32m"
#define AZUL "\x1b[34m"

// Constantes relacionadas al personaje de MAC
#define VIDAS_AL_INICIO 3
#define PUNTOS_AL_INICIO 0 
#define LLAVE_AL_INICIO false
#define MODO_INTERRUPTOR_AL_INICIO false
#define LETRA_MAC 'M'
#define ICONO_MAC "\u265C"

// Constantes relacionadas al personaje de BLUE
#define VIDA_SOMBRA_AL_INICIO true
#define LETRA_BLUE 'B'
#define ICONO_BLUE "\u265C"

// Constantes relacionadas al movimiendo de los personajes
#define MOVIMIENTO_ARRIBA 'W'
#define MOVIMIENTO_ABAJO 'S'
#define MOVIMIENTO_IZQUIERDA 'A'
#define MOVIMIENTO_DERECHA 'D'

// Constantes utilizadas para los elementos
#define LETRA_BANDERA 'P'
#define ICONO_BANDERA "\u2690" 

#define ESQUINA_SUP_DER "\u2513"
#define ESQUINA_SUP_IZQ "\u250F"
#define ESQUINA_INF_DER "\u251B"
#define ESQUINA_INF_IZQ "\u2517"
#define BORDE_SUP "\u2533"
#define BORDE_INF "\u253B"
#define BORDE_DER "\u252B"
#define BORDE_IZQ "\u2523"
#define CENTRO "\u254B"
#define HORIZONTAL "\u2501"
#define VERTICAL "\u2503"


/*  Precondiciones: no tiene. 
 *  Postcondiciones: devuelve true si las coordenadas a comparar son iguales y false si son distintas.
 */
bool coordenadas_iguales(coordenada_t a, coordenada_t b) {
    return a.fila == b.fila && a.col == b.col;
}

/*  Precondiciones: la coordenada de arranque_personaje debe encontrarse en el tablero dentro de los rangos de filas y columnas definidos.
 *  Postcondiciones: el personaje queda inicializado y con sus parámetros cargados, en un estado válido listo para empezar a jugar.
 */
void inicializar_personaje(personaje_t* ref_personaje, coordenada_t arranque_personaje) {
    ref_personaje->posicion = arranque_personaje;
    ref_personaje->vida = VIDAS_AL_INICIO;
    ref_personaje->puntos = PUNTOS_AL_INICIO;
    ref_personaje->tiene_llave = LLAVE_AL_INICIO;
    ref_personaje->interruptor_apretado = MODO_INTERRUPTOR_AL_INICIO;
}

/*  Precondiciones: la coordenada de arranque_personaje debe encontrarse en el tablero dentro de los rangos de filas y columnas definidos, y
 *  debe ser distinta de la del personaje principal. 
 *  Postcondiciones: la sombra queda inicializada y con sus parámetros cargados, en un estado válido listo para empezar a jugar.
 */
void inicializar_sombra(sombra_t* ref_sombra, coordenada_t arranque_sombra) {
    ref_sombra->posicion = arranque_sombra;
    ref_sombra->esta_viva = VIDA_SOMBRA_AL_INICIO;
}

/*  Precondiciones: no tiene.
 *  Postcondiciones: devuelve true si el movimiento se encuentra dentro de las 4 opciones válidas (W, A, D y S).
 */
bool es_movimiento_valido(char movimiento) {
    return movimiento == MOVIMIENTO_ARRIBA || movimiento == MOVIMIENTO_ABAJO ||  
           movimiento == MOVIMIENTO_IZQUIERDA || movimiento == MOVIMIENTO_DERECHA;         
}

/*  Precondiciones: no tiene.
 *  Postcondiciones: la variable queda cargada con un movimiento válido aportado por el usuario.
 */
void pedir_movimiento(char* ref_movimiento) {
    do {
        printf("Movimientos válidos: W = ARRIBA | S = ABAJO | A = IZQUIERDA | D = DERECHA\n");
        printf("Ingrese un movimiento válido:\n");
        scanf(" %c", ref_movimiento);
    } while (!es_movimiento_valido(*ref_movimiento));
}

/*  Precondiciones: la fila de la coordenada debe corresponder al alto y la columna al ancho.
 *  Postcondiciones: devuelve true si la coordenada se encuentra dentro de los rangos de filas y columnas válidos.
 */
bool esta_dentro_rango(coordenada_t posicion, int max_alto, int max_ancho) {  
   return (posicion.fila >= 0 && posicion.fila < max_alto) && 
          (posicion.col >= 0 && posicion.col < max_ancho);
}

/*  Precondiciones: no tiene.
 *  Postcondiciones: suma las 2 coordenadas.
 */
void suma_coordenadas(coordenada_t* ref_coordenada, coordenada_t desplazamiento) {
    ref_coordenada->fila += desplazamiento.fila;
    ref_coordenada->col += desplazamiento.col;
}

/*  Precondiciones: la posición debe encontrarse dentro del tablero y el desplazamiento debe ser de una sola coordenada y de
 *  un solo casillero a la vez (ya sea fila o columna).
 *  Postcondiciones: desplaza la coordenada, si se mantiene dentro de los rangos de filas y columnas válidos.
 */
void mover_casillero(coordenada_t* ref_posicion, coordenada_t desplazamiento) {
    coordenada_t coordenada_aux;
    coordenada_aux = *ref_posicion;
    suma_coordenadas(&coordenada_aux, desplazamiento);
    if (esta_dentro_rango(coordenada_aux, MAX_COLUMNAS, MAX_FILAS)) {
        *ref_posicion = coordenada_aux;
    }
}

/*  Precondiciones: las coordenadas donde se ubican los personajes deben encontrarse dentro del tablero y el movimiento debe estar
 *  entre 4 opciones (W, A, S y D).
 *  Postcondiciones: modifica las nuevas posiciones de los personajes luego de realizar el movimiento correspondiente para cada uno. 
 */
void mover_personaje(personaje_t* ref_personaje, sombra_t* ref_sombra, char movimiento) {
    coordenada_t desplazamiento;
    if (movimiento == MOVIMIENTO_ARRIBA) {
        desplazamiento.col = 0;
        desplazamiento.fila = -1;
        mover_casillero(&(ref_personaje->posicion), desplazamiento);  
        mover_casillero(&(ref_sombra->posicion), desplazamiento);
    } else if (movimiento == MOVIMIENTO_ABAJO) {
        desplazamiento.col = 0;
        desplazamiento.fila = 1;
        mover_casillero(&(ref_personaje->posicion), desplazamiento);
        mover_casillero(&(ref_sombra->posicion), desplazamiento);
    } else if (movimiento == MOVIMIENTO_IZQUIERDA) {
        desplazamiento.col = -1;
        desplazamiento.fila = 0;
        mover_casillero(&(ref_personaje->posicion), desplazamiento);
        desplazamiento.col = 1;
        mover_casillero(&(ref_sombra->posicion), desplazamiento);
    } else {
        desplazamiento.col = 1;
        desplazamiento.fila = 0;
        mover_casillero(&(ref_personaje->posicion), desplazamiento);
        desplazamiento.col = -1;
        mover_casillero(&(ref_sombra->posicion), desplazamiento);
    }
}

/*  Precondiciones: se debe invocar a srand previamente. 
 *  Postcondiciones: devuelve una coordenada aleatoria dentro de los rangos de filas y columnas válidos.
 */
coordenada_t coordenada_aleatoria(int max_alto, int max_ancho) {
    coordenada_t coordenada_generada;
    coordenada_generada.col = rand() % max_ancho;
    coordenada_generada.fila = rand() % max_alto;
    return coordenada_generada;
}

/*  Precondiciones: el tope debe ser menor o igual a la cantidad máxima de elementos y debe coincidir con la cantidad de 
 +  elementos cargados en el vector. 
 *  Postcondiciones: devuelve la primera ubicación encontrada de la coordenada buscada y en caso de no hallarla devuelve -1.
 */
int buscar_elemento(elemento_t elementos[MAX_ELEMENTOS], int tope, coordenada_t posicion) {
    int ubicacion = -1;
    bool encontrado = false;
    for (int i = 0; i < tope; i++) {
       if (!encontrado && coodenadas_iguales(elementos[i].posicion, posicion)) { 
           ubicacion = i;
           encontrado = true;
       }
    }
    return ubicacion;
}

/*  Precondiciones: no tiene.
 *  Postcondiciones: crea la matriz del tablero con el ancho y el alto adecuados y la deja cargada con espacios.
 */
void cargar_matriz_tablero(char (*tablero)[MAX_COLUMNAS]) {
    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
                tablero[i][j] = ' ';
        }
    }
}

/*  Precondiciones: no tiene.
 *  Postcondiciones: imprime el tablero en pantalla con sus personajes en posición.
 */
void imprimir_tablero(char (*tablero)[MAX_COLUMNAS]) {
    printf("    ");

    // imprime la cabecera del tablero con los números de las columnas
    for (int j = 0; j < MAX_COLUMNAS; j++) {    
        printf("  %.2i ", j + 1);
    }
    printf("\n");    

    // imprime el extremo superior del tablero 
    for (int j = 0; j < MAX_COLUMNAS + 1; j++) {           
        if (j == 0) printf("    " ESQUINA_SUP_IZQ HORIZONTAL HORIZONTAL);
        else if (j == MAX_COLUMNAS) printf(HORIZONTAL HORIZONTAL ESQUINA_SUP_DER "\n");
        else printf(HORIZONTAL HORIZONTAL BORDE_SUP HORIZONTAL HORIZONTAL);
    }

    // imprime las filas de la tabla con sus líneas medias
    for (int i = 0; i < MAX_FILAS; i++) {

        // imprime los números de las filas del tablero   
        printf("%.2i  " VERTICAL, i + 1);

        //imprime las filas del tablero
        for (int j = 0; j < MAX_COLUMNAS; j++) {    
            if (tablero[i][j] == LETRA_MAC) printf(VERDE " %s  " NORMAL, ICONO_MAC);
            else if (tablero[i][j] == LETRA_BLUE) printf(AZUL " %s  " NORMAL, ICONO_BLUE);
            else if (tablero[i][j] == LETRA_BANDERA) printf(" %s  ", ICONO_BANDERA);
            else printf(" %c  ", tablero[i][j]);
            printf(VERTICAL);
        }

        // imprime las líneas medias horizontales del tablero, excepto el último           
        if (i < (MAX_FILAS - 1)){  
            printf("\n"); 
            for (int j = 0; j < MAX_COLUMNAS + 1; j++) {    
                if(j == 0) printf("    " BORDE_IZQ HORIZONTAL HORIZONTAL);
                else if (j == MAX_COLUMNAS) printf(HORIZONTAL HORIZONTAL BORDE_DER);
                else printf(HORIZONTAL HORIZONTAL CENTRO HORIZONTAL HORIZONTAL);
            }
        }
        printf("\n");            
    }

    // imprime el extremo inferior del tablero 
    for (int j = 0; j < MAX_COLUMNAS + 1; j++) {    
        if (j == 0) printf("    " ESQUINA_INF_IZQ HORIZONTAL HORIZONTAL);
        else if (j == MAX_COLUMNAS) printf(HORIZONTAL HORIZONTAL ESQUINA_INF_DER);
        else printf(HORIZONTAL HORIZONTAL BORDE_INF HORIZONTAL HORIZONTAL);
    }
}

/*  Precondiciones: los personajes se deben haber inicializado previamente.
 *  Postcondiciones: carga la matriz del tablero con sus espacios vacíos y los personajes y los imprime por pantalla.
 */
void imprimir_terreno(juego_t juego) {
    char tablero[MAX_FILAS][MAX_COLUMNAS];

    cargar_matriz_tablero(tablero);
    
    elemento_t bandera = {.posicion = {0,11}, .tipo = LETRA_BANDERA};  // le puse una banderita como elemento
    tablero[bandera.posicion.fila][bandera.posicion.col] = bandera.tipo;
    tablero[juego.personaje.posicion.fila][juego.personaje.posicion.col] = LETRA_MAC;
    tablero[juego.sombra.posicion.fila][juego.sombra.posicion.col] = LETRA_BLUE;
   
    imprimir_tablero(tablero);    
    printf("\n");
}