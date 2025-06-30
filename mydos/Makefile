#    SPDX-FileCopyrightText: 2021 Monaco F. J. <monaco@usp.br>
#    SPDX-FileCopyrightText: 2025 vitoremerique <vitort.emerique@hotmail.com>
#   
#    SPDX-License-Identifier: GPL-3.0-or-later
#
#  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
#  and includes modifications made by the following author(s):
#  vitoremerique <vitort.emerique@hotmail.com>

CC=gcc
MAKE=make

<<<<<<< HEAD
dos=$(shell basename $$(realpath .))
dos = vidos
# Build the OS and an example user program.

# Link all objects needed by the OS.

$(dos).bin : bootloader.o bios1.o kernel.o kaux.o bios2.o logo.o syscall.o
	ld -melf_i386 -T vidos.ld --orphan-handling=discard $^ -o $@

# Here we are statically linking the user program 'prob.bin' into the kernel,
# so as to simulate the execution of a user program. If we were to actually load
# and execute an external program, we should remove 'prog.o' and 'libvidos.o'
# from the list of pre-requisites, and edit the linker script accordingly.
# Comment out the following line if this is the case.

$(dos).bin : prog.o libvidos.o

# Rules to build objects from either C or assembly code.
=======
# Nome fixo do sistema operacional
os_name=vidos

# Build do sistema operacional com um exemplo de programa de usuário

$(os_name).bin : bootloader.o bios1.o kernel.o kaux.o bios2.o logo.o syscall.o prog.o libtydos.o
	ld -melf_i386 -T tydos.ld --orphan-handling=discard $^ -o $@

# Regras para compilar código C e assembly
>>>>>>> bc3f2bb7de3153fd56ca4f6114d4d9ca292cef6a

%.o : %.c
	$(CC) -m16 -O0 --freestanding -fno-pic $(NO_CF_PROTECT) -c $< -o $@

%.o : %.S
	as -32 $< -o $@

bootloader.o : bios1.h kernel.h
kernel.o : bios1.h bios2.h kernel.h kaux.h
kaux.o:    bios2.h kaux.h

<<<<<<< HEAD
$(dos).bin : .EXTRA_PREREQS = rt0.o vidos.ld
=======
$(os_name).bin : .EXTRA_PREREQS = rt0.o tydos.ld
>>>>>>> bc3f2bb7de3153fd56ca4f6114d4d9ca292cef6a

# Programas de usuário

progs = prog.bin

$(progs)  : %.bin : %.o libvidos.a
	ld -melf_i386 -T prog.ld --orphan-handling=discard $< -o $@

<<<<<<< HEAD
$(progs:%.bin=%.o) : %.o : %.c vidos.h
	gcc -m16 -O0 --freestanding -fno-pic $(NO_CF_PROTECT) -c $< -o $@

$(progs:%.bin=%.o) : vidos.h

=======
$(progs:%.bin=%.o) : %.o : %.c tydos.h
	$(CC) -m16 -O0 --freestanding -fno-pic $(NO_CF_PROTECT) -c $< -o $@

$(progs:%.bin=%.o) : tydos.h
>>>>>>> bc3f2bb7de3153fd56ca4f6114d4d9ca292cef6a
$(progs:%.bin=%.o) : .EXTRA_PREREQS = prog.ld

# Biblioteca de usuário

<<<<<<< HEAD
libvidos.o: libvidos.c vidos.h
	gcc -m16 -O0 --freestanding -fno-pic $(NO_CF_PROTECT) -c  $< -o $@

libvidos.o : vidos.h
=======
libtydos.o: libtydos.c tydos.h
	$(CC) -m16 -O0 --freestanding -fno-pic $(NO_CF_PROTECT) -c $< -o $@
>>>>>>> bc3f2bb7de3153fd56ca4f6114d4d9ca292cef6a

libvidos.a : libvidos.o
	ar rcs $@ $^

<<<<<<< HEAD
vifsedit: vifsedit.c
	gcc vifsedit.c -lm -o vifsedit

disk.img: vifsedit
	dd if=/dev/zero of=disk.img count=2880
	./format disk.img

# Housekeeping.
=======
# Limpeza
>>>>>>> bc3f2bb7de3153fd56ca4f6114d4d9ca292cef6a

.PHONY: clean

clean:
<<<<<<< HEAD
	rm -f *.bin *.o *~ *.s *.a *img
# By default, the bootable program name will be vidos.bin
# If you export this directory to extend the example as part of a programming
# exercise, redefine $(dos) to reflect your own DOS name, say
# dos = "amazingOS"

# SYSeg's  convenience rules (not related to the example itself)
=======
	rm -f *.bin *.o *~ *.s *.a

# Regras auxiliares do SYSeg
>>>>>>> bc3f2bb7de3153fd56ca4f6114d4d9ca292cef6a
include bintools.mk
