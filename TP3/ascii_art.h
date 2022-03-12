#ifndef __ASCII_ART__
#define __ASCII_ART__

#define ROJO "\x1b[31m"
#define VERDE "\x1b[32;1m"
#define AZUL "\x1b[34;1m"
#define NORMAL "\x1b[0m"



#define STATUS "                                       S T A T U S    D E    L O S    P E R S O N A J E S\n"   


#define TITULO_TABLERO "                                               T A B L E R O    D E    J U E G O\n"


#define BANNER "\
                 ____ ___ _____ _   ___     _______ _   _ ___ ____   ___  ____       _ \n\
                | __ )_ _| ____| \\ | \\ \\   / / ____| \\ | |_ _|  _ \\ / _ \\/ ___|     / \\ \n\
                |  _ \\| ||  _| |  \\| |\\ \\ / /|  _| |  \\| || || | | | | | \\___ \\    / _ \\ \n\
                | |_) | || |___| |\\  | \\ V / | |___| |\\  || || |_| | |_| |___) |  / ___ \\ \n\
                |____/___|_____|_| \\_|  \\_/  |_____|_| \\_|___|____/ \\___/|____/  /_/   \\_\\ \n\n\
    " VERDE "  .___  ___.      ___       ______    " NORMAL "  ____    ____  " AZUL"   .______    __        _______   _______ \n\
    " VERDE "  |   \\/   |     /   \\     /      |  " NORMAL "   \\   \\  /   / " AZUL "    |   _  \\  |  |     /  .__.  \\ /  .__.  \\ \n\
    " VERDE "  |  \\  /  |    /  ^  \\   |  ,----'  " NORMAL "    \\   \\/   /  " AZUL "    |  |_)  | |  |     |  |  |  | |  |  |  | \n\
    " VERDE "  |  |\\/|  |   /  /_\\  \\  |  |      " NORMAL "      \\_    _/  " AZUL "     |   _  <  |  |     |  |  |  | |  |  |  | \n\
    " VERDE "  |  |  |  |  /  _____  \\ |  `----.  " NORMAL "       |  |      " AZUL "   |  |_)  | |  `----.|  `--'  | |  `--'  | \n\
    " VERDE "  |__|  |__| /__/     \\__\\ \\______|  " NORMAL "       |__|     " AZUL "    |______/  |_______| \\______/   \\______/ \n\n" NORMAL 




#define DIBUJOS_SALUDO "\
"VERDE"           -/+osssooooyoo++//                  " VERDE "     >>>> ¡HOLA, PRESIONÁ ENTER PARA EMPEZAR A JUGAR! <<<<    " NORMAL "\n\
"VERDE"    `:syyyyyyyyyyyyyyyyyyyyyyyys+- \n\
"VERDE"   :syyyyyyyyyyyyyyyyyyyyyyyyyyyyyo- \n\
"VERDE"   +yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy:       " AZUL "                      ./osyhyssso+/-` " NORMAL "\n\
"VERDE"  :yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy.     " AZUL "                    -smNMMMMMMMMMMMMMNd+." NORMAL "\n\
"VERDE"  syyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy+      " AZUL "    .:-          -yNMMMMMMMMMMMMMMMMMMMNs`" NORMAL "\n\
"VERDE"  syyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo     " AZUL "   .hNNNd/       +NMMMMMMMMMMMMMMMMMMMMMMMm- " NORMAL "\n\
"VERDE"  oyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy+   " AZUL "     yMMMMMMs`    :MMMMMNhhNMMNysyNMMMMMMMMMMN. " NORMAL "\n\
"VERDE"  +yyyyyyyyyyyyhyyyy:.+yyyyyyyyyyyyyyy+    " AZUL "    hMMMMMMMo   `dMMMMh:.``yN::  -MMMMMMMMMMMy  " NORMAL "\n\
"VERDE"  +yyyyyyyyyyyyhyyyy:.+yyyyyyyyyyyyyyy+  " AZUL "      oMMMMMMMN+  -MMMMMs/-  +N/:  :MMMMMMMMMMMM: " NORMAL "\n\
"VERDE"  +yyyyyyhhhhysyyys-...+yyyyyhhhhyyyyy/  " AZUL "      `NMMMMMMMM: `MMMMMMy++yNMNdydNMMNMMMMMMMMMd   " NORMAL "\n\
"VERDE"  +yyyyyyyyyy/oyy/....../syy/yyyyyyyyy/       " AZUL "  -NMMMMMMMm` MMMMMMMMMMMMMMMMMm/:MMMMMMMMMM/  " NORMAL "\n\
"VERDE"  -yyyyys+:/` //..........+/`.o+/yyyyy:   " AZUL "      :NMMMMMMMo dMMMMMMMMMMMMNmds. /MMMMMMMMMMm` " NORMAL "\n\
"VERDE"   yyho-.-   `o-.........-`   +.-./yys`    " AZUL "       /MMMMMMMNodMMMMMMMMh---.``   /MMMMMMMMMMMo ``  " NORMAL "\n\
"VERDE"   yys..-.  `.--...-:-...-.``.-..-yy.  " AZUL "            sMMMMMMMMMMMMMMMMMNyyo:.``.:mMMMMMMMMMMMNddddhs/-`   " NORMAL "\n\
"VERDE"   .sys-..---...:::........--.../ys.  " AZUL "             `dMMMMMMMMMMMMMMMMMMMMMNmmmMMMMMMMMMMMMMMMMMMMMMNmy:`  " NORMAL "\n\
"VERDE"   `/sys+:-----.....---:::::/+ys/`     " AZUL "             .hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh:  " NORMAL "\n\
"VERDE"     ./syyyyyy:...-yyyyyyyso+-       " AZUL "                :sNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNymMMMMMMMMM/ " NORMAL "\n\
"VERDE"       `./+o+-----:....-``           " AZUL "                  /NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM:`:sdMMMMMMN. " NORMAL "\n\
"VERDE"         osddsssssy-                     " AZUL "                .hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd   `:hNMMMMy " NORMAL "\n\
"VERDE"        :ssyymyssssy                    " AZUL "                   sMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+     .omNm: " NORMAL "\n\
"VERDE"       -+ossssdssssh/                    " AZUL "                   sMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN`      `.`  " NORMAL "\n\
"VERDE"       `.so///ossssy+`                    " AZUL "                   sNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMo    " NORMAL "\n\
"VERDE"        +o.```+sssss/`                    " AZUL "                    .hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN.   " NORMAL "\n\
"VERDE"       `so:-.:ossssss`                           " AZUL "              `dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMy   " NORMAL "\n\
"VERDE"        -+soosssssoss`                     " AZUL "                     .mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM-  " NORMAL "\n\
"VERDE"          /::::::/-:-                      " AZUL "                      :MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd     " NORMAL "\n\
"VERDE"          /......:-.-.                      " AZUL "                      dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM/    " NORMAL "\n\
"VERDE"          :.....-.-:-:`                       " AZUL "                    +MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm    " NORMAL "\n\
"VERDE"         .--..:::.../--:                       " AZUL "                    dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+     " NORMAL "\n\
"VERDE"        /-:/+//ossshddd+                    " AZUL "                       +MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN`   " NORMAL "\n\
"VERDE"        `:::-/-/+oo++//-.`                   " AZUL "                       NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMs   " NORMAL "\n"




