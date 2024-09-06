#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*Preencher um array [640] com valores aleatórios criados a partir do tipo de
intensidade inserido pelo usuário*/

void geraLinhaR(unsigned char array [], int tipo, int N);
unsigned char geraGreyPixel (int tipo);

int main () {
    int tipo, N = 640;
    unsigned char array [N];
    srand (time (NULL));
    printf (" tipo < 0 = cores mais escuras\n tipo > 0 = cores mais claras\n tipo == 0 = todas as intensidades\n");
    printf ("\nDigite o tipo de intensidade: ");
    scanf ("%d", &tipo);
    geraLinhaR(array, tipo, N-1);         
    for (int i = 0; i<N; i++) {               //imprimir o array
        printf ("%hhu\n", array [i]);
    }
    return 0;
}

unsigned char geraGreyPixel (int tipo) {
    unsigned char num;
    int probabilidade = rand() % 100;
    if(tipo < 0){
       if (probabilidade < 80)      //80% de chance de cor escura
            num = rand() % 128;
       else                        //20% de chance de todas as cores
            num = rand() % 256;
    }
    else if (tipo > 0) {
        if (probabilidade < 80)             //80% de chance de cor clara
            num = 128 + rand() % 128;       //20% de chance de todas as cores
        else
            num = rand() % 256;
    }
    else
        num = rand() % 256;          //100% de chance de todas as cores
    return num;
}

void geraLinhaR(unsigned char array [], int tipo, int N) {
    if (N<0) return;                     // verificação para determinar quando o array está totalmente preenchido
    array [N] = geraGreyPixel (tipo);   //preenche o array de N até 0;
    geraLinhaR (array, tipo, N-1);
}