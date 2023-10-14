#include <stdint.h>
typedef volatile unsigned int vuint32_t;
#define RCC_BASE 0x40021000
#define GPIOA_BASE 0x40010800
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)
#define GPIO_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIO_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0c)
#define RCC_IOPAEN (1 << 2)
#define GPIOA13 (1UL << 13)

typedef union
{
    vuint32_t all_fields;
    struct
    {
        vuint32_t reserved : 13;
        vuint32_t P_13 : 1;
    } Pin;
} R_ODR_t;

volatile R_ODR_t *R_ODR = (volatile R_ODR_t *)(GPIOA_BASE + 0x0C);

uint32_t arr[3]={5,5,8};
unsigned char const Const_var;

int main(void)
{

    int i;
    RCC_APB2ENR |= RCC_IOPAEN;
    GPIO_CRH &= 0xFF0FFFFF;
    GPIO_CRH |= 0x00200000;

    while (1)
    {
        R_ODR->Pin.P_13 = 1;
        // Delay Loop
        for (i = 0; i < 8000; i++);
        R_ODR->Pin.P_13 = 0;
        // Delay Loop
        for (i = 0; i < 8000; i++);
    }

    return 0;
}