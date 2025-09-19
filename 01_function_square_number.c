#include <stdio.h>

double square_number(double x){
    double square = x * x;
    return square;
}
int main(){
    double x;
    printf("digite o numero qual deve ser calculado o quadrado : \n");
    scanf("%lg",&x);
    double square = square_number(x);
    printf("o quadrada do numero digitado é {}%lf",square);
    printf("digite o numero qual deve ser calculado o quadrado : \n");
    scanf("%lg",&x);
    square = square_number(x);
    printf("o quadrada do numero digitado é {}%lf",square);
    printf("digite o numero qual deve ser calculado o quadrado : \n");
    scanf("%lg",&x);
    square = square_number(x);

    printf("o quadrada do numero digitado é {}%lf",square);
    return 0;
    
}
