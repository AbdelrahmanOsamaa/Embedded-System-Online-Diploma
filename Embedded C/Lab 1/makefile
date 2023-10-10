#@Copyright : Abdelrahman

CC=arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As= $(wildcard *.s)
AsOBJ= $(As:.s=.o)
Project_name=UART_Lab

all: $(Project_name).bin
	@echo "##### Mission Complete #####"

%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS) $< -o $@

startup.o: startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@

$(Project_name).bin: $(Project_name).elf
	
	$(CC)objcopy.exe -O binary $< $@



clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.bin *.elf