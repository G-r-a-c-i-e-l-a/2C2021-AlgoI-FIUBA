#include "la_sombra_de_mac.h"
#include "utiles.h"
#include "constantes_sombra_de_mac.h"
#include "ascii_art.h"
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


const objetos_t obstaculos[MAX_OBSTACULOS] = {
    {.tipo = LETRA_VELA, .cant_por_nivel = {VELAS_N1, VELAS_N2, VELAS_N3}},
    {.tipo = LETRA_POZO, .cant_por_nivel = {POZOS_N1, POZOS_N2, POZOS_N3}},
    {.tipo = LETRA_INTERRUPTOR, .cant_por_nivel = {INTERRUPTORES_N1, INTERRUPTORES_N2, INTERRUPTORES_N3}},
    {.tipo = LETRA_PORTAL, .cant_por_nivel = {PORTALES_N1, PORTALES_N2, PORTALES_N3}}
};


const objetos_t herramientas[MAX_HERRAMIENTAS] = {
    {.tipo = LETRA_PUERTA, .cant_por_nivel = {PUERTAS_N1, PUERTAS_N2, PUERTAS_N3}},
    {.tipo = LETRA_ESCALERA, .cant_por_nivel = {ESCALERAS_N1, ESCALERAS_N2, ESCALERAS_N3}},
    {.tipo = LETRA_MONEDA, .cant_por_nivel = {MONEDAS_N1, MONEDAS_N2, MONEDAS_N3}},
    {.tipo = LETRA_LLAVE, .cant_por_nivel = {LLAVES_N1, LLAVES_N2, LLAVES_N3}}
};





/*  
 *  Precondiciones: el entero proximidad tiene que ser positivo. 
 *  Postcondiciones: devuelve true si la coordenada a se encuentra dentro del area delimitado por la coordenada b y la proximidad asignada.
 */
bool coordenadas_cercanas(coordenada_t a, coordenada_t b, int proximidad) {
    return a.fila >= b.fila - proximidad && a.fila <= b.fila + proximidad  &&
           a.col >=  b.col - proximidad && a.col <=  b.col + proximidad;
}


/*  
 *  Precondiciones: el vector debe estar cargado junto con su tope y este debe ser menor al máximo.
 *  Postcondiciones: devuelve true si hay una pared asignada en esa coordenada.
 */
bool hay_pared(coordenada_t paredes[MAX_PAREDES], int tope, coordenada_t posicion) {
    bool encontrado = false;
    int i = 0;
    while (i < tope && !encontrado) {
       if (coordenadas_cercanas(paredes[i], posicion, 0)) { 
           encontrado = true;
       }
        i++;
    }
    return encontrado;
}


/*
 *  Precondiciones: el tope debe ser menor o igual a la cantidad máxima de elementos y debe coincidir con la cantidad de 
 *  elementos cargados en el vector. 
 *  Postcondiciones: devuelve la primera ubicación encontrada de la coordenada buscada y en caso de no hallarla devuelve -1.
 */
int buscar_elemento(elemento_t elementos[MAX_ELEMENTOS], int tope, coordenada_t posicion, bool buscando_area_vela) {
    
    int ubicacion = ELEMENTO_NO_ENCONTRADO;
    
    if(!tope)
        return ubicacion;
    
    bool encontrado = false;
    int i = 0;
    while (i < tope && !encontrado) {

        if (buscando_area_vela) {
            if(elementos[i].tipo == LETRA_VELA && coordenadas_cercanas(elementos[i].coordenada, posicion, 1)) {
                ubicacion = i;
                encontrado = true; 
            }
        } 
        
        else if (coordenadas_cercanas(elementos[i].coordenada, posicion, 0)) { 
           ubicacion = i;
           encontrado = true;
        }
        i++;
    }
    return ubicacion;
}


/*  
 *  Precondiciones: el vector elementos debe estar cargado y su tope debe ser menor al máximo de elementos.
 *  Postcondiciones: borra un elemento del vector y disminuye el tope.
*/
void borrar_elemento(elemento_t elementos[MAX_ELEMENTOS], int* tope, int pos_a_borrar) {

    elementos[pos_a_borrar] = elementos[*tope - 1];
    (*tope)--;
}


/*  
 *  Precondiciones: 
 *  Postcondiciones: devuelve true si la coordenada ya se encuentra ocupada por alguna pared o elemento.
*/
bool coordenada_ocupada(coordenada_t coordenada, nivel_t nivel) {        
    
    return hay_pared(nivel.paredes, nivel.tope_paredes, coordenada) ||
           buscar_elemento(nivel.obstaculos, nivel.tope_obstaculos, coordenada, false) != ELEMENTO_NO_ENCONTRADO ||
           buscar_elemento(nivel.herramientas, nivel.tope_herramientas, coordenada, false) != ELEMENTO_NO_ENCONTRADO;
}


