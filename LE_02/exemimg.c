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
