#include "procimg.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main () {

    printf("QUESTAO 1:\n\n");

    int tipo, escuro=0, claro=0;
    unsigned char array [N];
    srand (time (NULL));
    printf (" tipo < 0 = cores mais escuras\n tipo > 0 = cores mais claras\n tipo == 0 = todas as intensidades\n");
    printf ("\nDigite o tipo de intensidade: ");
    scanf ("%d", &tipo);
    geraLinhaR(array, tipo);
    for (int i = 0; i < N; i++)
    {
        if (array[i]<128) escuro++;
        if (array[i]>=128) claro++;
    }
    if (tipo<0 && escuro>claro || tipo>0 && claro>escuro || tipo==0)
        printf ("\nArray preenchido corretamente!\n");
    else
        printf ("\nErro: O array nao foi preenchido majoritariamente pelo tipo solicitado.\n");
    printf ("Cores escuras: %d\nCores claras: %d\n", escuro, claro);

    printf("\n-------------------------------------------------------------------------------------------------\n\n");

    printf("QUESTAO 2:\n\n");

    unsigned char img[linha][coluna] = {0}, pixel;
    int i, j, soma = 0;

    printf("Digite o valor do pixel: ");
    scanf("%hhu", &pixel);

    geraImgGreyFull_R(img, pixel);


    for(i = 0; i < linha; i++)                  // Verifica se a imagem foi gerada corretamente
    {
        for(j = 0; j < coluna; j++)
        {
            if(img[i][j] == pixel) soma++;
        }
    }

    if(soma != linha*coluna) printf("Erro!");              //se a soma for diferente de linha*coluna, a imagem n�o foi gerada corretamente
    else printf("\nDeu certo! Confira uma parte da imagem:\n");
    for (i=0; i<5; i++) {
        for (j=0; j<5; j++) {
            printf ("%3hhu", img[i][j]);
        }
        printf ("\n");
    }
    

    printf("\n-------------------------------------------------------------------------------------------------\n\n");

    printf("QUESTAO 3:\n\n");

    int cont = 0;


    geraImgGreyB_R(img);


    for(int i = 0; i < linha; i++)                                          // Verifica se a imagem foi gerada corretamente
    {
        for(int j = 0; j < coluna; j++)
        {
            if(img[i][j] != 0)
            {
                printf("Erro: img[%d][%d] = %hhu\n", i, j, img[i][j]);          // Se algum pixel n�o for igual a 0, a imagem n�o foi gerada corretamente

            }
            else cont++;                                        // Conta a quantidade de pixels gerados iguais a 0
        }
    }

    if(linha * coluna == cont) printf("Imagem gerada com sucesso!\n");     //linha * coluna representa a quantidade de pixels da imagem, que deve ser igual a cont
    else printf("Erro na geracao da imagem!\n");
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            printf ("%3hhu", img[i][j]);
        }
        printf ("\n");
    }

    printf("\n-------------------------------------------------------------------------------------------------\n\n");

    /*printf("QUESTAO 4:\n\n");

    cont = 0;

    geraImgGreyW_R(img);
    for(i = 0; i < linha; i++)                                          // Verifica se a imagem foi gerada corretamente
    {
        for(j = 0; j < coluna; j++)
        {
            if(img[i][j] == 255)
            {
                cont++;                                        // Conta a quantidade de pixels gerados iguais a 255
            }
            else
            {
                printf("Erro! img[%d][%d]: %u",i,j,img[i][j]);
                return 0;
            }
        }
    }
    printf("Exemplo:\nimg[%d][%d]: %u",i,j,img[i-1][j-1]);
    if(linha*coluna == cont) printf("Imagem gerada com sucesso!\n");     //linha * coluna representa a quantidade de pixels da imagem, que deve ser igual a cont
    else printf("Erro na geracao da imagem!\n");*/

    printf("\n-------------------------------------------------------------------------------------------------\n\n");

    printf("QUESTAO 5:\n\n");

    tipo=0;

    srand(time(NULL));
    geraImgGrey_R(img, tipo);
    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            int k = img[i][j];
            if (k<0 || k>255)
            {
                printf("Erro na imagem gerada!\nimg[%d][%d]: %hhu",i, j, img[i][j]);
                return 1;
            }
        }
    }
    printf("\n\nImagem gerada com sucesso! Confira uma parte: \n");
    for (i=0; i<5; i++) {
        for (j=0; j<5; j++) {
            printf ("%3hhu", img[i][j]);
        }
        printf ("\n");
    }

    printf("\n-------------------------------------------------------------------------------------------------\n\n");

    printf("QUESTAO 6:\n\n");

    int pixelMax, max = 0;

    pixelMax = pixelMax_R(img);

    printf("O maior valor eh %d", pixelMax);

    for(i = 0; i<linha; i++)
    {
        for(j = 0; j<coluna; j++)
        {
            if(img[i][j] > max)
            {
                max = img[i][j];
            }
        }
    }
    if(max == pixelMax) printf("\nTudo certo\n");
    else printf("\nErro\n");

    printf("\n-------------------------------------------------------------------------------------------------\n\n");

    printf("QUESTAO 7:\n\n");

    int pixelMin, min;
    // Iniciando a semente para gerar n�meros aleat�rios diferentes a cada execu��o

    pixelMin = pixelMin_R(img); // Coloca o valor da fun��o pixelMax_R na variavel pixelMax

    printf("O menor valor eh %d", pixelMin);

    for(i = 0; i< linha; i++)
    {
        for(j = 0; j< coluna; j++)
        {
            if(img[i][j] < min)
            {
                min = img[i][j];
            }
        }
    }

    if(min == pixelMin) printf("\nTudo certo\n");
    else printf("\nErro\n");

    printf("\n-------------------------------------------------------------------------------------------------\n\n");

    printf("QUESTAO 8:\n\n");

    /*int somaVetor[linha] = {0}, somaparcial = 0;    //somaparcial ser� usado para verifica��o de cada soma

    somaPorLinhas_R(img, soma);   //chamada da fun��o

     for(i = 0; i < linha; i++){
        somaparcial = 0;
        for(j = 0; j < coluna; j++){
            somaparcial += img[i][j];   //Verifica��o de cada soma
        }
        if(somaVetor[i] != somaparcial){
            printf("Array soma = %d, soma parcial = %d", somaVetor[i], somaparcial);  //Mostra o erro
            printf("ERRO!!");   //Verifica��o, se a soma parcial for diferente da soma no respectivo local do array, � erro.
            return 0;
        }

    }

    //Mostra a ultima soma parcial e ultima soma do vetor
    printf("ultima soma do array = %d, ultima soma parcial = %d", somaVetor[linha - 1], somaparcial);
    printf("\nTUDO CERTO!!\n");*/

    printf("\n-------------------------------------------------------------------------------------------------\n\n");

    printf("QUESTAO 9:\n\n");

    /*int somaVetor2[coluna] = {0}, somaparcial = 0;
    srand(time(NULL));

    //preenchimento da matriz
     for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            img[i][j] = rand() % 256;
        }
    }

    somaPorColunas_R(img, somaVetor2);
    for(j = 0; j < coluna; j++){
        somaparcial = 0;
        for(i = 0; i < linha; i++){
            somaparcial += img[i][j];   //somaparcial ser� usado para verifica��o de cada soma
        }
        if(somaVetor2[j] != somaparcial){
            printf("Array soma = %d, soma parcial = %d", somaVetor2[j], somaparcial);  // Mostra o erro
            printf("\nERRO!!\n");   //Verifica��o, se a soma parcial for diferente da soma no respectivo local do array, � erro.
            return 0;
        }
    }

    //Mostra a ultima soma parcial e ultima soma do vetor
    printf("ultima soma array = %d, ultima soma parcial = %d\n", somaVetor2[coluna - 1], somaparcial);
    printf("\nTUDO CERTO!!\n");*/

    printf("\n-------------------------------------------------------------------------------------------------\n\n");

    printf("QUESTAO 10:\n\n");

    soma = 0;

    // Preenche a matriz img com o valor 1 em todas as posi��es
    for (int i = 0; i < linha; i++)
    {
        for (int j = 0; j < coluna; j++)
        {
            img[i][j] = 1;
        }
    }

    // Calcula a soma dos elementos da matriz usando a fun��o recursiva
    soma = somaPorTotal_R(img);

    // Verifica se a soma calculada � igual ao n�mero total de elementos (linha * coluna)
    if (soma == linha * coluna)
        printf("Soma total: %d\n", soma);
    else
        printf("Erro: soma incorreta.\n");

    printf("\n-------------------------------------------------------------------------------------------------\n\n");

    printf("QUESTAO 11:\n");
    printf("-------------------------------------------------------------------------------------------------\n");
    int count = 0, inte;
    for (i = 0; i<linha; i++) {
        for (j = 0; j<coluna; j++) {
            img[i][j] = rand () % 256;
        }
    }
    printf ("Digite o numero que quer encontrar: ");
    scanf ("%hhu", &inte);      //pede para o usu�rio qual intensidade ele quer procurar

    for (i = 0; i<linha; i++)
    {
        for (j = 0; j<coluna; j++)
        {
            if (img[i][j]==inte) count++;   //contador de frequ�ncia do inte na img
        }
    }
    if (count==quantosPixelsNaInt_R (img, inte))   //verifica se a fun��o retorna a contagem correta
        printf ("\nO numero %hhu apareceu %d vezes", inte, count);   //imprime a frequ�ncia se estiver correta
    else
        printf ("\nErro: Contagem incorreta.");  // exibe mensagem de erro se estiver incorreta

    printf("\n-------------------------------------------------------------------------------------------------\n\n");

    printf("QUESTAO 12:\n");
    printf("-------------------------------------------------------------------------------------------------\n");

    min = 0;
    // Iniciando a semente para gerar n�meros aleat�rios diferentes a cada execu��o
    srand(time(NULL));

    // Preenchendo a matriz img com valores aleat�rios entre 0 e 255
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < coluna; j++)
        {
            img[i][j] = rand() % 256;
        }
    }

    int x = quantosPixelsAbaixoDeInt_R(img, 20);
    printf("Teve %d valores menor que o valor dado no parametro", x);

    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            if(img[i][j] < 20) min++;
        }
    }

    if(min == x) printf("\nTudo certo\n");
    else printf("\nErro\n");

    printf("\n-------------------------------------------------------------------------------------------------\n\n");

    printf("QUESTAO 13:\n");
    printf("-------------------------------------------------------------------------------------------------\n");

    int maior = 0, acima = 0, x;
    srand(time(NULL));

    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            img[i][j] = rand() % 256;
        }
    }
    printf("Digite um valor inteiro: ");
    scanf("%d", &x);

    acima = quantosPixelsAcimaDeInt_R(img, x);

    for(i = 0; i < linha; i++)
    {
        for(j = 0; j < coluna; j++)
        {
            if(img[i][j] > x) maior++;
        }
    }
    if(maior == acima) printf("A funcao esta correta\n");
    else printf("A funcao esta incorreta\n");


    return 0;
}
