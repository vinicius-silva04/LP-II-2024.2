//Q2
void geraImgGreyFull_R(unsigned char img[linha][coluna], unsigned char pixel, int i, int j){
    if(i == 0 && j == 0) return;    //quando i e j forem iguais a 0, a imagem estará completa, e a função encerra
    img[i-1][j-1] = pixel;          //atribui o valor do pixel na posição i-1 e j-1
    if(j == 0) geraImgGreyFull_R(img, pixel, i-1, coluna);  //quando apenas j for 0, a linha i ja tera sido preenchida, e passamos para a proxima linha i-1, e voltamos para a primeira coluna->coluna
    else geraImgGreyFull_R(img, pixel, i, j-1); //quando j for diferente de 0, preenchemos a mesma linha i, e passamos para a coluna j-1
}
