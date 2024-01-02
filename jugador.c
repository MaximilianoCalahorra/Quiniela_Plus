#include <stdio.h>
#include <stdlib.h>
#include "jugador.h"

///Jugador
struct JugadorE crearJugadorTeclado()
{
    struct JugadorE jug;
    printf("\nCarga de datos del jugador del carton:\n");
    printf("Ingrese el nombre: ");
    fflush(stdin);
    gets(jug.nombre);
    printf("Ingrese el DNI: ");
    scanf("%d", &jug.dni);
    return jug;
};

void mostrarJugador(struct JugadorE jug)
{
    printf("\n\nDatos del jugador del carton:\n");
    printf("Nombre: %s\n", jug.nombre);
    printf("DNI: %d\n", jug.dni);
}
