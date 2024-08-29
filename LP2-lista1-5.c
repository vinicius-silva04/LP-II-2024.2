//parte que vai para procimg.h

void drwLin(unsigned char img[640][480], int xA, int yA, int xB, int yB, unsigned char pixel);

/*  Função que desenha uma reta com base nas duas extremidades, (xA, yA) e (xB, yB).
    utiliza a cor armazenada em pixel.
*/

/*parte que vai para procimg.c

void drwLin(unsigned char img[640][480], int xA, int yA, int xB, int yB, unsigned char pixel){
    int inclinacao, x, y;

    inclinacao = (int) (yA - yB) / (xA - xB);

    for(x = 0; x < 640; x++){                       //multiplico cada x pela inclinação da reta para encontrar o y da coordenada, onde eu armazeno o valor da cor contido em pixel
        y = inclinacao * x;
        img[x][y] = pixel;
    }
}
*/

/*parte que vai para exemimg.c

#include <stdio.h>

int main(){
    unsigned char img[640][480], pixel = 0;
    int xA, xB, yA, yB;

    printf("intervalo de x: [0,639]\nintervalo de y: [0,479]\n\n");

    printf("Digite as coordenadas x e y de uma extremidade da reta:\n");
    scanf("%d%d", &xA, &yA);

    printf("\nDigite as coordenadas x e y da outra extremidade da reta:\n");
    scanf("%d%d", &xB, &yB);

    if(xA > 639 || xA < 0 || xB > 639 || xB < 0 || yA > 479 || yA < 0 || yB > 479 || yB < 0){
        printf("coordanada fora do intervalo");
        return 0;
    }

    drwLin(img, xA, yA, xB, yB, pixel);



    return 0;
}
*/

