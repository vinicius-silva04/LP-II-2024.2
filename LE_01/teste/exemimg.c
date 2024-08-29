//Q1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "procimg.h"

int main(){
    srand(time(NULL)); //Inicializa o gerador de números aleatórios.

    printf("Pixel de cor mais escura: %d\n",gerarGreyPixel(-1));       //Imprime as intensidades de cor mais escura
    printf("Pixel de cor mais clara: %d\n",gerarGreyPixel(1));         //Imprime as intensidades de cor mais clara
    printf("Pixel de intensidade qualquer: %d\n",gerarGreyPixel(0));   //Imprime qualquer intensidade
return 0;
}
/*Q2
#include <stdio.h>
#include "procimg.h"
int main(){
    unsigned char img[640][480],pixel;
    int i,j;

    printf("Digite o valor que vai preencher os pixels: ");
    scanf("%d",&pixel);
    geraImgGreyFull(img,pixel);
    for(i=0;i<640;i++){
        for(j=0;j<480;j++){
            printf("%3d",img[i][j]);
        }printf("\n");
    }
return 0;
}
*/
