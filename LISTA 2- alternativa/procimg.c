#include <time.h>
#include <stdlib.h>
#define linha 480
#define coluna 640


void preencherimg(unsigned char img[480][640],int pixel,int i,int j){
    if(i>=480 || j>=640) return; //condição de parada

    img[i][j]=pixel; //preenche com o valor inserido
    preencherimg(img,pixel,i,j+1); //preenche até o valor máximo de j
    if(j==0)   preencherimg(img,pixel,i+1,0); //quando j chega no limite, vai para próxima linha
}

//Q1
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
int N=640;
void preencherarray(unsigned char array[640],int tipo, int N){
     if (N<0) return;                     // verificação para determinar quando o array está totalmente preenchido
    array [N-1] = geraGreyPixel (tipo);   //preenche o array de 640 até 0;
    preencherarray(array, tipo,N-1);
}
void geraLinhaR(unsigned char array [640], int tipo) {
   preencherarray(array,tipo,N);
}

//Q2
void geraImgGreyFull_R(unsigned char img[linha][coluna],unsigned char pixel){
     preencherimg(img,pixel,0,0);
}
//Q3
void geraImgGreyB_R(unsigned char img[linha][coluna]){
    preencherimg(img,0,0,0);
}

//Q4

void geraImgGreyW_R(unsigned char img[480][640]){
    preencherimg(img,255,0,0);
}
//Q5

void geraImgGrey_R(unsigned char img[480][640],int tipo){
    unsigned char k= geraGreyPixel(tipo);
    preencherimg(img,k,0,0);
}
