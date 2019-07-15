#include "stm32f4xx.h"

//first program to toggle LED connected to PA5 of stm32f446RE
void delayMs(int n);

int main(void) {
		RCC -> AHB1ENR |= 1;			//enable clock
	GPIOA -> MODER &= ~0xC00;		//clear & set mode bits
	GPIOA -> MODER |=  0x400;		//now GPIO
	while (1) {
	GPIOA -> ODR	 |=  0x20;		//write HIGH, LED is on
	delayMs(1000000);							//keeps LED on for set time
	GPIOA -> ODR   &= ~0x20;		//turns off LED
	delayMs(1000000);							//keeps LED off for same amount of time
	}
}

void delayMs(int n) {
	for (int i = n; i > 0; i--);
}
