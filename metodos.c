#include "metodos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Profesor* crearProfesores(int cantidad) {
    Profesor* profesores = (Profesor*)malloc(cantidad * sizeof(Profesor));
    return profesores;
}

Estudiante* crearEstudiantes(int cantidad) {
    Estudiante* estudiantes = (Estudiante*)malloc(cantidad * sizeof(Estudiante));
    return estudiantes;
}

void eliminarProfesores(Profesor* profesores) {
    free(profesores);
}

void eliminarEstudiantes(Estudiante* estudiantes) {
    free(estudiantes);
}

void mostrarDatosProfesores(Profesor* profesores, int cantidad) {
    printf("\nProfesores: \n");
    for (int i = 0; i < cantidad; i++) {
        printf("Profesor %d\n", i + 1);
        printf("Nombre: %s\n", profesores[i].nombre);
        printf("Carrera: %s\n", profesores[i].carrera);
        printf("Materias dictando:\n");
        for (int j = 0; j < profesores[i].cantMaterias; j++) {
            printf("  - Materia %d: %s (Paralelo %s)\n", j + 1, profesores[i].materias[j].nombreMateria, profesores[i].materias[j].paralelo);
        }
        printf("\n");
    }
}

void mostrarDatosEstudiantes(Estudiante* estudiantes, int cantidad) {
    printf("\nEstudiantes: \n");
    for (int i = 0; i < cantidad; i++) {
        printf("Estudiante %d\n", i + 1);
        printf("Nombre: %s\n", estudiantes[i].nombre);
        printf("Nivel: %s\n", estudiantes[i].nivel);
        printf("Carrera: %s\n", estudiantes[i].carrera);
        printf("Materias tomando:\n");
        for (int j = 0; j < estudiantes[i].cantMaterias; j++) {
            printf("  - Materia %d: %s (Créditos %s)\n", j + 1, estudiantes[i].materias[j].nombreMateria, estudiantes[i].materias[j].creditos);
        }
        printf("\n");
    }
}


void eliminarMateriaEstudiante(Estudiante* estudiantes, int cantidadEstudiantes, int indiceEstudiante, int indiceMateria) {
    if (indiceEstudiante >= 0 && indiceEstudiante < cantidadEstudiantes) {
        if (indiceMateria >= 0 && indiceMateria < estudiantes[indiceEstudiante].cantMaterias) {
            for (int i = indiceMateria; i < estudiantes[indiceEstudiante].cantMaterias - 1; i++) {
                strcpy(estudiantes[indiceEstudiante].materias[i].nombreMateria, estudiantes[indiceEstudiante].materias[i + 1].nombreMateria);
                strcpy(estudiantes[indiceEstudiante].materias[i].creditos, estudiantes[indiceEstudiante].materias[i + 1].creditos);
            }
            estudiantes[indiceEstudiante].cantMaterias--;
            printf("Materia eliminada.\n");
        } else {
            printf("Índice de materia no válido.\n");
        }
    } else {
        printf("Índice de estudiante no válido.\n");
    }
}

void cambiarNivel(Estudiante* estudiantes, int cantidadEstudiantes, int indiceEstudiante, const char* nuevoNivel) {
    if (indiceEstudiante >= 0 && indiceEstudiante < cantidadEstudiantes) {
        strcpy(estudiantes[indiceEstudiante].nivel, nuevoNivel);
        printf("Nivel actualizado.\n");
    } else {
        printf("Índice de estudiante no válido.\n");
    }
}

void eliminarMateriaProfesor(Profesor* profesores, int cantidadprofesores, int indiceprofesor, int indiceMateria) {
    if (indiceprofesor >= 0 && indiceprofesor < cantidadprofesores) {
        if (indiceMateria >= 0 && indiceMateria < profesores[indiceprofesor].cantMaterias) {
            for (int i = indiceMateria; i < profesores[indiceprofesor].cantMaterias - 1; i++) {
                strcpy(profesores[indiceprofesor].materias[i].nombreMateria, profesores[indiceprofesor].materias[i + 1].nombreMateria);
                strcpy(profesores[indiceprofesor].materias[i].paralelo, profesores[indiceprofesor].materias[i + 1].paralelo);
            }
            profesores[indiceprofesor].cantMaterias--;
            printf("Materia eliminada.\n");
        } else {
            printf("Índice de materia no válido.\n");
        }
    } else {
        printf("Índice de profesor no válido.\n");
    }
}