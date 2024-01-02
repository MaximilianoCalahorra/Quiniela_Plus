#ifndef QUINIELA_PLUS_H_INCLUDED
#define QUINIELA_PLUS_H_INCLUDED

///Aleatorios
//PRE: el m�nimo que se env�e por par�metro tiene que ser menor al m�ximo que se env�e.
//POST: devuelve un entero entre el m�nimo y el m�ximo. Ambos extremos est�n inclu�dos.
int generarAleatorio(int minimo, int maximo);

///Opci�n
//PRE: ninguna.
//POST: devuelve la opci�n elegida por el usuario.
int pedirOpcion();

///Jugada Quini Plus
//PRE: tiene que existir un vector de 20 posiciones donde guardar cada n�mero de la jugada ganadora.
//POST: carga cada posici�n de la jugada con un entero aleatorio entre 0 y 99 (extremos inclu�dos).
void crearJugadaQuiniPlus(int jugadaQuiniPlus[20]);
//PRE: tiene que existir un vector de 20 posiciones y estar cargado.
//POST: ordena los n�meros de la jugada de menor a mayor.
void ordenarJugadaQuiniPlus(int jugadaQuiniPlus[20]);
//PRE: tiene que existir un vector de 20 posiciones y estar cargado.
//POST: muestra el contenido de cada posici�n de la jugada ganadora.
void mostrarJugadaQuiniPlus(int jugadaQuiniPlus[20]);

///Repetir
//PRE: ninguna.
//POST: el juego se repite mientras no se gane el premio mayor. Una vez conseguido, se informa en cu�ntos intentos se logr�.
void repetirJuego();

#endif // QUINIELA_PLUS_H_INCLUDED
