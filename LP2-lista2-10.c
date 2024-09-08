#include <stdio.h>
#define L 206
#define C 206

/* Implemente a função int somaPorTotal_R(unsigned char img[480][640]) que
   retorna a soma dos elementos da imagem img. */

int somaPorTotal_R(unsigned char img[L][C]);

int main() {
    unsigned char img[L][C];
    int soma;

    // Preenche a matriz img com o valor 1 em todas as posições
    for (int i = 0; i < L; i++) {
        for (int j = 0; j < C; j++) {
            img[i][j] = 1;
        }
    }

    // Calcula a soma dos elementos da matriz usando a função recursiva
    soma = somaPorTotal_R(img);

    // Verifica se a soma calculada é igual ao número total de elementos (L * C)
    if (soma == L * C)
        printf("Soma total: %d\n", soma);
    else
        printf("Erro: soma incorreta.\n");

    return 0;
}

int somaPorTotal_R(unsigned char img[L][C]) {
    static int linha = L-1, coluna = C-1, soma = 0;

    // Se a linha é menor que 0, significa que a soma de todos os elementos foi calculada
    if (linha < 0) {
        return soma;
    }

    // Adiciona o valor do elemento atual à soma
    soma += img[linha][coluna];

    // Move para a próxima coluna à esquerda
    coluna--;

    // Se a coluna é menor que 0, reseta a coluna para o último índice e move para a linha anterior
    if (coluna < 0) {
        coluna = C - 1;
        linha--;
    }

    // Chama a função recursivamente para processar a próxima posição
    return somaPorTotal_R(img);
}
