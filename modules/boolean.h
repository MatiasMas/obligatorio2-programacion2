#ifndef O2P2_BOOLEAN_H
#define O2P2_BOOLEAN_H

#include <stdio.h>

typedef enum {FALSE, TRUE} boolean;

//Carga un valor booleano por teclado
void cargarBoolean(boolean &b);

//Muestra un valor booleano por pantalla
void desplegarBoolean(boolean b);

#endif //O2P2_BOOLEAN_H
