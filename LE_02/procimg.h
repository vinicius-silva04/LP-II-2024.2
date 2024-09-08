#include "procimg.c"
#define linha 480
#define coluna 640
//Q1
void geraLinhaR(unsigned char array [], int tipo);
/*
   * Função que preenche um array [640] com valores aleatórios criados pelo geraGreyPixel (utiliza recursividade)
   * Parâmetro:
   * array: array que será preenchido.
   * tipo: determina a probabilidade dos números aleatórios.
*/
unsigned char geraGreyPixel (int tipo);
/*
   * Função que gera números aleatórios de acordo com o tipo inserido pelo uuário
   * Parâmetro:
   * tipo: determina a probabilidade dos números aleatórios.
*/
//Q2
void geraImgGreyFull_R(unsigned char img[linha][coluna], unsigned char pixel, int i, int j);
/*
    *Função que preenche uma imagem 640x480 com pixel utilizando de recursividade
    *Parâmetro:
    * img: matriz onde a imagem será preenchida.
    *pixel: número que será preenchido a imagem.
    *i e j: variáveis para iterar entre as linhas e colunas da matriz
*/
//Q3
void geraImgGreyB_R(unsigned char img[linha][coluna],int i,int j);
/*
    *Função que preenche uma imagem 640x480 com 0 utilizando de recursividade
    *Parâmetro:
    * img: matriz onde a imagem será preenchida.
    *i e j: variáveis para iterar entre as linhas e colunas da matriz
*/
//Q4
void preencheimg(unsigned char img[480][640],int pixel,int i,int j);
void geraImgGreyW_R(unsigned char img[480][640]);
/*
    *Função que preenche uma imagem 640x480 com 255 utilizando de recursividade
    *Parâmetro:
    * img: matriz onde a imagem será preenchida.
*/
//Q5
void geraImgGrey_R(unsigned char img[480][640],int tipo);
/*
   *Função que utilizando da função geraGreyPixel preenche a imagem com pixels aleatórios. 
   *Parâmetro:
   *img: matriz onde a imagem será preenchida.
   *tipo: determina a probabilidade dos números aleatórios.
*/
//Q8
void somaPorLinhas_R(unsigned char img[linha][coluna], int soma[linha]);
/*
  *Função que soma os elementos de cada linha da matriz.
  *Parãmetros:
  *img: matriz onde a imagem será preencida.
  *soma: vetor soma por cada linha.
*/
//Q9
void somaPorColunas_R(unsigned char img[linha][coluna], int soma[coluna]);
/*
  *Função que soma os elementos de cada coluna da matriz.
  *Parãmetros:
  *img: matriz onde a imagem será preencida.
  *soma: vetor soma por cada coluna.
*/
