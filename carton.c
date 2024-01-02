#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "carton.h"
#include "quiniela_plus.h"

///Comprar
void comprarCartonAutomatico(int cart[8])
{
    for (int i = 0; i < 8; i++)
    {
        cart[i] = generarAleatorio(0, 99);
        for (int j = 0; j < i; j++)
        {
            if (cart[i] == cart[j]) //Si alguno de los ya cargados coincide con el nuevo
            {
                i--; //Decremento el iterador del for donde se guarda para reemplazar ese repetido
            }
        }
    }
    ordenarCarton(cart); //Dejo el cartón ordenado de menor a mayor
}

void comprarCartonTeclado(int cart[8])
{
    for (int i = 0; i < 8; i++)
    {
        printf("\nIngrese un entero para la posicion %d: #", i + 1);
        scanf("%d", &cart[i]);
        if ((cart[i] < 0) || (cart[i] > 99)) //El número no es válido
        {
            printf("\nEl numero %d no es valido. Tiene que ser uno entre 0 y 99 (extremos incluidos).", cart[i]);
            i--; //Decremento el iterador for donde se guarda para reemplazar el número inválido
        }
        for (int j = 0; j < i; j++)
        {
            if (cart[i] == cart[j]) //Si alguno de los ya cargados coincide con el nuevo
            {
                printf("\nSe repite el numero %d.", cart[i]);
                i--; //Decremento el iterador for donde se guarda para reemplazar el repetido
            }
        }
    }
    ordenarCarton(cart); //Dejo el cartón ordenado de menor a mayor
}

///Ordenar
void ordenarCarton(int cart[8])
{
    int aux;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            if (cart[j + 1] < cart[j])
            {
                aux = cart[j + 1];
                cart[j + 1] = cart[j];
                cart[j] = aux;
            }
        }
    }
}

///Cartón
struct CartonE crearCarton(char direcAgencia[60])
{
    int opElegida = pedirOpcion();
    printf("\nCreemos el carton...\n");
    struct CartonE cart;
    if (opElegida == 1)
    {
        comprarCartonAutomatico(cart.jugada); //Se generan los números de forma automática
    }
    else if (opElegida == 2)
    {
        comprarCartonTeclado(cart.jugada); //Los números los carga el usuario
    }
    printf("\n");
    obtenerFechaActual(&cart.fechaEmision); //Consigo la fecha actual y se guarda como fecha de emisión del cartón
    printf("Fecha de emision del carton: ");
    mostrarFecha(cart.fechaEmision); //Muestro la fecha de emisión (la actual)
    strcpy(cart.fechaJuego, "El domingo mas proximo a la fecha de emision\n");
    printf("Fecha de juego del Quini Plus en el que participa: ");
    printf(cart.fechaJuego);
    strcpy(cart.direccionAgencia, direcAgencia); //Copio la dirección de la agencia en el cartón
    cart.precio = 70; //Precio del cartón
    printf("\nPrecio del carton: $%d\n", cart.precio);
    cart.jugador = crearJugadorTeclado(); //Incluyo el jugador propietario del cartón con sus datos a éste
    return cart;
};

void mostrarEspecialCarton(struct CartonE cart, int jugQuiniPlus[20])
{
    printf("\nSu carton:\n");
    printf("Fecha de emision: ");
    mostrarFecha(cart.fechaEmision);
    printf("\nDireccion de la agencia: %s\n", cart.direccionAgencia);
    printf("\nNumeros:\n\n");
    for (int i = 0; i < 8; i++)
    {
        int aux = 0; //Bandera para indicar si hubo coincidencia. 1 si hubo y 0 si no hubo.
        for (int j = 0; j < 20; j++)
        {
            if (cart.jugada[i] == jugQuiniPlus[j]) //Si coincide el número del cartón con el número de la jugada del Quini Plus
            {
                printf(" |%d| ", cart.jugada[i]); //Muestra de forma especial
                aux = 1; //Hubo coincidencia
                j = 20; //Sale del bucle
            }
        }
        if (aux == 0) //No coincidió ninguno de los 20
        {
            printf(" %d ", cart.jugada[i]); //Muestra común
        }
    }
    mostrarJugador(cart.jugador);
}

///Fechas
void obtenerFechaActual(struct tm* feEmision)
{
    time_t t = time(NULL);
    *feEmision = *localtime(&t); //Se guarda la fecha actual en la struct envíada como puntero
    feEmision->tm_mon++; //Incremento el mes en uno -Por algo que desconozco lo obtiene con una unidad menos-
    feEmision->tm_year += 1900; //Incremento el año en 1900 -Descubrí que empieza en 1900 el año, pero a lo que es el año le
    //resta 1900, así que se lo vuelvo a sumar-
}


