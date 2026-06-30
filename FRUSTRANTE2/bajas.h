#ifndef BAJAS_H
#define BAJAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"


void bajaUnaPersona(struct Persona **ptr) {
    if (*ptr == NULL) {
        printf("No hay registros para eliminar.\n");
        return;
    }

    char nombre[50];
    printf("Ingresa el nombre de la persona a eliminar: ");
    getchar(); 
    fgets(nombre, 50, stdin);
    nombre[strcspn(nombre, "\n")] = '\0';

    struct Persona *actual = *ptr;
    struct Persona *anterior = NULL;

    while (actual != NULL && strcmp(actual->nombre, nombre) != 0) {
        anterior = actual;
        actual = actual->sig;
    }

    if (actual == NULL) {
        printf("Persona no encontrada.\n");
        return;
    }


    if (actual->ptr != NULL) {
        free(actual->ptr);
    }

    free(actual->nombre);


    if (anterior == NULL) {
        *ptr = actual->sig;
    } else {
        anterior->sig = actual->sig;
    }

    free(actual);
    printf(" Persona y alumno eliminados correctamente.\n");
}

void bajaVariasPersonas(struct Persona **ptr) {
    char continuar = 'S';
    while (continuar == 'S' || continuar == 's') {
        bajaUnaPersona(ptr);
        printf("¿Deseas eliminar otra persona? (S/N): ");
        scanf(" %c", &continuar);
    }
}

#endif