/*  
 *  Precondiciones: se debe invocar a srand previamente. 
 *  Postcondiciones: devuelve una coordenada aleatoria dentro del rango de filas y columnas máximo.
 */
coordenada_t coordenada_aleatoria(nivel_t nivel) {
    
    coordenada_t coordenada_generada;

    do {
        coordenada_generada.col = rand() % MAX_COLUMNAS;
        coordenada_generada.fila = rand() % MAX_FILAS;
    } while (coordenada_ocupada(coordenada_generada, nivel));

    return coordenada_generada;
}


/*  
 *  Precondiciones: el vector paredes debe estar cargado junto con su tope.
 *  Postcondiciones: devuelve una coordeanda elegida del vector paredes.
 */
coordenada_t coordenada_pared_aleatoria(nivel_t nivel) {

    coordenada_t coordenada_elegida;    
    int pos_del_vector_paredes;

    do {
        pos_del_vector_paredes = rand() % nivel.tope_paredes;
        coordenada_elegida = nivel.paredes[pos_del_vector_paredes];
    } while (buscar_elemento(nivel.herramientas, nivel.tope_herramientas, coordenada_elegida, false) != ELEMENTO_NO_ENCONTRADO);

    return coordenada_elegida;
}


/*
 *  Precondiciones: no tiene.
 *  Postcondiciones: revive a la sombra y descuenta puntos al personaje.
 */
void revivir_sombra(int* puntos, bool* sombra_viva) {
    *puntos -= CANJE_PUNTOS_REVIVIR_BLUE;
    *sombra_viva = true;
}


/*
 *  Precondiciones: no tiene.
 *  Postcondiciones: mata a la sombra cambiandola el booleano tiene_vida a false.
*/ 
void matar_sombra(bool* sombra_viva) {
    *sombra_viva = false;
}


/*  
 *  Precondiciones: el nivel debe estar previamente cargado.
 *  Postcondiciones: posiciona a los personajes en coordenadas espejo vacías. 
 */
void posicionar_personajes(nivel_t nivel, coordenada_t* pos_personaje, coordenada_t* pos_sombra, bool* sombra_viva) {
    
    do { 
        *pos_personaje = coordenada_aleatoria(nivel);

        pos_sombra->fila = pos_personaje->fila;
        pos_sombra->col = MAX_COLUMNAS - (pos_personaje->col + 1);

    } while (coordenada_ocupada(*pos_sombra, nivel));

    int posicion = buscar_elemento(nivel.obstaculos, nivel.tope_obstaculos, *pos_sombra, true);
    if (posicion == ELEMENTO_NO_ENCONTRADO)
        return;
    else if (nivel.obstaculos[posicion].tipo == LETRA_VELA) 
        matar_sombra(sombra_viva);
}


      
/*  
 *  Precondiciones: no tiene.
 *  Postcondiciones: crea la matriz del tablero con el ancho y el alto adecuados y la deja cargada con espacios.
 */
void cargar_tablero_vacio(char tablero[MAX_FILAS][MAX_COLUMNAS]) {
    for (int i = 0; i < MAX_FILAS; i++) {
        for (int j = 0; j < MAX_COLUMNAS; j++) {
                tablero[i][j] = ' ';
        }
    }
}


/*  
 *  Precondiciones: no tiene.
 *  Postcondiciones: imprime las secciones horizontales del tablero.
 */
void imprimir_extremos_tablero(char* extremo_izq, char* extremo_der, char* extremo_cent) {
    for (int j = 0; j < MAX_COLUMNAS + 1; j++) {           
        if (j == 0) printf("    %s" HORIZONTAL HORIZONTAL, extremo_izq);
        else if (j == MAX_COLUMNAS) printf(HORIZONTAL HORIZONTAL "%s\n", extremo_der);
        else printf(HORIZONTAL HORIZONTAL "%s" HORIZONTAL HORIZONTAL, extremo_cent);
    }
}


/*  
 *  Precondiciones: no tiene.
 *  Postcondiciones: imprime los bordes del titulo.
 */
void imprimir_borde_titulos() {
    for (int k = 0; k < MAX_BORDES; k++) {
        printf(NORMAL "=");
    }
    printf("\n");    
}


/*  
 *  Precondiciones: no tiene.
 *  Postcondiciones: imprime el titulo para el status de los personajes.
 */
void imprimir_titulo_status() {
    imprimir_borde_titulos();
    printf(STATUS);
    imprimir_borde_titulos();
}


