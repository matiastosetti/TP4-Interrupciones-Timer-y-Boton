#ifndef _BSP_H
#define _BSP_H



void bsp_delayMS(uint16_t x); //prototipo funci�n
/**
 * @brief Prende un led
 *
 * @param led Led a prender
 */
void led_on(uint8_t led);

/**
 * @brief Apaga un led
 *
 * @param led Led a apagar
 */
void led_off(uint8_t led);

/**
 * @brief Conmuta un led
 *
 * @param led Led a apagar
 */
void led_toggle(uint8_t led);

/**
 * @brief Delay por software
 */
/**
 * @brief conmuta un led
 *
 * @param led Led a apagar
 */
void led_toggle(uint8_t led);


uint8_t sw_getState();

/**
 * @brief Inicializacion de los servicios de BSP
 */
void bsp_init();

/**
 * @brief Delay de x ms
 */
void bsp_delayMs(uint16_t x);

#endif
