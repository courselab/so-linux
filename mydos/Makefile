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

# Nome fixo do sistema operacional
os_name=vidos

# Build do sistema operacional com um exemplo de programa de usuário

$(os_name).bin : bootloader.o bios1.o kernel.o kaux.o bios2.o logo.o syscall.o prog.o libtydos.o
	ld -melf_i386 -T tydos.ld --orphan-handling=discard $^ -o $@

# Regras para compilar código C e assembly

%.o : %.c
	$(CC) -m16 -O0 --freestanding -fno-pic $(NO_CF_PROTECT) -c $< -o $@

%.o : %.S
	as -32 $< -o $@

bootloader.o : bios1.h kernel.h
kernel.o : bios1.h bios2.h kernel.h kaux.h
kaux.o:    bios2.h kaux.h

$(os_name).bin : .EXTRA_PREREQS = rt0.o tydos.ld

# Programas de usuário

progs = prog.bin

$(progs)  : %.bin : %.o libtydos.a
	ld -melf_i386 -T prog.ld --orphan-handling=discard $< -o $@

$(progs:%.bin=%.o) : %.o : %.c tydos.h
	$(CC) -m16 -O0 --freestanding -fno-pic $(NO_CF_PROTECT) -c $< -o $@

$(progs:%.bin=%.o) : tydos.h
$(progs:%.bin=%.o) : .EXTRA_PREREQS = prog.ld

# Biblioteca de usuário

libtydos.o: libtydos.c tydos.h
	$(CC) -m16 -O0 --freestanding -fno-pic $(NO_CF_PROTECT) -c $< -o $@

libtydos.a : libtydos.o
	ar rcs $@ $^

# Limpeza

.PHONY: clean

clean:
	rm -f *.bin *.o *~ *.s *.a

# Regras auxiliares do SYSeg
include bintools.mk
