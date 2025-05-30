#    SPDX-FileCopyrightText: 2025 vitoremerique <vitort.emerique@hotmail.com>
#   
#    SPDX-License-Identifier: GPL-3.0-or-later
#
#  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
#  and includes modifications made by the following author(s):
#  vitoremerique <vitort.emerique@hotmail.com>

	.code16gcc
	.global _start
	
_start:
	mov $0x7c00, %sp
	call main
halt:	
	hlt
	jmp halt
