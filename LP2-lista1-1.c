#include <stdio.h>
#include <stdlib.h>
#include <time.h>


unsigned char geraGreyPixel(int tipo);

unsigned char geraGreyPixel(int tipo){

    int prob, valor;

    prob = rand() % 100;

    if(tipo < 0){
        if(prob < 80) valor = rand() % 128;
        
        else valor = rand() % 256;
    }
    else if(tipo > 0){
        if(prob < 80) valor = rand() % 128 + 128;

        else valor = rand() % 256;
    }
    else valor = rand() % 256;

    return (unsigned char) valor;
}

int main(){
    srand(time(NULL));
    printf("%d", geraGreyPixel(1));
    return 0;
}