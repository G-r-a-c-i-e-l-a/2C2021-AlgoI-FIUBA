#include "funciones_de_archivos.h"
#include "la_sombra_de_mac.h"
#include "constantes_sombra_de_mac.h"
#include <stdlib.h>


#define PARAMETROS_A_LEER 5
#define CANT_PARAMETROS 1
#define AFIRMACION 'S'
#define NEGACION 'N'
#define SI "Si"
#define NO "No"
#define FORMATO_LECTURA_1 "%[^;];%i;%i;%i;%[^\n]\n"
#define FORMATO_ESCRITURA "%s;%i;%i;%i;%s\n"
#define FORMATO_LECTURA_2 "N%s\n"
#define MAX_PARTIDAS 200
#define MAX_CARACTERES 100



const objetos_t obstaculos[MAX_OBJETOS] = {
    {.tipo = LETRA_VELA, .cant_por_nivel = {VELAS_N1, VELAS_N2, VELAS_N3}},
    {.tipo = LETRA_POZO, .cant_por_nivel = {POZOS_N1, POZOS_N2, POZOS_N3}},
    {.tipo = LETRA_INTERRUPTOR, .cant_por_nivel = {INTERRUPTORES_N1, INTERRUPTORES_N2, INTERRUPTORES_N3}},
    {.tipo = LETRA_PORTAL, .cant_por_nivel = {PORTALES_N1, PORTALES_N2, PORTALES_N3}}
};


const objetos_t herramientas[MAX_OBJETOS] = {
    {.tipo = LETRA_PUERTA, .cant_por_nivel = {PUERTAS_N1, PUERTAS_N2, PUERTAS_N3}},
    {.tipo = LETRA_ESCALERA, .cant_por_nivel = {ESCALERAS_N1, ESCALERAS_N2, ESCALERAS_N3}},
    {.tipo = LETRA_MONEDA, .cant_por_nivel = {MONEDAS_N1, MONEDAS_N2, MONEDAS_N3}},
    {.tipo = LETRA_LLAVE, .cant_por_nivel = {LLAVES_N1, LLAVES_N2, LLAVES_N3}}
};



/*  
 *  Precondiciones: nivel debe estar entre 1 y 3.
 *  Postcondiciones: carga la cantidad de elementos en el obstaculo o herramienta correspondiente según el nivel.
 */
void agregar_parametro(parametros_t* parametros, char* tipo, int nivel, int cantidad) {   

    if (strcmp(tipo, "VELAS") == 0)  
        parametros->obstaculos[0].cant_por_nivel[nivel - 1] = cantidad;

    else if (strcmp(tipo, "POZOS") == 0)
        parametros->obstaculos[1].cant_por_nivel[nivel - 1] = cantidad;

    else if (strcmp(tipo, "INTERRUPTORES") == 0)
        parametros->obstaculos[2].cant_por_nivel[nivel - 1] = cantidad;

    else if (strcmp(tipo, "PORTALES") == 0)
        parametros->obstaculos[3].cant_por_nivel[nivel - 1] = cantidad;

    else if (strcmp(tipo, "ESCALERAS") == 0)
        parametros->herramientas[1].cant_por_nivel[nivel - 1] = cantidad;

    else if (strcmp(tipo, "MONEDAS") == 0)
        parametros->herramientas[2].cant_por_nivel[nivel - 1] = cantidad;

    else if (strcmp(tipo, "LLAVES") == 0)
        parametros->herramientas[3].cant_por_nivel[nivel - 1] = cantidad;
}


/*  
 *  Precondiciones: parametros debe estar previamente cargado con las configuraciones estandar por si en el archivo no existen todas los elementos por nivel.
 *  Postcondiciones: lee el archivo con las configuraciones y carga la cantidad de cada elemento en la estructura parametros. 
 */
void cargar_cant_objetos(FILE* archivo, parametros_t* parametros) {

    char linea[MAX_CARACTERES];
    char* numero; char* tipo_objeto; char* valor;
    int nivel; int cantidad;

    int leidos = fscanf(archivo, FORMATO_LECTURA_2 , linea);  
    
    while (leidos == CANT_PARAMETROS) {  

        numero = strtok(linea, "_");
        nivel = atoi(numero);

        tipo_objeto = strtok(NULL, "=");
   
        valor = strtok(NULL, "\0");
        cantidad = atoi(valor);

        agregar_parametro(parametros, tipo_objeto, nivel, cantidad);

        leidos = fscanf(archivo, FORMATO_LECTURA_2, linea);
    }
}


void cargar_configuraciones(bool configuraciones, parametros_t* parametros){

    for (int i = 0; i < MAX_OBJETOS; i++) { 
        parametros->obstaculos[i] = obstaculos[i];  
        parametros->herramientas[i] = herramientas[i];
    }

    if (configuraciones) { 

        FILE* archivo_config = fopen("config.txt", "r");
        
        if(!archivo_config) {
            perror(ROJO "No se pudo abrir el archivo de configuraciones iniciales, se juega en modalidad estandar.\n\n" NORMAL);
            return;
        }

        cargar_cant_objetos(archivo_config, parametros);
    }
}


/*  
 *  Precondiciones: -
 *  Postcondiciones: devuelve true cuando la letra comparada es S o N.
 */
bool es_letra_valida(char letra) {
    return letra == AFIRMACION || letra == NEGACION;
}