/*  
 *  Precondiciones: no tiene.
 *  Postcondiciones: imprime el titulo del tablero con sus bordes.
 */
void imprimir_titulo_terreno(){
    imprimir_borde_titulos();
    printf(TITULO_TABLERO);
    imprimir_borde_titulos();
}


/*  
 *  Precondiciones: el personaje y la sombra deben estar inicializados.
 *  Postcondiciones: imprime el status de los personajes por pantalla.
 */
void imprimir_status_personajes(personaje_t personaje, sombra_t sombra) {
    imprimir_titulo_status();
    printf("\t\t\t\t"VERDE FLECHA_DERECHA " " FLECHA_DERECHA " " FLECHA_DERECHA );
    printf(" M A C ");
    printf(FLECHA_IZQUIERDA " " FLECHA_IZQUIERDA " " FLECHA_IZQUIERDA "\t\t\t\t\t\t");
    printf(AZUL FLECHA_DERECHA " " FLECHA_DERECHA " " FLECHA_DERECHA);
    printf(" B L O O ");
    printf(FLECHA_IZQUIERDA " " FLECHA_IZQUIERDA " " FLECHA_IZQUIERDA "\n");
    printf(VERDE "\t===============================================================" AZUL "\t\t\t===================================\n" NORMAL);
    printf("\t" VERDE DIAMANTE NORMAL " Posición: " VERDE INDICADOR NORMAL " Fila: %.2i, Columna: %.2i\t\t",
    personaje.posicion.fila + 1, personaje.posicion.col + 1);
    printf(VERDE DIAMANTE NORMAL " Puntos: %i\t\t\t", personaje.puntos);   
    printf(AZUL DIAMANTE NORMAL " Posición: " AZUL INDICADOR NORMAL " Fila: %.2i, Columna: %.2i\n",
    sombra.posicion.fila + 1, sombra.posicion.col + 1);
    printf("\t" VERDE DIAMANTE NORMAL " Vidas:" ROJO);
    for (int i = 0; i < personaje.vida ; i++) {
       printf(CORAZON);
    }
    printf("\t\t");
    printf(VERDE DIAMANTE NORMAL " Llave: %s" LLAVE "\t\t", personaje.tiene_llave? AMARILLO : GRIS);
    printf(VERDE DIAMANTE NORMAL " Interruptor: %s" INTERRUPTOR "\t\t", personaje.interruptor_apretado? MAGENTA : GRIS);    
    printf(AZUL DIAMANTE NORMAL " Vida: %s" ESTRELLA NORMAL "\n", sombra.esta_viva? AMARILLO : GRIS);
}


/*  
 *  Precondiciones: el tablero ya debe estar previamente cargado. 
 *  Postcondiciones: imprime por pantalla el tablero de juego. 
 */
void imprimir_tablero(char tablero[MAX_FILAS][MAX_COLUMNAS]) {

    imprimir_titulo_terreno(); 
    
    printf("    ");

    // imprime la cabecera del tablero con los números de las columnas
    for (int j = 0; j < MAX_COLUMNAS; j++) {    
        printf("  %.2i ", j + 1);
    }
    printf("\n");    

    // imprime el extremo superior del tablero 
    imprimir_extremos_tablero(ESQUINA_SUP_IZQ, ESQUINA_SUP_DER, BORDE_SUP);

    // imprime las filas de la tabla con sus líneas medias
    for (int i = 0; i < MAX_FILAS; i++) {

        // imprime los números de las filas del tablero   
        printf("%.2i  " VERTICAL, i + 1);

        //imprime las filas del tablero
        for (int j = 0; j < MAX_COLUMNAS; j++) {    
            if (tablero[i][j] == LETRA_MAC) printf(" %s ", ICONO_MAC);
            else if (tablero[i][j] == LETRA_BLUE) printf(" %s ", ICONO_BLUE);
            else if (tablero[i][j] == LETRA_PARED) printf(" %s ", ICONO_PARED);
            else if (tablero[i][j] == LETRA_PUERTA) printf(" %s ", ICONO_PUERTA);
            else if (tablero[i][j] == LETRA_ESCALERA) printf(" %s " NORMAL, ICONO_ESCALERA);
            else if (tablero[i][j] == LETRA_MONEDA) printf(" %s ", ICONO_MONEDA);
            else if (tablero[i][j] == LETRA_LLAVE) printf(" %s  ", ICONO_LLAVE);
            else if (tablero[i][j] == LETRA_VELA) printf(" %s  ", ICONO_VELA);
            else if (tablero[i][j] == LETRA_POZO) printf(" %s  ", ICONO_POZO);
            else if (tablero[i][j] == LETRA_INTERRUPTOR) printf(" %s  ", ICONO_INTERRUPTOR);
            else if (tablero[i][j] == LETRA_PORTAL) printf(" %s ", ICONO_PORTAL);
            else printf(" %c  ", tablero[i][j]);
            printf(VERTICAL);
        }

        // imprime las líneas medias horizontales del tablero, excepto el último           
        if (i < (MAX_FILAS - 1)){  
            printf("\n"); 
            imprimir_extremos_tablero(BORDE_IZQ, BORDE_DER, CENTRO);
        }           
    }
    printf("\n"); 
    // imprime el extremo inferior del tablero 
    imprimir_extremos_tablero(ESQUINA_INF_IZQ, ESQUINA_INF_DER, BORDE_INF);
}


