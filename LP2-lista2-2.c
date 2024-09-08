#include <stdio.h>

#define linha 150
#define coluna 150

int N = linha * coluna;

void geraImgGreyFull_R(unsigned char img[linha][coluna], unsigned char pixel);

int main(){
    unsigned char img[linha][coluna] = {0}, pixel;
    int i, j, soma = 0;
    
    printf("Digite o valor do pixel: ");
    scanf("%hhu", &pixel);

    geraImgGreyFull_R(img, pixel);


    for(i = 0; i < linha; i++){                 // Verifica se a imagem foi gerada corretamente
        for(j = 0; j < coluna; j++){
            if(img[i][j] == pixel) soma++;
        }
    }

    if(soma != linha*coluna) printf("erro");              //se a soma for diferente de linha*coluna, a imagem não foi gerada corretamente
    else printf("deu certo");

    
    return 0;
}

void geraImgGreyFull_R(unsigned char img[linha][coluna], unsigned char pixel){
    if(N == 0){                     //testa se N chegou a 0
        N = linha * coluna;          //reseta N para que a função possa ser chamada novamente
        return;                      //encerra a função
    }
    N--;                            //decrementa N para controlar a quantidade de vezes que a função foi chamada
    img[0][0] = pixel;              //atribui o valor 0 ao pixel atual
    geraImgGreyFull_R(&img[0][1], pixel);     //chama a função novamente, passando o endereço do próximo pixel
}