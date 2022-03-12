#ifndef _CONSTANTES_SOMBRA_DE_MAC_
#define _CONSTANTES_SOMBRA_DE_MAC_


#define NIVEL_UNO 1
#define ELEMENTO_NO_ENCONTRADO -1


// Constantes vinculadas a los estados posibles del juego y del nivel
#define JUEGO_JUGANDO 0
#define JUEGO_PERDIDO -1
#define JUEGO_GANADO 1
#define NIVEL_JUGANDO 0
#define NIVEL_GANADO 1

// Constantes relacionadas al personaje de MAC
#define VIDAS_MAXIMAS 3
#define PUNTOS_AL_INICIO 0 
#define LLAVE_AL_INICIO false
#define MODO_INTERRUPTOR_AL_INICIO false
#define LETRA_MAC 'M'
#define ICONO_MAC "\U0001F9D2"


// Constantes relacionadas al personaje de BLUE
#define VIDA_SOMBRA_AL_INICIO true
#define LETRA_BLUE 'B'
#define ICONO_BLUE "\U0001F47B"


// Caracteres válidos a ingresar por parte del usuario
#define MOVIMIENTO_ARRIBA 'W'
#define MOVIMIENTO_ABAJO 'S'
#define MOVIMIENTO_IZQUIERDA 'A'
#define MOVIMIENTO_DERECHA 'D'
#define SUMAR_VIDA 'V'


// Constantes vinculadas a las paredes
#define LETRA_PARED 'X'
#define ICONO_PARED "\U0001F9F1"

// Constantes relacionadas con los obstáculos del tablero
#define LETRA_VELA 'V'
#define ICONO_VELA "🕯️"      //! están como literales algunos porque no me reconocia el código de Unicode
#define VELAS_N1 5
#define VELAS_N2 10
#define VELAS_N3 12  
#define FILAS_EFECTO_VELA 3
#define COLUMNAS_EFECTO_VELA 3  
#define LETRA_POZO 'W'
#define ICONO_POZO "🕳️"
#define POZOS_N1 15
#define POZOS_N2 20
#define POZOS_N3 30
#define LETRA_INTERRUPTOR 'O'
#define ICONO_INTERRUPTOR "🕹️"
#define INTERRUPTORES_N1 1
#define INTERRUPTORES_N2 2
#define INTERRUPTORES_N3 4
#define LETRA_PORTAL 'P'
#define ICONO_PORTAL "🌀"
#define PORTALES_N1 0
#define PORTALES_N2 2
#define PORTALES_N3 4


// Constantes relacionadas a las herramientas de los personajes
#define LETRA_ESCALERA 'E'
#define ICONO_ESCALERA "🧗" 
#define ESCALERAS_N1 10
#define ESCALERAS_N2 15
#define ESCALERAS_N3 15 
#define LETRA_MONEDA 'C' 
#define ICONO_MONEDA "💰"
#define MONEDAS_N1 10
#define MONEDAS_N2 15
#define MONEDAS_N3 15
#define LETRA_LLAVE 'L'
#define ICONO_LLAVE "🗝️"
#define LLAVES_N1 0
#define LLAVES_N2 1
#define LLAVES_N3 1
#define CANJE_PUNTOS_POR_VIDA 200
#define CANJE_PUNTOS_REVIVIR_BLUE 50
#define LETRA_PUERTA 'D'
#define ICONO_PUERTA "\U0001F6AA"
#define PUERTAS_N1 1
#define PUERTAS_N2 1
#define PUERTAS_N3 1
#define DISTANCIA_MIN 1

//bordes del tablero
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


//constantes para dar formato
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
#define MAX_BORDES 130


#endif