/*
 *  Precondiciones: el vector paredes y su tope deben estar cargados.
 *  Postcondiciones: ubica las paredes en el tablero.
 */
void ubicar_paredes(char (*tablero)[MAX_COLUMNAS], coordenada_t posicion[MAX_PAREDES], int tope) {
    
    for(int i = 0; i < tope; i++) {
        tablero[posicion[i].fila][posicion[i].col] = LETRA_PARED;
    }
}


/*
 *  Precondiciones: el vector objetos y su tope deben estar cargados.
 *  Postcondiciones: ubica los elementos del vector objetos en el tablero.
 */
void ubicar_objetos(char tablero[MAX_FILAS][MAX_COLUMNAS], elemento_t objetos[MAX_ELEMENTOS], int tope) {
    
    for(int i = 0; i < tope; i++) {
        tablero[objetos[i].coordenada.fila][objetos[i].coordenada.col] = objetos[i].tipo;
    }

}

/*
 *  Precondiciones: el tablero debe estar cargado previamente vacío. 
 *  Postcondiciones: ubica a los personajes y objetos (paredes, herramientas y obstáculos) en el tablero.
 */
void ubicar_elementos_tablero(juego_t juego, char tablero[MAX_FILAS][MAX_COLUMNAS]) {

    nivel_t nivel_actual = juego.niveles[juego.nivel_actual - 1];
    ubicar_paredes(tablero, nivel_actual.paredes, nivel_actual.tope_paredes);
    ubicar_objetos(tablero, nivel_actual.obstaculos, nivel_actual.tope_obstaculos);
    ubicar_objetos(tablero, nivel_actual.herramientas, nivel_actual.tope_herramientas);  

    tablero[juego.personaje.posicion.fila][juego.personaje.posicion.col] =  LETRA_MAC;
    tablero[juego.sombra.posicion.fila][juego.sombra.posicion.col] = LETRA_BLUE;
}


/*
 *  Precondiciones: el juego debe estar inicializado.
 *  Postcondiciones: imprime el tablero de juego cargado por pantalla.
 */
void imprimir_terreno(juego_t juego) {

    char tablero[MAX_FILAS][MAX_COLUMNAS];

    cargar_tablero_vacio(tablero);    
    ubicar_elementos_tablero(juego, tablero);
    imprimir_status_personajes(juego.personaje, juego.sombra);
    imprimir_tablero(tablero);    
}


/*  
 *  Precondiciones: no tiene.
 *  Postcondiciones: devuelve true si el caracter se encuentra dentro de las 5 opciones válidas (W, A, D, S y V).
 */
bool es_caracter_valido(char caracter) {
    return caracter == MOVIMIENTO_ARRIBA || caracter == MOVIMIENTO_ABAJO ||  
           caracter == MOVIMIENTO_IZQUIERDA || caracter == MOVIMIENTO_DERECHA ||
           caracter == SUMAR_VIDA;         
}


/*  Precondiciones: no tiene.
 *  Postcondiciones: la variable queda cargada con un caracter válido aportado por el usuario.
 */
void pedir_movimiento(char* caracter) {

    bool leido_correctamente = false;
    do {
        printf("Caracteres válidos: W = ARRIBA | S = ABAJO | A = IZQUIERDA | D = DERECHA | V = CANJE DE PUNTOS POR 1 VIDA\n");
        printf("Ingrese un caracter válido y en mayúscula:\n");

        scanf(" %c", caracter);

        leido_correctamente = es_caracter_valido(*caracter);
        
        if(!leido_correctamente) printf(AMARILLO "\n>>>> %c no es un caracter válido. ¡Avíspese! <<<< \n\n" NORMAL, *caracter);

    } while (!leido_correctamente);
    
}


/*
 *  Precondiciones: no tiene.
 *  Postcondiciones: realiza el movimiento a otra coordenada.
 */
