#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define linha 480
#define coluna 640
int flag = -1;

void somaPorLinhas_R(unsigned char img[linha][coluna], int soma[linha]);   //Função

int main(){
    unsigned char img[linha][coluna];
    int soma[linha] = {0}, i = 0, j = 0, somaparcial = 0;    //somaparcial será usado para verificação de cada soma
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
            somaparcial += img[i][j];   //Verificação de cada soma
        }
        if(soma[i] != somaparcial){
            printf("Array soma = %d, soma parcial = %d", soma[i], somaparcial);  //Mostra o erro
            printf("ERRO!!");   //Verificação, se a soma parcial for diferente da soma no respectivo local do array, é erro.
            return 0;
        }
        
    }
    
    //Mostra a ultima soma parcial e ultima soma do vetor
    printf("ultima soma do array = %d, ultima soma parcial = %d", soma[linha - 1], somaparcial); 
    printf("\nTUDO CERTO!!\n");

    return 0;
}

void somaPorLinhas_R(unsigned char img[linha][coluna], int soma[linha]){
    flag++; //Essa flag conta as iterações e marca o momento de mudança de posição do ponteiro soma. (soma[0], soma[1], soma[2],...)

    if(flag == linha * coluna){
        return;   //Quando todas as posições forem preenchidas, as iterações acabam
    }

    //(flag / linha): marca em qual linha está, só vai para a próxima linha quando soma todas as colunas da mesma linha
    //(flag % coluna): marca em qual coluna está, vai para a próxima linha até atingir o valor "coluna", quando alcança, volta a 0
    soma[flag / linha] += img[flag / linha][flag % coluna];

    somaPorLinhas_R(img, soma);  //Pula para a próxima iteração
}