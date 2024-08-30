#include <stdlib.h>
#include <stdio.h>
#include "procimg.h"

// Define a resolução da imagem (ajusta conforme necessário)
#define WIDTH 640
#define HEIGHT 480

int pixelMin(unsigned char);

int main() {

    return 0;
}

// Função para encontrar o valor mínimo de um pixel na imagem
int pixelMin(unsigned char img[WIDTH][HEIGHT]) {
    int min = 255; // Inicializa o valor mínimo com o maior valor possível para um unsigned char

    // Percorre todos os pixels da imagem
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (img[i][j] < min) {
                min = img[i][j]; // Atualiza o valor mínimo se encontrar um pixel com intensidade menor
            }
        }
    }

    return min;
}


