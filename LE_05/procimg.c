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

//Função free imgGray
void liberaImagemGray(imgGray img) {
    // Liberar cada linha da imagem
    for (int i = 0; i < img.nLin; i++) {
        free(img.img[i]);  // Libera a linha i
    }
    // Liberar o ponteiro de ponteiros para as linhas
    free(img.img);
}

//Função free imgRGB
void liberaImagemRGB(imgRGB img) {
    // Liberar cada linha alocada dinamicamente
    for (int i = 0; i < img.nLin; i++) {
        free(img.img[i]);  // Libera a linha i
    }
    // Liberar o array de ponteiros para as linhas
    free(img.img);
}

//Q1
imgGray alocaImagemGray(int nLin,int nCol){
    imgGray img;
    
    img.nLin = nLin;
    img.nCol = nCol;

   
    //Aloca para um ponteiro de ponteiros
    img.img = (uchar**) malloc(nLin * sizeof(uchar*));
    if(img.img ==NULL){
        img.img= NULL;
        return img;
    }
    for(int i=0;i<nLin;i++){
        img.img[i]= (uchar*)malloc(nCol* sizeof(uchar));
        if(img.img[i]==NULL){
            for(int j=0;j<nCol;j++){
                free(img.img[j]);
            }free(img.img);
            img.img=NULL;
            return img;
        }
    }
     //aloca para um array
    img._img = (uchar*)malloc(nLin*nCol*sizeof(uchar));
    if(img._img ==NULL){
        img._img= NULL;
        free(img._img);
        return img;
    }
return img;
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
    // Aloca para ponteiro de ponteiros
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
    //Aloca para um array
    img._img = (tRGB**)malloc(nLin*nCol*sizeof(tRGB*));
    if(img._img ==NULL){
        img._img= NULL;
        free(img._img);
        return img;
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
//Q6
int geraImgRGBB(imgRGB img){
    tRGB pixel;
    pixel.R = 0;
    pixel.G = 0;
    pixel.B = 0;
    return geraImgRGBFull(img, pixel);
}
//Q7
int geraImgGrayW(imgGray img){
    return geraImgGrayFull(img, 255);
}
//Q8
int geraImgRGBW(imgRGB img){
    tRGB pixel;
    pixel.R = 255;
    pixel.G = 255;
    pixel.B = 255;
    return geraImgRGBFull(img, pixel);
}

unsigned char geraPixelGrey(int tipo){

    int prob, valor;

    prob = rand() % 100;

    if(tipo < 0){
        if(prob < 80) valor = rand() % 128;
        
        else valor = rand() % 256;
    }
    else if(tipo > 0){
        if(prob < 80) valor = rand() % 128 + 128;

        else valor = rand() % 256;
    }
    else valor = rand() % 256;

    return (unsigned char) valor;
}
//Q9
int geraImgGray(imgGray img, int tipo){
    if(img.img == NULL || img._img == NULL) return 0;

    for(int i = 0; i < img.nCol * img.nLin; i++){
        img._img[i] = geraPixelGrey(tipo);
    }
    return 1;
}
//Q10
int geraImgRGB(imgRGB img, int tipo){
    if(img.img == NULL || img._img == NULL) return 0;

    for(int i = 0; i < img.nCol * img.nLin; i++){
        img._img[i].R = geraPixelGrey(tipo);
        img._img[i].G = geraPixelGrey(tipo);
        img._img[i].B = geraPixelGrey(tipo);
    }

    return 1;
}
