#include <stdio.h>

void geraImgGreyW_R(unsigned char img[480][640],int i, int j);

int main(){
    unsigned char img[480][640];
    int cont = 0,i,j;

    geraImgGreyW_R(img,0,0);
    for(i = 0; i < 480; i++){                                         // Verifica se a imagem foi gerada corretamente
        for(j = 0; j < 640; j++){ 
            if(img[i][j] == 255){
            cont++;                                        // Conta a quantidade de pixels gerados iguais a 255      
            }else (printf("Erro! img[%d][%d]: %u",i,j,img[i][j]));
        }
    }
    if(480*640 == cont) printf("\n\nImagem gerada com sucesso!\n");     //linha * coluna representa a quantidade de pixels da imagem, que deve ser igual a cont
    else printf("\n\nErro na geracao da imagem!\n");


    
return 0;
}

void geraImgGreyW_R(unsigned char img[480][640],int i,int j){
   if (i>=480 || j>=640) return;  // Condição de parada: ultrapassou as linhas

    img[i][j] = 255; // Preenche o pixel atual com 255

     geraImgGreyW_R(img,i,j+1);  // Vai para o próximo pixel da linha
    
    if(j==0) geraImgGreyW_R(img,i+1,0);  // Vai para a próxima linha
}