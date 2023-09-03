#include <stdio.h>
#include <time.h>

int primo(int numero, int divisor){

    if(divisor < 2 && numero >= 2){
        printf("%d\n", numero);
        return 0;
    }

    if(numero < 2){
        return 0;
    }

    if(numero == 2){
        printf("%d\n", numero);
        return 1;
    }

    if(numero % divisor == 0 && numero != divisor){
        return 0;
    }


    return primo(numero, divisor - 1);
}

int actual_time(){
    time_t actual_seconds;

    time(&actual_seconds);

    return actual_seconds;
}

int main(){
    time_t start_time;
    time(&start_time);

    printf("%d\n", actual_time());

    int numero = 1;

    while((actual_time() - start_time) < 60){
        primo(numero, numero);
        numero ++;
    }

    return 0; 
}