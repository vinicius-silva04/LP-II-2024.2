#include <stdio.h>
#include <stdlib.h>

/*Implemente a função int quantosPixelsGrayNaInt(imgGray img, uchar inten) que retorna a 
quantidade de pixels, na imagem img, possuem uma intensidade específica inten. */

typedef unsigned char uchar;
int i, j;

typedef struct {
    unsigned char R, G, B;
}tRGB;

typedef struct {
    tRGB *_img;
    tRGB **img;
    int nLin, nCol;
}imgRGB;

imgRGB alocaImagemRGB(int nLin, int nCol) {
    imgRGB img2;
    img2.nLin = nLin;
    img2.nCol = nCol;
    img2._img = (tRGB*) malloc (nLin*nCol*sizeof(tRGB)); //aloca matriz unidimensional
    img2.img = (tRGB**) malloc (nLin*sizeof(tRGB*));  //aloca matriz bidimensional
    // Verifica se a alocação falhou
    if (img2._img == NULL || img2.img == NULL) {
        img2._img = NULL;
        img2.img = NULL;
        return img2;  // Retorna a estrutura com ponteiros NULL
    }
    for (i = 0; i<nLin; i++) {
        img2.img[i] = img2._img + i*nCol;
    }
    return img2;
}

// Função que conta quantos pixels têm a intensidade RGB igual à especificada
int quantosPixelsRGBNaInt(imgRGB img, tRGB inten) {
    int count = 0;
    int total = img.nLin*img.nCol;  //total de pixels na imagem
    
    // Percorre a imagem unidimensionalmente
    for (i = 0; i<total; i++) {
        if (img._img[i].R==inten.R && img._img[i].G==inten.G && img._img[i].B==inten.B)
                count++;
    }
    return count;
}

int main () {
    int l = 3, c = 3;
    imgRGB imagem2 = alocaImagemRGB (l, c);
    
    //verifica se a alocação foi bem-sucedida e comunica o usuário
    if (imagem2.img==NULL || imagem2._img==NULL) { 
        printf("Falha na alocacao de memoria!\n");
        return 1;
    }

    // Preenche a imagem RGB com valores arbitrários
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            imagem2.img[i][j].R = 3;  // Define o valor do vermelho (R)
            imagem2.img[i][j].G = 5;  // Define o valor do verde (G)
            imagem2.img[i][j].B = 7;  // Define o valor do azul (B)
        }
    }
    tRGB intensidade = {3, 5, 7};    // define a intensidade que queremos contar
    printf ("%d pixels tem intensidade igual a R=3, G=5 e G=7.\n", quantosPixelsRGBNaInt(imagem2, intensidade));
    free (imagem2._img);     //desaloca espaço contínuo
    free (imagem2.img);     //desaloca espaço das linhas
    return 0;
}
