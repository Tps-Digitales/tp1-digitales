# TP1

# IMPORTANTE: En este archivo escribir el informe  

## Uso de puertos de entrada y salida. 

Utilizando un Arduino Nano (`atmega328p`), `4 LEDs` y `4 Pulsadores` se pide:

1. Mediante el uso de un `pulsador` controle el estado de un `LED` de manera que si el pulsador elegido esta presionado entonces el LED elegido debe de estar encendido. De manera extensiva si el pulsador elegido NO esta presionado entonces el LED elegido debe de estar apagado. 

2.  Hacer extensivo el funcionamiento a los cuatro pulsadores, de manera que se controlen a los cuatro LEDs mediante los cuatro PULSADORES. 

> Nota: Todos los pulsadores `deben` tener habilitada la resistencia de `pull-up`

> Asi mismo los LEDs deben conectarse con su resistencia limitadora de corriente 2 asegurando no superar la corriente máxima que puede entregar el pin. Almenos de 330 Ohms


## ¡USAR LOS PINES INDICADOS NO CAMBIARLOS!

``` C
PD4 -> BOTON 1 
PD5 -> BOTON 2 
PD6 -> BOTON 3 
PD7 -> BOTON 4


PB0 -> LED 1 
PB1 -> LED 2 
PB2 -> LED 3 
PB3 -> LED 4
```


# INFORME:

Al comienzo de todo codigo de programacion se debe de definir las `MACROS` utilizando:

```C
#define bot1 ((PIND >> 4) & 0x01)
#define bot2 ((PIND >> 5) & 0x01)
#define bot3 ((PIND >> 6) & 0x01)
#define bot4 ((PIND >> 7) & 0x01)

#define prender(PORT, PIN) (PORT |= 1 << PIN)
#define apagar(PORT, PIN) (PORT &= 1 << PIN)
```
##  Entradas y salidas 

Ahora se definiran las entradas y salidas lo cual sirven para administrar el orden del codigo y se codificaria de la siguiente manera:

```C
DDRD &= ~(1 << PD4);
DDRD &= ~(1 << PD5);
DDRD &= ~(1 << PD6);
DDRD &= ~(1 << PD7);

DDRB |= (1 << PB0);
DDRB |= (1 << PB1);
DDRB |= (1 << PB2);
DDRB |= (1 << PB3);
```
## Codigo principal

```C
while (1)
    {
        if (bot1 != 1)
        {
            prender(PORTB, 0);
        }
        else
        {
            apagar(PORTB, 0);
        }
        if (bot2 != 1)
        {

            prender(PORTB, 1);
        }
        else
        {
            apagar(PORTB, 1);
        }
        if (bot3 != 1)
        {
            prender(PORTB, 2);
        }
        else{
            apagar(PORTB, 2);
        }
        if (bot4 != 1)
        {
            prender(PORTB, 3); 
        }
        else{
            apagar(PORTB, 3);
        }

    }
}
```
Bien este mismo es el codigo que nos va a permitir encender y apagar los LEDs a nuestro gusto. Como pueden observar utilizamos un `While` para ejecutar nuestro codigo de forma correcta, luego utilizamos un `if` ya que la primer condición del while se cumplió. a partir de ahora se esta ejecutando nuestro codigo, los `else`se refieren a que si no esta ocurriendo el `if`se mantiene activo.

## Diagrama de Flujo

Por ultimo tenemos el Diagrama de Flujo el cual explica el codigo de una forma mas simplificada.
