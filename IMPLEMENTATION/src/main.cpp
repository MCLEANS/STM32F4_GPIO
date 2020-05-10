/**
  ******************************************************************************
  * @file    main.c
  * @author  Ac6
  * @version V1.0
  * @date    01-December-2013
  * @brief   Default main function.
  ******************************************************************************
*/


#include "stm32f4xx.h"
#include "clockconfig.h"
#include "GPIO.h"

#define LED_PIN 7
#define BUTTON_PIN 3

custom_libraries::clock_config system_clock;
custom_libraries::_GPIO LED(GPIOA,LED_PIN);
custom_libraries::_GPIO BUTTON(GPIOE,BUTTON_PIN);
			

int main(void)
{

	system_clock.initialize();
	LED.pin_mode(custom_libraries::OUTPUT);
	LED.output_settings(custom_libraries::PUSH_PULL,custom_libraries::HIGH);

	BUTTON.pin_mode(custom_libraries::INPUT);
	BUTTON.input_state(custom_libraries::PULL_UP);


	while(1){

		if(!BUTTON.digital_read()){
			LED.digital_write(0);
		}
		else{
			LED.digital_write(1);
		}

	}
}
