#include "uart.h"

#define UART0DR *((volatile unsigned int*const) ((unsigned int)0x101f1000))

void Uart_Send_str(unsigned char *Str_Puffer)
{
    while(*Str_Puffer != '\0')
    {
        UART0DR = (unsigned int)(*Str_Puffer);
        Str_Puffer++;
    }
}