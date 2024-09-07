#include "procimg.c"
#define linha 480
#define coluna 640

//Q1
void preencherarray(unsigned char array[640],int tipo, int N);
void geraLinhaR(unsigned char array [], int tipo);
unsigned char geraGreyPixel (int tipo);

//Q2
void geraImgGreyFull_R(unsigned char img[linha][coluna], unsigned char pixel);
/*
    *Função que preenche uma imagem 640x480 com pixel utilizando de recursividade
    *Parâmetro:
    * img: matriz onde a imagem será preenchida.
    *pixel: número que será preenchido a imagem.
    *i e j: variáveis para iterar entre as linhas e colunas da matriz
*/
//Q3
void geraImgGreyB_R(unsigned char img[linha][coluna]);
/*
    *Função que preenche uma imagem 640x480 com 0 utilizando de recursividade
    *Parâmetro:
    * img: matriz onde a imagem será preenchida.
    *i e j: variáveis para iterar entre as linhas e colunas da matriz
*/
//Q4
void preencherimg(unsigned char img[480][640],int pixel,int i,int j);
void geraImgGreyW_R(unsigned char img[480][640]);
/*
    *Função que preenche uma imagem 640x480 com 255 utilizando de recursividade
    *Parâmetro:
    * img: matriz onde a imagem será preenchida.
*/
//Q5
void geraImgGrey_R(unsigned char img[480][640],int tipo);
