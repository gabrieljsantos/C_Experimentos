#include <stdio.h>

double absolt(double x) {
    if (x >= 0)
        return x;
    else
        return -x;
}


double pow_exp_int(double x,int Exp){
    double pow_value = 1; 
    for(int i = 0; i < Exp; i++){
        pow_value *= x ;
    }
    return pow_value;
}

double root_Newton_Raphson(double x){
    double root = 0.0;
    double yn = 1.0;
    double y_next_n = 0.5 * (yn+(x/yn));

    while (absolt(yn - y_next_n) > 1e-9) {
        yn = y_next_n;
        y_next_n = 0.5*(yn+(x/yn));
    }
    root = y_next_n;
    return root;
}


double sum_array(double *arr, int Size_t){
    double sum = 0;
    for(int i = 0; i < Size_t; i++){
        sum += *(arr+i);
    }
    return sum;
}

void array_mean_variance(double *arr, double *sum, double *mean, double *variance, double *std_dev, int Size_t){

    *sum = sum_array(arr, Size_t);
    double Sum_of_Squares = 0;
    *mean = *sum / Size_t;
    for(int i = 0; i < Size_t; i++){
        double diff = ((*(arr+i)) - *mean);
        Sum_of_Squares += pow_exp_int(diff,2);
    }
    *variance = Sum_of_Squares / Size_t;
    *std_dev = root_Newton_Raphson(*variance) ;

    
}

int main(){
    int Size_t = 10;
    double data[10] = {4,2,3,4,3,4,3,4,5,6};
    double sum = 0;
    double mean = 0;
    double variance = 0;
    double std_dev2 = 0;

    array_mean_variance(data, &sum, &mean, &variance, &std_dev2, Size_t);

    printf("somatorio : %lg \nmedia : %lg \nvariance : %lg \ndesvio_pad : %lg", sum, mean, variance, std_dev2);
    printf("\n \n Pressione Enter para sair...\n");
    getchar(); // consome o Enter deixado pelo último scanf
    getchar(); // espera o Enter do usuário
    return 0;


}