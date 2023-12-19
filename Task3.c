/*
 * GccApplication1.c
 *
 * Created: 16-11-2023 17:57:11
 * Author : Atiq
 

 OCR1 Calculation
 ------------------------
 OCR1 = (Dutycycle/100)*40000
 2.5% - 12.5% Duty Cycle
 For -90 deg, OCR0 = 1000
 For -45 deg, OCR0 = 2000
 For   0 deg, OCR0 = 3000
 For  45 deg, OCR0 = 4000
 For  90 deg, OCR0 = 5000
 */

 #define F_CPU 1000000UL

 #include <avr/io.h>			//Library for using the inputs and outputs in atmega
 #include <util/delay.h>		//Software Delay

 


 int main(){
 
 DDRB |= 1 << PINB1;		//Initialise Pin 9 as Output
 
 /* 1. Set Fast PWM mode 14: WGM11, WGM12, WGM13 to 1*/
 /* 2. Set pre-scale of 8 */
 /* 3. Set Fast PWM non-inverting mode */

 TCCR1A |= (1 << WGM11) | (1 << COM1A1);
 TCCR1B |= (1 << WGM13) | (1 << WGM12) |(1 << CS11);
 
 int delay = 10000;		//Short Delay between angles
 
 /* 4. Set ICR1: ICR1 is the top defining PWM period */
 ICR1 = 40000;
 while(1) {
 OCR1A = 1000;		//-90
 _delay_ms(delay);
 OCR1A = 2000;		//-45
 _delay_ms(delay);
 OCR1A = 3000;		//0
 _delay_ms(delay);
 OCR1A = 4000;		//45
 _delay_ms(delay);
 OCR1A = 5000;		//90
 _delay_ms(delay);
 OCR1A = 4000;		//45
 _delay_ms(delay);
 OCR1A = 3000;		//0
 _delay_ms(delay);
 OCR1A = 2000;		//-45
 _delay_ms(delay);
 
 }
 return 0;
 }
