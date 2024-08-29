//Q1
unsigned char gerarGreyPixel (int tipo){
    int valor;
    int proba= rand() % 100; //gera um número entre 0 e 100;
    if(tipo<0){
       if(proba < 80){      //80% de gerar um número entre 0 e 127.
            valor= rand() % 128;
       }else{               //20% de gerar um número de qualquer intensidade.
            valor= rand() % 256;
        }
    }else if(tipo>0){
        if(proba < 80){     //80% de gerar um número entre 128 e 255.
            valor = 128 + rand() % 128;
        }else{
            valor = rand() % 256; //20% de gerar um número de qualquer intensidade.
        }
    }else{
        valor = rand() % 256; //gera um número entre 0 e 255.
    }
return (unsigned char) valor;
}
//Q2
void geraImgGreyFull ( unsigned char img [640][480], unsigned char pixel){
    int i,j;
    for(i=0;i<640;i++){
        for(j=0;j<480;j++){
            img[i][j]= pixel;
        }
    }
}
//Q4
void geraImgGreyW(unsigned char img[640][480]){
    for(int i = 0; i < 640; i++){
        for(int j = 0; j < 480; j++){
          img[i][j] = 255;
        }
    }
}
//Q6
void drwRect(unsigned char img[640][480], int x, int y, int larg, int alt, unsigned char pixel){
    for(int i = y; i < y+alt; i++){
        for(int j = x; j < x+larg; j++) img[i][j] = pixel;
    }
}
//Q12
void imgHistogram(unsigned char img[640][480], int hist[256]){
    int i,j;
    for(i=0;i<640;i++){
        for(j=0;j<480;j++){
            hist[img[i][j]]++;
        }
    }
}
