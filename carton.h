#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED
#include "jugador.h"

///Cart�n
//Axiomas
/*
1- 'jugada': vector de 8 enteros con n�meros entre 0 y 99 (extremos inclu�dos), sin repetir y ordenados
2- 'fechaEmision': ser� una struct tm con sus atributos definidos por el lenguaje.
3- 'fechaJuego': menos de 50 caracteres que no sean especiales ni con tildes.
4- 'direccionAgencia': menos de 60 caracteres que no sean especiales ni con tildes.
5- 'precio': siempre ser� 70.
6- 'jugador': debe respetar los axiomas de la struct JugadorE.
*/
struct CartonE
{
    int jugada[8];
    struct tm fechaEmision;
    char fechaJuego[50];
    char direccionAgencia[60];
    int precio;
    struct JugadorE jugador;
};

///Comprar
//PRE: tiene que existir un cart�n con un vector de 8 posiciones donde guardar los n�meros aleatorios.
//POST: se guardan 8 n�meros ordenados de menor a mayor sin repetir.
void comprarCartonAutomatico(int carton[8]);
//PRE: tiene que existir un cart�n con un vector de 8 posiciones donde guardar cada n�mero que ingresa el usuario.
//POST: se gurdan 8 n�meros ordenados de menor a mayor sin repetir.
void comprarCartonTeclado(int carton[8]);

///Ordenar
//PRE: tiene que existir un cart�n con un vector de 8 posiciones y estar cargado.
//POST: ordena el contenido del vector de menor a mayor.
void ordenarCarton(int carton[8]);

///Cart�n
//PRE: la direcci�n de la agencia debe cumplir el axioma n� 4 de la struct CartonE.
//POST: crea un cart�n, lo carga y lo retorna.
struct CartonE crearCarton(char direccionAgencia[60]);
//PRE: tiene que existir un cart�n y estar cargado.
//POST: muestra la informaci�n del cart�n y marca los n�meros que se acertaron.
void mostrarEspecialCarton(struct CartonE carton, int jugadaQuiniPlus[20]);

///Fechas
//PRE: tiene que enviarse un puntero a una struct tm.
//POST: carga la struct tm que se env�a con la fecha actual.
void obtenerFechaActual(struct tm* fechaEmision);
//PRE: tiene que existir una struct tm y estar cargada.
//POST: muestra la fecha completa.
void mostrarFecha(struct tm fecha);

///Escribir
//PRE: tiene que existir un cart�n y tener cargados los n�meros.
//POST: guarda los n�meros del cart�n en un archivo separados por el delimitador ';'.
void escribirCarton(struct CartonE carton);

///Verificar
//PRE: tiene que existir un cart�n y la jugada del Quini Plus. Ambos deben tener cargados los n�meros.
//POST: cuenta los aciertos del cart�n con respecto a la jugada del Quini Plus y lo retorna.
int contarAciertos(struct CartonE carton, int jugadaQuiniPlus[20]);
//PRE: El nombre del jugador debe estar cargado.
//POST: asigna premios seg�n la cantidad de aciertos.
void entregarPremios(int cantidadAciertos, struct CartonE carton);

#endif // CARTON_H_INCLUDED
