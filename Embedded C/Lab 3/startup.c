// Learn-in-depth
//Abdelrahman osama

#include <stdint.h>
extern int main(void);
void Rest_Handler(void);

void Default_Handler()
{
	Rest_Handler();
}

void NMI_Handler(void) __attribute__((weak,alias("Default_Handler")));
void H_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));
void MM_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));
void Bus_Fault(void)__attribute__((weak,alias("Default_Handler")));
void Usage_Fault_Handler(void)__attribute__((weak,alias("Default_Handler")));

extern uint32_t _E_text ;
extern uint32_t _S_DATA ;
extern uint32_t _E_DATA ;
extern uint32_t _S_bss ;
extern uint32_t _E_bss ;
/* to create stack in this startup.c without using it as a simpol in linker script
assume it has size of 1024 byte as an array and it's uninitialized so it will appear on .bss section */
static unsigned long Stack_top[256]; // static to limit the scope of this variable to this file only 


void (* p_fn_vectors[])()__attribute__((section(".vectors")))=
{
	(void(*)()) ((unsigned long)Stack_top + sizeof(Stack_top)), // casting to avoid the warning even though it has same size
	 &Rest_Handler, // no need to cast beacuse it's already has the same type (function take nothing and return void ) 
	 &NMI_Handler, // no need to cast beacuse it's already has the same type (function take nothing and return void )
	 &H_Fault_Handler, // no need to cast beacuse it's already has the same type (function take nothing and return void )
	 &MM_Fault_Handler, // no need to cast beacuse it's already has the same type (function take nothing and return void )
	 &Bus_Fault, // no need to cast beacuse it's already has the same type (function take nothing and return void )
	 &Usage_Fault_Handler // no need to cast beacuse it's already has the same type (function take nothing and return void )
};

void Rest_Handler(void)
{
	int i ;
	// copy data from ROM to RAM
	uint32_t Data_size = (unsigned char *) &_E_DATA - (unsigned char *)& _S_DATA ;
	unsigned char *p_source = (unsigned char *) &_E_text ;
	unsigned char *p_dst = (unsigned char *) &_S_DATA ;
	for(i = 0 ;i > Data_size; i++)
	{
		*((unsigned char *)p_source ++) = *((unsigned char *)p_dst ++);
	}
	
	// intializing .bss section with zeros in RAM
	
	uint32_t Bss_size = (unsigned char *) &_E_bss - (unsigned char *) &_S_bss ;
	p_dst = (unsigned char *) &_S_bss ;
	for(i = 0 ;i > Bss_size; i++)
	{
		 *((unsigned char *)p_dst ++) = (unsigned char) 0 ;
	}
	//Jump to main
	main();
}