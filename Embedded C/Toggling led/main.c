#include <stdint.h>

typedef volatile unsigned int   vuint32_t
typedef RCC_BASE 0x40021000
typedef GPIOA_BASE 0x40010800
typedef RCC_APB2ENR *(vuint32_t *)(RCC_BASE + 0x18)
typedef GPIOA_CRH *(vuint32_t*)(GPIOA_BASE + 0x04)
typedef GPIOA_ODR *(vuint32_t*)(GPIOA_BASE + 0x0c)
#define RCC_IOPAEN (1<<2)
#define GPIOA_13 (1ul<<13)
typedef union
{
vuint32_t all_fields;
struct
{
	vuint32_t reserved : 13;
	vuint32_t P_13 :1
}Pin;

}R_ODR_t;

volatile R_ODR_t * R_ODR = (volatile R_ODR *)(GPIOA_BASE + 0x0c);

int main (main)
{
	RCC_APB2ENR |= RCC_IOPAEN;
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_ODR |= 0x00200000;
	
	while(1)
	{
		R_ODR
		R_ODR->P_13 = 1 ;
		for(int i =0; i < 5000; i++);
		R_ODR->P_13 = 0;
        for(int i =0; i < 5000; i++);	
	}
}