#include <stdio.h>

int primo(int n, int x){
    if(n==2){
       return 1;
        
    }
    if(n==1){
        return 0;
        
    }
    else if(n%x==0){
       return 0;
       
    }
    if(n-1 == x){
        return 1;
    }
    return primo(n, x+1);
}

void loopPrimo(){
    int n;
    scanf("%d", &n);

    int res = primo(n, 2);

    if(n<1){
        return ;
    }
    if (res == 1) {
        printf("%d eh primo\n", n);
    } else if (res ==0 ) {
        printf("%d nao eh primo\n", n);
    }

    loopPrimo();

}

int main () {

loopPrimo();

return 0;
}