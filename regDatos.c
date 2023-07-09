#include "regDatos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void registrarProfesores(Profesor* profesores, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el nombre del profesor %d: ", i + 1);
        scanf(" %s", profesores[i].nombre);
        printf("Ingrese la carrera del profesor %d: ", i + 1);
        scanf(" %s", profesores[i].carrera);
        int numero;
        printf("Ingrese la cantidad de materias que dicta (2-3): ");
        scanf(" %d", &numero);
        while(numero < 2  || numero > 3 ){
            printf("Ingrese la cantidad de materias que dicta (2-3): ");
            scanf("%d", &numero);
        }
        int *cantMaterias = &profesores[i].cantMaterias;
        *cantMaterias = numero;
        for (int j = 0; j < profesores[i].cantMaterias; j++) {
            printf("Ingrese el nombre de la materia %d: ", j + 1);
            scanf(" %s", profesores[i].materias[j].nombreMateria);
            printf("Ingrese el paralelo de la materia %d: ", j + 1);
            scanf(" %s", profesores[i].materias[j].paralelo);   
        }
        printf("\n");
    }
}

void registrarEstudiantes(Estudiante* estudiantes, int cantidad) {
    for (int i = 0; i < cantidad; i++) {
        printf("Ingrese el nombre del estudiante %d: ", i + 1);
        scanf(" %s", estudiantes[i].nombre);

        printf("Ingrese el nivel del estudiante %d: ", i + 1);
        scanf(" %s", &estudiantes[i].nivel);

        printf("Ingrese la carrera del estudiante %d: ", i + 1);
        scanf(" %s", estudiantes[i].carrera);
        int numero;
        printf("Ingrese la cantidad de materias que toma (3-7): ");
        scanf(" %d", &numero);
        while(numero < 3  || numero > 7 ){
           printf("Ingrese la cantidad de materias que toma (3-7):  ");
          scanf("%d", &numero);
        }
        int *cantMateriasEstudiante = &estudiantes[i].cantMaterias;
        *cantMateriasEstudiante = numero;

        for (int j = 0; j < estudiantes[i].cantMaterias; j++) {
            printf("Ingrese el nombre de la materia %d: ", j + 1);
            scanf(" %s", estudiantes[i].materias[j].nombreMateria);

            printf("Ingrese los créditos de la materia %d: ", j + 1);
            scanf(" %s", &estudiantes[i].materias[j].creditos);
        }

        printf("\n");
    }
}
