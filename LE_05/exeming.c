#include "procimg.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int i, j;
    int nLin = 4, nCol = 4;
    printf("Questao 1\n");
    
    // Questão 1: Aloca a imagem em tons de cinza
    imgGray imagem = alocaImagemGray(nLin, nCol);
    if (imagem.img == NULL) {
        printf("Falha na alocacao da imagem\n");
        return 1;
    }
    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            imagem.img[i][j] = 128;
        }
    }
    bool erro = false;
    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            if (imagem.img[i][j] != 128) {
                printf("Erro! Imagem gerada errada no pixel [%d][%d].\n", i, j);
                erro = true;
            }
        }
    }
    if (!erro) {
        printf("Imagem gerada com sucesso!\n");
    }
    for (i = 0; i < imagem.nLin; i++) {
        free(imagem.img[i]);
    }
    free(imagem.img);
    printf("\n------------------------------------------------------------\n");
    
    // Questão 2: Aloca a imagem RGB
    printf("\nQuestao 2\n");
    imgRGB imagem2 = alocaImagemRGB(nLin, nCol);
    if (imagem2.img == NULL) {
        printf("Falha na alocacao da imagem RGB\n");
        return 1;
    }

    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            imagem2.img[i][j].R = 0;
            imagem2.img[i][j].G = 1;
            imagem2.img[i][j].B = 2;
        }
    }

    erro = false;
    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            if (imagem2.img[i][j].R != 0) {
                printf("Erro! Componente R preenchido errado no pixel [%d][%d].\n", i, j);
                erro = true;
            }
            if (imagem2.img[i][j].G != 1) {
                printf("Erro! Componente G preenchido errado no pixel [%d][%d].\n", i, j);
                erro = true;
            }
            if (imagem2.img[i][j].B != 2) {
                printf("Erro! Componente B preenchido errado no pixel [%d][%d].\n", i, j);
                erro = true;
            }
        }
    }
    if (!erro) {
        printf("Imagem RGB gerada com sucesso!\n");
    }
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
    if (imagem3.img == NULL) {
        printf("Falha na alocacao da imagem em tons de cinza na Questao 3\n");
        return 1;
    }

    // Depuração: verificar se a função geraImgGrayFull está funcionando corretamente
    printf("Preenchendo a imagem com o valor %d...\n", pixel);

    if (geraImgGrayFull(imagem3, pixel) == 1) {
        printf("Imagem alocada com sucesso!\n");
    } else {
        printf("Erro ao alocar a imagem!\n");
        return 1;
    }

    erro = false;
    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            if (imagem3.img[i][j] != pixel) {
                printf("Erro! O pixel [%d][%d] não está com o valor correto.\n", i, j);
                erro = true;
            }
        }
    }
    if (!erro) {
        printf("\nImagem na Questao 3 gerada com sucesso!\n");
    }

    for (i = 0; i < imagem3.nLin; i++) {
        free(imagem3.img[i]);
    }
    free(imagem3.img);

    return 0;
}
