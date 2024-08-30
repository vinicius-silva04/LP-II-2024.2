//parte que vai para procimg.h
void drwRect(unsigned char img[640][480], int x, int y, int larg, int alt, unsigned char pixel);

/*  Função que preenche um retangulo com o valor do parâmetro pixel.
    img: Matriz onde a imagem será preenchida
    pixel: número que será preenchido o retangulo
    x,y: coordenadas do vertice superior esquerdo do retangulo
    larg,alt: largura e altura do retangulo


/*parte que vai para procimg.c

void drwRect(unsigned char img[640][480], int x, int y, int larg, int alt, unsigned char pixel){
    for(int i = y; i < y+alt; i++){
        for(int j = x; j < x+larg; j++) img[i][j] = pixel;
    }
}
*/


/*parte que vai para exemimg.c

#include <stdio.h>

int main(){
    int i, j;
    unsigned char img[640][480], pixel = 255;

    for( i = 0; i < 640; i++){
        for( j = 0; j < 480; j++){
            img[i][j] = 70;
        }
    }

    drwRect(img, 2,2,400,400,pixel);

    for( i = 0; i < 640; i++){
        printf("\n");
        for( j = 0; j < 480; j++){
            printf("%c", img[i][j]);
        }
    }
    return 0;
}
*/