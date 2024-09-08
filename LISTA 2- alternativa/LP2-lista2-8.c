#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define linha 480
#define coluna 640
int flag = 0;

void somaPorLinhas_R(unsigned char *img, int *soma);

int main(){
    unsigned char img[linha][coluna];
    int soma[linha] = {0}, i = 0, j = 0, somaparcial = 0, somatotal = 0;    //somaparcial e somatotal serão usados para verificação
    srand(time(NULL));

    //preenchimento da matriz
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            img[i][j] = rand() % 256;
        }
    }

    somaPorLinhas_R(img, soma);   //chamada da função

     for(i = 0; i < linha; i++){
        somaparcial = 0;
        for(j = 0; j < coluna; j++){
            somaparcial += img[i][j];
            somatotal += img[i][j];
        }
        if(soma[i] != somaparcial){
            printf("ERRO!!");
            return 0;
        }
        
    }
    
    printf("Array soma = %d, soma parcial = %d", soma[linha - 1], somaparcial);
    somaparcial = 0;

    for(i = 0; i < linha; i++){
        somaparcial += soma[i];
    }

    printf("\nArray soma total = %d, soma total = %d", somatotal, somaparcial);
    printf("\nTUDO CERTO!!\n");

    return 0;
}

void somaPorLinhas_R(unsigned char *img, int *soma){
    flag++;

    *soma += *img;

    if(flag == linha * coluna){
        return;
    }

    if(flag % coluna == 0){
        somaPorLinhas_R(img+1, soma+1);
        return;
    }

    somaPorLinhas_R(img+1, soma);
}