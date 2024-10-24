#include <stdio.h>
#include <stdlib.h>

/*Implementa a função tRGB somaTotalRGB(imgRGB img) que retorna a soma dos elementos 
por canal (R, G, B) da imagem img.*/

typedef unsigned char uchar;
int i, j;

typedef struct {
    unsigned char R, G, B;
}tRGB;

typedef struct {
    tRGB *_img;
    tRGB **img;
    int nLin, nCol;
}imgRGB;

imgRGB alocaImagemRGB(int nLin, int nCol) {
    imgRGB img2;
    img2.nLin = nLin;
    img2.nCol = nCol;
    img2._img = (tRGB*) malloc (nLin*nCol*sizeof(tRGB)); //aloca matriz unidimensional
    img2.img = (tRGB**) malloc (nLin*sizeof(tRGB*));  //aloca matriz bidimensional
    // Verifica se a alocação falhou
    if (img2._img == NULL || img2.img == NULL) {
        img2._img = NULL;
        img2.img = NULL;
        return img2;  // Retorna a estrutura com ponteiros NULL
    }
    for (i = 0; i<nLin; i++) {
        img2.img[i] = img2._img + i*nCol;
    }
    return img2;
}

tRGB somaTotalRGB (imgRGB img) {
    tRGB total = {0, 0, 0};        //inicializar as variáveis R, G, B do struct com 0
    
    /*Soma os valores da imagem bidimensional RGB imagem2 (chamada de img no parâmetro) 
    nos canais R, G e B percorrendo nLin e nCol*/
    for (i = 0; i<img.nLin; i++) { 
        for (j = 0; j<img.nCol; j++) {
            total.R += img.img [i][j].R;    
            total.G += img.img [i][j].G;
            total.B += img.img [i][j].B;
        }
    }
    return total;  //retorna a soma acumulada dos canais
}

int main () {
    int l = 3, c = 3;
    imgRGB imagem2 = alocaImagemRGB (l, c);
    if (imagem2.img==NULL || imagem2._img==NULL) {   //comunicar o usuário a falha na alocação da memória
        printf("Falha na alocacao de memoria!\n");
        return 1;
    }

    // Preenche a imagem RGB com valores arbitrários
    for (i = 0; i < l; i++) {
        for (j = 0; j < c; j++) {
            imagem2.img[i][j].R = 3;  // Define o valor do vermelho (R)
            imagem2.img[i][j].G = 5;  // Define o valor do verde (G)
            imagem2.img[i][j].B = 7;  // Define o valor do azul (B)
        }
    }

    tRGB total = somaTotalRGB (imagem2);    //chamada da função
    printf("\nSoma total dos canais RGB\n");      //printa a soma dos canais
    printf ("Soma R: %u\n", total.R);
    printf ("Soma G: %u\n", total.G);
    printf ("Soma B: %u\n", total.B);
    
    free (imagem2._img);     //desaloca espaço contínuo
    free (imagem2.img);     //desaloca espaço das linhas
    return 0;
}