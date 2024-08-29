//Implemente uma a função void geraImgGreyB(unsigned char img[640][480]), que preenche todos os pixels de uma imagem com o valor 0 (black, intensidade zero em imagem cinza significa cor preta).

#include <stdio.h>
#include <stdlib.h>

//cabeçalho da função
void geraImgGreyB(unsigned char img[640][480]);


int main(){
    int i, j;
    unsigned char img[640][480];

    geraImgGreyB(img);                       //Chamada da função

    for(i = 0; i < 640; i++){
        for(j = 0; j < 480; j++){
            printf("%u", img[i][j]);         //Exibição da matriz
        }
        printf("\n");
    }

    printf("\n\nTodos os elementos são 0.");

    return 0;
}

//função preenche todos os pixels com 0
void geraImgGreyB(unsigned char img[640][480]){
    int i, j;

    for(i = 0; i < 640; i++){
        for(j = 0; j < 480; j++){
            img[i][j] = 0;
        }
    }
}
