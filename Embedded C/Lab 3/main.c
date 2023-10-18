#define SYSCTL_RCGC2_R (*((volatile unsigned long *)0x400FE108))
#define GPIO_PORTF_DIR (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_DATA_R (*((volatile unsigned long *)0x400253FC))
#define GPIO_PORTF_EN (*((volatile unsigned long *)0x4002551C))

int main (void)
{
	volatile unsigned long delay ;
	SYSCTL_RCGC2_R = 0x00000020 ; // Enabling GPIO 
	for(delay = 0 ; delay < 300 ; delay++);
	GPIO_PORTF_DIR |= 1 << 3 ; // Sitting direction of Port F pin 3 ( input , output )
	GPIO_PORTF_EN |= 1 << 3 ; // sitting pin 3  
	
	while(1)
	{
		GPIO_PORTF_DATA_R |= 1 << 3 ;
		for(delay  = 0 ; delay  < 15000 ;delay++);
		GPIO_PORTF_DATA_R &= ~ (1 << 3) ;
		for(delay  = 0 ; delay  < 15000 ; delay++);
	}
	
	return 0;
}