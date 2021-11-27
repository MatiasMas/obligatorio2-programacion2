#include "boolean.h"

void cargarBoolean(boolean &b) {
    char c;

    fflush(stdin);
    printf("Ingrese T para TRUE o F para FALSE: ");
    scanf("%c", &c);

    if (c == 'T') {
        b = TRUE;
    } else {
        b = FALSE;
    }
}

void desplegarBoolean(boolean b) {
    if (b) {
        printf("TRUE");
    } else {
        printf("FALSE");
    }
}
