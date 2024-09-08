#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define linha 480
#define coluna 640

int flag = -1;  //-1 pra lá na função o primeiro valor ser 0

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
            somaparcial += img[i][j];   //somaparcial será usado para verificação de cada soma
        }
        if(soma[j] != somaparcial){
            printf("Array soma = %d, soma parcial = %d", soma[j], somaparcial);  // Mostra o erro
            printf("\nERRO!!\n");   //Verificação, se a soma parcial for diferente da soma no respectivo local do array, é erro.
            return 0;
        }
    }

    //Mostra a ultima soma parcial e ultima soma do vetor
    printf("ultima soma array = %d, ultima soma parcial = %d\n", soma[coluna - 1], somaparcial); 
    printf("\nTUDO CERTO!!\n");
        
    return 0;
}


void somaPorColunas_R(unsigned char img[linha][coluna], int soma[]){
    flag++;   //Essa flag conta as iterações e marca o momento de mudança de posição do ponteiro soma. (soma[0], soma[1], soma[2],...)

    if(flag == linha * coluna){
        return;   //Caso a matriz acabe, a função acaba também
    }

    //(flag / coluna): marca em qual coluna está, só vai para a próxima coluna quando soma todas as linhas da mesma coluna
    //(flag % linha): marca em qual linha está, só vai para a próxima linha 
    soma[flag / coluna] += img[flag % linha][flag / coluna]; 

    somaPorColunas_R(img, soma);   //Pula para a próxima iteração
}