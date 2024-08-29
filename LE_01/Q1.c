//parte que vai no procimg.h
unsigned char gerarGreyPixel (int tipo);
/*
    *Fun��o que gera um n�mero que determina a intensidade de cor do pixel.
    *Par�metro:
    * tipo: n�mero que determina qual intensidade escolhida.
    *Retorno:
    * int: n�mero gerado que determina a intensidade.
*/

/*parte que vai pro procimg.c
unsigned char gerarGreyPixel (int tipo){
    int valor;
    int proba= rand() % 100; //gera um n�mero entre 0 e 100;
    if(tipo<0){
       if(proba < 80){      //80% de gerar um n�mero entre 0 e 127.
            valor= rand() % 128;
       }else{               //20% de gerar um n�mero de qualquer intensidade.
            valor= rand() % 256;
        }
    }else if(tipo>0){
        if(proba < 80){     //80% de gerar um n�mero entre 128 e 255.
            valor = 128 + rand() % 128;
        }else{
            valor = rand() % 256; //20% de gerar um n�mero de qualquer intensidade.
        }
    }else{
        valor = rand() % 256; //gera um n�mero entre 0 e 255.
    }
return (unsigned char) valor;
}
*/
/* parte que vai exemimg.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "procimg.h"

int main(){
    srand(time(NULL)); //Inicializa o gerador de n�meros aleat�rios.

    printf("Pixel de cor mais escura: %d\n",gerarGreyPixel(-1));       //Imprime as intensidades de cor mais escura
    printf("Pixel de cor mais clara: %d\n",gerarGreyPixel(1));         //Imprime as intensidades de cor mais clara
    printf("Pixel de intensidade qualquer: %d\n",gerarGreyPixel(0));   //Imprime qualquer intensidade
return 0;
}
*/
