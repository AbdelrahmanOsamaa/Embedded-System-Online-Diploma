
#ifndef FIFO_H
#define FIFO_H
#include <stdio.h>
#include"Platform_types.h"

// User configuration
#define element_type uint8
#define length_count_type uint32
// #define length 5;

typedef struct{
    element_type* base;
    element_type* tail;
    element_type* head;
    length_count_type length ;
    length_count_type count ;
}fifo_buf_t;

typedef enum
{
    fifo_no_error,
    fifo_full,
    fifo_empty,
    fifo_null
}E_fifo_status;

E_fifo_status fifo_init(fifo_buf_t * buffer , element_type* buf, length_count_type length);
E_fifo_status Enqueue(fifo_buf_t * buffer , element_type* item );
E_fifo_status Dequeue(fifo_buf_t* buffer , element_type* item);
E_fifo_status fifo_is_full(fifo_buf_t* buffer);
void fifo_print(fifo_buf_t* buffer);


#endif
