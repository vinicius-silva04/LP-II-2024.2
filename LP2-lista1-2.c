//parte que vai no procimg.h
void geraImgGreyFull ( unsigned char img [640][480], unsigned char pixel);
/*
    *Fun��o que preenche a imagem com o valor do par�metro pixel.
    *Par�metro:
    * img: matriz onde a imagem ser� preenchida.
    * pixel: n�mero que ser� preenchido a imagem.
    *Retorno:
    * int: n�mero gerado que determina a intensidade.
*/

//parte que vai pro procimg.c
void geraImgGreyFull ( unsigned char img [640][480], unsigned char pixel){
    int i,j;
    for(i=0;i<640;i++){
        for(j=0;j<480;j++){
            img[i][j]= pixel;
        }
    }
}
//

//parte que vai exemimg.c
#include <stdio.h>
//#include "procimg.h"
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














    /*definir o numero que vai preencher a imagem e depois imprimir*/
