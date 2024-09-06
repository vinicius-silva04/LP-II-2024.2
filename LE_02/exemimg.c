#include "procimg.h"
//Q2
/*#include <stdio.h>
#define linha 480
#define coluna 640
int main(){
    unsigned char img[linha][coluna], pixel;
    int cont = 0;

    printf("Digite o valor do pixel: ");
    scanf("%hhu", &pixel);
    
    geraImgGreyFull_R(img, pixel, linha, coluna);
    
    for(int i = 0; i < linha; i++){                                         // Verifica se a imagem foi gerada corretamente
        for(int j = 0; j < coluna; j++){ 
            if(img[i][j] != pixel){
                printf("Erro: img[%d][%d] = %hhu\n", i, j, img[i][j]);          // Se algum pixel não for igual ao valor digitado, a imagem não foi gerada corretamente
                return 0;
            }
            else cont++;                                        // Conta a quantidade de pixels gerados iguais ao valor digitado         
        }
    }

    if(linha * coluna == cont) printf("\n\nImagem gerada com sucesso!\n");     //linha * coluna representa a quantidade de pixels da imagem, que deve ser igual a cont
    else printf("\n\nErro na geração da imagem!\n");

    return 0;
}
*/
//Q3
/*#include <stdio.h>
#define linha 480
#define coluna 640
int main(){
    unsigned char img[linha][coluna];
    int cont = 0;
   
    geraImgGreyB_R(img, linha, coluna);
    
    for(int i = 0; i < linha; i++){                                         // Verifica se a imagem foi gerada corretamente
        for(int j = 0; j < coluna; j++){ 
            if(img[i][j] != 0){
                printf("Erro: img[%d][%d] = %hhu\n", i, j, img[i][j]);          // Se algum pixel não for igual a 0, a imagem não foi gerada corretamente
            }
            else cont++;                                        // Conta a quantidade de pixels gerados iguais a 0        
        }
    }

    if(linha * coluna == cont) printf("\n\nImagem gerada com sucesso!\n");     //linha * coluna representa a quantidade de pixels da imagem, que deve ser igual a cont
    else printf("\n\nErro na geracao da imagem!\n");

    return 0;
}
*/

//Q4
/*#include <stdio.h>

int main(){
    unsigned char img[480][640];
    int cont = 0,i,j;

    geraImgGreyW_R(img);
    for(i = 0; i < 480; i++){                                         // Verifica se a imagem foi gerada corretamente
        for(j = 0; j < 640; j++){ 
            if(img[i][j] == 255){
            cont++;                                        // Conta a quantidade de pixels gerados iguais a 255      
            }else printf("Erro! img[%d][%d]: %u",i,j,img[i][j]);
        }
    }printf("Exemplo:\nimg[%d][%d]: %u",i,j,img[i-1][j-1]);
    if(480*640 == cont) printf("\n\nImagem gerada com sucesso!\n");     //linha * coluna representa a quantidade de pixels da imagem, que deve ser igual a cont
    else printf("\n\nErro na geracao da imagem!\n");


    
return 0;
}
*/
//Q5
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    unsigned char img[480][640];
    int i,j,cont=0;
    srand(time(NULL));
    geraImgGrey_R(img,0);
    for(i=0;i<480;i++){
        for(j=0;j<640;j++){
            int k=img[i][j];
            if(k>=0 && k<256){
                cont++;
            }else printf("Erro! img[%d][%d]: %u",i,j,img[i][j]);
        }
    }printf("Exemplo:\nimg[%d][%d]: %u",i,j,img[i-1][j-1]);
    if(480*640==cont) printf("\n\nImagem gerada com sucesso");
    else printf("Erro na imagem gerada");
return 0;
}
*/
