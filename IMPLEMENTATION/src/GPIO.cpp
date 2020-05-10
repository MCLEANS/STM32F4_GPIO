/*
 * GPIO.cpp
 *
 *  Created on: May 4, 2020
 *      Author: MCLEANS
 */

#include "GPIO.h"

namespace custom_libraries {

_GPIO::_GPIO(GPIO_TypeDef *GPIO,uint8_t PIN):GPIO(GPIO),
											PIN(PIN),
											mode(0),
											type(0),
											speed(0),
											state(0){
	// TODO Auto-generated constructor stub
	//Enable GPIO RCC
	if(GPIO == GPIOA) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	if(GPIO == GPIOB) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOBEN;
	if(GPIO == GPIOC) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOCEN;
	if(GPIO == GPIOD) RCC->AHB1ENR |= RCC_AHB1ENR_GPIODEN;
	if(GPIO == GPIOE) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOEEN;
	if(GPIO == GPIOF) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOFEN;
	if(GPIO == GPIOG) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOGEN;
	if(GPIO == GPIOH) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOHEN;
	if(GPIO == GPIOI) RCC->AHB1ENR |= RCC_AHB1ENR_GPIOIEN;

}

void _GPIO::pin_mode(Mode mode){
	if(mode == INPUT){
		GPIO->MODER &= ~(1<<(PIN*2));
		GPIO->MODER &= ~(1<<((PIN*2)+1));
	}
	else if(mode == OUTPUT){
		GPIO->MODER |= (1<<(PIN*2));
		GPIO->MODER &= ~(1<<((PIN*2)+1));
	}
}

void _GPIO::output_settings(OUTPUT_Type type, OUTPUT_Speed speed){
	if(type == OPEN_DRAIN){
		GPIO->OTYPER |= (1<<PIN);
	}
	else if(type == PUSH_PULL){
		GPIO->OTYPER &= ~(1<<PIN);
	}

}

_GPIO::~_GPIO() {
	// TODO Auto-generated destructor stub
}

} /* namespace custom_libraries */
