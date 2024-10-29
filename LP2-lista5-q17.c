#include <stdio.h>
#include <stdlib.h>

/*Implemente a função int quantosPixelsGrayNaInt(imgGray img, uchar inten) que retorna a 
quantidade de pixels, na imagem img, possuem uma intensidade específica inten. */

typedef unsigned char uchar;
int i, j;

typedef struct {
    uchar *_img;
    uchar **img;
    int nLin, nCol;
}imgGray;

imgGray alocaImagemGray(int nLin, int nCol) {
    imgGray img1;
    img1.nLin = nLin;
    img1.nCol = nCol;
    img1._img = (uchar*) malloc (nLin*nCol*sizeof(uchar));
    img1.img = (uchar**) malloc (nLin*sizeof(uchar*));
    // Verifica se a alocação falhou
    if (img1._img == NULL || img1.img == NULL) {
        img1._img = NULL;
        img1.img = NULL;
        return img1;  // Retorna a estrutura com ponteiros NULL
    }
    for (i = 0; i<nLin; i++) {
        img1.img[i] = img1._img + i*nCol;
    }
    return img1;
}

// Função que conta quantos pixels têm a intensidade igual à especificada
int quantosPixelsGrayNaInt(imgGray img, uchar inten) {
    int count = 0;
    int total = img.nLin*img.nCol;  //total de pixels na imagem
    
    // Percorre a imagem unidimensionalmente
    for (i = 0; i<total; i++) {
        if (img._img[i]==inten) count++;
    }
    return count;
}

int main () {
    int l = 3, c = 3;
    imgGray imagem = alocaImagemGray (l, c);

    //verifica se a alocação foi bem-sucedida e comunica o usuário
    if (imagem.img==NULL || imagem._img==NULL) {
        printf("Falha na alocacao de memoria!\n");
        return 1;
    }
    
    //Preenche imagem 
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            imagem.img[i][j] = 12;
        }
    }
    
    printf ("%d pixels tem intensidade igual a 12.\n", quantosPixelsGrayNaInt(imagem, 12));
    free (imagem._img);     //desaloca espaço contínuo
    free (imagem.img);     //desaloca espaço das linhas
    return 0;
}