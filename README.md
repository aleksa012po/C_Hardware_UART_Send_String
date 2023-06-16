# C_Hardware_UART_Send_String

This project demonstrates the implementation of hardware UART communication on an Atmel AVR microcontroller. 
It showcases a half-duplex serial communication channel, allowing bidirectional data transmission and reception.

Features
- Reliable hardware UART communication
- Supports baud rate of 9600
- Sending characters in a string via UART
- Utilizes AVR interrupts for efficient data handling
- 
Getting Started
- Prerequisites
- Atmel AVR microcontroller
- AVR development board or programmer
- AVR-GCC toolchain
- 
Installation
1. Clone the repository: git clone https://github.com/username/C_Hardware_UART.git
2. Compile the code using the AVR-GCC toolchain: avr-gcc -mmcu=your_microcontroller -Os C_Hardware_UART.c -o C_Hardware_UART.elf
3. Flash the generated binary onto your AVR microcontroller: avrdude -c your_programmer -p your_microcontroller -U flash:w:C_Hardware_UART.elf

Usage
1. Connect your AVR development board or programmer to the microcontroller.
2. Configure the baud rate in the code to match your requirements (default baud rate 9600 but you can change that).
3. Build and flash the code onto the microcontroller.
4. Monitor the serial output using a terminal program at the specified baud rate.

Contributing
Contributions to this project are welcome. Feel free to open issues and submit pull requests.

License
This project is licensed under the MIT License.

Acknowledgments
Special thanks to Aleksandar Bogdanovic for creating and sharing this project.
