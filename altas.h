#ifndef ALTAS_H
#define ALTAS_H

#include <stdio.h>
#include <stdlib.h>
#include "datos.h"

void Altas(Persona **lista){
    Persona *nuevo = nuevaPersona();
    if(nuevo != NULL){
        nuevo->siguiente = *lista;
        *lista = nuevo;
        printf("\nPersona agregada correctamente.\n");
    }
}

Persona *nuevaPersona(void){
    Persona *ptrTemp = NULL;
    ptrTemp = (Persona *) malloc(sizeof(Persona));

    if(ptrTemp == NULL){
        printf("No se reservó memoria para Persona\n");
        return NULL;
    }else{
        ptrTemp->siguiente = NULL;
        ptrTemp->alumno = nuevoAlumno();
        ptrTemp->profesor = NULL;
        ptrTemp->servicios = NULL;
        ptrTemp->aspirante = NULL;
        return ptrTemp;
    }
}

Alumno *nuevoAlumno(void){
    Alumno *ptrTempA = NULL;
    ptrTempA = (Alumno *) malloc(sizeof(Alumno));

    if(ptrTempA == NULL){
        printf("No se reservó memoria para Alumno\n");
        return NULL;
    }else{
        return ptrTempA;
    }
}

#endif
