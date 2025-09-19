#include <stdio.h>

int main(){
    
    double number[3];
    for(int i = 0; i < 3; i++){
        printf("digite o numero de index %d : \n ", i);
        scanf("%lg",&number[i]);
    }


    for(int i = 2; i >= 0; i--){
        printf("%lg",number[i]);
        printf("\n");
    }
    
    printf("Pressione Enter para sair...\n");
    getchar(); // consome o Enter deixado pelo último scanf
    getchar(); // espera o Enter do usuário
    return 0;
}
