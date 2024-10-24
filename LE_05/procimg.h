#include "procimg.c"

//Função free imgGray
void liberaImagemGray(imgGray img);
/*
   *Função que dá free em qualquer img que recebeu alocaImagemGray
   *SÓ FUNCIONA COM O ".IMG" DENTRO DO STRUCT
   *Parâmetros: 
   *img: matriz bidimensional a ser desalocada
*/

//Função free imgRGB
void liberaImagemRGB(imgRGB img);
/*
   *Função que dá free em qualquer img que recebeu alocaImagemRGB
   *SÓ FUNCIONA COM O ".IMG" DENTRO DO STRUCT
   *Parâmetros: 
   *img: matriz bidimensional a ser desalocada
*/

//Q1
imgGray alocaImagemGray(int nLin,int nCol);
/*
    *Função que aloca imagem em tons de cinza
    *Parâmetros:  
    *nLin: quantidade de linhas da matriz
    *nCol: quantidade de colunas da matriz  
    *Retorno:
    *Uma struct com a imagem alocado ou ponteiros nulos em caso de falha 
*/

//Q2
imgRGB  alocaImagemRGB(int nLin,int nCol);
/*
    *Função que aloca imagem colorida
    *Parâmetros:
    *nLin: quantidade de linhas da matriz
    *nCol: quantidade de colunas da matriz
    *Retorno:
    *Uma struct com a imagem alocado ou ponteiros nulos em caso de falha
*/

//Q3
int geraImgGrayFull(imgGray img,uchar pixel);
/*
    *Função que preenche todos os pixels com o valor de pixel 
    *Parâmetros:
    *img: imagem já alocada
    *pixel: valor que preencherá a imagem
    *Retorno:
    *True(1) se funcionar corretamente,False(0) se houver algum erro
*/
//Q4
int geraImgRGBFull(imgRGB img,tRGB pixel);
/*
    *Função que preenche todos os pixels com o valor de pixel 
    *Parâmetros:
    *img: imagem já alocada previamente 
    *pixel: valor da cor RGB para preencher todos os pixels da imagem.
    *Retorno:
    *True(1) se funcionar corretamente,False(0) se houver algum erro
*/
//Q5 
int geraImgGrayB(imgGray img);
/*
    *Função que preenche todos os pixels com 0
    *Parâmetro:
    *img: Imagem já alocada previamente
    *Retorno:
    *True(1) se funcionar corretamente,False(0)d se houver algum erro
*/
//Q6
int geraImgRGBB(imgRGB img);

//Q7
int geraImgGrayW(imgGray img);

//Q8
int geraImgRGBW(imgRGB img);

//Q9
unsigned char geraPixelGrey(int tipo);
int geraImgGray(imgGray img, int tipo);

//Q10
int geraImgRGB(imgRGB img, int tipo);

//Q13
int* somaPorLinhasGray(imgGray img);
/*
  *Função que soma os elementos das linhas da matriz gray
  *Parâmetro:
  *img: Imagem já alocada previamente
  *Retorno:
  *Array inteiro somaL (A soma de cada linha)
*/
int* somaPorColunasGray(imgGray img);
/*
  *Função que soma os elementos das colunas da matriz gray
  *Parâmetro:
  *img: Imagem já alocada previamente
  *Retorno:
  *Array inteiro somaC (A soma de cada coluna)
*/

//Q14
tRGB* somaPorLinhasRGB(imgRGB img);
/*
  *Função que soma os elementos R, G e B das linhas da matriz RGB
  *Parâmetro:
  *img: Imagem já alocada previamente
  *Retorno:
  *Array do tipo tRGB linhas (A soma de cada linha)
*/
tRGB* somaPorColunasRGB(imgRGB img);
/*
  *Função que soma os elementos R, G e B das colunas da matriz RGB
  *Parâmetro:
  *img: Imagem já alocada previamente
  *Retorno:
  *Array do tipo tRGB colunas (A soma de cada coluna)
*/

//Q15
int somaTotalGray(imgGray img);
/*
  *Função que soma todos os elementos da matriz gray
  *Parâmetro:
  *img: Imagem já alocada previamente
  *Retorno
  *somaT15 do tipo inteiro (que é a soma de todos os elementos)
*/
