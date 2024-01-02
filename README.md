# Descripción del programa
Este sistema consiste en un **simulador por consola desarrollado íntegramente en C de un juego de azar denominado Quini Plus**.

## Reglamento
- El jugador compra un **cartón de 8 números entre 0 y 99 (ambos inclusive), sin repetir y ordenados de menor a mayor**.
- En la **jugada** salen **20 números del 0 al 99 (ambos inclusive), que pueden repetirse y están ordenados de menor a mayor**.
- Premios:
  - En caso de tener **8 aciertos**, al jugador le corresponden **$11.000.000**.
  - En caso de tener **7 aciertos**, al jugador le corresponden **$20.000**.
  - En caso de tener **6 aciertos**, al jugador le corresponden **$500**.
  - En caso de tener **5 aciertos**, al jugador le corresponden **$50**.

## Funcionalidades
- Permite elegir si la **selección de los números del cartón** debe ser **en forma manual o automática**.
- El cartón es una struct que tiene como atributos los números, la fecha y hora al momento de la compra y el jugador asociado, entre otras.
- El jugador también es una struct que tiene nombre y dni.
- Capacidad de generar la jugada de los 20 números.
- Contar los aciertos.
- Entregar premios correspondientes según la cantidad de aciertos.
- Mostrar la jugada ganadora y el cartón comprado, marcando entre | | los números del cartón que coincidan con la jugada.
- Escribir los números del cartón comprado en un archivo .txt.
- Repetir las jugadas hasta que con el cartón comprado se tengan 8 aciertos y se gane el premio mayor. Luego, informa cuántas jugadas fueron necesarias para lograrlo.

*Gracias por interesarte en visitar este repositorio y leer acerca de él*.

¡Saludos!

Maximiliano Calahorra.
