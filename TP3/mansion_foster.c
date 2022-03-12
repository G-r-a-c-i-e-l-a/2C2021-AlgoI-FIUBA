#include "funciones_de_archivos.h"
#include "ascii_art.h"
#include "la_sombra_de_mac.h"
#include <stdlib.h>
#include <time.h>


/*  
 *  Precondiciones: no tiene.
 *  Postcondiciones: devuelve 0 si se pudo efectuar el comando solicitado o -1 si se produjo algún error.
 */
int trabajar_con_partidas(int cantidad, char* parametro[]) {  

    FILE* archivo_partidas = fopen(parametro[2], "r");     
    if (!archivo_partidas) {
        perror("No se pudo abrir el archivo de partidas\n");
        return ERROR;
    }

    FILE* archivo_auxiliar = fopen("archivo_aux.csv", "w");
    if (!archivo_auxiliar) {
        perror("No se pudo abrir el archivo auxiliar\n");
        fclose(archivo_partidas);
        return ERROR;
    }

    if (strcmp(parametro[1], "agregar_partida") == 0) {
        agregar_partida(archivo_partidas, archivo_auxiliar);    

    } else if (strcmp(parametro[1], "eliminar_partida") == 0 && cantidad >= 4) {
        eliminar_partida(archivo_partidas, archivo_auxiliar, parametro[3]);

    } else if (strcmp(parametro[1], "ordenar_partidas") == 0) {
        ordenar_partidas(archivo_partidas, archivo_auxiliar);
    
    } else {
        perror("No se pudo realizar la operacion solicitada");
        return ERROR;
    }
    
    fclose(archivo_auxiliar);
    fclose(archivo_partidas);

    rename("archivo_aux.csv", parametro[2]);

    return 0; 
}


int main(int argc, char* argv[]){

    srand ((unsigned)time(NULL));

    parametros_t parametros;

    if (argc == 1) {
        cargar_configuraciones(false, &parametros);
        jugar_partida(parametros);

    } else if (argc > 1 && strcmp(argv[1], "juego_config") == 0) {
        cargar_configuraciones(true, &parametros);
        jugar_partida(parametros);

    } else if (argc > 2) {
        return trabajar_con_partidas(argc, argv);
    
    } else {
        perror("No se pudo realizar la operacion\n");
        return ERROR;
    }

    return 0;
}