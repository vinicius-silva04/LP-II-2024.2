#include "procimg.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    int nLin = 5, nCol = 5;
    printf("Questao 1\n");
    
    // Questão 1: Aloca a imagem em tons de cinza
    imgGray imagem = alocaImagemGray(nLin, nCol);

    //Verifica se a alocação foi feita corretamente 
    
    if (imagem.img == NULL) {
        printf("Falha na alocacao da imagem\n");
        return 1;
    }
    
    //Preenche a matriz já alocada com pixel 128;
    
    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            imagem.img[i][j] = 128;
        }
    }
    // Flag para detectar erro
    bool erro = false;

    //Verifica se a imagem foi preenchida corretamente

    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            if (imagem.img[i][j] != 128) {
                printf("Erro! Imagem gerada errada no pixel [%d][%d].\n", i, j);
                erro = true;
                return 1;
            }
        }
    }
    if (!erro) {
        printf("Imagem gerada com sucesso!\n");
    }
    //Libera a memoria alocada

    liberaImagemGray(imagem);
    printf("\n------------------------------------------------------------\n");
    
    // Questão 2: Aloca a imagem RGB
    printf("\nQuestao 2\n");
    imgRGB imagem2 = alocaImagemRGB(nLin, nCol);
    if (imagem2.img == NULL) {
        printf("Falha na alocacao da imagem RGB\n");
        return 1;
    }
    //Preenche cada componente da imagem RGB
    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            imagem2.img[i][j].R = 0;
            imagem2.img[i][j].G = 1;
            imagem2.img[i][j].B = 2;
        }
    }
    //Reseta a flag
    erro = false;
    //Verifica se cada componente da imagem RGB foi preenchido corretamente 
    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            if (imagem2.img[i][j].R != 0) {
                printf("Erro! Componente R preenchido errado no pixel [%d][%d].\n", i, j);
                erro = true;
                return 1;
            }
            if (imagem2.img[i][j].G != 1) {
                printf("Erro! Componente G preenchido errado no pixel [%d][%d].\n", i, j);
                erro = true;
                return 1;
            }
            if (imagem2.img[i][j].B != 2) {
                printf("Erro! Componente B preenchido errado no pixel [%d][%d].\n", i, j);
                erro = true;
                return 1;
            }
        }
    }
    if (!erro) {
        printf("Imagem RGB gerada com sucesso!\n");
    }
    //Libera a memoria alocada
    for (i = 0; i < imagem2.nLin; i++) {
        free(imagem2.img[i]);
    }
    free(imagem2.img);
    printf("\n------------------------------------------------------------\n");
    
    // Questão 3: Preenchimento com um valor específico
    uchar pixel;
    printf("\nQuestao 3\n");
    printf("Digite o pixel que quer preencher a imagem: ");
    scanf("%hhu", &pixel);

    imgGray imagem3 = alocaImagemGray(nLin, nCol);
    //Verifica se a imagem foi alocada corretamente
    if (imagem3.img == NULL) {
        printf("Falha na alocacao da imagem em tons de cinza na Questao 3\n");
        return 1;
    }

    // Verifica se a função geraImgGrayFull está funcionando corretamente
    if (geraImgGrayFull(imagem3, pixel) == 1) {
        erro = false;
    } else {
        erro = true;
    }
    //Verifica se a imagem foi preenchida corretamente
    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            if (imagem3.img[i][j] != pixel) {
                printf("Erro! O pixel [%d][%d] não está com o valor correto.\n", i, j);
                erro = true;
                return 1;
            }
        }
    }
    if (!erro) {
        printf("\nImagem gerada com sucesso!\n");
    }
    //Libera a memoria alocada
    for (i = 0; i < imagem3.nLin; i++) {
        free(imagem3.img[i]);
    }
    free(imagem3.img);

    printf("\n------------------------------------------------------------\n");
    
    // Questão 4: Preenchimento de imagem RGB com um valor específico
    
    printf("\nQuestao 4\n");
    tRGB cores;
    cores.R = 0;
    cores.G = 1;
    cores.B = 2;

    imgRGB imagem4 = alocaImagemRGB(nLin, nCol);
    
    //Verifica se a memoria foi alocada corretamente
    if (imagem4.img == NULL) {
        printf("Falha na alocacao da imagem RGB na Questao 4\n");
        return 1;
    }

    // verificar se a função geraImgRGBFull está funcionando corretamente
    if (geraImgRGBFull(imagem4, cores) == 1) {
        erro=false;
    } else {
        erro=true;
    }
    //Verifica se a imagem foi preenchida corretamente
    for ( i = 0; i < nLin; i++) {
        for ( j = 0; j < nCol; j++) {
           if (imagem4.img[i][j].R != 0) {
                printf("Erro! Componente R preenchido errado no pixel [%d][%d].\n", i, j);
                erro = true;
                return 1;
            }
            if (imagem4.img[i][j].G != 1) {
                printf("Erro! Componente G preenchido errado no pixel [%d][%d].\n", i, j);
                erro = true;
                return 1;
            }
            if (imagem4.img[i][j].B != 2) {
                printf("Erro! Componente B preenchido errado no pixel [%d][%d].\n", i, j);
                erro = true;
                return 1;
            }
        }
    }printf("\nImagem gerada com sucesso!\n");

    
    //Libera a memoria alocada
    for (i = 0; i < imagem4.nLin; i++) {
        free(imagem4.img[i]);
    }
    free(imagem4.img);

    printf("\n------------------------------------------------------------\n");
     // Questão 5: Preenchimento de imagem com 0
    printf("\nQuestao 5");

    imgGray imagem5 = alocaImagemGray(nLin, nCol);
    //Verifica se a imagem foi alocada corretamente
    if (imagem5.img == NULL) {
        printf("Falha na alocacao da imagem em tons de cinza na Questao 3\n");
        return 1;
    }

    // Verifica se a função geraImgGrayFull está funcionando corretamente
    if (geraImgGrayB(imagem5) == 1) {
        erro = false;
    } else {
        erro = true;
    }
    //Verifica se a imagem foi preenchida corretamente
    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            if (imagem3.img[i][j] != 0) {
                printf("Erro! O pixel [%d][%d] não está com o valor correto.\n", i, j);
                erro = true;
                return 1;
            }
        }
    }
    if (!erro) {
        printf("\nImagem gerada com sucesso!\n");
    }
    //Libera a memoria alocada
    for (i = 0; i < imagem5.nLin; i++) {
        free(imagem5.img[i]);
    }
    free(imagem5.img);

    printf("\n------------------------------------------------------------\n");

    return 0;
}
