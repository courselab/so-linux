Escolhemos implementar a "conventional memory size (int 0x12)"
Solução:
1) No arquivo: Libc.S incluimos a label para a chamada dessa função.
2) Na biblioteca personalizada stdio.h incluimos a fastcall "memsize"
3) Na Main.C fizemos a chamada paraa Bios, convertemos o valor de int para char e imprimimos com a função printf que já havia sido implemedntada pelo professor em aula.
