#include <stdio.h>

void geraImgGreyW_R(unsigned char img[480][640]);
void preencherimg(unsigned char img[480][640],int pixel,int i,int j);

int main(){
    unsigned char img[480][640];
    int cont = 0,i,j;

    geraImgGreyW_R(img);
    for(i = 0; i < 480; i++){                                         // Verifica se a imagem foi gerada corretamente
        for(j = 0; j < 640; j++){ 
            if(img[i][j] == 255){
            cont++;                                        // Conta a quantidade de pixels gerados iguais a 255      
            }else (printf("Erro! img[%d][%d]: %u",i,j,img[i][j]));
        }
    }printf("Exemplo:\nimg[%d][%d]: %u",i,j,img[i-1][j-1]);
    if(480*640 == cont) 
        printf("\n\nImagem gerada com sucesso!\n");     //Verifica se o total de pixels é igual a soma dos pixels iguais a 255
    else 
        printf("\n\nErro na geracao da imagem!\n");


    
return 0;
}

void preencheimg(unsigned char img[480][640],int pixel,int i,int j){
    if(i>=480 || j>=640) return; //condição de parada

    img[i][j]=pixel; //preenche com o valor que deseja
    preencheimg(img,255,i,j+1); // continua a preencher a mesma linha enquanto j não atingir o limite.
    if(j==0) preencheimg(img,255,i+1,0); //Vai pra próxima linha 
}

void geraImgGreyW_R(unsigned char img[480][640],int i,int j){
   preencheimg(img,255,0,0);
}
