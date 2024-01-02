#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "quiniela_plus.h"
#include "carton.h"

///Aleatorios
int generarAleatorio(int min, int max)
{
   return min + rand() % (max - min + 1);
}

///Opción
int pedirOpcion()
{
    int opElegida;
    do
    {
        printf("\nBienvenido al Quini Plus\n");
        printf("Elija como quiere comprar los numeros de su carton:\n");
        printf("Opcion #1: comprar aleatoriamente.\n");
        printf("Opcion #2: comprar manualmente.\n");
        printf("Su opcion: #");
        scanf("%d", &opElegida);
    }
    while((opElegida != 1) && (opElegida != 2));
    return opElegida;
}


///Jugada Quini Plus
void crearJugadaQuiniPlus(int juQuiniPlus[20])
{
    for (int i = 0; i < 20; i++)
    {
        juQuiniPlus[i] = generarAleatorio(0, 99);
    }
    ordenarJugadaQuiniPlus(juQuiniPlus);
}

void ordenarJugadaQuiniPlus(int juQuiniPlus[20])
{
    int aux;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (juQuiniPlus[j + 1] < juQuiniPlus[j])
            {
                aux = juQuiniPlus[j];
                juQuiniPlus[j] = juQuiniPlus[j + 1];
                juQuiniPlus[j + 1] = aux;
            }
        }
    }
}

void mostrarJugadaQuiniPlus(int juQuiniPlus[20])
{
    printf("\nJugada del Quini Plus:\n\n");
    for (int i = 0; i < 20; i++)
    {
        printf(" %d ", juQuiniPlus[i]);
    }
    printf("\n");
}

///Repetir
void repetirJuego()
{
    struct CartonE carto = crearCarton("Fonrouge 115, Lomas de Zamora");
    escribirCarton(carto);
    int jugaQuiniPlus[20];
    int cAciertos = 0;
    int cIntentos = 0;
    while (cAciertos < 8)
    {
        cIntentos++;
        crearJugadaQuiniPlus(jugaQuiniPlus);
        mostrarJugadaQuiniPlus(jugaQuiniPlus);
        mostrarEspecialCarton(carto, jugaQuiniPlus);
        cAciertos = contarAciertos(carto, jugaQuiniPlus);
        entregarPremios(cAciertos, carto);
        system("pause");
    }
    printf("\nSe necesitaron %d intento/s para ganar el premio mayor\n", cIntentos);
}
