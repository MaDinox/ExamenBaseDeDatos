#ifndef MENU_H
#define MENU_H

#include <stdio.h>

int menuPrincipal(void){
    int op;
    printf("\n ------------------------------\n");
    printf("\n ------- MENU PRINCIPAL -------\n");
    printf("[1] Dar de alta personas\n");
    printf("[2] Eliminar personas\n");
    printf("[3] Mostrar registros\n");
    printf("[4] Funciones especiales\n");
    printf("[0] Salir\n");
    printf("\n ------------------------------\n");
    printf("Selecciona una opción: ");
    scanf("%d", &op);
    return op;
}

#endif