#define BANNER_GANASTE " \n\
"AZUL"        GGGGGGGGGGGGG                AAA                NNNNNNNN        NNNNNNNN                AAA                  SSSSSSSSSSSSSSS  TTTTTTTTTTTTTTTTTTTTTTT EEEEEEEEEEEEEEEEEEEEEE\n\
     GGG::::::::::::G               A:::A               N:::::::N       N::::::N               A:::A               SS:::::::::::::::S T:::::::::::::::::::::T E::::::::::::::::::::E\n\
   GG:::::::::::::::G              A:::::A              N::::::::N      N::::::N              A:::::A             S:::::SSSSSS::::::S T:::::::::::::::::::::T E::::::::::::::::::::E\n\
  G:::::GGGGGGGG::::G             A:::::::A             N:::::::::N     N::::::N             A:::::::A            S:::::S     SSSSSSS T:::::TT:::::::TT:::::T EE::::::EEEEEEEEE::::E\n\
 G:::::G       GGGGGG            A:::::::::A            N::::::::::N    N::::::N            A:::::::::A           S:::::S             TTTTTT  T:::::T  TTTTTT   E:::::E       EEEEEE\n\
G:::::G                         A:::::A:::::A           N:::::::::::N   N::::::N           A:::::A:::::A          S:::::S                     T:::::T           E:::::E             \n\
G:::::G                        A:::::A A:::::A          N:::::::N::::N  N::::::N          A:::::A A:::::A          S::::SSSS                  T:::::T           E::::::EEEEEEEEEE   \n\
G:::::G    GGGGGGGGGG         A:::::A   A:::::A         N::::::N N::::N N::::::N         A:::::A   A:::::A          SS::::::SSSSS             T:::::T           E:::::::::::::::E   \n\
G:::::G    G::::::::G        A:::::A     A:::::A        N::::::N  N::::N:::::::N        A:::::A     A:::::A           SSS::::::::SS           T:::::T           E:::::::::::::::E   \n\
G:::::G    GGGGG::::G       A:::::AAAAAAAAA:::::A       N::::::N   N:::::::::::N       A:::::AAAAAAAAA:::::A             SSSSSS::::S          T:::::T           E::::::EEEEEEEEEE   \n\
G:::::G        G::::G      A:::::::::::::::::::::A      N::::::N    N::::::::::N      A:::::::::::::::::::::A                 S:::::S         T:::::T           E:::::E             \n\
 G:::::G       G::::G     A:::::AAAAAAAAAAAAA:::::A     N::::::N     N:::::::::N     A:::::AAAAAAAAAAAAA:::::A                S:::::S         T:::::T           E:::::E       EEEEEE\n\
  G:::::GGGGGGGG::::G    A:::::A             A:::::A    N::::::N      N::::::::N    A:::::A             A:::::A   SSSSSSS     S:::::S       TT:::::::TT       EE::::::EEEEEEEE:::::E\n\
   GG:::::::::::::::G   A:::::A               A:::::A   N::::::N       N:::::::N   A:::::A               A:::::A  S::::::SSSSSS:::::S       T:::::::::T       E::::::::::::::::::::E\n\
     GGG::::::GGG:::G  A:::::A                 A:::::A  N::::::N        N::::::N  A:::::A                 A:::::A S:::::::::::::::SS        T:::::::::T       E::::::::::::::::::::E\n\
        GGGGGG   GGGG AAAAAAA                   AAAAAAA NNNNNNNN         NNNNNNN AAAAAAA                   AAAAAAA SSSSSSSSSSSSSSS          TTTTTTTTTTT       EEEEEEEEEEEEEEEEEEEEEE\n\n"


