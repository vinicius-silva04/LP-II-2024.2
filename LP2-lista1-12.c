//parte que vai no procimg.h
void imgHistogram(unsigned char img[640][480], int hist[256]);
/*
    *Função que mostra de acordo com o índice do array a quantidade de pixels de intesidade.
    *Parâmetro:
    * img: imagem que os pixels serão analisados.
    * hist: array que será preenchido pela quantidade de pixels de intensidade.
    *Retorno:
    * int: quantidade de pixels de intensidade em cada posição no array.
*/

//parte que vai pro procimg.c
void imgHistogram(unsigned char img[640][480], int hist[256]){
    int i,j;
    for(i=0;i<640;i++){
        for(j=0;j<480;j++){
            hist[img[i][j]]++;
        }
    }
}

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    unsigned char img[640][480];
    int i,j;
    int hist[256];
    srand(time(NULL));

    for(i=0;i<640;i++){
        for(j=0;j<480;j++){
            img[i][j]= rand() % 256;
        }
    }

    imgHistogram(img, hist);
    for(i=0;i<256;i++){
        printf("Intensidade %d: %d pixels\n",i,hist[i]);
    }
return 0;
}
