# TP1

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
### Antes del main
1. Empezamos el código definiendo cada `MACRO` para cada botón por ej: 
### Como definí la macro para los botones 
``` C
#define bot1 ((PIND >> 4) & 0x01)
#define bot2 ((PIND >> 5) & 0x01)
#define bot3 ((PIND >> 6) & 0x01)
#define bot4 ((PIND >> 7) & 0x01)
```  
2. después de definir cada botón, empezamos a hacer `MACROS` para los **<span style="color:red">LEDS</span>** en mí caso yo hice un macro general para todos los leds ej:
### Macro general de los **<span style="color:red">LEDS</span>**
``` C
#define SET_PIN(PORT,PIN) (PORT|= 1<<PIN)
#define CLEAR_PIN(PORT,PIN) (PORT&=~(1<<PIN))
 ```
 cuando ya terminamos de definir cada variable empezamos a escribir el codigo dentro del `"main"`

 3. Dentro del main comenzamos a setear cada `PIN` como entrada y como salida dependiendo del el pin en el que se encuentren los **<span style="color:red">LEDS</span>** y los `BOTONES`, *como los pines de los botones y leds son consecutivos definimos cada salida y cada entrada de forma general.
 ### Como declaré los pines
``` C
DDRD &=0x0f;
DDRB |=0x0f;
``` 
4. Ahora empezamos escribiendo el **<span style="color:lightblue">While</span>** con intencion de que se `repita` el codigo cuando termine de ejecutarse todo y dentro de él vamos a hacer una pregunta <span style="color:lightgreen">-"Si el botón 1 está accionado encender el led numero 1 y si no mantenerlo apagado"</span> así con todos los botones.
### Uso del **<span style="background-image: linear-gradient(45deg, #020024 0%, #090979 35%, #00d4ff 100%); border-radius:5px">"If"</span>** y **<span style="color:orange">"else"</span>** Dentro del While 
``` C
  while (1){
    
    if (bot1 != 1){
      SET_PIN(PORTB,0);
    }
    else{
      CLEAR_PIN(PORTB,0);
    }
    if (bot2 != 1){
      SET_PIN(PORTB, 1);
    }
    else{
      CLEAR_PIN(PORTB,1);
    }
    if (bot3 != 1){
      SET_PIN(PORTB, 2);
    }
    else{
      CLEAR_PIN(PORTB,2);
    }
    if (bot4 != 1){
      SET_PIN(PORTB, 3);
  
    }
    else{
      CLEAR_PIN(PORTB,3);
    }
  }
```
# Diagrama de Flujo
![Diagrama de Flujo](Diagrama_TP1.svg "Diagrama")

