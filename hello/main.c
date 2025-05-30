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


extern unsigned short memsize(void);

char *convert_kb_to_mb(unsigned short val_kb, char *buf) {
    unsigned short val_mb;
    char *p = buf;
    char *p1, tmp_char;
    unsigned short tmp_val_digit;

    // PASSO 1: Converter Kilobytes para Megabytes (divisão inteira, truncando decimais)
    val_mb = val_kb / 1024; // 1 MB = 1024 KB

    // Se o valor_kb for menor que 1024, o resultado em MB será 0.
    // Garantimos que '0' seja impresso pelo menos uma vez.
    if (val_mb == 0 && val_kb < 1024) {
        *p++ = '0';
    } else {
        // PASSO 2: Converter o valor em Megabytes (inteiro) para string ASCII
        do {
            tmp_val_digit = val_mb;
            val_mb /= 10;
            // Pega o último dígito: (valor_antigo - (valor_novo * 10))
            *p++ = '0' + (tmp_val_digit - val_mb * 10);
        } while (val_mb);
    }

    *p-- = '\0'; // Adiciona o terminador nulo e ajusta o ponteiro para o último dígito
    
    // Inverte a string (porque os dígitos foram adicionados na ordem inversa)
    for (p1 = buf; p1 < p; ++p1, --p) {
        tmp_char = *p;
        *p = *p1;
        *p1 = tmp_char;
    }

    return buf; // Retorna o ponteiro para o início da string no buffer
}


int main(void)   
{
  char buffer[6];
  unsigned short mem_kb = memsize();
  printf ("Hello World");
  convert_kb_to_mb(mem_kb,buffer);
  printf(" ");
  printf("Mem KB: ");
  
  printf(buffer);
  return 0;
}





