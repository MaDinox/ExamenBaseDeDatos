#ifndef STRUCTS_H
#define STRUCTS_H

struct Persona {

    char *nombre;
    int edad;
    char genero;
    char fn[9];
    struct Persona *sig;
    struct Alumno *ptr;

};

struct Alumno {

    char matricula[10];
    char carrera[5];
    int semestre;
    char correo[23];
    float calif[5][5];

};

#endif

