#include <stdlib.h>
#include <stdio.h>
#include "procimg.h"

// Define a resolução da imagem (ajusta conforme necessário)
#define WIDTH 640
#define HEIGHT 480

int pixelMax(unsigned char);

int main() {

    return 0;
}

// Função para encontrar o valor máximo de um pixel na imagem
int pixelMax(unsigned char img[WIDTH][HEIGHT]) {
    int max = 0; // Inicializa o valor máximo com 0

    // Percorre todos os pixels da imagem
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (img[i][j] > max) {
                max = img[i][j]; // Atualiza o valor máximo se encontrar um pixel com intensidade maior
            }
        }
    }

    return max;
}


