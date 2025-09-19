#include <stdio.h>

int main(){
    
    double x;
    double *px;
    
    px = &x;
    scanf("%lg",px);


    printf("%lg\n",x);
    printf("%p\n",px);

    *px = 543;
    
    printf("%lg\n",x);
    printf("Pressione Enter para sair...\n");
    getchar(); // consome o Enter deixado pelo último scanf
    getchar(); // espera o Enter do usuário
    return 0;
}
