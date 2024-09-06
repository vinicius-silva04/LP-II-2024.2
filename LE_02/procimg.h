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
void geraImgGreyB_R(unsigned char img[linha][coluna],int i ,int j);
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
   *img:matriz onde a imagem será preenchida.
   *tipo: determina a probabilidade dos números aleatórios.
*/
