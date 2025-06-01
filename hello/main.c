/*
 *    SPDX-FileCopyrightText: 2021 Monaco F. J. <monaco@usp.br>
 *    SPDX-FileCopyrightText: 2025 vitoremerique <vitort.emerique@hotmail.com>
 *   
 *    SPDX-License-Identifier: GPL-3.0-or-later
 *
 *  This file is a derivative of SYSeg (https://gitlab.com/monaco/syseg)
 *  and includes modifications made by the following author(s):
 *  vitoremerique <vitort.emerique@hotmail.com>
 */



#include <stdio.h>


char *convert_kb_to_mb(int val_kb, char *buf) {
    int val_mb;
    char *p = buf;
    char *p1, tmp_char;
    int tmp_val_digit;


    val_mb = val_kb / 1024;

 
    if (val_mb == 0 && val_kb < 1024) {
        *p++ = '0';
    } else {
       
        do {
            tmp_val_digit = val_mb;
            val_mb /= 10;
            
            *p++ = '0' + (tmp_val_digit - val_mb * 10);
        } while (val_mb);
    }

    *p-- = '\0'; 
    
   
    for (p1 = buf; p1 < p; ++p1, --p) {
        tmp_char = *p;
        *p = *p1;
        *p1 = tmp_char;
    }

    return buf; 
}


int main(void)   
{
    char buffer[20];                   
    int mem_kb = memsize();

    printf("Hello World");
    convert_kb_to_mb(mem_kb, buffer); 
    

    printf(" ");
    printf("Mem KB: ");
    printf(buffer);                   
    return 0;
}
