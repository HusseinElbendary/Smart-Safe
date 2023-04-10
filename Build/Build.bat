avr-gcc -Wall -g -os -mmcu=atmega32 -o main.bin ../main.c ../Src/DIO.c ../Src/Keypad.c ../Src/Delay.c ../Src/LCD.c
avr-objcopy -j .text -j .data -O ihex main.bin main.hex
PAUSE