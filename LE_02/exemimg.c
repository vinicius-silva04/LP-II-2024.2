#include "procimg.h"
//Q1
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 640

int main () {
    int tipo;
    unsigned char array [N];
    srand (time (NULL));
    printf (" tipo < 0 = cores mais escuras\n tipo > 0 = cores mais claras\n tipo == 0 = todas as intensidades\n");
    printf ("\nDigite o tipo de intensidade: ");
    scanf ("%d", &tipo);
    geraLinhaR(array, tipo);         
    for (int i = 0; i < N; i++) {
        if (array[i] > 255) {     // Valor fora do intervalo esperado
            printf ("Erro: O array contém valores fora do esperado.\n");
            return 0;  
        }
    }
    printf ("\nArray preenchido corretamente!\n");
    return 0;
} 
*/
//Q2
/*
#include <stdio.h>
#define linha 480
#define coluna 640
int main(){
    unsigned char img[linha][coluna], pixel;
    int cont = 0;

    printf("Digite o valor do pixel: ");
    scanf("%hhu", &pixel);
    
    geraImgGreyFull_R(img, pixel, 480, 640);
    
    for(int i = 0; i < linha; i++){                                         // Verifica se a imagem foi gerada corretamente
        for(int j = 0; j < coluna; j++){ 
            if(img[i][j] != pixel){
                printf("Erro: img[%d][%d] = %u\n", i, j, img[i][j]);          // Se algum pixel não for igual ao valor digitado, a imagem não foi gerada corretamente
                return 0;
            }
            else cont++;                                        // Conta a quantidade de pixels gerados iguais ao valor digitado         
        }
    }printf("Exemplo:\nimg[%d][%d]: %u",linha,coluna,img[linha-1][coluna-1]);

    if(linha * coluna == cont) printf("\n\nImagem gerada com sucesso!\n");     //linha * coluna representa a quantidade de pixels da imagem, que deve ser igual a cont
    else printf("\n\nErro na geração da imagem!\n");

    return 0;
}
*/
//Q3
/*
#include <stdio.h>
#define linha 480
#define coluna 640
int main(){
    unsigned char img[linha][coluna];
    int cont = 0;
   
    geraImgGreyB_R(img,linha,coluna);
    
    for(int i = 0; i < linha; i++){                                         // Verifica se a imagem foi gerada corretamente
        for(int j = 0; j < coluna; j++){ 
            if(img[i][j] != 0){
                printf("Erro: img[%d][%d] = %u\n", i, j, img[i][j]);          // Se algum pixel não for igual a 0, a imagem não foi gerada corretamente
                return 0;
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
            }else{
                printf("Erro! img[%d][%d]: %u",i,j,img[i][j]);
                return 0;
            }
        }
    }printf("Exemplo:\nimg[%d][%d]: %u",i,j,img[i-1][j-1]);
    if(480*640 == cont) printf("\n\nImagem gerada com sucesso!\n");     //linha * coluna representa a quantidade de pixels da imagem, que deve ser igual a cont
    else printf("\n\nErro na geracao da imagem!\n");


    
return 0;
}
*/
//Q5
/*
#include <stdio.h>
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
//Q8
/*
int main(){
    unsigned char img[linha][coluna];
    int soma[linha] = {0}, i = 0, j = 0, somaparcial = 0;    //somaparcial será usado para verificação de cada soma
    srand(time(NULL));

    //preenchimento da matriz
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            img[i][j] = rand() % 256;
        }
    }

    somaPorLinhas_R(img, soma);   //chamada da função

     for(i = 0; i < linha; i++){
        somaparcial = 0;
        for(j = 0; j < coluna; j++){
            somaparcial += img[i][j];   //Verificação de cada soma
        }
        if(soma[i] != somaparcial){
            printf("Array soma = %d, soma parcial = %d", soma[i], somaparcial);  //Mostra o erro
            printf("ERRO!!");   //Verificação, se a soma parcial for diferente da soma no respectivo local do array, é erro.
            return 0;
        }
        
    }
    
    //Mostra a ultima soma parcial e ultima soma do vetor
    printf("ultima soma do array = %d, ultima soma parcial = %d", soma[linha - 1], somaparcial); 
    printf("\nTUDO CERTO!!\n");

    return 0;
}
*/
//Q9
/*
int main(){
    unsigned char img[linha][coluna] = {0};
    int i = 0, j = 0, soma[coluna] = {0}, somaparcial = 0;   
    srand(time(NULL));

    //preenchimento da matriz
     for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            img[i][j] = rand() % 256;
        }
    }
    
    somaPorColunas_R(img, soma);
    for(j = 0; j < coluna; j++){
        somaparcial = 0;
        for(i = 0; i < linha; i++){
            somaparcial += img[i][j];   //somaparcial será usado para verificação de cada soma
        }
        if(soma[j] != somaparcial){
            printf("Array soma = %d, soma parcial = %d", soma[j], somaparcial);  // Mostra o erro
            printf("\nERRO!!\n");   //Verificação, se a soma parcial for diferente da soma no respectivo local do array, é erro.
            return 0;
        }
    }

    //Mostra a ultima soma parcial e ultima soma do vetor
    printf("ultima soma array = %d, ultima soma parcial = %d\n", soma[coluna - 1], somaparcial); 
    printf("\nTUDO CERTO!!\n");
        
    return 0;
}
*/
