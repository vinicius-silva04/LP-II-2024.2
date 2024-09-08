#include <stdio.h>
#define L 480
#define C 640

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

int linha = 0;
int somaPorTotal_R(unsigned char img[L][C]) {
    int soma = 0;
    if (linha>=L)
        return 0;        //não há mais linhas a serem processadas e retorna 0 às funções anteriores para não altera a soma total acumulado.
    for (int i = 0; i<C; i++) {
        soma += img [linha][i];
    }
    linha++;
    // Soma a linha atual com a soma das linhas seguintes
    return soma + somaPorTotal_R(img);
}
