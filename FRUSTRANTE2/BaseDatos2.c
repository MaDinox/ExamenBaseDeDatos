#include "struct.h"
#include <stdio.h>
#include "menu.h"
#include "altas.h"
#include "bajas.h"
#include "mostrar.h"
#include "especiales.h"

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

        case 3: {
            int subopcion = menuMostrar();
            switch(subopcion){
                case 1:
                    mostrarTodos(ptr);
                    break;
                case 2: {
                    char carrera[20];
                    printf("Carrera a buscar: ");
                    scanf(" %19s", carrera);
                    mostrarPorCarrera(ptr, carrera);
                    break;
                }
                case 3: {
                    int semestre;
                    printf("Semestre a buscar: ");
                    scanf("%d", &semestre);
                    mostrarPorSemestre(ptr, semestre);
                    break;
                }
                case 4: {
                    char carrera[20];
                    int semestre;
                    printf("Carrera: ");
                    scanf(" %19s", carrera);
                    printf("Semestre: ");
                    scanf("%d", &semestre);
                    mostrarPorCarreraSemestre(ptr, carrera, semestre);
                    break;
                }
                case 5: {
                    char nombre[50];
                    getchar();
                    printf("Nombre a buscar: ");
                    fgets(nombre, 50, stdin);
                    nombre[strcspn(nombre, "\n")] = '\0';
                    buscarPorNombre(ptr, nombre);
                    break;
                }
                case 6: {
                    char matricula[10];
                    printf("Matricula a buscar: ");
                    scanf(" %9s", matricula);
                    buscarPorMatricula(ptr, matricula);
                    break;
                }
                case 7:
                    break;
                default:
                    printf("Opcion invalida.\n");
                    break;
            }
            break;
        }


        case 4: {
            int subopcion = menuEspeciales();
            switch(subopcion){
                case 1:
                    contarAlumnos(ptr);
                    break;
                case 2: {
                    char carrera[20];
                    printf("Carrera: ");
                    scanf(" %19s", carrera);
                    contarPorCarrera(ptr, carrera);
                    break;
                }
                case 3:
                    promedioGeneral(ptr);
                    break;
                case 4: {
                    char carrera[20];
                    printf("Carrera: ");
                    scanf(" %19s", carrera);
                    promedioPorCarrera(ptr, carrera);
                    break;
                }
                case 5:
                    break;
                default:
                    printf("Opcion invalida.\n");
                    break;
            }
            break;
        }

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
