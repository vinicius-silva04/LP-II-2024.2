#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define linha 200
#define coluna 200

int flag = -1;

void somaPorColunas_R(unsigned char img[linha][coluna], int soma[coluna]);

int main(){
    unsigned char img[linha][coluna] = {0};
    int i = 0, j = 0, soma[coluna] = {0}, somaparcial = 0;
    srand(time(NULL));

    //preenchimento da matriz
     for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            img[i][j] = rand() % 256;
        }
    }
    
    somaPorColunas_R(img, soma);
    for(j = 0; j < coluna; j++){
        somaparcial = 0;
        for(i = 0; i < linha; i++){
            somaparcial += img[i][j];
        }
        if(soma[j] != somaparcial){
            printf("Array soma = %d, soma parcial = %d", soma[j], somaparcial);
            printf("\nERRO!!\n");
            return 0;
        }
    }
    printf("ultima soma array = %d, ultima soma parcial = %d\n", soma[coluna - 1], somaparcial);
    printf("\nTUDO CERTO!!\n");
        
    return 0;
}


void somaPorColunas_R(unsigned char img[linha][coluna], int soma[]){
    flag++;   //Flag serve pra marcar em qual iteração está

    if(flag == linha * coluna){
        return;   //Caso a matriz acabe, a função acaba também
    }

    soma[flag / coluna] += img[flag % coluna][flag / coluna]; 

    somaPorColunas_R(img, soma);   //Pula para a próxima linha
}