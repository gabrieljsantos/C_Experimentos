#include <stdio.h>

void square_number(double *x, double *square){
    *square = *x * *x;
}
int main(){
    double x, square;
    printf("digite o numero qual deve ser calculado o quadrado usando ponteiro: \n");
    scanf("%lg",&x);
    square_number(&x, &square);
    printf("o quadrada do numero digitado é %lf\n\n",square);

    printf("Pressione Enter para sair...\n");
    getchar(); // consome o Enter deixado pelo último scanf
    getchar(); // espera o Enter do usuário
    return 0;
    
}
