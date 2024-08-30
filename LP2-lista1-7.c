#define tamanho 100

void drwCirc(unsigned char img[tamanho][tamanho], int x, int y, int rad, unsigned char pixel);


void drwCirc(unsigned char img[tamanho][tamanho], int x, int y, int rad, unsigned char pixel){
    int m, i, j, n;

    for(i = 0; i < tamanho; i++){
        n = (i - x)*(i - x);
        for(j = 0; j < tamanho; j++){
            m = sqrt(n + (j - y)*(j - y));
            if(m <= rad){
                img[j][i] = pixel;
            }
        }
    }
}

#include <stdio.h>
#include <math.h>
int main(){
    unsigned char img[640][480], pixel = 178;
    int i, j;
   
    for( i = 0; i < 640; i++){
        for( j = 0; j < 480; j++){
            img[i][j] = 176;
        }
    }

    drwCirc(img,50, 50, 28, pixel);

    for( i = 0; i < 640; i++){
        printf("\n");
        for( j = 0; j < 480; j++){
            printf("%c", img[i][j]);
        }
    }
    return 0;
}