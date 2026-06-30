#ifndef ALTAS_H
#define ALTAS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void Altas(struct Persona **ptr) {
    struct Persona *nuevo = (struct Persona*) malloc(sizeof(struct Persona));
    if (nuevo == NULL) {
        printf("Error: no se pudo asignar memoria para Persona.\n");
        return;
    }

    nuevo->nombre = (char*) malloc(50 * sizeof(char));
    if (nuevo->nombre == NULL) {
        printf("Error: no se pudo asignar memoria para el nombre.\n");
        free(nuevo);
        return;
    }

    printf("Nombre: ");
    getchar(); 
    fgets(nuevo->nombre, 50, stdin);
    nuevo->nombre[strcspn(nuevo->nombre, "\n")] = '\0';

    printf("Edad: ");
    scanf("%d", &nuevo->edad);

    printf("Genero (M/F): ");
    scanf(" %c", &nuevo->genero);

    printf("Fecha de nacimiento (dd/mm/aa): ");
    scanf(" %8s", nuevo->fn);


    struct Alumno *A = (struct Alumno*) malloc(sizeof(struct Alumno));
    if (A == NULL) {
        printf("Error: no se pudo asignar memoria para Alumno.\n");
        free(nuevo->nombre);
        free(nuevo);
        return;
    }

    printf("Matricula: ");
    scanf(" %9s", A->matricula);

    while (getchar() != '\n');

    printf("Carrera (ej. IDSSI): ");
    fgets(A->carrera, 20, stdin);
    A->carrera[strcspn(A->carrera, "\n")] = '\0';

    printf("Semestre: ");
    scanf("%d", &A->semestre);

    char correoGen[50];
    char carrera2[3];
    strncpy(carrera2, A->carrera, 2); 
    carrera2[2] = '\0';

    char primeros4[5];
    strncpy(primeros4, A->matricula, 4); 
    primeros4[4] = '\0';

    int lenMat = strlen(A->matricula);
    char ultimos4[5];
    if (lenMat >= 4) {
        strncpy(ultimos4, A->matricula + lenMat - 4, 4); 
        ultimos4[4] = '\0';
    } else {
        strcpy(ultimos4, "0000");
    }

    snprintf(correoGen, sizeof(correoGen), "%s%s%s@unsij.edu.mx", carrera2, primeros4, ultimos4);
    strcpy(A->correo, correoGen);

    printf("Correo generado: %s\n", A->correo);

    printf("Ingresa las calificaciones de 5 materias:\n");
    for (int i = 0; i < 5; i++) {
        printf("\nMateria %d:\n", i+1);
        printf("  Parcial 1: ");
        scanf("%f", &A->calif[i][0]);
        printf("  Parcial 2: ");
        scanf("%f", &A->calif[i][1]);
        printf("  Parcial 3: ");
        scanf("%f", &A->calif[i][2]);
        printf("  Ordinario: ");
        scanf("%f", &A->calif[i][3]);

        float promParciales = (A->calif[i][0] + A->calif[i][1] + A->calif[i][2]) / 3;
        A->calif[i][4] = (promParciales * 0.50) + (A->calif[i][3] * 0.50);

        printf("  Promedio final: %.2f\n", A->calif[i][4]);
    }

    nuevo->ptr = A;
    nuevo->sig = *ptr;
    *ptr = nuevo;

    printf("Persona y alumno dados de alta correctamente.\n");
}

#endif


