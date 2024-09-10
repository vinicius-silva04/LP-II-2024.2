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
int main(){
    unsigned char img[linha][coluna] = {0}, pixel;
    int i, j, soma = 0;
    
    printf("Digite o valor do pixel: ");
    scanf("%hhu", &pixel);

    geraImgGreyFull_R(img, pixel);


    for(i = 0; i < linha; i++){                 // Verifica se a imagem foi gerada corretamente
        for(j = 0; j < coluna; j++){
            if(img[i][j] == pixel) soma++;
        }
    }

    if(soma != linha*coluna) printf("erro");              //se a soma for diferente de linha*coluna, a imagem não foi gerada corretamente
    else printf("deu certo");

    
    return 0;
}
*/
//Q3
/*
#include <stdio.h>
int main(){
    unsigned char img[linha][coluna];
    int cont = 0;


    geraImgGreyB_R(img);
    

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
//Q6
/*
#define linha 480
#define coluna 640

int main(void)
{
    unsigned char img[linha][coluna];
    int i, j, pixelMax;
    // Iniciando a semente para gerar números aleatórios diferentes a cada execução
    srand(time(NULL));

    // Preenchendo a matriz img com valores aleatórios entre 0 e 255
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            img[i][j] = rand() % 256;
        }
    }

    pixelMax = pixelMax_R(img); // Coloca o valor da função pixelMax_R na variavel pixelMax
    
    printf("O maior valor eh %d", pixelMax);

    return 0;
}
*/
//Q7
/*
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define linha 480
#define coluna 640
int pixelMin_R(unsigned char img[linha][coluna]); // Declaração completa da função

int main(void)
{
    unsigned char img[linha][coluna];
    int i, j, pixelMin;
    // Iniciando a semente para gerar números aleatórios diferentes a cada execução
    srand(time(NULL));

    // Preenchendo a matriz img com valores aleatórios entre 0 e 255
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            img[i][j] = rand() % 256;
        }
    }

    pixelMin = pixelMin_R(img); // Coloca o valor da função pixelMax_R na variavel pixelMax

    printf("O menor valor eh %d", pixelMin);

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
//Q12
/*
#define linha 480
#define coluna 640

int quantosPixelsAbaixoDeInt_R(unsigned char img[linha][coluna], unsigned char Int); // Declaração completa da função

int main(void)
{
    unsigned char img[linha][coluna];
    int i, j;
    // Iniciando a semente para gerar números aleatórios diferentes a cada execução
    srand(time(NULL));

    // Preenchendo a matriz img com valores aleatórios entre 0 e 255
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            img[i][j] = rand() % 256;
        }
    }

    printf("Teve %d valores menor que o valor dado no parametro", quantosPixelsAbaixoDeInt_R(img, 20));

    return 0;
}
*/
//Q13
/*
int main(){
    unsigned char img[linha][coluna];
    int i, j, x, maior = 0, acima;
    srand(time(NULL));

    for(i = 0; i < linha; i++) {
        for(j = 0; j < coluna; j++) {
            img[i][j] = rand() % 256;
        }
    }
    printf("Digite um valor inteiro: ");
    scanf("%d", &x);

    acima = quantosPixelsAcimaDeInt_R(img, x);

    for(i = 0; i < linha; i++) {
        for(j = 0; j < coluna; j++) {
            if(img[i][j] > x) maior++;
        }
    }
    if(maior == acima) printf("A funcao esta correta\n");
    else printf("A funcao esta incorreta\n");

    return 0;
}
*/
//Q14
/*
int main(){
    unsigned char img[linha][coluna], Int = 0, equilibrio;
    int i, j, menorint, maiorint, media, reserva;
    srand(time(NULL));

    //preenchimento da matriz
     for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            img[i][j] = rand() % 256;
        }
    }

    menorint = pixelMin_R(img);
    maiorint = pixelMax_R(img);
    media = (menorint + maiorint)/2;

    equilibrio = pontoEquilibrio(img, Int);

    Int = 0;
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            reserva = img[i][j];
            if(reserva == media){
                Int = reserva;    //Verificação do valor mais próximo da média
                break;
            }
            else if(abs(reserva - media) < abs(Int - media)){
                Int = reserva;    //Verificação do valor mais próximo da média
            }
        }
    }

    if(Int != equilibrio){
        printf("Int = %d, equilibrio = %d\nERRO!!!\n");   //Se for diferente lascou
    }
    return 0;
}
*/
