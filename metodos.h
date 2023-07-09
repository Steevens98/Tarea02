#ifndef METODOS_H
#define METODOS_H

#include "estructuras.h"

Profesor* crearProfesores(int cantidad);
Estudiante* crearEstudiantes(int cantidad);
void eliminarProfesores(Profesor* profesores);
void eliminarEstudiantes(Estudiante* estudiantes);
void mostrarDatosProfesores(Profesor* profesores, int cantidad);
void mostrarDatosEstudiantes(Estudiante* estudiantes, int cantidad);
void cambiarNivel(Estudiante* estudiantes, int cantidadEstudiantes, int indiceEstudiante, const char* nuevoNivel);
void eliminarMateriaEstudiante(Estudiante* estudiantes, int cantidadEstudiantes, int indiceEstudiante, int indiceMateria);
void eliminarMateriaProfesor(Profesor* profesores, int cantidadprofesores, int indiceprofesor, int indiceMateria) ;

#endif