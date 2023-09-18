#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int eh_primo(int num) // função pra verificar se um numero é primo.
{
    if(num <=1)
    {
        return 0;
    }
    else
    {
        int i;

        for(i = 2; i <= sqrt(num); i++)
        {
            if(num % i == 0) // meu num só pode ser divido por 1 e por ele mesmo.
            {
                return 0; // não é primo pelo motivo comentado acima.
            }
                return 1;
        }
    }
}

int mdc(int x, int y) // função pra verificar o mdc de dois números.
{
 
    if(x%y == 0)
    {
        return y;
    }
 
    return mdc(y, x%y);
}

int gerar_chave(int ch_publica[], int ch_privada[]) // não sei o que colocar de argumento.
{
    int p, q; // meus números primos.
    int n, r;

    printf("Digite um número primo p: \n");
    scanf("%d", &p);
    printf("Digite um número primo q: \n");
    scanf("%d", &q);

    n = p * q;
    r = (p - 1) * (q - 1);

    int e;
    printf("Digite e: \n");
    scanf("%d", &e);

    // ver sobre inversao modular (eu acho)

    /*IMPORTANTE: VER COMO VAI SER A PARTE DE ACHAR O NUMERO 'E' RELATIVAMENTE PRIMO A R
    SE VAI SER DE FORMA ALEATORIO OU NAO.
    */ 

    
}   


int main()
{   
    int opcao;
    int ch_pub[2] = {0, 0}; // chave publica
    int ch_pri[2] = {0, 0}; // chave privada

    // minha chave publica vai ser (n, e)
    

    printf("Escolha uma opção:\n");
    printf("1 - Gerar chave pública\n");
    printf("2 - Encriptar\n");
    printf("3 - Desencriptar\n");
    scanf("%d", &opcao);

    if(opcao == 1)
    {   
        // chamar a função de gerar a chave.
        gerar_chave(ch_pub, ch_pri);
    }
    else if(opcao == 2)
    {
        // criar uma variavel char pra conseguir ler o texto
        // Solicite que o usuário digite a mensagem de texto a encriptar.
        // Solicite que o usuário digite a chave pública recebida previamente.
        // Salve, no diretório de execução do programa, um arquivo txt com a mensagem encriptada.
    }
    else if(opcao == 3)
    {
        // Solicite que o usuário digite p, q e e.
        // Salve, no diretório de execução do programa, um arquivo txt com a mensagem desencriptada.
    }



    return 0;
}