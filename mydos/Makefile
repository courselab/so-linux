#    SPDX-FileCopyrightText: 2021 Monaco F. J. <monaco@usp.br>
#    SPDX-FileCopyrightText: 2025 vitoremerique <vitort.emerique@hotmail.com>
#   
#    SPDX-License-Identifier: GPL-3.0-or-later
#
#  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
#  and includes modifications made by the following author(s):
#  vitoremerique <vitort.emerique@hotmail.com>

# By default, the bootable program name will be vidos.bin
# If you export this directory to extend the example as part of a programming
# exercise, redefine $(dos) to reflect your own DOS name, say
# dos = "amazingOS"
CC=gcc
MAKE=make

dos=$(shell basename $$(realpath .))
dos = vidos
# Build the OS and an example user program.

# Link all objects needed by the OS.

$(dos).bin : bootloader.o bios1.o kernel.o kaux.o bios2.o logo.o syscall.o vifs.o
	ld -melf_i386 -T vidos.ld --orphan-handling=discard $^ -o $@

# Here we are statically linking the user program 'prob.bin' into the kernel,
# so as to simulate the execution of a user program. If we were to actually load
# and execute an external program, we should remove 'prog.o' and 'libvidos.o'
# from the list of pre-requisites, and edit the linker script accordingly.
# Comment out the following line if this is the case.

$(dos).bin : prog.o libvidos.o

# Rules to build objects from either C or assembly code.

%.o : %.c
	$(CC) -m16 -O0 --freestanding -fno-pic $(NO_CF_PROTECT) -c $< -o $@

%.o : %.S
	as -32 $< -o $@

bootloader.o : bios1.h kernel.h
kernel.o : bios1.h bios2.h kernel.h kaux.h
kaux.o:    bios2.h kaux.h

$(dos).bin : .EXTRA_PREREQS = rt0.o vidos.ld

# Programas de usuário

progs = prog.bin

$(progs)  : %.bin : %.o libvidos.a
	ld -melf_i386 -T prog.ld --orphan-handling=discard $< -o $@

$(progs:%.bin=%.o) : %.o : %.c vidos.h
	gcc -m16 -O0 --freestanding -fno-pic $(NO_CF_PROTECT) -c $< -o $@

$(progs:%.bin=%.o) : vidos.h

$(progs:%.bin=%.o) : .EXTRA_PREREQS = prog.ld

# Biblioteca de usuário

libvidos.o: libvidos.c vidos.h
	gcc -m16 -O0 --freestanding -fno-pic $(NO_CF_PROTECT) -c  $< -o $@

libvidos.o : vidos.h

libvidos.a : libvidos.o
	ar rcs $@ $^
	
#Make disk image

reserved_blocks =  30

vifsedit: vifsedit.c
	gcc vifsedit.c -lm -o vifsedit

disk.img: vifsedit vidos.bin
	dd if=/dev/zero of=disk.img count=2880
	./format -r $(reserved_blocks) disk.img
	dd if=vidos.bin of=disk.img conv=notrunc obs=1 seek=16
	./put file1.txt disk.img
	./put file2.txt disk.img
	./put file3.txt disk.img

# Housekeeping.

.PHONY: clean

clean:
	rm -f *.bin *.o *~ *.s *.a *img

# SYSeg's  convenience rules (not related to the example itself)
include bintools.mk
