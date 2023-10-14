#@Copyright : Abdelrahman

CC=arm-none-eabi-
CFLAGS=-gdwarf-2 -mcpu=cortex-m3 -mthumb
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
As= $(wildcard *.s)
AsOBJ= $(As:.s=.o)
Project_name=Learn-in-depth-cortex-m3

all: $(Project_name).bin
	@echo "##### Mission Complete #####"

%.o: %.c
	$(CC)gcc.exe -c  $(INCS) $(CFLAGS) $< -o $@



$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld -T linker_script.ld $(LIBS) $(OBJ) $(AsOBJ) -o $@ -Map=Map_file.map

$(Project_name).bin: $(Project_name).elf
	
	$(CC)objcopy.exe -O binary $< $@



clean_all:
	rm *.o *.elf *.bin

clean:
	rm *.bin *.elf