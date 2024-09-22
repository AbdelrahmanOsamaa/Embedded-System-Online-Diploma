#include"LIFO.h"

Buffer_status lifo_init(LIFO_buf_t* lifo_buffer,unsigned int* buffer , unsigned int length)
{ 
	if(buffer == NULL)
		return lifo_NULL;
	lifo_buffer->base = buffer;
    lifo_buffer->head = buffer;
    lifo_buffer->length = length;
    lifo_buffer->count = 0;
    return no_error ;
}

Buffer_status lifo_push(LIFO_buf_t* lifo_buffer,unsigned int item)
{
	// checking if the lifo is intialized properly
	if(lifo_buffer->base == NULL || lifo_buffer->head == NULL)
		return lifo_NULL;
	// checking if the lifo is full
	if(lifo_buffer->count == lifo_buffer->length)
		return lifo_full;
	*(lifo_buffer->head) = item;
    lifo_buffer->head++;
    lifo_buffer->count++;
    return no_error;
}

Buffer_status lifo_pop(LIFO_buf_t* lifo_buffer,unsigned int* item)
{
	// checking if the lifo is intialized properly
	if(lifo_buffer->base == NULL || lifo_buffer->head == NULL)
		return lifo_NULL;
	// checking if the lifo is empty
	if(lifo_buffer->count == 0)
		return lifo_empty;
	lifo_buffer->head--;
	*item =*(lifo_buffer->head);
	lifo_buffer->count--;
	return no_error;
}