void mostrarFecha(struct tm fe)
{
    //Impresión del día
    if ((fe.tm_mday >= 0) && (fe.tm_mday <= 9)) //Si el día tiene solo un dígito
    {
        printf("0%d/", fe.tm_mday); //Lo imprimo pero con un cero adelante
    }
    else //Si tiene dos dígitos
    {
        printf("%d/", fe.tm_mday); //Lo imprimo normal
    }
    //Impresión del mes
    if ((fe.tm_mon >= 0) && (fe.tm_mon <= 9)) //Si el mes tiene solo un dígito
    {
        printf("0%d/", fe.tm_mon); //Lo imprimo pero con un cero adelante
    }
    else //Si tiene dos dígitos
    {
        printf("%d/", fe.tm_mon); //Lo imprimo normal
    }
    //Impresión del año
    if ((fe.tm_year >= 0) && (fe.tm_year <= 9)) //Si el año tiene solo un dígito
    {
        printf("000%d ", fe.tm_year); //Lo imprimo pero con un cero adelante
    }
    else if ((fe.tm_year >= 10) && (fe.tm_year <= 99)) //Si el año tiene dos dígitos
    {
        printf("00%d ", fe.tm_year); //Lo imprimo pero con dos ceros adelante
    }
    else if ((fe.tm_year >= 100) && (fe.tm_year <= 999)) //Si el año tiene tres dígitos
    {
        printf("0%d ", fe.tm_year); //Lo imprimo pero con tres ceros adelante
    }
    else //Si tiene 4 o más dígitos
    {
        printf("%d ", fe.tm_year); //Lo imprimo normal
    }
    //Impresión de las horas
    if ((fe.tm_hour >= 0) && (fe.tm_hour <= 9)) //Si tiene solo un dígito
    {
        printf("0%d:", fe.tm_hour); //Lo imprimo pero con un cero adelante
    }
    else //Si tiene dos dígitos
    {
        printf("%d:", fe.tm_hour); //Lo imprimo normal
    }
    //Impresión de los minutos
    if ((fe.tm_min >= 0) && (fe.tm_min <= 9)) //Si tiene solo un dígito
    {
        printf("0%d:", fe.tm_min); //Lo imprimo pero con un cero adelante
    }
    else //Si tiene dos dígitos
    {
        printf("%d:", fe.tm_min); //Lo imprimo normal
    }
    //Impresión de los segundos
    if ((fe.tm_sec >= 0) && (fe.tm_sec <= 9)) //Si tiene solo un dígito
    {
        printf("0%d\n", fe.tm_sec); //Lo imprimo pero con un cero adelante
    }
    else //Si tiene dos dígitos
    {
        printf("%d\n", fe.tm_sec); //Lo imprimo normal
    }
}

///Escribir
void escribirCarton(struct CartonE cart)
{
    FILE* archivo = fopen("carton.txt", "a"); //Intento abrir el archivo con la intención de agregar
    if (archivo == NULL) //Si no existe
    {
        archivo = fopen("carton.txt", "w"); //Lo creo y escribo en él por primera vez
    }
    fprintf(archivo, "%d;%d;%d;%d;%d;%d;%d;%d\n", cart.jugada[0], cart.jugada[1], cart.jugada[2], cart.jugada[3], cart.jugada[4], cart.jugada[5], cart.jugada[6], cart.jugada[7]); //Los números del cartón separados por un ';'
    fclose(archivo);
}

///Verificar
int contarAciertos(struct CartonE cart, int juQuiniPlus[20])
{
    int cAciertos = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 20; j++)
        {
            if (cart.jugada[i] == juQuiniPlus[j]) //Si coincide
            {
                cAciertos++; //Sumamos 1 acierto al contador
                j = 20; //Salimos de la comparación
            }
        }
    }
    return cAciertos;
}

void entregarPremios(int cAciertos, struct CartonE cart)
{
    switch(cAciertos)
    {
        case 8: printf("\nTuviste %d aciertos! Felicitaciones %s! Ganaste el Quini Plus! Te llevas $11.000.000!\n", cAciertos, cart.jugador.nombre); break;
        case 7: printf("\nTuviste %d aciertos! Felicitaciones %s! Ganaste $20.000!\n", cAciertos, cart.jugador.nombre); break;
        case 6: printf("\nTuviste %d aciertos! Felicitaciones %s! Ganaste $500!\n", cAciertos, cart.jugador.nombre); break;
        case 5: printf("\nTuviste %d aciertos! Felicitaciones %s! Ganaste $50!\n", cAciertos, cart.jugador.nombre); break;
        default: printf("\nTuviste %d acierto/s! Esta vez no ganaste %s, quizas la proxima.\n", cAciertos, cart.jugador.nombre);
    }
}
