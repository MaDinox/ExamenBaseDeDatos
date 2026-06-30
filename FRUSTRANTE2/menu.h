#ifndef MENU_H
#define MENU_H

#include <stdio.h>

int menuPrincipal(void){
    int opcion;
    
    printf(" -------- MENU PRINCIPAL --------\n");
    printf(" -------------------------------\n");
    printf("[1] Dar de alta personas\n");
    printf("[2] Eliminar personas\n");
    printf("[3] Mostrar registros\n");
    printf("[4] Funciones especiales\n");
    printf("[5] Salir\n");
    printf(" -------------------------------\n");
    printf("Selecciona una opcion: ");
    scanf("%d", &opcion);
    return opcion;
}

int menuAltas(void){
    int subopcion;
    printf("\n ----------- MENU ALTAS -----------\n");
    printf("[1] Dar de alta una persona-alumno\n");
    printf("[2] Dar de alta varias personas-alumnos\n");
    printf("[0] Regresar\n");
    printf("-----------------------------------\n");
    printf("Selecciona una opcion: ");
    scanf("%d", &subopcion);
    return subopcion;
}

int menuBajas(void){
    int subopcion;
    printf("\n ----------- MENU BAJAS -----------\n");
    printf("[1] Eliminar una persona-alumno\n");
    printf("[2] Eliminar varias personas-alumnos\n");
    printf("[0] Regresar\n");
    printf("-----------------------------------\n");
    printf("Selecciona una opcion: ");
    scanf("%d", &subopcion);
    return subopcion;
}

#endif

