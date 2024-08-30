#include <stdlib.h>
#include <stdio.h>
#include "procimg.h"

// Define a resolu��o da imagem (ajusta conforme necess�rio)
#define WIDTH 640
#define HEIGHT 480

int pixelMax(unsigned char);

int main() {

    return 0;
}

// Fun��o para encontrar o valor m�ximo de um pixel na imagem
int pixelMax(unsigned char img[WIDTH][HEIGHT]) {
    int max = 0; // Inicializa o valor m�ximo com 0

    // Percorre todos os pixels da imagem
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (img[i][j] > max) {
                max = img[i][j]; // Atualiza o valor m�ximo se encontrar um pixel com intensidade maior
            }
        }
    }

    return max;
}


