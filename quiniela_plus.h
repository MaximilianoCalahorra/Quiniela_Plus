#ifndef QUINIELA_PLUS_H_INCLUDED
#define QUINIELA_PLUS_H_INCLUDED

///Aleatorios
//PRE: el mínimo que se envíe por parámetro tiene que ser menor al máximo que se envíe.
//POST: devuelve un entero entre el mínimo y el máximo. Ambos extremos están incluídos.
int generarAleatorio(int minimo, int maximo);

///Opción
//PRE: ninguna.
//POST: devuelve la opción elegida por el usuario.
int pedirOpcion();

///Jugada Quini Plus
//PRE: tiene que existir un vector de 20 posiciones donde guardar cada número de la jugada ganadora.
//POST: carga cada posición de la jugada con un entero aleatorio entre 0 y 99 (extremos incluídos).
void crearJugadaQuiniPlus(int jugadaQuiniPlus[20]);
//PRE: tiene que existir un vector de 20 posiciones y estar cargado.
//POST: ordena los números de la jugada de menor a mayor.
void ordenarJugadaQuiniPlus(int jugadaQuiniPlus[20]);
//PRE: tiene que existir un vector de 20 posiciones y estar cargado.
//POST: muestra el contenido de cada posición de la jugada ganadora.
void mostrarJugadaQuiniPlus(int jugadaQuiniPlus[20]);

///Repetir
//PRE: ninguna.
//POST: el juego se repite mientras no se gane el premio mayor. Una vez conseguido, se informa en cuántos intentos se logró.
void repetirJuego();

#endif // QUINIELA_PLUS_H_INCLUDED
