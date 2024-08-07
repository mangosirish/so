/*
    Nombre:    Diego Flores Chávez.
    Matrícula: 2203031129.
    Grupo:     CSI01.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char *argv[]) {
    // Revisión del número de argumentos provistos:
    if (argc != 2) {
        fprintf(stderr, "Uso: %s <number_of_iterations>\n", argv[0]);

        return 1;
    }

    // Conversión del número de iteraciones:
    long long num_iterations = atoll(argv[1]);

    if (num_iterations <= 0) {
        fprintf(stderr, "Error: El número de iteraciones debe ser positivo.\n");

        return 1;
    }

    // Inicio de la medición con registro:
    clock_t start_time = clock();

    // Creación del registro para el ciclo:
    register long long i;

    for (i = 0; i < num_iterations; ++i); // Simulación de trabajo.

    // Fin de la medición con registro:
    clock_t end_time = clock();

    // Cálculo del tiempo total con registro:
    double elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Impresión del tiempo total con registro:
    printf("Tiempo transcurrido por %lld iteraciones:\n\tCON REGISTRO >> %f segundos.\n", num_iterations, elapsed_time);

    // Inicio de la medición sin registro:
    start_time = clock();

    // Creación de variable normal para el ciclo:
    long long j;

    for (j = 0; j < num_iterations; ++j); // Simulación de trabajo.

    // Fin de la medición sin registro:
    end_time = clock();

    // Cálculo del tiempo total sin registro:
    elapsed_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    // Impresión del tiempo total sin registro:
    printf("\tSIN REGISTRO >> %f segundos.\n", elapsed_time);

    return 0;
}