#include "procimg.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    int i, j;
    int nLin = 5, nCol = 5;
    printf("Questao 1\n");
    
    // Questão 1: Aloca a imagem em tons de cinza
    imgGray imagem = alocaImagemGray(nLin, nCol);
    if (imagem._img == NULL) {
        printf("Falha na alocacao da imagem\n");
        return 1;
    }
    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            imagem._img[i*imagem.nCol+j] = 128;
        }
    }
    bool erro = false;
    for (i = 0; i < nLin; i++) {
        for (j = 0; j < nCol; j++) {
            if (imagem._img[i*imagem.nCol+j] != 128) {
                printf("Erro! Imagem gerada errada no pixel [%d][%d].\n", i, j);
                erro = true;
            }
        }
    }
    if (!erro) {
        printf("Imagem gerada com sucesso!\n");
    }
    free(imagem._img);
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
    //Verificar se a função geraImgGrayFull está funcionando corretamente
    if (geraImgGrayFull(imagem3, pixel) == 1) {
        erro=false;
    } else {
        erro=true;
        return 1;
    }
    if(!erro){
        for (i = 0; i < nLin; i++) {
            for (j = 0; j < nCol; j++) {
                if (imagem3.img[i][j] != pixel) {
                    printf("Erro! O pixel [%d][%d] nao esta com o valor correto.\n", i,j);
                    erro = true;
                }
            }
        }
    }
    if (!erro) {
        printf("\nImagem gerada com sucesso!\n");
    }
    for(i=0;i<imagem3.nLin;i++){
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
            if (imagem5.img[i][j] != 0) {
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

    //funcoes 6-10
    imgGray imagemC;
    imgRGB imagemCrgb;
    int teste = 0;
    imagemC = alocaImagemGray(10,10);
    imagemCrgb = alocaImagemRGB(30,30);

    //funcao 6
    geraImgRGBB(imagemCrgb);

    teste = 0;
    for(i = 0; i < imagemCrgb.nCol*imagemCrgb.nLin; i++) if(imagemCrgb._img[i].R || imagemCrgb._img[i].G || imagemCrgb._img[i].B) teste = 1;

    if(teste)
        printf("\nExecucao da funcao 6 falhou");
    else
        printf("\nExecucao da funcao 6 teve exito");


    //funcao 7
    geraImgGrayW(imagemC);

    teste = 0;
    for(i = 0; i < imagemC.nCol*imagemC.nLin; i++) if(imagemC._img[i] != 255) teste = 1;
    if(teste)
        printf("\nExecucao da funcao 7 falhou");
    else
        printf("\nExecucao da funcao 7 teve exito");

    //funcao 8

    geraImgRGBW(imagemCrgb);

    teste = 0;
    for(i = 0; i < imagemCrgb.nCol*imagemCrgb.nLin; i++) if(imagemCrgb._img[i].R != 255 || imagemCrgb._img[i].G != 255 || imagemCrgb._img[i].B != 255) teste = 1;
    if(teste)
        printf("\nExecucao da funcao 8 falhou");
    else
        printf("\nExecucao da funcao 8 teve exito");
    
    //funcao 9
    geraImgGray(imagemC, 1);
    int maior = 0, menor = 0;
    teste = 0;

    for(i = 0; i < imagemC.nCol*imagemC.nLin; i++){
        if(imagemC._img[i] >= 128) maior++;
        else menor++;
    }
    if(maior < menor) teste = 1;
    
    if(teste)
        printf("\nExecucao da funcao 9 falhou");
    else
        printf("\nExecucao da funcao 9 teve exito");

    //funcao 10
    geraImgRGB(imagemCrgb, 1);
    maior = 0;
    menor = 0;
    teste = 0;

    for(i = 0; i < imagemCrgb.nCol*imagemCrgb.nLin; i++){
        if(imagemCrgb._img[i].R >= 128) maior++;
        else menor++;
        if(imagemCrgb._img[i].G >= 128) maior++;
        else menor++;
        if(imagemCrgb._img[i].B >= 128) maior++;
        else menor++;
    }
    if(maior < menor) teste = 1;

    if(teste)
        printf("\nExecucao da funcao 10 falhou");
    else
        printf("\nExecucao da funcao 10 teve exito");

    free(imagemC._img);
    free(imagemC.img);
    free(imagemCrgb._img);
    free(imagemCrgb.img);

    return 0;
}
