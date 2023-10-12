/* Learn-in-depth : Abdelrahman osama*/


section .vector
.word _reset
.word Vector_handler			/* NMI*/
.word Vector_handler			/* Hard Fault*/
.word Vector_handler			/* MM Fault*/
.word Vector_handler			/* Bus Fault*/
.word Vector_handler			/* Usage Fault*/
.word Vector_handler			/* RESERVER*/
.word Vector_handler			/* RESERVER*/
.word Vector_handler			/* RESERVER*/
.word Vector_handler			/* RESERVER*/
.word Vector_handler			/* SV call*/
.word Vector_handler			/* Debug reserved*/
.word Vector_handler			/* RESERVER*/
.word Vector_handler			/* PendSV*/
.word Vector_handler			/* SysTick*/
.word Vector_handler			/* IRQ0*/
.word Vector_handler			/* IRQ1*/
.word Vector_handler			/* IRQ2*/
				
				/* on to IRQ67 */
section .text
reset:
	bl main
	b .
.thumb_func
Vector_handler:
b _reset