#include "stringd.h"

void crearString(stringd &s) {
    s = new char[1];
    s[0] = '\0';
}

void liberarString(stringd &s) {
    delete[] s;
    s = NULL;
}

void cargarString(stringd &s) {
    stringd aux = new char[MAX];
    int i = 0;
    char c;

    scanf("%c", &c);
    while ((c != '\n' && i < MAX - 1)) {
        aux[i] = c;
        i++;
        scanf("%c", &c);
    }

    aux[i] = '\0';
    copiarString(s, aux);
    liberarString(aux);
}

int stringLargo(stringd s) {
    int i = 0;

    while (s[i] != '\0')
        i++;
    return i;
}

void copiarString(stringd &s1, stringd s2) {
    int i = 0;
    int largo = stringLargo(s2) + 1;

    delete[] s1;
    s1 = new char[largo];
    while (s2[i] != '\0') {
        s1[i] = s2[i];
        i++;
    }

    s1[i] = '\0';
}

void concatenarString(stringd &s1, stringd s2) {
    stringd aux;
    crearString(aux);
    copiarString(aux, s1);

    int largo = stringLargo(s1) + stringLargo(s2) + 1;

    if (largo > MAX) {
        largo = MAX;
    }

    delete[] s1;
    s1 = new char[largo];
    int i = 0;

    while (aux[i] != '\0') {
        s1[i] = aux[i];
        i++;
    }

    int j = 0;
    while (s2[j] != '\0' && i < MAX - 1) {
        s1[i] = s2[j];
        i++;
        j++;
    }

    s1[i] = '\0';
    liberarString(aux);
}

void intercambiarString(stringd &s1, stringd &s2) {
    stringd aux;
    aux = s1;
    s1 = s2;
    s2 = aux;
}

void printString(stringd s) {
    int i = 0;

    while (s[i] != '\0') {
        printf("%c", s[i]);
        i++;
    }
}

boolean stringMenor(stringd s1, stringd s2) {
    int i = 0;
    boolean encontre = FALSE;
    boolean menor = FALSE;

    while ((!encontre) && (s1[i] != '\0') && (s2[i] != '\0')) {
        if (s1[i] != s2[i]) {
            encontre = TRUE;
        }
        if (s1[i] < s2[i]) {
            menor = TRUE;
        }
        i++;
    }

    if ((!encontre) && (s2[i] != '\0')) {
        menor = TRUE;
    }

    return menor;
}

boolean stringIguales(stringd s1, stringd s2) {
    int i = 0;
    boolean iguales = TRUE;

    while (iguales && (s1[i] != '\0') && (s2[i] != '\0')) {
        if (s1[i] != s2[i]) {
            iguales = FALSE;
        }
        i++;
    }

    if ((s1[i] != '\0') || (s2[i] != '\0')) {
        iguales = FALSE;
    }
    return iguales;
}

void bajarString(stringd s, FILE *f) {

    int i = 0;
    while (s[i] != '\0') {
        fwrite(&s[i], sizeof(char), 1, f);
        i++;
    }
    // escribo el '\0'
    fwrite(&s[i], sizeof(char), 1, f);

}

void levantarString(stringd &s, FILE *f) {
    int i = 0;
    stringd aux;

    aux = new char[MAX];
    fread(&aux[i], sizeof(char), 1, f);

    while (!feof(f) && (aux[i] != '\0')) {
        i++;
        fread(&aux[i], sizeof(char), 1, f);
    }

    copiarString(s, aux);
    delete[] aux;
}
