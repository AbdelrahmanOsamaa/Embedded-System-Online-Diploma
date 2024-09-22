#include<stdio.h>
#include<stdlib.h>

#ifndef _LIFO_H_
#define _LIFO_H_
/*
Last-in-first-out (Stack) buffer
it's used with data that has the type unsigned int 
*/
typedef struct {

		unsigned int* base;
		unsigned int* head;
		unsigned int length;
		unsigned int count;

}LIFO_buf_t;

typedef enum status
{
	no_error,
	lifo_not_full,
	lifo_full,
	lifo_empty,
	lifo_not_empty,
	lifo_NULL

}Buffer_status;

Buffer_status lifo_init(LIFO_buf_t* lifo_buffer, unsigned int* buffer , unsigned int length);
Buffer_status lifo_push(LIFO_buf_t* lifo_buffer, unsigned int item);
Buffer_status lifo_pop(LIFO_buf_t* lifo_buffer, unsigned int* item);

#endif