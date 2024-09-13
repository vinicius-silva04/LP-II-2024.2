#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define linha 200
#define coluna 200

void geraImgGrey_R (unsigned char img[linha][coluna], int tipo);
unsigned char geraGreyPixel (int tipo);

int main(){
    unsigned char img[linha][coluna];
    int i, j, tipo=0;
    srand(time(NULL));
    geraImgGrey_R(img, tipo);
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            int k = img[i][j];
            if (k<0 || k>255){
                printf("Erro na imagem gerada!\nimg[%d][%d]: %hhu",i, j, img[i][j]);
                return 1;
            }
        }
    }
    printf("Exemplo:\nimg[%d][%d] = %hhu", i-1, j-1, img[i-1][j-1]);
    printf("\n\nImagem gerada com sucesso\n");
    return 0;
}
unsigned char geraGreyPixel(int tipo) {
    unsigned char num;
    int probabilidade = rand () % 100;
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

int L = 0, C = 0;
void geraImgGrey_R(unsigned char img[linha][coluna], int tipo){
    if (L==linha) return;
    img [L][C] = geraGreyPixel(tipo);
    C++;
    if (C==coluna) {
        L++;
        C = 0;
    }
    return geraImgGrey_R (img, tipo);
}
