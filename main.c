#include <stdint.h>
#include "bsp/bsp.h"

/**
 * @brief Delay por software
 *
 * @param nCount Numero de ciclos del delay
 */
void Delay(volatile uint32_t nCount);

/**
 * @brief Se encarga de prender un led y apagarlo luego de un tiempo
 *
 * @param led    Numero de led a pulsar
 * @param tiempo Numero de ciclos del delay entre prendido y apagado
 */
void pulsoLed(uint8_t led, uint32_t tiempo);

/**
 * @brief Aplicacion principal
 */
void APP_ISR_sw(void) { //Interrupcion switch
//	led_toggle(0); se comenta para que no haga dos cosas ya que abajo lo usamos
	led_toggle(1);
	led_toggle(2);
	led_toggle(3);

}
void APP_ISR_1ms(void) { //esta función es lo que se ejecutará cuando salte la interrupción de 1ms del timer
	static uint16_t count_1s = 0;

	//contador de milisegundos
	if (count_1s++ > 1000) { //incrementa de a 1 y hasta que no sea mayor a 1000
		//no se ejecuta lo de adentro.
		//GPIO_ToggleBits(leds_port[0], leds[0]); //toglea un pin (Led1) del puerto D. Como ahora estamos en la app. no podemos manejar pines. COmo ya creamos una función. la invocamos abajo.
		led_toggle(0);
		count_1s = 0; //resetea el count_1s a cero.
		//Este if se trajo de la interrupción a la aplicción dejando que la interrupción simplemente se fije si debe llamar a esta función donde ahora está el if.
	}

	int main(void) { //sólo se inicializa hardware y no hace nada el bucle while y todo lo que hace depende de la interrupción que llaman a funciones implementadas en el main.c. Si esas funciones fueran de extenso código, comoanalizar la trama, en la interrupción cuento el tiempo en el que debería preguntar si debo analizar la trama y si debo recogerla para guardar el dato (el concepto es hacer lo minimo posible) y en el main.c analizo la trama.
		bsp_init();

		while (1) {

		}
	}

	void pulsoLed(uint8_t led, uint32_t tiempo) {
		led_on(led);
		Delay(tiempo);
		led_off(led);
	}

	void Delay(volatile uint32_t nCount) {
		while (nCount--) {
		}
	}
}
