#ifndef MOSTRAR_H
#define MOSTRAR_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void mostrarRegistros(struct Persona *ptr) {
    if (ptr == NULL) {
        printf(" No hay registros para mostrar.\n");
        return;
    }

    struct Persona *actual = ptr;
    int contador = 1;

    while (actual != NULL) {
        printf("\n=====================================\n");
        printf("Registro #%d\n", contador++);
        printf("Nombre: %s\n", actual->nombre);
        printf("Edad: %d\n", actual->edad);
        printf("Genero: %c\n", actual->genero);
        printf("Fecha de nacimiento: %s\n", actual->fn);

        if (actual->ptr != NULL) {
            struct Alumno *A = actual->ptr;
            printf("Matricula: %s\n", A->matricula);
            printf("Carrera: %s\n", A->carrera);
            printf("Semestre: %d\n", A->semestre);
            printf("Correo institucional: %s\n", A->correo);

            printf("Calificaciones:\n");
            for (int i = 0; i < 5; i++) {
                printf("  Materia %d:\n", i+1);
                printf("    Parcial 1: %.2f\n", A->calif[i][0]);
                printf("    Parcial 2: %.2f\n", A->calif[i][1]);
                printf("    Parcial 3: %.2f\n", A->calif[i][2]);
                printf("    Ordinario: %.2f\n", A->calif[i][3]);
                printf("    Promedio final: %.2f\n", A->calif[i][4]);
            }
        } else {
            printf("Este registro no tiene datos de alumno.\n");
        }

        actual = actual->sig;
    }

    printf("\nFin de registros.\n");
}

#endif
