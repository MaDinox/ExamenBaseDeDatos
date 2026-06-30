#include "struct.h"
#include <stdio.h>
#include "menu.h"
#include "altas.h"
#include "bajas.h"
#include "mostrar.h"

int main() {
    int opcion;
    struct Persona *ptr = NULL;

    do {
        opcion = menuPrincipal();

        switch (opcion) {
        case 1: { 
            int subopcion = menuAltas();
            switch (subopcion) {
                case 1:
                    Altas(&ptr); 
                    break;
                case 2: {
                    char continuar = 'S';
                    while (continuar == 'S' || continuar == 's') {
                        Altas(&ptr); 
                        printf("¿Deseas dar de alta otra persona? (S/N): ");
                        scanf(" %c", &continuar);
                    }
                    break;
                }
                case 0:
                    break;
                default:
                    printf("Opcion invalida.\n");
                    break;
            }
            break;
        }

        case 2: { 
            int subopcion = menuBajas();
            switch (subopcion) {
                case 1:
                    bajaUnaPersona(&ptr);
                    break;
                case 2:
                    bajaVariasPersonas(&ptr);
                    break;
                case 0:
                    break;
                default:
                    printf("Opcion invalida.\n");
                    break;
            }
            break;
        }

        case 3:
            mostrarRegistros(ptr);
            break;

        case 4:

            break;

        case 5:
            printf("Saliendo del programa...\n");
            break;

        default:
            printf("Opcion invalida.\n");
            break;
        }

    } while (opcion != 5);

    return 0;
}



