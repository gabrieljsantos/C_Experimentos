#include <stdio.h>

void sum_array(double *arr, double *sum, int Size_of){
    for(int i = 0; i < Size_of; i++){
        *sum += *(arr+i);
    }
}

int main(){
    #define SIZE_ARR 5
    double arr[SIZE_ARR] = {1 , 3 , 5 , 7, 9};
    double sum = 0;
    sum_array(arr,&sum,SIZE_ARR);
    printf("A soma do vetor é %lg", sum);
    printf("\n \n Pressione Enter para sair...\n");
    getchar(); // consome o Enter deixado pelo último scanf
    getchar(); // espera o Enter do usuário
    return 0;
}