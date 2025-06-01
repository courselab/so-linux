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



#include "stdio.h"


char* int_to_char_buffer(int num, char* buffer) {
    char* ptr = buffer;
    char* ptr1 = buffer;
    char tmp_char;
    

    // Lida com o caso de num ser 0
    if (num == 0) {
        *ptr++ = '0';
        *ptr = '\0'; // Adiciona o terminador nulo
        return buffer;
    }

    // Lida com números negativos
    if (num < 0) {
        *ptr++ = '-';
        num = -num; // Trabalha com o valor absoluto
    }

    // Converte os dígitos individualmente
    // Os dígitos são gerados na ordem inversa (ex: 123 -> 3, 2, 1)
    while (num > 0) {
        *ptr++ = (num % 10) + '0'; // Pega o último dígito e converte para ASCII
        num /= 10;                 // Remove o último dígito
    }

    // Se houve sinal de negativo, o ponteiro ptr já avançou,
    // então precisamos ajustar o ponteiro de início para a inversão.
    // Se o número original era negativo, ptr1 aponta para o '-'.
    // Caso contrário, ptr1 aponta para o início do buffer.
    if (buffer[0] == '-') {
        ptr1++; // Começa a inversão após o '-'
    }

    // Adiciona o terminador nulo
    *ptr = '\0';
    ptr--; // Volta para o último caractere válido antes do terminador

    // Inverte a string de dígitos (agora a ordem está correta)
    // Ex: "321" vira "123"
    while (ptr1 < ptr) {
        tmp_char = *ptr;
        *ptr = *ptr1;
        *ptr1 = tmp_char;
        ptr--;
        ptr1++;
    }

    return buffer; // Retorna o ponteiro para o início da string no buffer
}


int main(void)   
{
    char kb_buffer[20];
    int mem_kb = memsize();
    const char * rs; 

    printf("Hello World");
    printf("\r\n"); 
    

    
    /* Convert MB to string and print */
    int_to_char_buffer(mem_kb, kb_buffer);
    rs = kb_buffer;
    printf("Memory Size KB:");
    printf(rs);
    
    
    return 0;
}
