#include"fifo.h"

element_type buffer[5];
void main()
{
    uint32 i ,temp = 0;
    fifo_buf_t uart_buffer;
    fifo_init(&uart_buffer,buffer,5);


    for(i = 0 ; i <7 ; i++)
    {
        // printf("##### Count : %X\n",uart_buffer.count);
        printf("Enqueue (%X) \n",i);
        if(Enqueue(&uart_buffer,&i) == fifo_no_error)
            printf("Enqueue (%X)---> DONE! \n",i);
        else
            printf("Enqueue (%X)---> FAILED! \n",i);
    }
    fifo_print(&uart_buffer);

    Dequeue(&uart_buffer,&temp);
    printf("###### Fifo Dequeue (%X) #######\n",temp);
    Dequeue(&uart_buffer,&temp);
    printf("###### Fifo Dequeue (%X) #######\n",temp);
    fifo_print(&uart_buffer);
}