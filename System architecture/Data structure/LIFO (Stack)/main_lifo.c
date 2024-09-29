#include"LIFO.h"

unsigned int lifo_buf1[5];
#define buffer_length 5
int main()
{
	int i , lifo_pop_var;
	unsigned int*lifo_buf2 = (unsigned int *)malloc(5*sizeof(unsigned int));
	LIFO_buf_t uart_lifo , i2c_lifo;

	// static allocation
	lifo_init(&uart_lifo,lifo_buf1,buffer_length);
	//dynamic allocation
	lifo_init(&i2c_lifo,lifo_buf2,buffer_length);
	for(i = 0 ; i<5 ; i++)
	{
		if((lifo_push(&uart_lifo,i)) == no_error)
			printf("uart buffer(static allocation) pushing : %d\n",i);
	}
	for(i = 0 ; i<5 ; i++)
	{
		if((lifo_pop(&uart_lifo,&lifo_pop_var)) == no_error)
			printf("uart buffer(static allocation) popping : %d\n",lifo_pop_var);
	}
	return 0;
}