#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void geraImgGrey_R(unsigned char img[480][640],int tipo);
void geraLinhaR(unsigned char array [], int tipo, int N);
unsigned char geraGreyPixel (int tipo);

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
unsigned char geraGreyPixel(int tipo) {
    unsigned char num;
    int probabilidade = rand () % 100;
    if(tipo < 0){
       if (probabilidade < 80)      //80% de chance de cor escura
            num = rand() % 128;
       else                        //20% de chance de todas as cores
            num = rand() % 256;
    }
    else if (tipo > 0) {
        if (probabilidade < 80)             //80% de chance de cor clara
            num = 128 + rand() % 128;       //20% de chance de todas as cores
        else
            num = rand() % 256;
    }
    else
        num = rand() % 256;          //100% de chance de todas as cores
    return num;
}

void geraLinhaR(unsigned char array [], int tipo, int N) {
    if (N<0) return;                     // verificação para determinar quando o array está totalmente preenchido
    array [N] = geraGreyPixel (tipo);   //preenche o array de N até 0;
    geraLinhaR (array, tipo, N-1);
}
void geraImgGrey_R(unsigned char img[480][640],int tipo){
    unsigned char k= geraGreyPixel(tipo);
    preencherimg(img,k,0,0);
}
