#ifndef __ASCII_ART__
#define __ASCII_ART__


#define VERDE "\x1b[32;1m"
#define AZUL "\x1b[34;1m"
#define NORMAL "\x1b[0m"

#define STATUS "                           S T A T U S    D E    L O S    P E R S O N A J E S\n"   

#define TITULO_TABLERO "                                   T A B L E R O    D E    J U E G O\n"

#define BANNER "\
                 ____ ___ _____ _   ___     _______ _   _ ___ ____   ___  ____       _ \n\
                | __ )_ _| ____| \\ | \\ \\   / / ____| \\ | |_ _|  _ \\ / _ \\/ ___|     / \\ \n\
                |  _ \\| ||  _| |  \\| |\\ \\ / /|  _| |  \\| || || | | | | | \\___ \\    / _ \\ \n\
                | |_) | || |___| |\\  | \\ V / | |___| |\\  || || |_| | |_| |___) |  / ___ \\ \n\
                |____/___|_____|_| \\_|  \\_/  |_____|_| \\_|___|____/ \\___/|____/  /_/   \\_\\ \n\n\
    " VERDE "  .___  ___.      ___       ______    " NORMAL "  ____    ____  " AZUL "   .______    __       __    __   _______ \n\
    " VERDE "  |   \\/   |     /   \\     /      |  " NORMAL "   \\   \\  /   / " AZUL "    |   _  \\  |  |     |  |  |  | |   ____| \n\
    " VERDE "  |  \\  /  |    /  ^  \\   |  ,----'  " NORMAL "    \\   \\/   /  " AZUL "    |  |_)  | |  |     |  |  |  | |  |__ \n\
    " VERDE "  |  |\\/|  |   /  /_\\  \\  |  |      " NORMAL "      \\_    _/  " AZUL "     |   _  <  |  |     |  |  |  | |   __| \n\
    " VERDE "  |  |  |  |  /  _____  \\ |  `----.  " NORMAL "       |  |      " AZUL "   |  |_)  | |  `----.|  `--'  | |  |____ \n\
    " VERDE "  |__|  |__| /__/     \\__\\ \\______|  " NORMAL "       |__|     " AZUL "    |______/  |_______| \\______/  |_______| \n\n"



#define DIBUJOS_SALUDO "\
           -/+osssooooyoo++//                  " VERDE "     >>>> ¡HOLA, PRESIONÁ ENTER PARA EMPEZAR A JUGAR! <<<<    " NORMAL "\n\
    `:syyyyyyyyyyyyyyyyyyyyyyyys+- \n\
   :syyyyyyyyyyyyyyyyyyyyyyyyyyyyyo- \n\
   +yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy:       " AZUL "                      ./osyhyssso+/-` " NORMAL "\n\
  :yyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy.     " AZUL "                    -smNMMMMMMMMMMMMMNd+." NORMAL "\n\
  syyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy+      " AZUL "    .:-          -yNMMMMMMMMMMMMMMMMMMMNs`" NORMAL "\n\
  syyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyo     " AZUL "   .hNNNd/       +NMMMMMMMMMMMMMMMMMMMMMMMm- " NORMAL "\n\
  oyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy+   " AZUL "     yMMMMMMs`    :MMMMMNhhNMMNysyNMMMMMMMMMMN. " NORMAL "\n\
  +yyyyyyyyyyyyhyyyy:.+yyyyyyyyyyyyyyy+    " AZUL "    hMMMMMMMo   `dMMMMh:.``yN::  -MMMMMMMMMMMy  " NORMAL "\n\
  +yyyyyyyyyyyyhyyyy:.+yyyyyyyyyyyyyyy+  " AZUL "      oMMMMMMMN+  -MMMMMs/-  +N/:  :MMMMMMMMMMMM: " NORMAL "\n\
  +yyyyyyhhhhysyyys-...+yyyyyhhhhyyyyy/  " AZUL "      `NMMMMMMMM: `MMMMMMy++yNMNdydNMMNMMMMMMMMMd   " NORMAL "\n\
  +yyyyyyyyyy/oyy/....../syy/yyyyyyyyy/       " AZUL "  -NMMMMMMMm` MMMMMMMMMMMMMMMMMm/:MMMMMMMMMM/  " NORMAL "\n\
  -yyyyys+:/` //..........+/`.o+/yyyyy:   " AZUL "      :NMMMMMMMo dMMMMMMMMMMMMNmds. /MMMMMMMMMMm` " NORMAL "\n\
   yyho-.-   `o-.........-`   +.-./yys`    " AZUL "       /MMMMMMMNodMMMMMMMMh---.``   /MMMMMMMMMMMo ``  " NORMAL "\n\
   yys..-.  `.--...-:-...-.``.-..-yy.  " AZUL "            sMMMMMMMMMMMMMMMMMNyyo:.``.:mMMMMMMMMMMMNddddhs/-`   " NORMAL "\n\
   .sys-..---...:::........--.../ys.  " AZUL "             `dMMMMMMMMMMMMMMMMMMMMMNmmmMMMMMMMMMMMMMMMMMMMMMNmy:`  " NORMAL "\n\
   `/sys+:-----.....---:::::/+ys/`     " AZUL "             .hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMh:  " NORMAL "\n\
     ./syyyyyy:...-yyyyyyyso+-       " AZUL "                :sNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMNymMMMMMMMMM/ " NORMAL "\n\
       `./+o+-----:....-``           " AZUL "                  /NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM:`:sdMMMMMMN. " NORMAL "\n\
         osddsssssy-                     " AZUL "                .hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd   `:hNMMMMy " NORMAL "\n\
        :ssyymyssssy                    " AZUL "                   sMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+     .omNm: " NORMAL "\n\
       -+ossssdssssh/                    " AZUL "                   sMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN`      `.`  " NORMAL "\n\
       `.so///ossssy+`                    " AZUL "                   sNMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMo    " NORMAL "\n\
        +o.```+sssss/`                    " AZUL "                    .hMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN.   " NORMAL "\n\
       `so:-.:ossssss`                           " AZUL "              `dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMy   " NORMAL "\n\
        -+soosssssoss`                     " AZUL "                     .mMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM-  " NORMAL "\n\
          /::::::/-:-                      " AZUL "                      :MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMd     " NORMAL "\n\
          /......:-.-.                      " AZUL "                      dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM/    " NORMAL "\n\
          :.....-.-:-:`                       " AZUL "                    +MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMm    " NORMAL "\n\
         .--..:::.../--:                       " AZUL "                    dMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMM+     " NORMAL "\n\
        /-:/+//ossshddd+                    " AZUL "                       +MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMN`   " NORMAL "\n\
        `:::-/-/+oo++//-.`                   " AZUL "                       NMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMs   " NORMAL "\n"


#endif
