#include "metodos.h"
#include "regDatos.h"
#include "estructuras.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
  printf("Menu de registro\n Profesor: -p\n Estudiante: -e\n Ambos: -a\n");
  
  //ejemplo de Formato usado ./main -p 4
  int opt;
  
  while((opt = getopt(argc, argv, "p:e:a:")) != -1) {
    Profesor* profesores = NULL;
    Estudiante* estudiantes = NULL;
    switch (opt) {
      int numeroPersonas;
      case 'p':
        if(atoi(optarg)<2){
          printf("La cantidad de personas a ingresar deben ser mayor o igual a 2\n");
          exit(1);
        }
        numeroPersonas= atoi(optarg);
        profesores = crearProfesores(numeroPersonas);
        registrarProfesores(profesores, numeroPersonas);
        int opc;
        do{
          printf("\n Menu \n 1.Mostar Datos\n 2.Eliminar Materia\n 3.Salir\n");
          printf("Elegir Opcion: ");
          scanf("%d", &opc);
          int indiceprofesor;
          int indiceMateria;
          switch (opc) {
          case 1:
            mostrarDatosProfesores(profesores, numeroPersonas);
          break;    
          case 2:
          printf("Ingrese el indice del Profesor: ");
          scanf(" %d", &indiceprofesor);
          printf("Ingrese el indice de la Materia: ");
          scanf(" %d", &indiceMateria);
          eliminarMateriaProfesor(profesores, numeroPersonas, indiceprofesor , indiceMateria);
          break;
          case 3:
          break;
          default:
           printf("Opcion Incorrecta: \n");
          break;
          }
        } while(opc!=3);
        eliminarProfesores(profesores);
        break;
      case 'e':
        if(atoi(optarg)<2){
          printf("La cantidad de personas a ingresar deben ser mayor o igual a 2\n");
          exit(1);
        }
        numeroPersonas=atoi(optarg);
        estudiantes = crearEstudiantes(numeroPersonas);
        registrarEstudiantes(estudiantes, numeroPersonas);
        int opc2;
        do{
          printf("\n Menu \n 1.Mostar Datos\n 2.Eliminar Materia\n 3.Cambiar Nivel\n 4.Salir\n");
          printf("Elegir Opcion: ");
          scanf("%d", &opc2);
          int indiceEstudiante;
          int indiceMateria;
          char nuevoNivel[7];
          switch (opc2) {
          case 1:
            mostrarDatosEstudiantes(estudiantes, numeroPersonas);
          break;    
          case 2:
          printf("Ingrese el indice del Estudiante: ");
          scanf(" %d", &indiceEstudiante);
          printf("Ingrese el indice de la Materia: ");
          scanf(" %d", &indiceMateria);
          eliminarMateriaEstudiante(estudiantes,numeroPersonas, indiceEstudiante,indiceMateria);
          break;
          case 3:
          printf("Ingrese el indice del Estudiante: ");
          scanf(" %d", &indiceEstudiante);
          printf("Ingrese el nuevo nivel: ");
          scanf(" %s", nuevoNivel); 
          cambiarNivel(estudiantes, numeroPersonas , indiceEstudiante, nuevoNivel);
          break;
          case 4:
          break;
          default:
           printf("Opcion Incorrecta: \n");
          break;
          }
        } while(opc2!=4);
        eliminarEstudiantes(estudiantes);
        break; 
      case 'a': 
        if(atoi(optarg)<2){
          printf("La cantidad de personas a ingresar deben ser mayor o igual a 2\n");
          exit(1);
        }
        numeroPersonas=atoi(optarg);
        profesores = crearProfesores(numeroPersonas - (numeroPersonas-1));
        registrarProfesores(profesores, numeroPersonas - (numeroPersonas-1));
        estudiantes = crearEstudiantes(numeroPersonas - 1);
        registrarEstudiantes(estudiantes, numeroPersonas -1);
        int opc3;
        do{
          printf("\n Menu \n 1.Mostar Datos Profesor\n 2.Eliminar Materia Profesor\n 3.Mostar Datos Estudiante\n 4.Eliminar Materia Estudiante\n 5.Cambiar Nivel Estudiante\n 6.Salir\n");
          printf("Elegir Opcion: ");
          scanf("%d", &opc3);
          int indiceprofesor;
          int indiceMateria;
          int indiceEstudiante;
          char nuevoNivel[7];
          switch (opc3) {
          case 1:
            mostrarDatosProfesores(profesores, numeroPersonas - (numeroPersonas-1));
          break;    
          case 2:
          printf("Ingrese el indice del Profesor: ");
          scanf(" %d", &indiceprofesor);
          printf("Ingrese el indice de la Materia: ");
          scanf(" %d", &indiceMateria);
          eliminarMateriaProfesor(profesores, numeroPersonas - (numeroPersonas-1), indiceprofesor , indiceMateria);
          break;
          case 3:
            mostrarDatosEstudiantes(estudiantes, numeroPersonas - 1);
          break;    
          case 4:
          printf("Ingrese el indice del Estudiante: ");
          scanf(" %d", &indiceEstudiante);
          printf("Ingrese el indice de la Materia: ");
          scanf(" %d", &indiceMateria);
          eliminarMateriaEstudiante(estudiantes,numeroPersonas - 1, indiceEstudiante,indiceMateria);
          break;
          case 5:
          printf("Ingrese el indice del Estudiante: ");
          scanf(" %d", &indiceEstudiante);
          printf("Ingrese el nuevo nivel: ");
          scanf(" %s", nuevoNivel); 
          cambiarNivel(estudiantes, numeroPersonas - 1 , indiceEstudiante, nuevoNivel);
          break;
          case 6:
          break;
          default:
           printf("Opcion Incorrecta: \n");
          break;
          }
        } while(opc3!=6); 
        eliminarProfesores(profesores);
        eliminarEstudiantes(estudiantes);
        break; 
      case ':': 
        printf("Opción: %c Falta argumento\n", optopt); 
        break; 
      case '?': 
        printf("Opción no valida: %c\n", optopt);
        break; 
        } 
    } 
  
  for (; optind < argc; optind++) {
    printf("Argumentos sobrantes: %s\n", argv[optind]);
  }

  return 0;
}