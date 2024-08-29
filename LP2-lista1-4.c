//parte que vai para procimg.h

void geraImgGreyW(unsigned char img[640][480]);

/*função que preenche todos os pixels da matriz img com o valor 0*/

/*parte que vai para procimg.c

void geraImgGreyW(unsigned char img[640][480]){
    for(int i = 0; i < 640; i++){
        for(int j = 0; j < 480; j++){
          img[i][j] = 255;
        }
    }

}
*/

/*parte que vai para exemimg.c

#include <stdio.h>
int main(){
    unsigned char img[640][480];

    geraImgGreyW(img);    //gerou uma imagem completamente branca

    return 0;
}
*/