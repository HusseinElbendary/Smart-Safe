avr-gcc -Wall -g -os -mmcu=atmega32 -o main.bin ../main.c ../Src/DIO.c
avr-objcopy -j .text -j .data -O ihex main.bin main.hex
PAUSE