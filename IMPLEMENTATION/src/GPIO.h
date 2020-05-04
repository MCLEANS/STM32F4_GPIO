/*
 * GPIO.h
 *
 *  Created on: May 4, 2020
 *      Author: MCLEANS
 */

#ifndef GPIO_H_
#define GPIO_H_

namespace custom_libraries {

enum Mode{
	INPUT,
	OUTPUT
};

enum OUTPUT_Type{
	PUSH_PULL,
	OPEN_DRAIN
};

enum OUTPUT_Speed{
	LOW,
	MEDUIM,
	HIGH,
	VERY_HIGH
};

enum State{
	NO_PULLUP_PULLDOWN,
	PULL_UP,
	PULL_DOWN
};


class _GPIO {
public:
	_GPIO();
	~_GPIO();
};

} /* namespace custom_libraries */

#endif /* GPIO_H_ */
