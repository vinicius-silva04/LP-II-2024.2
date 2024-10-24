#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned char uchar;

typedef struct {
    uchar *_img;
    uchar **img;
    int nLin,nCol;

}imgGray;

typedef struct{
    uchar R,G,B;
}tRGB;

typedef struct{
    tRGB *_img;
    tRGB **img;
    int nLin,nCol;
}imgRGB;

struct imagens{
    imgGray img;
    struct imagens *prox; 
};
typedef struct imagens tImagens;

//Função free
void liberaImagemGray(imgGray img) {
    // Liberar cada linha da imagem
    for (int i = 0; i < img.nCol; i++) {
        free(img.img[i]);  // Libera a linha i
    }
    // Liberar o ponteiro de ponteiros para as linhas
    free(img.img);
}

//Q1
imgGray alocaImagemGray(int nLin,int nCol){
    imgGray imagem;
    imagem.nLin = nLin;
    imagem.nCol = nCol;

    imagem.img = (unsigned char**) malloc(nLin * sizeof(uchar*));
    if(imagem.img ==NULL){
        imagem.img= NULL;
        return imagem;
    }
    for(int i=0;i<nLin;i++){
        imagem.img[i]= (uchar*)malloc(nCol* sizeof(uchar));
        if(imagem.img[i]==NULL){
            for(int j=0;j<nCol;j++){
                free(imagem.img[j]);
            }free(imagem.img);
            imagem.img=NULL;
            return imagem;
        }
    }
return imagem;
}
//Q2
imgRGB alocaImagemRGB(int nLin, int nCol) {
    imgRGB img;

    
    img.nLin = nLin;
    img.nCol = nCol;

    img.img = (tRGB **)malloc(nLin * sizeof(tRGB *));
    if (img.img == NULL) {
        // Falha na alocação das linhas
        return img;  // img == NULL indica falha
    }
    // Aloca memória para o array 1D de pixels (_img)
    for (int i = 0; i < nLin; i++) {
        img.img[i] = (tRGB *)malloc(nCol * sizeof(tRGB));
        if (img.img[i] == NULL) {
            // Falha na alocação de uma linha, liberar as anteriores
            for (int j = 0; j < i; j++) {
                free(img.img[j]);
            }
            free(img.img);
            img.img = NULL;  // Indica falha
            return img;
        }
    }

    return img;
}

//Q3
int geraImgGrayFull(imgGray img, uchar pixel) {
    // Verifica se a imagem foi alocada corretamente
    if (img.img == NULL) {
        return false;  // Retorna False (0) se img é NULL
    }

    // Percorre todos os pixels da imagem e os preenche com o valor dado
    for (int i = 0; i < img.nLin; i++) {
        if (img.img[i] == NULL) {
            return false;  // Se alguma linha for NULL, indica falha
        }
        for (int j = 0; j < img.nCol; j++) {
            img.img[i][j] = pixel; // Preenche o pixel com o valor
        }
    }

    return true;  // Retorna True (1) se tudo ocorreu bem
}
//Q4
int geraImgRGBFull(imgRGB img,tRGB pixel){
     // Verifica se a imagem foi previamente alocada
    if (img.img == NULL) {
        return 0; // Retorna False se a imagem não foi alocada
    }

    // Itera sobre cada pixel e preenche com o valor do pixel fornecido
    for (int i = 0; i < img.nLin; i++) {
        if (img.img[i] == NULL) {
            return 0; // Retorna False se alguma linha não foi alocada corretamente
        }
        for (int j = 0; j < img.nCol; j++) {
            img.img[i][j] = pixel;
        }
    }

    return 1; // Retorna True se o preenchimento for bem-sucedido
}
//Q5
int geraImgGrayB(imgGray img) {
    // Verifica se a imagem foi alocada corretamente
    if (img.img == NULL) {
        return false;  // Retorna False (0) se img é NULL
    }

    // Percorre todos os pixels da imagem e os preenche com o valor dado
    for (int i = 0; i < img.nLin; i++) {
        if (img.img[i] == NULL) {
            return false;  // Se alguma linha for NULL, indica falha
        }
        for (int j = 0; j < img.nCol; j++) {
            img.img[i][j] = 0; // Preenche o pixel com o valor
        }
    }

    return true;  // Retorna True (1) se tudo ocorreu bem
}
