#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define linha 480
#define coluna 640
#define N 640
//Q1
unsigned char geraGreyPixel (int tipo) {
    unsigned char num;
    int probabilidade = rand() % 100;
    if(tipo < 0){
       if (probabilidade < 80)      //80% de chance de cor escura
            num = rand() % 128;
       else                        //20% de chance de todas as cores
            num = rand() % 256;
    }
    else if (tipo > 0) {
        if (probabilidade < 80)             //80% de chance de cor clara
            num = 128 + rand() % 128;       
        else                            //20% de chance de todas as cores
            num = rand() % 256;
    }
    else
        num = rand() % 256;          //100% de chance de todas as cores
    return num;
}

int indice = N-1;

void geraLinhaR(unsigned char array [], int tipo) {
    if (indice < 0) return;                   // para quando o array está totalmente preenchido
    array [indice] = geraGreyPixel (tipo);   //preenche o array de N-1 até 0;
    indice--;
    geraLinhaR (array, tipo);
}
//Q2
int num = linha * coluna

void geraImgGreyFull_R(unsigned char img[linha][coluna], unsigned char pixel){
    if(num == 0){                     //testa se N chegou a 0
        num = linha * coluna;          //reseta N para que a função possa ser chamada novamente
        return;                      //encerra a função
    }
    num--;                            //decrementa N para controlar a quantidade de vezes que a função foi chamada
    img[0][0] = pixel;              //atribui o valor 0 ao pixel atual
    geraImgGreyFull_R(&img[0][1], pixel);     //chama a função novamente, passando o endereço do próximo pixel
}
//Q3
void geraImgGreyB_R(unsigned char img[linha][coluna],int i ,int j){
    if(i == 0 && j == 0) return;    //quando i e j forem iguais a 0, a imagem estará completa, e a função encerra
    img[i-1][j-1] = 0;          //atribui o valor do pixel na posição i-1 e j-1
    if(j == 0) geraImgGreyB_R(img, i-1, coluna);  //quando apenas j for 0, a linha i ja tera sido preenchida, e passamos para a proxima linha i-1, e voltamos para a primeira coluna->coluna
    else geraImgGreyB_R(img, i, j-1); //quando j for diferente de 0, preenchemos a mesma linha i, e passamos para a coluna j-1
}

