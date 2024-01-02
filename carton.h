#ifndef CARTON_H_INCLUDED
#define CARTON_H_INCLUDED
#include "jugador.h"

///Cartón
//Axiomas
/*
1- 'jugada': vector de 8 enteros con números entre 0 y 99 (extremos incluídos), sin repetir y ordenados
2- 'fechaEmision': será una struct tm con sus atributos definidos por el lenguaje.
3- 'fechaJuego': menos de 50 caracteres que no sean especiales ni con tildes.
4- 'direccionAgencia': menos de 60 caracteres que no sean especiales ni con tildes.
5- 'precio': siempre será 70.
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
//PRE: tiene que existir un cartón con un vector de 8 posiciones donde guardar los números aleatorios.
//POST: se guardan 8 números ordenados de menor a mayor sin repetir.
void comprarCartonAutomatico(int carton[8]);
//PRE: tiene que existir un cartón con un vector de 8 posiciones donde guardar cada número que ingresa el usuario.
//POST: se gurdan 8 números ordenados de menor a mayor sin repetir.
void comprarCartonTeclado(int carton[8]);

///Ordenar
//PRE: tiene que existir un cartón con un vector de 8 posiciones y estar cargado.
//POST: ordena el contenido del vector de menor a mayor.
void ordenarCarton(int carton[8]);

///Cartón
//PRE: la dirección de la agencia debe cumplir el axioma nº 4 de la struct CartonE.
//POST: crea un cartón, lo carga y lo retorna.
struct CartonE crearCarton(char direccionAgencia[60]);
//PRE: tiene que existir un cartón y estar cargado.
//POST: muestra la información del cartón y marca los números que se acertaron.
void mostrarEspecialCarton(struct CartonE carton, int jugadaQuiniPlus[20]);

///Fechas
//PRE: tiene que enviarse un puntero a una struct tm.
//POST: carga la struct tm que se envía con la fecha actual.
void obtenerFechaActual(struct tm* fechaEmision);
//PRE: tiene que existir una struct tm y estar cargada.
//POST: muestra la fecha completa.
void mostrarFecha(struct tm fecha);

///Escribir
//PRE: tiene que existir un cartón y tener cargados los números.
//POST: guarda los números del cartón en un archivo separados por el delimitador ';'.
void escribirCarton(struct CartonE carton);

///Verificar
//PRE: tiene que existir un cartón y la jugada del Quini Plus. Ambos deben tener cargados los números.
//POST: cuenta los aciertos del cartón con respecto a la jugada del Quini Plus y lo retorna.
int contarAciertos(struct CartonE carton, int jugadaQuiniPlus[20]);
//PRE: El nombre del jugador debe estar cargado.
//POST: asigna premios según la cantidad de aciertos.
void entregarPremios(int cantidadAciertos, struct CartonE carton);

#endif // CARTON_H_INCLUDED
