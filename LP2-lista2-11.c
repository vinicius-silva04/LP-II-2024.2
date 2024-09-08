#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define L 150
#define C 200

/*int quantosPixelsNaInt_R(unsigned char img[480][640], unsigned char int) 
retorna a quantidade de pixels, na imagem img, que possuem uma intensidade 
específica int.*/

int quantosPixelsNaInt_R (unsigned char img[L][C], unsigned char inte);

int main () {
    unsigned char img [L][C], inte;
    int i, j, count=0;
    srand (time (NULL));
    for (i = 0; i<L; i++) {
        for (j = 0; j<C; j++) {
            img [i][j] = rand () % 256;     //preencher a img com numeros aleatorios
        }
    }
    printf ("Digite o numero que quer encontrar: ");
    scanf ("%hhu", &inte);      //pede para o usuário qual intensidade ele quer procurar
    
    for (i = 0; i<L; i++) {
        for (j = 0; j<C; j++) {
            if (img[i][j]==inte) count++;   //contador de frequência do inte na img
        }
    }
    if (count==quantosPixelsNaInt_R (img, inte))   //verifica se a função retorna a contagem correta
        printf ("\nO numero %hhu apareceu %d vezes \n", inte, count);   //imprime a frequência se estiver correta
    else
        printf ("\nErro: Contagem incorreta.\n");  // exibe mensagem de erro se estiver incorreta
}

int linha = 0, coluna = 0;  // declaração de variáveis globais para manipular na função

int quantosPixelsNaInt_R (unsigned char img[L][C], unsigned char inte) {
    int count = 0;
    if (linha >= L) return 0;          // verifica se todas as linhas estão preenchidas
    if (img [linha][coluna]==inte)     // contador de frequência do inte na img
        count++;
    coluna++;
    if (coluna>=C) {        //se completar uma coluna, pula a linha e percorre as colunas dnv
        coluna = 0;
        linha++;
    }
    // Retorna a soma da contagem de pixels encontrados no bloco atual e a contagem
    // dos pixels encontrados nas chamadas recursivas seguintes.
    return count + quantosPixelsNaInt_R (img, inte);
}