#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 640

/*Preencher um array [640] com valores aleatórios criados a partir do tipo de
intensidade inserido pelo usuário*/

int indice = N-1;

void geraLinhaR(unsigned char array [], int tipo);
unsigned char geraGreyPixel (int tipo);

int main () {
    int tipo, escuro=0, claro=0;
    unsigned char array [N];
    srand (time (NULL));
    printf (" tipo < 0 = cores mais escuras\n tipo > 0 = cores mais claras\n tipo == 0 = todas as intensidades\n");
    printf ("\nDigite o tipo de intensidade: ");
    scanf ("%d", &tipo);
    geraLinhaR(array, tipo);         
    for (int i = 0; i < N; i++) {
        if (array[i]<128) escuro++;
        if (array[i]>=128) claro++;
    }
    if (tipo<0 && escuro>claro || tipo>0 && claro>escuro || tipo==0)
        printf ("\nArray preenchido corretamente!\n");
    else
        printf ("\nErro: O array nao foi preenchido majoritariamente pelo tipo solicitado.\n");
    printf ("Cores escuras: %d\nCores claras: %d\n", escuro, claro);
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

void geraLinhaR(unsigned char array [], int tipo) {
    if (indice < 0) return;                   // para quando o array está totalmente preenchido
    array [indice] = geraGreyPixel (tipo);   //preenche o array de N-1 até 0;
    indice--;
    geraLinhaR (array, tipo);
}