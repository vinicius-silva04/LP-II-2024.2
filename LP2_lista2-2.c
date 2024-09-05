#include <stdio.h>

#define linha 20
#define coluna 20

void geraImgGreyFull_R(unsigned char img[linha][coluna], unsigned char pixel, int i, int j);

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

void geraImgGreyFull_R(unsigned char img[linha][coluna], unsigned char pixel, int i, int j){
    if(i == 0 && j == 0) return;    //quando i e j forem iguais a 0, a imagem estará completa, e a função encerra
    img[i-1][j-1] = pixel;          //atribui o valor do pixel na posição i-1 e j-1
    if(j == 0) geraImgGreyFull_R(img, pixel, i-1, coluna);  //quando apenas j for 0, a linha i ja tera sido preenchida, e passamos para a proxima linha i-1, e voltamos para a primeira coluna->coluna
    else geraImgGreyFull_R(img, pixel, i, j-1); //quando j for diferente de 0, preenchemos a mesma linha i, e passamos para a coluna j-1
}