#define BANNER_PERDISTE " \n\
"ROJO"██▓███   ▓█████   ██▀███   ▓█████▄   ██▓   ██████  ▄▄▄█████▓ ▓█████  \n\
▓██░  ██ ▒▓█   ▀  ▓██ ▒ ██ ▒▒██▀ ██▌ ▓██▒▒ ██    ▒  ▓  ██▒ ▓ ▒▓█   ▀ \n\
▓██░ ██▓ ▒▒███    ▓██ ░▄█  ▒░██   █▌ ▒██▒░  ▓██▄    ▒ ▓██░ ▒ ░▒███   \n\
▒██▄█▓▒  ▒▒▓█  ▄  ▒██▀▀█▄   ░▓█▄   ▌ ░██░   ▒   ██▒ ░ ▓██▓ ░  ▒▓█  ▄ \n\
▒██▒ ░   ░░▒████▒ ░██▓ ▒██▒ ░▒████▓  ░██░ ▒██████▒▒   ▒██▒ ░  ░▒████▒\n\
▒▓▒░ ░   ░░░ ▒░ ░ ░ ▒▓ ░▒▓░  ▒▒▓  ▒  ░▓   ▒ ▒▓▒ ▒ ░   ▒ ░░    ░░ ▒░ ░\n\
░▒ ░       ░ ░  ░   ░▒ ░ ▒░  ░ ▒  ▒   ▒ ░ ░ ░▒  ░ ░     ░      ░ ░  ░\n\
░░           ░      ░░   ░   ░ ░  ░   ▒ ░ ░  ░  ░     ░          ░   \n\
             ░  ░    ░        ░      ░        ░               ░  ░\n\n"


#endif