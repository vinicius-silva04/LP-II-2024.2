#include <stdio.h>
#define L 250
#define C 250

/* Implemente a função int somaPorTotal_R(unsigned char img[480][640]) que
   retorna a soma dos elementos da imagem img. */
int somador(unsigned char img [L][C],int s,int i,int j);
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

int somador(unsigned char img[L][C],int s,int i,int j){
    if (i>=L) return s;
    s+=img[i][j];
     if (j == C - 1) {
        // Vai para a próxima linha e reseta a coluna para 0
        return somador(img, s, i + 1, 0);
    } else {
        // Continua na mesma linha, próxima coluna
        return somador(img, s, i, j + 1);
    }
}
int somaPorTotal_R(unsigned char img[L][C]) {
    int soma= somador(img,0,0,0);
return soma;
    
}
