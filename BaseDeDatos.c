#include <stdio.h>
#include <stdlib.h>
#include "datos.h"
#include "menu.h"
#include "altas.h"
//clude "bajas.h"
//nclude "mostrar.h"
//nclude "especiales.h"
//nclude "util.h"

int main(){
    Persona *lista = NULL;
    int op;

    do{
        op = menuPrincipal(lista); 

        switch(op){
            case 1:
                Altas(&lista); 
                break;
            case 2:
                Bajas(&lista);  
                break;
            case 3:
                Mostrar(lista); 
                break;
            case 4:
                Especiales(lista); 
                break;
            case 0:
                printf("\nSaliendo del programa...\n");
                liberarLista(&lista);
                break;
            case -1:
                break;
            default:
                printf("\n Opción no válida.\n");
                break;
        }
    }while(op != 0);

    return 0;
}