void mover_casillero(char movimiento, coordenada_t* coordenada) {

    if (movimiento == MOVIMIENTO_ARRIBA) (coordenada->fila)--; 
    else if (movimiento == MOVIMIENTO_ABAJO) (coordenada->fila)++;
    else if (movimiento == MOVIMIENTO_DERECHA) (coordenada->col)++;
    else (coordenada->col)--;
}


/*  
 *  Precondiciones: la fila de la coordenada debe corresponder al alto y la columna al ancho.
 *  Postcondiciones: devuelve true si la coordenada se encuentra dentro de los rangos de filas y columnas válidos.
 */
bool esta_dentro_rango(coordenada_t posicion) {  
   return (posicion.fila >= 0 && posicion.fila < MAX_FILAS) && (posicion.col >= 0 && posicion.col < MAX_COLUMNAS);
}


/*
 *  Precondiciones: no tiene.
 *  Postcondiciones: devuelve true si el movimiento hacia el otro casillero está permitido.
 */
bool es_movimiento_permitido(coordenada_t coordenada, coordenada_t paredes[MAX_PAREDES], int tope) {
    return esta_dentro_rango(coordenada) && !hay_pared(paredes, tope, coordenada);
}


/*
 *  Precondiciones: el juego debe estar inicializado.
 *  Postcondiciones: mueve al personaje a otro casillero permitido. 
 */
void mover_personaje(char movimiento, coordenada_t* posicion, nivel_t* nivel) {

    int vector_aux[MAX_HERRAMIENTAS];
    int tope_aux = 0; 
    coordenada_t coordenada_aux;

    coordenada_aux = *posicion;
    mover_casillero(movimiento, &coordenada_aux);
   
    bool hay_escalera = true;
    while(hay_escalera) {     

        int pos_escalera = buscar_elemento(nivel->herramientas, nivel->tope_herramientas, coordenada_aux, false);

        if (pos_escalera != ELEMENTO_NO_ENCONTRADO && nivel->herramientas[pos_escalera].tipo == LETRA_ESCALERA) {
            mover_casillero(movimiento, &coordenada_aux);
            vector_aux[tope_aux] = pos_escalera;
            tope_aux++;
        }
        else
            hay_escalera = false;
    }
    
    if (es_movimiento_permitido(coordenada_aux, nivel->paredes, nivel->tope_paredes)) {

        *posicion = coordenada_aux;
        for (int i = 0; i < tope_aux; i++) {
            borrar_elemento(nivel->herramientas, &nivel->tope_herramientas, vector_aux[i]);
        }
    }
}


/*
 *  Precondiciones: el juego debe estar inicializado.
 *  Postcondiciones: mueve a la sombra a otra posición permitida.
 */
void mover_sombra(char movimiento, coordenada_t* posicion, bool sombra_viva, bool interruptor_apretado, nivel_t nivel) {

    if (!sombra_viva) return;

    coordenada_t coordenada_aux;
    coordenada_aux = *posicion;

    if(!interruptor_apretado) {
        if (movimiento == MOVIMIENTO_DERECHA) movimiento = MOVIMIENTO_IZQUIERDA;
        else if (movimiento == MOVIMIENTO_IZQUIERDA) movimiento = MOVIMIENTO_DERECHA;
    }
    
    mover_casillero(movimiento, &coordenada_aux);

    if (es_movimiento_permitido(coordenada_aux, nivel.paredes, nivel.tope_paredes))
        *posicion = coordenada_aux; 
}


/*
 *  Precondiciones: no tiene.
 *  Postcondiciones: alguno de los personajes agarra una moneda y se elimina del vector herramientas.
 */
void agarrar_monedas(int* puntos, elemento_t elementos[MAX_ELEMENTOS], int* tope, int pos_a_borrar) {
    *puntos += rand() % 11 + 10;
    borrar_elemento(elementos, tope, pos_a_borrar);
    
}


/*
 *  Precondiciones: no tiene.
 *  Postcondiciones: el personaje agarra la llave y la elimina del vector herramientas.
 */
void agarrar_llave(bool* tiene_llave, elemento_t elementos[MAX_ELEMENTOS], int* tope, int pos_a_borrar) {
    *tiene_llave = true;
    borrar_elemento(elementos, tope, pos_a_borrar);
}


/*
 *  Precondiciones: no tiene.
 *  Postcondiciones: el interruptor cambia a true si estaba en false; o a false si estaba en true.
 */
void presionar_interruptor(bool* interruptor_apretado) {

    if (*interruptor_apretado) *interruptor_apretado = false;
    else *interruptor_apretado = true;
}


