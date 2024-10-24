#include "procimg.c"


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
