#ifndef MOSTRAR_H
#define MOSTRAR_H

#include <stdio.h>
#include <string.h>
#include "struct.h"


void mostrarTodos(struct Persona *ptr){
    if(ptr == NULL){
        printf(" No hay registros.\n");
        return;
    }
    while(ptr != NULL){
        printf("\nNombre: %s\nEdad: %d\nGenero: %c\nFecha Nac: %s\n",
               ptr->nombre, ptr->edad, ptr->genero, ptr->fn);
        if(ptr->ptr != NULL){
            struct Alumno *A = ptr->ptr;
            printf("Matricula: %s\nCarrera: %s\nSemestre: %d\nCorreo: %s\n",
                   A->matricula, A->carrera, A->semestre, A->correo);
        }
        ptr = ptr->sig;
    }
}

void mostrarPorCarrera(struct Persona *ptr, const char *carrera){
    while(ptr != NULL){
        if(ptr->ptr != NULL && strcmp(ptr->ptr->carrera, carrera) == 0){
            printf("\nNombre: %s\nCarrera: %s\n", ptr->nombre, ptr->ptr->carrera);
        }
        ptr = ptr->sig;
    }
}


void mostrarPorSemestre(struct Persona *ptr, int semestre){
    while(ptr != NULL){
        if(ptr->ptr != NULL && ptr->ptr->semestre == semestre){
            printf("\nNombre: %s\nSemestre: %d\n", ptr->nombre, ptr->ptr->semestre);
        }
        ptr = ptr->sig;
    }
}

void mostrarPorCarreraSemestre(struct Persona *ptr, const char *carrera, int semestre){
    while(ptr != NULL){
        if(ptr->ptr != NULL && strcmp(ptr->ptr->carrera, carrera) == 0 && ptr->ptr->semestre == semestre){
            printf("\nNombre: %s\nCarrera: %s\nSemestre: %d\n", ptr->nombre, ptr->ptr->carrera, ptr->ptr->semestre);
        }
        ptr = ptr->sig;
    }
}

void buscarPorNombre(struct Persona *ptr, const char *nombre){
    while(ptr != NULL){
        if(strcmp(ptr->nombre, nombre) == 0){
            printf("\nEncontrado: %s\n", ptr->nombre);
            return;
        }
        ptr = ptr->sig;
    }
    printf(" Nombre no encontrado.\n");
}


void buscarPorMatricula(struct Persona *ptr, const char *matricula){
    while(ptr != NULL){
        if(ptr->ptr != NULL && strcmp(ptr->ptr->matricula, matricula) == 0){
            printf("\nEncontrado: %s con matricula %s\n", ptr->nombre, ptr->ptr->matricula);
            return;
        }
        ptr = ptr->sig;
    }
    printf(" Matricula no encontrada.\n");
}

#endif