/*
 *  Precondiciones: no tiene.
 *  Postcondiciones: el personaje apaga la vela en caso de caer en un casillero donde haya una y se elimina del vector obstáculos.
 */
void apagar_vela(elemento_t elementos[MAX_ELEMENTOS], int* tope, int pos_a_borrar) {
    borrar_elemento(elementos, tope, pos_a_borrar);

}


/*
 *  Precondiciones: no tiene. 
 *  Postcondiciones: posiciona a los personajes en sus nuevas coordenadas en caso que el personaje haya caido en un pozo.
 */
void caer_en_pozo(personaje_t* personaje, sombra_t* sombra, nivel_t nivel) {

    personaje->vida -= 1;
    posicionar_personajes(nivel, &personaje->posicion, &sombra->posicion, &sombra->esta_viva);

}


/*
 *  Precondiciones: no tiene.
 *  Postcondiciones: intercambia las posiciones de los personajes en caso de que la sombra haya caido en un portal.
*/ 
void atravesar_portal(coordenada_t* pos_personaje, coordenada_t* pos_sombra, bool* sombra_viva, nivel_t* nivel) {

    coordenada_t aux = *pos_personaje;
    *pos_personaje = *pos_sombra;
    *pos_sombra = aux;
    int posicion = buscar_elemento(nivel->obstaculos, nivel->tope_obstaculos, *pos_sombra, true);

    if (posicion == ELEMENTO_NO_ENCONTRADO)
        return;
    else if (nivel->obstaculos[posicion].tipo == LETRA_VELA) 
        matar_sombra(sombra_viva);
}


/*
 *  Precondiciones: el personaje debe estar inicializado.
 *  Postcondiciones: se intercambian puntos ganados por una vida en caso de tener menos del máximo. 
 */
void intercambiar_vida_por_puntos(personaje_t* personaje) {

    if(personaje->vida < VIDAS_MAXIMAS && personaje->puntos >= CANJE_PUNTOS_POR_VIDA) {
        (personaje->vida)++;
        personaje->puntos -= CANJE_PUNTOS_POR_VIDA;
    }
}


/*
 *  Precondiciones: no tiene.
 *  Postcondiciones: el personaje reacciona a una herramienta en caso de habersela encontrado.
 */
void reaccionar_personaje_a_herramienta(personaje_t* personaje, nivel_t* nivel) {

    int posicion = buscar_elemento(nivel->herramientas, nivel->tope_herramientas, personaje->posicion, false);

    if(posicion == ELEMENTO_NO_ENCONTRADO) return;

    char tipo_herramienta = nivel->herramientas[posicion].tipo;
    
    switch (tipo_herramienta) {
        
    case LETRA_MONEDA:
        agarrar_monedas(&personaje->puntos, nivel->herramientas, &nivel->tope_herramientas, posicion);
        break;
        
    case LETRA_LLAVE:
        agarrar_llave(&personaje->tiene_llave, nivel->herramientas, &nivel->tope_herramientas, posicion);
        break;
    }
}


/*
 *  Precondiciones: no tiene.
 *  Postcondiciones: el personaje reacciona a un obstaculo en caso de haberselo encontrado.
*/ 
void reaccionar_personaje_a_obstaculo(juego_t* juego) {

    nivel_t* nivel = &juego->niveles[juego->nivel_actual - 1];

    int posicion = buscar_elemento(nivel->obstaculos, nivel->tope_obstaculos, juego->personaje.posicion, false);
    
    if (posicion == ELEMENTO_NO_ENCONTRADO) return;

    char tipo_obstaculo = nivel->obstaculos[posicion].tipo;
    switch (tipo_obstaculo) {
        
    case LETRA_VELA:
        apagar_vela(nivel->obstaculos, &nivel->tope_obstaculos, posicion);
        break;
        
    case LETRA_POZO:
        caer_en_pozo(&juego->personaje, &juego->sombra, *nivel);            
        break;

    case LETRA_INTERRUPTOR:
        presionar_interruptor(&juego->personaje.interruptor_apretado);
        break;
    }
}


/*
 *  Precondiciones: no tiene.
 *  Postcondiciones: la sombra reacciona agarrando la moneda en caso de haberla encontrado.
 */
void reaccionar_sombra_a_herramienta(personaje_t* personaje, sombra_t sombra, nivel_t* nivel) {

     int posicion = buscar_elemento(nivel->herramientas, nivel->tope_herramientas, sombra.posicion, false);

    if(posicion == ELEMENTO_NO_ENCONTRADO) return;

    char tipo_herramienta = nivel->herramientas[posicion].tipo;
    
    if(tipo_herramienta == LETRA_MONEDA) {
        agarrar_monedas(&personaje->puntos, nivel->herramientas, &nivel->tope_herramientas, posicion);
    }
}


