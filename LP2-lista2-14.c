#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define coluna 300
#define linha 300
#define MAX 255
#define MAXDIF 65025  // 255 * 255

unsigned char pontoEquilibrio(unsigned char img[linha][coluna]);
void histograma (unsigned char img [linha][coluna], int L, int C);
void preencherimg (unsigned char img [linha][coluna], int L, int C, int tipo);
unsigned char geraGreyPixel(int tipo);

int hist [MAX+1];

int main() {
    unsigned char img[linha][coluna], equilibrio;
    int tipo;
    srand (time (NULL));
    preencherimg (img, 0, 0, 200);
    histograma (img, 0, 0);
    equilibrio = pontoEquilibrio(img);
    printf("Ponto de Equilíbrio: %hhu\n", equilibrio);
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
            num = 128 + rand() % 128;       //20% de chance de todas as cores
        else
            num = rand() % 256;
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
    static int i = 0;
    static int dif_esquerda = 0;
    static int dif_direita = linha * coluna;
    static int menordif = MAXDIF;     // Maior diferença possível
    static unsigned char equilibrio = 0;

    /* Explicação do maxdif: A diferença máxima possivel é 255 - 0 = 255.
       O array tem 255 posições. Logo, se todas as diferenças individuais 
       entre esquerda e direita forem 255,serão 255 valores 255 vezes. Sendo 
       assim, o valor maximo é 255*255 = 65025 */
    
    if (i > MAX) return equilibrio;    // condição de parada
    
    // Atualizar as diferenças
    dif_direita -= hist[i];
    dif_esquerda += hist[i];
    int dif = (dif_esquerda > dif_direita) ? (dif_esquerda - dif_direita) : (dif_direita - dif_esquerda);
    if (dif < menordif) {   //Atualizar o ponto de equilíbrio se necessário
        menordif = dif;
        equilibrio = (unsigned char) i;
    }
    i++;    //incremento para percorrer o array
    return pontoEquilibrio(img);
}
