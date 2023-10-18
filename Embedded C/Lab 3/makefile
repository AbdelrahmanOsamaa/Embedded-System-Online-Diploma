#@Copyright : Abdelrahman

CC=arm-none-eabi-
CFLAGS=-gdwarf-2 -mcpu=cortex-m4 -mthumb -g
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As= $(wildcard *.s)
AsOBJ= $(As:.s=.o)
Project_name=TM4C123-cortex-M4

all: $(Project_name).bin
	@echo "##### Mission Complete #####"

%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS) $< -o $@



$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map
	#@copy content of .elf file to . axf file to simulate on kiel vision
	cp $(Project_name).elf $(Project_name).axf 

$(Project_name).bin: $(Project_name).elf
	
	$(CC)objcopy.exe -O binary $< $@



clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.bin *.elf