/*
 *  Precondiciones: no tiene.
 *  Postcondiciones: la sombra reacciona a una vela o un portal en caso de haberselo encontrado.
*/ 
void reaccionar_sombra_a_obstaculo(juego_t* juego) {


    nivel_t* nivel = &juego->niveles[juego->nivel_actual - 1];

    int posicion = buscar_elemento(nivel->obstaculos, nivel->tope_obstaculos, juego->sombra.posicion, false);
    
    if (posicion == ELEMENTO_NO_ENCONTRADO)
        posicion = buscar_elemento(nivel->obstaculos, nivel->tope_obstaculos, juego->sombra.posicion, true);
    
    if (posicion == ELEMENTO_NO_ENCONTRADO)
        return;

    char tipo_obstaculo = nivel->obstaculos[posicion].tipo;
    switch (tipo_obstaculo) {
        
    case LETRA_VELA:
        matar_sombra(&juego->sombra.esta_viva);
        break;
        
    case LETRA_PORTAL:
        atravesar_portal(&juego->personaje.posicion, &juego->sombra.posicion, &juego->sombra.esta_viva, nivel);
        break;
    }    
}


/*
 *  Precondiciones: el juego debe estar inicializado.
 *  Postcondiciones: los personajes reaccionan al movimiento realizado.
 */
void reaccionar_personajes_a_movimiento(juego_t* juego) {

    if(coordenadas_cercanas(juego->personaje.posicion, juego->sombra.posicion, 0)  && !juego->sombra.esta_viva) {
        revivir_sombra(&juego->personaje.puntos, &juego->sombra.esta_viva);
    }

    nivel_t* nivel = &juego->niveles[juego->nivel_actual - 1];
    reaccionar_personaje_a_herramienta(&juego->personaje, nivel);
    reaccionar_sombra_a_herramienta(&juego->personaje, juego->sombra, nivel);
    reaccionar_personaje_a_obstaculo(juego);
    reaccionar_sombra_a_obstaculo(juego);    
}


/*
 *  Precondiciones: no tiene.
 *  Postcondiciones: devuelve true si el personaje está cerca de la puerta.
 */
bool esta_cerca_puerta(coordenada_t pos_figura, coordenada_t pos_puerta) {
    return (abs(pos_figura.fila - pos_puerta.fila) + abs(pos_figura.col - pos_puerta.col)) <= DISTANCIA_MIN; 
}


/*
 *  Precondiciones: el juego debe estar inicializado.
 *  Postcondiciones: devuelve 1 si se gana el juego, 0 si debe seguir jugando y -1 si se pierde.
 */
int estado_juego(juego_t juego) {

    int estado = JUEGO_JUGANDO;       

    if(!juego.personaje.vida) 
        estado = JUEGO_PERDIDO;

    else if (juego.personaje.vida && juego.sombra.esta_viva && juego.nivel_actual >= MAX_NIVELES)
        estado = JUEGO_GANADO;        
    
    return estado;
}


/*
 *  Precondiciones: no tiene.
 *  Postcondiciones: devuelve true si se ganó el nivel. 
 */
bool es_nivel_ganado(int nivel_actual, personaje_t personaje, sombra_t sombra, coordenada_t coord_puerta) {

return esta_cerca_puerta(personaje.posicion, coord_puerta) && esta_cerca_puerta(sombra.posicion, coord_puerta) &&
    (personaje.tiene_llave || nivel_actual == NIVEL_UNO) && sombra.esta_viva;
}


/*
 *  Precondiciones: el juego debe estar inicializado.
 *  Postcondiciones: devuelve 1 si se gana el nivel y 0 si se debe seguir jugando en el mismo.
 */
int estado_nivel(juego_t juego) {

    int estado = NIVEL_JUGANDO;
    
    coordenada_t coord_puerta = juego.niveles[juego.nivel_actual - 1].herramientas[0].coordenada;

    if(es_nivel_ganado(juego.nivel_actual, juego.personaje, juego.sombra, coord_puerta))
       estado = NIVEL_GANADO;

    return estado;
}


/*
 *  Precondiciones: el juego debe estar inicializado.
 *  Postcondiciones: cambia de nivel a uno superior y deja a los personajes en un estado listo para jugar. 
 */
void cambio_nivel(juego_t* juego) {

    juego->nivel_actual++;
    nivel_t nivel = juego->niveles[juego->nivel_actual - 1];
    juego->personaje.tiene_llave = false;
    juego->personaje.interruptor_apretado = false; 
    posicionar_personajes(nivel, &juego->personaje.posicion, &juego->sombra.posicion, &juego->sombra.esta_viva);
}


