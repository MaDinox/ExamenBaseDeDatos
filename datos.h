#ifndef DATOS_H
#define DATOS_H

typedef struct Persona Persona;
typedef struct Alumno Alumno;
typedef struct Profesor Profesor;
typedef struct Servicios Servicios;
typedef struct Aspirante Aspirante;


struct Persona {
    char *nombre;
    int edad;
    char genero;
    char fn[8];   

    Alumno *alumno;      
    Profesor *profesor;  
    Servicios *servicios; 
    Aspirante *aspirante; 

    Persona *siguiente; 
}; 
    
struct Alumno {
    char matricula[10];
    char *carrera;
    int semestre;
    char correo[25];
    float promedio;
    float calif[5][5];
};


struct Profesor {
    char idEmpleado[10];
    char edificio[30];
    char correo[25];
};

struct Servicios {
    char idEmpleado[10];
    char area[30];
    char correo[25];
};

struct Aspirante {
    char folio[10];
    char carreraDeseada[30];
    int añoIngreso;
};

#endif