//Q4
void preencherimg(unsigned char img[480][640],int pixel,int i,int j){
    if(i>=480 || j>=640) return; //condição de parada

    img[i][j]=pixel; //preenche com o valor inserido
    preencherimg(img,pixel,i,j+1); //preenche até o valor máximo de j
    if(j==0)   preencherimg(img,pixel,i+1,0); //quando j chega no limite, vai para próxima linha
}
void geraImgGreyW_R(unsigned char img[480][640]){
    preencherimg(img,255,0,0);
}
//Q5
void geraImgGrey_R(unsigned char img[480][640],int tipo){
    unsigned char k= geraGreyPixel(tipo);
    preencherimg(img,k,0,0);
}
//Q6
int pixelMax_R(unsigned char img[linha][coluna]) //Entrada da matriz
{
    int aux_pixelMax_R(unsigned char img[linha][coluna], int row, int col, int maxValue)
    /*
        *Função auxiliar que recebe os parametros para fazer a função principal funcionar.
        *Parametros:
            *img: matriz onde a imagem será preencida.
            *row: parametro que representa as linhas da matriz, e será constantemente atualizada, para ter o controle da recursividade.
            *col: parametro que representa as colunas da matriz, e será constantemente atualizada, para ter o controle da recursividade.
            *maxValue: responsável por inicializar, guardar e retornar o maior valor encontrado dentro da matriz, deve ser inicializado com 0.
    */
    {
        if (row == 480)
        {
            return maxValue;
        }
        /*
            IF para verificar a condição de saída da recursividade, nesse caso, o método de saída será quando row(linha) for igual a 480, pois a matriz vai de 0 a 479, se chegar em 480
            irá passar do tamanho da matriz.

            Quando o caso for positivo, então ele deve retornar o valor maxValue, que foi modificado ao decorrer do código para ter o maior valor da matriz.
        */
        if(col > 639)
        {
            return aux_pixelMax_R(img, row + 1, 0, maxValue);
        }
        /*
            IF para verficar se a coluna(col) passou de 639, que é o valor máximo que uma coluna pode ter nessa matriz.
            
            Quando col == 640, ele irá chamar a função novamente chamando a matriz img, mas agora a row(linha) será adicionada +1, portanto a próxima linha. A col receberá o valor 0, para
            começar a repetição novamente, e o valor maxValue irá passar para a função a ser chamada.
        */
        else // ELSE para caso col seja menor que 639, ocorrerá na maioria das vezes
        {
            if(maxValue < img[row][col])
            {
                maxValue = img[row][col];
            }
            /* 
                IF para verificar se o valor da matriz img de posição [linha][coluna], row e col respectivamente, é maior que o maxValue atual.
                
                Caso o IF seja positivo maxValue recebe o valor img[row][col], portanto o maior valor atualmente.
            */
            
            return aux_pixelMax_R(img, row, col + 1, maxValue); // Chama a função auxiliar novamente, mas agora atualizando o valor da coluna, adicionando +1.
        }
    }
    return aux_pixelMax_R(img, 0, 0, 0); // Inicializa a função auxliar, dentro da função principal, com os valores row(0), col(0), maxValue(0). Para que o laço de repetição seja feito da esquerda para a direita e que o maxValue seja o menor possível(0). 
}
//Q7
int pixelMin_R(unsigned char img[linha][coluna])//Entrada da matriz
{
    int aux_pixelMin_R(unsigned char img[linha][coluna], int row, int col, int minValue)
    {
        /*
        *Função auxiliar que recebe os parametros para fazer a função principal funcionar.
        *Parametros:
            *img: matriz onde a imagem será preencida.
            *row: parametro que representa as linhas da matriz, e será constantemente atualizada, para ter o controle da recursividade.
            *col: parametro que representa as colunas da matriz, e será constantemente atualizada, para ter o controle da recursividade.
            *minValue: responsável por inicializar, guardar e retornar o menor valor encontrado dentro da matriz, deve ser inicializado com 255.

        */
        if (row == 480)
        {
            return minValue;
        }
        /*
            IF para verificar a condição de saída da recursividade, nesse caso, o método de saída será quando row(linha) for igual a 480, pois a matriz vai de 0 a 479, se chegar em 480
            irá passar do tamanho da matriz.

            Quando o caso for positivo, então ele deve retornar o valor minValue, que foi modificado ao decorrer do código para ter o menor valor da matriz.
        */

        if(col > 639)
        {
            return aux_pixelMin_R(img, row + 1, 0, minValue);
        }
        /*
            IF para verficar se a coluna(col) passou de 639, que é o valor máximo que uma coluna pode ter nessa matriz.

            Quando col == 640, ele irá chamar a função novamente chamando a matriz img, mas agora a row(linha) será adicionada +1, portanto a próxima linha. A col receberá o valor 0, para
            começar a repetição novamente, e o valor minValue irá passar para a próxima função a ser chamada.
        */
        else // ELSE para caso col seja menor que 639, ocorrerá na maioria das vezes
        {
            if(minValue > img[row][col])
            {
                minValue = img[row][col];
            }
            /* 
                IF para verificar se o valor da matriz img de posição [linha][coluna], row e col respectivamente, é menor que o minValue atual.
                
                Caso o IF seja positivo minValue recebe o valor img[row][col], portanto o menor valor atualmente.
            */
            return aux_pixelMin_R(img, row, col + 1, minValue); // Chama a função auxiliar novamente, mas agora atualizando o valor da coluna, adicionando +1.
        }
    }
    return aux_pixelMin_R(img, 0, 0, 255);// Inicializa a função auxliar, dentro da função principal, com os valores row(0), col(0), minValue(0). Para que o laço de repetição seja feito da esquerda para a direita e que o minValue seja o maior possível(255).
}
//Q8
int flag8 = -1; //usei flag = -1 para na primeira iteração flag ser igual a 0, pra ficar igual ao primeiro elemento dos arrays
void somaPorLinhas_R(unsigned char img[linha][coluna], int soma[linha]){
    flag8++;   //Essa flag conta as iterações, ajuda marcar coluna e linha, e marca o momento de mudança de posição do ponteiro soma.
    if(flag8 == linha * coluna){
        return;   //Quando todas as posições forem preenchidas, as iterações acabam
    }
    //(flag / linha): marca em qual linha está, só vai para a próxima linha quando soma todas os elementos da mesma linha
    //(flag % coluna): marca em qual coluna está, vai para a próximo elemento da linha até atingir o valor "coluna", quando alcança, volta a 0
    //A posição do ponteiro soma só deve mudar quando a linha mudar
    soma[flag8 / linha] += img[flag8 / linha][flag8 % coluna]; //Realiza a soma em cada posição do vetor soma
    somaPorLinhas_R(img, soma);  //Pula para a próxima iteração
}
//Q9
int flag9 = -1; //usei flag = -1 para na primeira iteração flag ser igual a 0, pra ficar igual ao primeiro elemento dos arrays
void somaPorColunas_R(unsigned char img[linha][coluna], int soma[]){
    flag9++;   //Essa flag conta as iterações, ajuda marcar coluna e linha, e marca o momento de mudança de posição do ponteiro soma.
    if(flag9 == linha * coluna){
        return;   //Quando todas as posições forem preenchidas, as iterações acabam
    }
    //(flag / coluna): marca em qual coluna está, só vai para a próxima coluna quando soma todas os elementos da mesma coluna
    //(flag % linha): marca em qual linha está, vai para o próximo elemento da coluna até atingir o valor "linha", quando alcança, volta a 0
    //A posição do ponteiro soma só deve mudar quando a coluna mudar
    soma[flag9 / coluna] += img[flag9 % linha][flag9 / coluna]; //Realiza a soma em cada posição do vetor soma
    somaPorColunas_R(img, soma);   //Pula para a próxima iteração
}
//Q12
int quantosPixelsAbaixoDeInt_R(unsigned char img[linha][coluna], unsigned char Int)
/*
    *Função principal:
    *Parametros:
        *img: entrada da matriz.
        *Int: entrada do valor que deve ser comparado para saber quantos valores são menores que ele.
*/
{
    int aux_quantosPixelsAbaixoDeInt_R(unsigned char img[linha][coluna], unsigned char Int, int row, int col, int soma)
    /*
        *Função auxiliar que recebe os parametros para fazer a função principal funcionar.
        *Parametros:
            *img: matriz onde a imagem será preencida.
            *Int: valor recebido para servir de base de comparação.
            *row: parametro que representa as linhas da matriz, e será constantemente atualizada, para ter o controle da recursividade.
            *col: parametro que representa as colunas da matriz, e será constantemente atualizada, para ter o controle da recursividade.
            *soma: Para somar quantos valores são menores que o parametro Int.

    */
    {
        if(row == 480)
        {
            return soma;
        }
        /*
           IF para verificar a condição de saída da recursividade, nesse caso, o método de saída será quando row(linha) for igual a 480, pois a matriz vai de 0 a 479, se chegar em 480
           irá passar do tamanho da matriz.

           Quando o caso for positivo, então ele deve retornar o valor soma, que foi modificado ao decorrer do código para ter a soma da quantidade dos valores menores que Int da matriz.
        */

        if(col > 639)
        {
            return aux_quantosPixelsAbaixoDeInt_R(img, Int, row + 1, 0, soma);
        }
        /*
            IF para verficar se a coluna(col) passou de 639, que é o valor máximo que uma coluna pode ter nessa matriz.

            Quando col == 640, ele irá chamar a função novamente chamando a matriz img, mas agora a row(linha) será adicionada +1, portanto a próxima linha. A col receberá o valor 0, para
            começar a repetição novamente, e o valor soma e Int irá passar para a próxima função a ser chamada.
        */
        else // ELSE para caso col seja menor que 639, ocorrerá na maioria das vezes
        {
            if(img[row][col] < Int)
            {
                soma ++;
            }
            /* 
                IF para verificar se o valor da matriz img de posição [linha][coluna], row e col respectivamente, é menor que o valor base Int.
                
                Caso o IF seja positivo soma recebe o valor adicionado +1.
            */
            return aux_quantosPixelsAbaixoDeInt_R(img, Int, row, col + 1, soma); // Chama a função auxiliar novamente, mas agora atualizando o valor da coluna, adicionando +1.
        }
    }

    return aux_quantosPixelsAbaixoDeInt_R(img, Int, 0, 0, 0);// Inicializa a função auxliar, dentro da função principal, com os valores row(0), col(0), soma(0). Para que o laço de repetição seja feito da esquerda para a direita.
}
