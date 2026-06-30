#ifndef ESPECIALES_H
#define ESPECIALES_H

#include <stdio.h>
#include <string.h>
#include "struct.h"


void contarAlumnos(struct Persona *ptr){
    int total = 0;
    while(ptr != NULL){
        if(ptr->ptr != NULL) total++;
        ptr = ptr->sig;
    }
    printf("Total de alumnos registrados: %d\n", total);
}


void contarPorCarrera(struct Persona *ptr, const char *carrera){
    int total = 0;
    while(ptr != NULL){
        if(ptr->ptr != NULL && strcmp(ptr->ptr->carrera, carrera) == 0){
            total++;
        }
        ptr = ptr->sig;
    }
    printf("Total de alumnos en %s: %d\n", carrera, total);
}


void promedioGeneral(struct Persona *ptr){
    int materias = 0;
    float suma = 0;
    while(ptr != NULL){
        if(ptr->ptr != NULL){
            for(int i=0; i<5; i++){
                suma += ptr->ptr->calif[i][4];
                materias++;
            }
        }
        ptr = ptr->sig;
    }
    if(materias > 0)
        printf("Promedio general: %.2f\n", suma/materias);
    else
        printf("No hay calificaciones registradas.\n");
}

void promedioPorCarrera(struct Persona *ptr, const char *carrera){
    int materias = 0;
    float suma = 0;
    while(ptr != NULL){
        if(ptr->ptr != NULL && strcmp(ptr->ptr->carrera, carrera) == 0){
            for(int i=0; i<5; i++){
                suma += ptr->ptr->calif[i][4];
                materias++;
            }
        }
        ptr = ptr->sig;
    }
    if(materias > 0)
        printf("Promedio en %s: %.2f\n", carrera, suma/materias);
    else
        printf("No hay calificaciones registradas para %s.\n", carrera);
}

#endif
