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
extern uint32_t _stack_top;

uint32_t vectors[] = {
	(uint32_t) &_stack_top ,
	(uint32_t) &Rest_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_Fault_Handler,
	(uint32_t) &MM_Fault_Handler,
	(uint32_t) &Bus_Fault,
	(uint32_t) &Usage_Fault_Handler,
	
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