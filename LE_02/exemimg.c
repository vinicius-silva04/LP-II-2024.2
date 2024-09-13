#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "procimg.h"  

#define LINHA 480
#define COLUNA 640
#define N 640

int main() {
    int tipo, escuro = 0, claro = 0;
    unsigned char array[N];
    unsigned char img[LINHA][COLUNA];
    int i, j, soma = 0, cont = 0;
    unsigned char pixel;
    int pixelMax, pixelMin, min = 0, max = 0;
    int somaparcial = 0, somaLinhas[LINHA] = {0}, somaColunas[COLUNA] = {0};
    int somaTotal;
    unsigned char inte;
    int count = 0, x, maior = 0, abaixoDeInt, acimaDeInt;

    srand(time(NULL));

    // Q1 - GeraLinhaR
    printf("\nQuestao 1\n");
    printf("Tipo < 0 = cores mais escuras\nTipo > 0 = cores mais claras\nTipo == 0 = todas as intensidades\n");
    printf("\nDigite o tipo de intensidade: ");
    scanf("%d", &tipo);
    geraLinhaR(array, tipo);         
    for (i = 0; i < N; i++) {
        if (array[i] < 128) escuro++;
        if (array[i] >= 128) claro++;
    }
    if (tipo < 0 && escuro > claro || tipo > 0 && claro > escuro || tipo == 0)
        printf("\nArray preenchido corretamente!\n");
    else
        printf("\nErro: O array nao foi preenchido majoritariamente pelo tipo solicitado.\n");
    printf("Cores escuras: %d\nCores claras: %d\n", escuro, claro);

    // Q2 - GeraImgGreyFull_R
    printf("\nQuestao 2\n");
    printf("Digite o valor do pixel: ");
    scanf("%hhu", &pixel);
    geraImgGreyFull_R(img, pixel);
    soma = 0;
    for(i = 0; i < LINHA; i++) {
        for(j = 0; j < COLUNA; j++) {
            if(img[i][j] == pixel) soma++;
        }
    }
    if(soma != LINHA * COLUNA) printf("Erro na geracao da imagem full grey\n");
    else printf("Imagem grey full gerada corretamente\n");

    // Q3 - GeraImgGreyB_R
    printf("\nQuestao 3\n");
    geraImgGreyB_R(img);
    cont = 0;
    for(i = 0; i < LINHA; i++) {
        for(j = 0; j < COLUNA; j++) {
            if(img[i][j] != 0) {
                printf("Erro: img[%d][%d] = %hhu\n", i, j, img[i][j]);
            } else cont++;
        }
    }
    if(LINHA * COLUNA == cont) printf("Imagem grey B gerada com sucesso!\n");
    else printf("Erro na geracao da imagem grey B!\n");

    // Q4 - GeraImgGreyW_R
    printf("\nQuestao 4\n");
    geraImgGreyW_R(img);
    cont = 0;
    for(i = 0; i < LINHA; i++) {
        for(j = 0; j < COLUNA; j++) {
            if(img[i][j] == 255) {
                cont++;
            } else {
                printf("Erro! img[%d][%d]: %u\n", i, j, img[i][j]);
                return 0;
            }
        }
    }
    printf("Exemplo:\nimg[%d][%d]: %u\n", i-1, j-1, img[i-1][j-1]);
    if(LINHA * COLUNA == cont) printf("Imagem grey W gerada com sucesso!\n");
    else printf("Erro na geracao da imagem grey W!\n");

    // Q5 - GeraImgGrey_R
    printf("\nQuestao 5\n");
    geraImgGrey_R(img, tipo);
    for(i = 0; i < LINHA; i++) {
        for(j = 0; j < COLUNA; j++) {
            int k = img[i][j];
            if (k < 0 || k > 255) {
                printf("Erro na imagem gerada!\nimg[%d][%d]: %hhu\n", i, j, img[i][j]);
                return 1;
            }
        }
    }
    printf("Exemplo:\nimg[%d][%d] = %hhu\n", i-1, j-1, img[i-1][j-1]);
    printf("Imagem grey gerada com sucesso\n");

    // Q6 - pixelMax_R
    printf("\nQuestao 6\n");
    for (i = 0; i < LINHA; i++) {
        for (j = 0; j < COLUNA; j++) {
            img[i][j] = rand() % 256;
        }
    }
    pixelMax = pixelMax_R(img); 
    printf("O maior valor eh %d\n", pixelMax);
    max = 0;
    for(i = 0; i < LINHA; i++) {
        for(j = 0; j < COLUNA; j++) {
            if(img[i][j] > max) {
                max = img[i][j];
            }
        }
    }
    if(max == pixelMax) printf("Maximo correto\n");
    else printf("Erro no calculo do maximo\n");

    // Q7 - pixelMin_R
    printf("\nQuestao 7\n");
    for (i = 0; i < LINHA; i++) {
        for (j = 0; j < COLUNA; j++) {
            img[i][j] = rand() % 256;
        }
    }
    pixelMin = pixelMin_R(img);
    printf("O menor valor eh %d\n", pixelMin);
    min = 255;
    for(i = 0; i < LINHA; i++) {
        for(j = 0; j < COLUNA; j++) {
            if(img[i][j] < min) {
                min = img[i][j];
            }
        }
    }
    if(min == pixelMin) printf("Minimo correto\n");
    else printf("Erro no calculo do minimo\n");

    // Q8 - somaPorLinhas_R
    printf("\nQuestao 8\n");
    for(i = 0; i < LINHA; i++) {
        for(j = 0; j < COLUNA; j++) {
            img[i][j] = rand() % 256;
        }
    }
    somaPorLinhas_R(img, somaLinhas);
    for(i = 0; i < LINHA; i++) {
        somaparcial = 0;
        for(j = 0; j < COLUNA; j++) {
            somaparcial += img[i][j];
        }
        if(somaLinhas[i] != somaparcial) {
            printf("Erro! Array soma = %d, soma parcial = %d\n", somaLinhas[i], somaparcial);
            return 0;
        }
    }
    printf("Soma por linhas correta\n");

    // Q9 - somaPorColunas_R
    printf("\nQuestao 9\n");
    for(i = 0; i < LINHA; i++) {
        for(j = 0; j < COLUNA; j++) {
            img[i][j] = rand() % 256;
        }
    }
    somaPorColunas_R(img, somaColunas);
    for(j = 0; j < COLUNA; j++) {
        somaparcial = 0;
        for(i = 0; i < LINHA; i++) {
            somaparcial += img[i][j];
        }
        if(somaColunas[j] != somaparcial) {
            printf("Erro! Array soma = %d, soma parcial = %d\n", somaColunas[j], somaparcial);
            return 0;
        }
    }
    printf("Soma por colunas correta\n");

    // Q10 - somaPorTotal_R
    printf("\nQuestao 10");
    for (i = 0; i < LINHA; i++) {
        for (j = 0; j < COLUNA; j++) {
            img[i][j] = 1;
        }
    }
    somaTotal = somaPorTotal_R(img);
    if (somaTotal == LINHA * COLUNA)
        printf("Soma total correta: %d\n", somaTotal);
    else
        printf("Erro na soma total\n");

    // Q11 - quantosPixelsNaInt_R
    printf("\nQuestao 11");
    for (i = 0; i < LINHA; i++) {
        for (j = 0; j < COLUNA; j++) {
            img[i][j] = rand() % 256;
        }
    }
    printf("Digite o numero que quer encontrar: ");
    scanf("%hhu", &inte);
    count = 0;
    for (i = 0; i < LINHA; i++) {
        for (j = 0; j < COLUNA; j++) {
            if (img[i][j] == inte)
                count++;
        }
    }
    x = quantosPixelsNaInt_R(img, inte);
    printf("Quantidade do numero %d eh %d\n", inte, x);
    if (x == count) printf("Quantidade correta\n");
    else printf("Quantidade incorreta\n");

    // Q12 - quantosPixelsAbaixoDeInt_R
    printf("\nQuestao 12\n");
    printf("Digite o numero: ");
    scanf("%hhu", &inte);
    abaixoDeInt = quantosPixelsAbaixoDeInt_R(img, inte);
    count = 0;
    for(i = 0; i < LINHA; i++) {
        for(j = 0; j < COLUNA; j++) {
            if(img[i][j] < inte) count++;
        }
    }
    if(count == abaixoDeInt) printf("\nResultado correto\n");
    else printf("\nResultado incorreto\n");

    // Q13 - quantosPixelsAcimaDeInt_R
    printf("\nQuestao 13\n");
    printf("\nDigite o numero: ");
    scanf("%hhu", &inte);
    acimaDeInt = quantosPixelsAcimaDeInt_R(img, inte);
    count = 0;
    for(i = 0; i < LINHA; i++) {
        for(j = 0; j < COLUNA; j++) {
            if(img[i][j] > inte) count++;
        }
    }
    if(count == acimaDeInt) printf("\nResultado correto\n");
    else printf("\nResultado incorreto\n");

    return 0;
}
