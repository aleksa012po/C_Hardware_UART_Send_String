/*
 * C_Hardware_UART.c
 *
 * Created: 5.12.2022. 09:50:57
 * Author : Aleksandar Bogdanovic
 */
 // Arduino Asembler, Hardverski UART, Half Duplex
 
 
#define  F_CPU 16000000				// 16MHz
#define BAUD 9600
#define UBRRN ((F_CPU/16/BAUD) - 1)
#define TX_BUFFER_SIZE 256

#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>


char serialBuffer [TX_BUFFER_SIZE];
uint8_t serialReadPos = 0;
uint8_t serialWritePos = 0;

void appendSerial(char c);
void serialWrite(char c[]);

void transmitInit() {
	UBRR0H = 0;
	UBRR0L = UBRRN;
	
	UCSR0B |= (1 << TXEN0) | (1 << TXCIE0);
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00);
	
	sei();
}

int main(void)
{
    transmitInit();
	
	serialWrite("Serial communication initializing.");
	_delay_ms(1000);
	serialWrite(".");
	_delay_ms(1000);
	serialWrite(".\n\r");
	_delay_ms(1000);
	serialWrite("Moje ime je: \n\r");
	_delay_ms(1500);
	serialWrite("Aleksandar\n\r");
	_delay_ms(1500);
	serialWrite("Bogdanovic\n\r");
	_delay_ms(1500);
	serialWrite("A ovo je projekat za: \n\r");
	_delay_ms(1500);
	serialWrite("Hardverski\n\r");
	_delay_ms(1500);
	serialWrite("UART\n\r");
	_delay_ms(1500);
	serialWrite("...\n\r");
	_delay_ms(1500);
	serialWrite("KRAJ!\n\r");
	_delay_ms(1500);
	
    while (1) 
    {
		// Loop
    }
}

void appendSerial(char c) {
	serialBuffer[serialWritePos] = c;
	serialWritePos++;
	
	if(serialWritePos >= TX_BUFFER_SIZE) {
		serialWritePos = 0;
	}
}

void serialWrite(char c[]) {
	
	for(uint8_t i = 0; i < strlen(c); i++) {
		appendSerial(c[i]);
	}
	if(UCSR0A & (1 << UDRE0)) {
		UDR0 = 0;
	}
}

ISR(USART_TX_vect) {
	if(serialReadPos != serialWritePos) {				// if this NOT EQUAL that
			UDR0 = serialBuffer[serialReadPos];
			serialReadPos++;
			
			if(serialReadPos >= TX_BUFFER_SIZE) {
				serialReadPos++;
			}
		}			
}