/*  
 *  Precondiciones: -
 *  Postcondiciones: carga los datos de la nueva partida en un registro.
 */
void cargar_datos_partida(partida_t* partida) {

    printf("Ingrese el nombre del jugador:\n");
    scanf("%s", partida->jugador);

    do {
        printf("Ingrese el número de nivel llegado de 1 a 3:\n");
        scanf("%i", &partida->nivel_llegado);
    } while(partida->nivel_llegado > MAX_NIVELES || partida->nivel_llegado <= 0);

    printf("Ingrese la cantidad de puntos alcanzados:\n");
    scanf("%i", &partida->puntos);

    do {
        printf("Ingrese el número de vidas restantes entre 0 y 3:\n");
        scanf("%i", &partida->vidas_restantes);
    } while (partida->vidas_restantes > VIDAS_MAXIMAS || partida->vidas_restantes < 0);

    char letra_aux;
    do {
        printf("¿Ganó la partida? S/N\n");
        scanf(" %c", &letra_aux);
    } while (!es_letra_valida(letra_aux));

    if(letra_aux == AFIRMACION) partida->gano = true;
    else partida->gano = false;
}


/*  
 *  Precondiciones: -
 *  Postcondiciones: carga la partida en una estructura desde un archivo y devuelve la cantidad de parámetros leidos.
 */
int leer_partida(FILE* archivo, partida_t* partida) {

    char string_aux[3];

    int leidos = fscanf(archivo, FORMATO_LECTURA_1, partida->jugador, &partida->nivel_llegado,
    &partida->puntos, &partida->vidas_restantes, string_aux);

    if (strcmp(string_aux, SI) == 0) partida->gano = true;
    else if (strcmp(string_aux, NO) == 0) partida->gano = false;

    return leidos;
}


/*  
 *  Precondiciones: -
 *  Postcondiciones: imprime la partida en un archivo.
 */
void imprimir_partida(FILE* archivo_aux, partida_t partida) {

    char string_aux[3];

    if (partida.gano) strcpy(string_aux, SI);
    else strcpy(string_aux, NO);

    fprintf(archivo_aux, FORMATO_ESCRITURA, partida.jugador, partida.nivel_llegado,
    partida.puntos, partida.vidas_restantes, string_aux);
}


void agregar_partida(FILE* archivo_partidas, FILE* archivo_auxiliar) {

    partida_t partida_a_agregar;
    cargar_datos_partida(&partida_a_agregar);

    partida_t partida_en_archivo;
    int leidos = leer_partida(archivo_partidas, &partida_en_archivo);

    bool partida_agregada = false;

    while (leidos == PARAMETROS_A_LEER) {
        if (strcmp(partida_en_archivo.jugador, partida_a_agregar.jugador) >= 0 && !partida_agregada) {
            imprimir_partida(archivo_auxiliar, partida_a_agregar);
            partida_agregada = true;
        }

        imprimir_partida(archivo_auxiliar, partida_en_archivo);
        leidos = leer_partida(archivo_partidas, &partida_en_archivo);
    }    

    if (!partida_agregada)
        imprimir_partida(archivo_auxiliar, partida_a_agregar);

}


void eliminar_partida(FILE* archivo_partidas, FILE* archivo_auxiliar, char jugador_a_eliminar[MAX_NOMBRE]) {

    partida_t partida_en_archivo;
    int leidos = leer_partida(archivo_partidas, &partida_en_archivo);

    bool partida_eliminada = false;

    while (leidos == PARAMETROS_A_LEER) {
        if (strcmp(partida_en_archivo.jugador, jugador_a_eliminar) != 0 || (strcmp(partida_en_archivo.jugador, jugador_a_eliminar) == 0 && partida_eliminada))
            imprimir_partida(archivo_auxiliar, partida_en_archivo);
        else
            partida_eliminada = true;

        leidos = leer_partida(archivo_partidas, &partida_en_archivo);
    }    
}


/*  
 *  Precondiciones: el tope debe ser menor o igual a la cantidad máxima de partidas y debe coincidir con la cantidad de 
 *  partidas cargadas en el vector. 
 *  Postcondiciones: ordena el vector de partidas. 
 */
void ordenar_vector_partidas(partida_t partidas[MAX_PARTIDAS], int tope) {
    
    for (int i = 0; i < tope - 1; i++){

        for (int j = 0; j < tope - 1 - i; j++){

            if(strcmp(partidas[j+1].jugador, partidas[j].jugador) < 0) {
                partida_t aux = partidas[j+1];
                partidas[j+1] = partidas[j];
                partidas[j] = aux;
            }
        }
    }
}


void ordenar_partidas(FILE* archivo_partidas, FILE* archivo_auxiliar) {

    partida_t partidas_en_archivo[MAX_PARTIDAS];
    int tope = 0;

    int leidos = leer_partida(archivo_partidas, &partidas_en_archivo[tope]);

    while (leidos == PARAMETROS_A_LEER) {        
        tope++;
        leidos = leer_partida(archivo_partidas, &partidas_en_archivo[tope]);
    }

    if(tope > 2)
        ordenar_vector_partidas(partidas_en_archivo, tope);

    for (int i = 0; i < tope; i++) 
        imprimir_partida(archivo_auxiliar, partidas_en_archivo[i]);
}