/*
 *  Precondiciones: el juego debe estar previamente inicializado.
 *  Postcondiciones: Mueve a los personajes y realiza la acción necesaria en caso de que alguno choque con un elemento.
 */
void realizar_jugada(juego_t* juego) {

    char caracter;
    pedir_movimiento(&caracter);

    if (caracter == SUMAR_VIDA) {
        intercambiar_vida_por_puntos(&juego->personaje);
        
    } else { 

        nivel_t* nivel = &juego->niveles[juego->nivel_actual - 1];

        mover_personaje(caracter, &juego->personaje.posicion, nivel);
        mover_sombra(caracter, &juego->sombra.posicion, juego->sombra.esta_viva, juego->personaje.interruptor_apretado, *nivel);

        reaccionar_personajes_a_movimiento(juego); 

        if(estado_nivel(*juego) == NIVEL_GANADO && juego->nivel_actual < MAX_NIVELES)
            cambio_nivel(juego);
            
    }
}


/*  
 *  Precondiciones: el vector de niveles debe estar previamente cargado.
 *  Postcondiciones: carga el vector de obstáculos según el nivel requerido.
 */
void inicializar_obstaculos(nivel_t* nivel) {

    for(int j = 0; j < MAX_OBSTACULOS; j++) {
        for (int i = 0; i < obstaculos[j].cant_por_nivel[nivel->numero_nivel - 1]; i++) {

            nivel->obstaculos[nivel->tope_obstaculos].tipo = obstaculos[j].tipo;
            nivel->obstaculos[nivel->tope_obstaculos].coordenada = coordenada_aleatoria(*nivel);
            (nivel->tope_obstaculos)++;        
        }
    }
}


/*  
 *  Precondiciones: el vector de niveles debe estar previamente cargado.
 *  Postcondiciones: carga el vector de herramientas según el nivel requerido.
 */
void inicializar_herramientas(nivel_t* nivel) {

    for(int j = 0; j < MAX_HERRAMIENTAS; j++) {        
        for (int i = 0; i < herramientas[j].cant_por_nivel[nivel->numero_nivel -  1]; i++) {

            nivel->herramientas[nivel->tope_herramientas].tipo = herramientas[j].tipo;

            if (herramientas[j].tipo == LETRA_ESCALERA) 
                nivel->herramientas[nivel->tope_herramientas].coordenada = coordenada_pared_aleatoria(*nivel);            
            else
                nivel->herramientas[nivel->tope_herramientas].coordenada = coordenada_aleatoria(*nivel);
                       
            (nivel->tope_herramientas)++;        
        }
    }
}    


/*  
 *  Precondiciones: no tiene. 
 *  Postcondiciones: carga los vectores de paredes, herramientas y obstáculos de todos los niveles del juego.
 */
void inicializar_niveles(nivel_t niveles[MAX_NIVELES]) {

    cargar_mapas();
    for (int i = 0; i < MAX_NIVELES; i++) {
        
        niveles[i].tope_paredes = niveles[i].tope_obstaculos = niveles[i].tope_herramientas = 0;

        niveles[i].numero_nivel = i + 1;
        obtener_mapa(niveles[i].paredes, &niveles[i].tope_paredes);
        inicializar_obstaculos(&niveles[i]);
        inicializar_herramientas(&niveles[i]);
    }
}


/*  
 *  Precondiciones: el nivel 1 debe estar inicializado previamente.
 *  Postcondiciones: carga los personajes y los deja en un estado listo para empezar a jugar el nivel 1.
 */
void inicializar_personajes(personaje_t* personaje, sombra_t* sombra, nivel_t nivel) {

    personaje->vida = VIDAS_MAXIMAS;
    personaje->puntos = PUNTOS_AL_INICIO;
    personaje->interruptor_apretado = MODO_INTERRUPTOR_AL_INICIO;
    personaje->tiene_llave = LLAVE_AL_INICIO;    
    
    sombra->esta_viva = VIDA_SOMBRA_AL_INICIO;

    posicionar_personajes(nivel, &personaje->posicion, &sombra->posicion, &sombra->esta_viva);
}


/*  
 *  Precondiciones: no tiene.
 *  Postcondiciones: inicializa el juego cargando toda su información inicial y dejándolo listo para empezar a jugar.
 */
void inicializar_juego(juego_t* juego) {

    juego->nivel_actual = NIVEL_UNO; 
    inicializar_niveles(juego->niveles);

    nivel_t nivel = juego->niveles[juego->nivel_actual - 1];     
    inicializar_personajes(&juego->personaje, &juego->sombra, nivel);   
}


