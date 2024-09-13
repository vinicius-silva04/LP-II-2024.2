#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define coluna 250
#define linha 250
#define MAX 255
#define MAXDIF 65025  // 255 * 255

unsigned char pontoEquilibrio(unsigned char img[linha][coluna]);
unsigned char pontoEquilibrio_aux(unsigned char img[linha][coluna], int i, int dif_esquerda, int dif_direita, int menordif, unsigned char equilibrio);
void histograma (unsigned char img [linha][coluna], int L, int C);
void preencherimg (unsigned char img [linha][coluna], int L, int C, int tipo);
unsigned char geraGreyPixel(int tipo);

int hist [MAX+1] = {0};

int main() {
    unsigned char img[linha][coluna], equilibrio;
    int tipo=11;
    srand (time (NULL));
    preencherimg (img, 0, 0, tipo);
    histograma (img, 0, 0);
    equilibrio = pontoEquilibrio(img);
    printf("Ponto de Equilibrio: %hhu\n", equilibrio);
    
    // Verificação do ponto de equilíbrio com base no tipo
    if (tipo < 0 && equilibrio >= 50 && equilibrio <= 100)
        printf("O ponto de equilibrio esta dentro do intervalo esperado.\n");
    else if (tipo > 0 && equilibrio >= 180 && equilibrio <= 220)
        printf("O ponto de equilibrio esta dentro do intervalo esperado.\n");
    else if (tipo == 0 && equilibrio >= 100 && equilibrio <= 150)
        printf("O ponto de equilibrio esta dentro do intervalo esperado.\n");
    else
        printf("ERRO: O ponto de equilibrio esta fora do intervalo esperado.\n");
    return 0;
}

void preencherimg (unsigned char img [linha][coluna], int L, int C, int tipo){
    if (L>=linha) return;
    if (C>=coluna) {
        return preencherimg (img, L+1, 0, tipo);
    }
    img [L][C] = geraGreyPixel(tipo);
    preencherimg (img, L, C+1, tipo);
}

unsigned char geraGreyPixel(int tipo) {
    unsigned char num;
    int probabilidade = rand () % 100;
    if(tipo < 0){
       if (probabilidade < 80)      //80% de chance de cor escura
            num = rand() % 128;
       else                        //20% de chance de todas as cores
            num = rand() % 256;
    }
    else if (tipo > 0) {
        if (probabilidade < 80)             //80% de chance de cor clara
            num = 128 + rand() % 128;       
        else
            num = rand() % 256;            //20% de chance de todas as cores
    }
    else
        num = rand() % 256;          //100% de chance de todas as cores
    return num;
}

void histograma (unsigned char img [linha][coluna], int L, int C) {
    if (L>=linha) return;
    if (C>=coluna) {
        return histograma (img, L+1, 0);
    }
    hist[img[L][C]]++;
    histograma (img, L, C+1);
}

unsigned char pontoEquilibrio(unsigned char img[linha][coluna]) {
    return pontoEquilibrio_aux (img, 0, 0, linha*coluna, MAXDIF, 0);

    /* Explicação do maxdif: A diferença máxima possivel é 255 - 0 = 255.
       O array tem 255 posições. Logo, se todas as diferenças individuais 
       entre esquerda e direita forem 255,serão 255 valores 255 vezes. Sendo 
       assim, o valor maximo é 255*255 = 65025 */
}

unsigned char pontoEquilibrio_aux(unsigned char img[linha][coluna], int i, int dif_esquerda, int dif_direita, int menordif, unsigned char equilibrio) {
    if (i > MAX) return equilibrio;    // condição de parada
    
    // Atualizar as diferenças
    dif_direita -= hist[i];
    dif_esquerda += hist[i];
     int dif = (dif_esquerda > dif_direita) ? (dif_esquerda - dif_direita) : (dif_direita - dif_esquerda);
    if (dif < menordif) {   //Atualizar o ponto de equilíbrio se necessário
        menordif = dif;
        equilibrio = (unsigned char) i;
    }
    return pontoEquilibrio_aux(img, i+1, dif_esquerda, dif_direita, menordif, equilibrio);
}
