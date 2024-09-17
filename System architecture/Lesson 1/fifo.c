#include "fifo.h"

E_fifo_status fifo_init(fifo_buf_t * buffer , element_type* buf, length_count_type length)
{
    // initiating fifo buffer
    buffer->base = buf;
    buffer->head = buffer->base;
    buffer->tail = buffer->base;
    buffer->length = length;
    buffer->count = 0;
    if(buffer->base && buffer->length)
    {
        printf("Fifo created!\n");
        return fifo_no_error;
    }
    else
        return fifo_null;
}
E_fifo_status fifo_is_full(fifo_buf_t* buffer)
{
    if(!buffer->base || !buffer->head || !buffer->tail)
        return fifo_null;

    if(buffer->count >= buffer->length)
    {  
        return fifo_full;
    }
    else
        return fifo_no_error;
}

E_fifo_status Enqueue(fifo_buf_t * buffer , element_type* item )
{
    if(!buffer->base || !buffer->head || !buffer->tail)
        return fifo_null;
    
        *(buffer->head) = *item;
    if(fifo_is_full(buffer) == fifo_no_error)
    {
          buffer->count++;

        if(buffer->head == buffer->base + (buffer->length * sizeof(element_type)))
        {
            buffer->head = buffer->base;
        }
        else
            buffer->head++;
        
        return fifo_no_error;
    }
    else
    {
        printf("Enqueue failed!\n");
        return fifo_is_full(buffer);
    }

}
E_fifo_status Dequeue(fifo_buf_t* buffer , element_type* item)
{
    if(!buffer->base || !buffer->head || !buffer->tail)
        return fifo_null;

       if(buffer->count ==0)
    {
        printf("fifo is empty!\n");
        return fifo_empty;
    }
        *item = *(buffer->tail);
        buffer->count--;
        if(buffer->tail == buffer->base + (buffer->length * sizeof(element_type)))
        {
            buffer->tail = buffer->base;
        }
        else
        buffer->tail++;
        
        return fifo_no_error;
    }
   
void fifo_print(fifo_buf_t* buffer)
{
    uint32 i;
    element_type* temp;
    printf("#### Printing fifo content ####\n");
       if(buffer->count ==0)
    {
        printf("#### Fifo is empty #####\n");
        return fifo_empty;
    }
    
    temp = buffer->tail;
        for(i=0 ; i < buffer->count ; i++)
        {
            printf("\t %X\n",*temp);
            temp++;
        }
        printf("#####################\n");
    
}
