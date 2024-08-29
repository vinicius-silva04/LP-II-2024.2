//parte que vai para procimg.h

void geraImgGreyB(unsigned char img[640][480]);

/*função que preenche todos os pixels da matriz img com o valor 0*/

/*parte que vai para procimg.c

void geraImgGreyB(unsigned char img[640][480]){
    for(int i = 0; i < 640; i++){
        for(int j = 0; j < 480; j++){
          img[i][j] = 0;
        }
    }

}
*/

/*parte que vai para exemimg.c

#include <stdio.h>
int main(){
    unsigned char img[640][480];

    geraImgGreyB(img);    //gerou uma imagem completamente preta
    
    return 0;
}
*/