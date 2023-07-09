#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

typedef struct {
    char nombre[20];
    char nivel[7];
    char carrera[20];
    int cantMaterias;
    struct {
        char nombreMateria[20];
        char creditos[20];
    } materias[7];
} Estudiante;

typedef struct {
    char nombre[20];
    char carrera[20];
    int cantMaterias;
    struct {
        char nombreMateria[20];
        char paralelo[20];
    } materias[3];
} Profesor;

#endif