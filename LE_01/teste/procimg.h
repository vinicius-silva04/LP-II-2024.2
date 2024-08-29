//Q1
unsigned char gerarGreyPixel (int tipo);
/*
    *Função que gera um número que determina a intensidade de cor do pixel.
    *Parâmetro:
    * tipo: número que determina qual intensidade escolhida.
    *Retorno:
    * int: número gerado que determina a intensidade.
*/
//Q2
void geraImgGreyFull ( unsigned char img [640][480], unsigned char pixel);
/*
    *Função que preenche a imagem com o valor do parâmetro pixel.
    *Parâmetro:
    * img: matriz onde a imagem será preenchida.
    * pixel: número que será preenchido a imagem.
    *Retorno:
    * int: número gerado que determina a intensidade.
*/
//Q4
void geraImgGreyW(unsigned char img[640][480]);
/*função que preenche todos os pixels da matriz img com o valor 0*/
//Q6
void drwRect(unsigned char img[640][480], int x, int y, int larg, int alt, unsigned char pixel);
/* 
    *Função que preenche um retangulo com o valor do parâmetro pixel.
    *img: Matriz onde a imagem será preenchida
    *pixel: número que será preenchido o retangulo
    *x,y: coordenadas do vertice superior esquerdo do retangulo
    *larg,alt: largura e altura do retangulo
*/
//Q7
void drwCirc(unsigned char img[640][480], int x, int y, int rad, unsigned char pixel);
/*
   *Função que desenha a área de um círculo.
   *Parâmetros:
   *img: matriz onde o círculo será desenhado.
   *x,y: coordenadas do centro do círculo.
   *rad: raio da circunferência.
   *pixel: cor que será usada.
*/
//Q12
void imgHistogram(unsigned char img[640][480], int hist[256]);
/*
    *Função que mostra de acordo com o índice do array a quantidade de pixels de intesidade.
    *Parâmetro:
    * img: imagem que os pixels serão analisados.
    * hist: array que será preenchido pela quantidade de pixels de intensidade.
    *Retorno:
    * int: quantidade de pixels de intensidade em cada posição no array.
*/
