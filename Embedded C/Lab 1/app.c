#include "uart.h"
unsigned char String_puffer[100] = "Learn-in-depth: Abdelrahman osama";


int main(void)
{
    Uart_Send_str(String_puffer);
}