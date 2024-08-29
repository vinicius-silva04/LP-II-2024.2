//parte que vai para procimg.h
void geraImgGreyFull(unsigned char img[640][480], unsigned char pixel);

//função preenche todos pixels da matriz img com o valor de pixel

/*parte que vai para procimg.c

void geraImgGreyFull(unsigned char img[640][480], unsigned char pixel){
    for(int i = 0; i < 640; i++){
        for(int j = 0; j < 480; j++){
          img[i][j] = pixel;
        }
    }

}
*/

/*parte que vai para exemimg.c

#include <stdio.h>
int main(){
    unsigned char img[640][480], pixel = 1;

    geraImgGreyFull(img, pixel);    //gerou uma imagem com cor mais escura
    
    return 0;
}
*/