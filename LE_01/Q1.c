//parte que vai no procimg.h
unsigned char gerarGreyPixel (int tipo);
/*
    *Função que gera um número que determina a intensidade de cor do pixel.
    *Parâmetro:
    * tipo: número que determina qual intensidade escolhida.
    *Retorno:
    * int: número gerado que determina a intensidade.
*/

//parte que vai pro procimg.c
unsigned char gerarGreyPixel (int tipo){
    int valor;
    double u = (double)rand() / RAND_MAX; // Gera um número aleatório entre 0 e 1
    if (tipo == 0) {
        valor = rand () % 256;
    } else if (tipo < 0) {
        // Maior probabilidade para valores escuros
        valor = (unsigned char)((1 - sqrt(u)) * 255);
    } else {
        // Maior probabilidade para valores claros
        valor = (unsigned char)(sqrt(u) * 255);
return (unsigned char) valor;
}

// parte que vai exemimg.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "procimg.h"

int main(){
    srand(time(NULL)); //Inicializa o gerador de números aleatórios.

    printf("Pixel de cor mais escura: %d\n",gerarGreyPixel(-1));       //Imprime as intensidades de cor mais escura
    printf("Pixel de cor mais clara: %d\n",gerarGreyPixel(1));         //Imprime as intensidades de cor mais clara
    printf("Pixel de intensidade qualquer: %d\n",gerarGreyPixel(0));   //Imprime qualquer intensidade
return 0;
}

