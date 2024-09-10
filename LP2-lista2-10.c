#include <stdio.h>
#define linha 206
#define coluna 206

/* Implemente a função int somaPorTotal_R(unsigned char img[linha][coluna]) que
   retorna a soma dos elementos da imagem img. */

int somaPorTotal_R(unsigned char img[linha][coluna]);

int main() {
    unsigned char img[linha][coluna];
    int soma;

    // Preenche a matriz img com o valor 1 em todas as posições
    for (int i = 0; i < linha; i++) {
        for (int j = 0; j < coluna; j++) {
            img[i][j] = 1;
        }
    }

    // Calcula a soma dos elementos da matriz usando a função recursiva
    soma = somaPorTotal_R(img);

    // Verifica se a soma calculada é igual ao número total de elementos (linha * coluna)
    if (soma == linha * coluna)
        printf("Soma total: %d\n", soma);
    else
        printf("Erro: soma incorreta.\n");

    return 0;
}

int somaPorTotal_R(unsigned char img[linha][coluna]) {
    static int L = linha-1, C = coluna-1, soma = 0;

    // Se a L é menor que 0, significa que a soma de todos os elementos foi calculada
    if (L < 0) {
        return soma;
    }

    // Adiciona o valor do elemento atual à soma
    soma += img[L][C];

    // Move para a próxima coluna à esquerda
    C--;

    // Se a coluna é menor que 0, reseta a coluna para o último índice e move para a linha anterior
    if (C < 0) {
        C = coluna - 1;
        L--;
    }

    // Chama a função recursivamente para processar a próxima posição
    return somaPorTotal_R(img);
}
