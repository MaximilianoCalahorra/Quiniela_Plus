#ifndef JUGADOR_H_INCLUDED
#define JUGADOR_H_INCLUDED

///Jugador
//Axiomas
/*
1- 'nombre': menos de 50 caracteres que no sean especiales ni con tildes.
2- 'dni': entero de 7 u 8 dígitos.
*/
struct JugadorE
{
    char nombre[50];
    int dni;
};

///Jugador
//PRE: los datos que ingresa el usuario deben respetar los axiomas de la struct JugadorE.
//POST: crea un jugador y lo carga con los datos que ingresa el usuario.
struct JugadorE crearJugadorTeclado();
//PRE: tiene que existir un jugador y estar cargado.
//POST: muestra la información del jugador.
void mostrarJugador(struct JugadorE jugador);

#endif // JUGADOR_H_INCLUDED
