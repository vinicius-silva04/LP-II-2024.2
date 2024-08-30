#include <stdio.h>
#include <math.h>

void media_desvio (unsigned char img [640][480], double *desviop, double *media);
int i, j;

int main () {
    unsigned char img [640][480];
    double media=0, desviop=0;
    printf ("Digite as intensidades de cada pixel (0-255)\n");

    //Leitura das intensidades dos pixels da imagem
    for (i = 0; i<640; i++) {
        for (j = 0; j<480; j++) {
            printf ("[%d][%d]: ", i, j);
            scanf ("%u", &img [i][j]);
        }
    }
    media_desvio (img, &desviop, &media);
    printf ("\nMedia: %.2lf\nDesvio padrao: %.2lf\n", media, desviop);
}

void media_desvio (unsigned char img [640][480], double *desviop, double *media) {
    double soma=0, diferenca=0;

    //Soma de todos as intensidades dos pixels
    for (i = 0; i<640; i++) {
        for (j = 0; j<480; j++) {
            soma += img [i][j];
        }
    }
    *media = soma/(640*480);

    //Desvio padrão = raiz de {[(img [i][j] - media)²]/total]}
    for (i = 0; i<640; i++) {
        for (j = 0; j<480; j++) {
            diferenca +=  (img [i][j] - *media)*(img [i][j] - *media);
        }
    }
    *desviop = sqrt (diferenca/(640*480));
}
