//Q2
void geraImgGreyFull_R(unsigned char img[linha][coluna], unsigned char pixel, int i, int j){
    if(i == 0 && j == 0) return;    //quando i e j forem iguais a 0, a imagem estará completa, e a função encerra
    img[i-1][j-1] = pixel;          //atribui o valor do pixel na posição i-1 e j-1
    if(j == 0) geraImgGreyFull_R(img, pixel, i-1, coluna);  //quando apenas j for 0, a linha i ja tera sido preenchida, e passamos para a proxima linha i-1, e voltamos para a primeira coluna->coluna
    else geraImgGreyFull_R(img, pixel, i, j-1); //quando j for diferente de 0, preenchemos a mesma linha i, e passamos para a coluna j-1
}
//Q3
void geraImgGreyB_R(unsigned char img[linha][coluna],int i ,int j){
    if(i == 0 && j == 0) return;    //quando i e j forem iguais a 0, a imagem estará completa, e a função encerra
    img[i-1][j-1] = 0;          //atribui o valor do pixel na posição i-1 e j-1
    if(j == 0) geraImgGreyB_R(img, i-1, coluna);  //quando apenas j for 0, a linha i ja tera sido preenchida, e passamos para a proxima linha i-1, e voltamos para a primeira coluna->coluna
    else geraImgGreyB_R(img, i, j-1); //quando j for diferente de 0, preenchemos a mesma linha i, e passamos para a coluna j-1
}

//Q4
void preencherimg(unsigned char img[480][640],int pixel,int i,int j){
    if(i>=480 || j>=640) return; //condição de parada

    img[i][j]=pixel; //preenche com o valor inserido
    preencherimg(img,255,i,j+1); //preenche até o valor máximo de j
    if(j==0)   preencherimg(img,255,i+1,0) //quando j chega no limite, vai para próxima linha
}
void geraImgGreyW_R(unsigned char img[480][640],int i,int j){
    preencherimg(img,255,0,0);
}
