#include "la_sombra_de_mac.h"
#include "constantes_sombra_de_mac.h"
#include "utiles.h"
#include "ascii_art.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>


void imprimir_banner() {
    printf("%s", BANNER);
    printf("%s", DIBUJOS_SALUDO);
    getchar();
}


int main() {

    srand ((unsigned)time(NULL));

    juego_t juego;

    inicializar_juego(&juego);

    imprimir_banner();
    system("clear");

    while (estado_juego(juego) != JUEGO_PERDIDO && estado_nivel(juego) == NIVEL_JUGANDO) {    
      
        imprimir_terreno(juego);            
        realizar_jugada(&juego);
        system("clear");           
    }

    if (estado_juego(juego) == JUEGO_GANADO) printf(BANNER_GANASTE);
    else printf(BANNER_PERDISTE);    

    return 0;  
}