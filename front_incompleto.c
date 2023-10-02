#include <gtk/gtk.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define MAX_FRASE 10000

//ATRIBUI ÀS LETRAS E CARACTERES SEUS VALORES DECIMAIS CORRESPONDENTES NA TABELA ASCII

char letras[] = {' ', '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                 ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q',
                 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', '_', '`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i',
                 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
int numero_no_alfabeto[] = {32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57,
                            58, 59, 60, 61, 62, 63, 64, 65, 66, 67, 68, 69, 70, 71, 72, 73, 74, 75, 76, 77, 78, 79, 80, 81,
                            82, 83, 84, 85, 86, 87, 88, 89, 90, 91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103,
                            104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119, 120, 121, 122};


//DECLARANDO AS FUNÇÕES USADAS AO LONGO DO PROGRAMA                            

long long int exponenciacao_modular_rapida(long long int base, long long int expoente, long long int mod);
bool mdc(long long int a, long long int b);
long long int calcular_chave_privada(long long int e, long long int phi);
bool ehPrimo(long long int p);
void criptografar_mensagem(long long int frase_enumerada[], int tamanho, long long int frase_criptografada[], long long int e, long long int n);
void reenumerar_frase(long long int frase_criptografada[], int tamanho, long long int new_frase_enumerada[], long long int e, long long int d, long long int n);
int letra_na_tabela(int tabela[], long long new[], long long int n, int j, int i);
int numero_na_tabela(char letras[], char frase[], int tam, int j, int i);
void enumerar(char letras[], int tabela[], char frase[], long long int new_frase[], int n, int i);
void decifrar(char letras[], int tabela[], long long int new[], char novo_texto[], long long int n, int i);
void verMensagemDesencriptada();
void desencriptarMensagem();
void gerarChavePublica(long long int *num1, long long int *num2, long long int *phi);
void encriptarMensagem();
void entrada();


//FUNÇÃO PARA CALCULAR O MDC ENTRE (d*e) e (p-1)(q-1) USANDO O ALGORITMO DE EUCLIDES

bool mdc(long long int a, long long int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }   
    return a == 1 ? true : false;
}

//FUNÇÃO PARA OBTER A CHAVE PRIVADA A PARTIR DO EXPOENTE "e", E DA FUNÇÃO TOTIENTE PHI

long long int calcular_chave_privada(long long int e, long long int phi) {
    long long int b_base = phi, q, t;
    long long int x0 = 0, chave_privada = 1;

    if (phi == 1) return 1;
    while (e > 1) {
        q = e / phi;
        t = phi;
        phi = e % phi;
        e = t;
        t = x0;
        x0 = chave_privada - (q * x0);
        chave_privada = t;  
    }

    if (chave_privada < 0) {
        chave_privada += b_base;
    } 
    return chave_privada;
}

//FUNÇÃO PARA VERIFICAR SE O NUMERO "p" É PRIMO, RETORNANDO TRUE SE O NÚMERO FOR PRIMO

bool ehPrimo(long long int p) {
    long long int i;
    double j;

    if (p < 2) return false;

    j = sqrt(p);

    for (i = 2; i <= j; i++) {
        if (p % i == 0) return false;
    }

    return true;
}

/*FUNÇÃO PARA CRIPTOGRAFAR UMA MENSAGEM REPRESENTADA COMO UMA SEQUENCIA DE NUMEROS, COM BASE NA CHAVE PUBLICA
E ARMAZENA A MENSAGEM NO ARRAY FRASE_CRIPTOGRAFADA[]*/

void criptografar_mensagem(long long int frase_enumerada[], int tamanho, long long int frase_criptografada[], long long int e, long long int n) {
    for (int i = 0; i < tamanho; i++) {                           
        long long int potencia_da_letra = exponenciacao_modular_rapida(frase_enumerada[i], e, n);     
        frase_criptografada[i] = potencia_da_letra;      
    }
}

/*FUNÇÃO PARA DESENCRIPTAR UMA MENSAGEM CRIPTOGRAFADA, REPRESENTADA COM UMA SEQUÊNCIA DE NÚMEROS, USANDO A CHAVE PRIVADA
E ARMAZENA A MENSAGEM NO ARRAY NEW_FRASE_ENUMERADA[]*/

void reenumerar_frase(long long int frase_criptografada[], int tamanho, long long int new_frase_enumerada[], long long int e, long long int d, long long int n) {
    int i;
    for (i = 0; i < tamanho; i++) {                           
        long long int potencia_da_letra = exponenciacao_modular_rapida(frase_criptografada[i], d, n); 
        new_frase_enumerada[i] = potencia_da_letra;      
    }
}


/*FUNÇÕES AUXILIARES USADAS PARA ENCONTRAR O ÍNDICE DE UM CARACTERE OU NUMERO NA TABELA*/

int letra_na_tabela(int tabela[], long long new[], long long int n, int j, int i) {
    if (new[i] == tabela[j]) {
        return j;
    } else {
        j++;
        return letra_na_tabela(tabela, new, n, j, i);
    }
}

int numero_na_tabela(char letras[], char frase[], int tam, int j, int i) {
    if (frase[i] == letras[j]) return j;
    else {
        j++;
        return numero_na_tabela(letras, frase, tam, j, i);
    }
}

/*CONVERTE UMA MENSAGEM EM TEXTO LEGÍVEL PARA NÚMEROS, COM BASE NA TABELA ASCII*/

void enumerar(char letras[], int tabela[], char frase[], long long int new_frase[], int n, int i) {
    if (i < n) {
        int pos;
        pos = numero_na_tabela(letras, frase, n, 0, i);
        new_frase[i] = tabela[pos];
        return enumerar(letras, tabela, frase, new_frase, n, i + 1);
    }
}


/*CONVERTE A MENSAGEM CRIPTOGRAFADA PARA TEXTO NORMAL*/

void decifrar(char letras[], int tabela[], long long int new[], char novo_texto[], long long int n, int i) {
    if (i == n) {
        novo_texto[i] = '\0';
        FILE *new_text;
        new_text = fopen("descriptado.txt", "w");
        fprintf(new_text, "%s", novo_texto);
        fclose(new_text);
        return;
    } else {
        long long int posicao;
        posicao = letra_na_tabela(tabela, new, n, 0, i);
        novo_texto[i] = letras[posicao];
    }
    decifrar(letras, tabela, new, novo_texto, n, i + 1);
}


/*FUNÇÕES RESPONSÁVEIS PELA ENTRADA E SAÍDA DE DADOS RELACIONADOS À DESCRIPTOGRAFIA, INCLUINDO A CRIAÇÃO DE ARQUIVOS TXT*/

void verMensagemDesencriptada() {
    FILE *descrip;

    char frase[MAX_FRASE];
    int tamanho = 0;

    descrip = fopen("descriptado.txt", "r");

    if (descrip == NULL) {
        printf("Nao existe texto descriptado!\n");
    } else {
        while (fscanf(descrip, "%c", &frase[tamanho]) != EOF) {
            tamanho++;
        }

        printf("Frase descriptografada: %s\n", frase);
        fclose(descrip);
    }
}

void desencriptarMensagem() {
    FILE *crip;

    crip = fopen("grifado.txt", "r");

    if (crip == NULL) {
        printf("Não existe texto criptado!\n");
        printf("Retornando ao menu.\n");
        return;
    } else {
        long long int p = 0, q = 0, e = 0;
        gerarChavePublica(&p, &q, &e);
        long long int n = p * q;
        long long int cop = (p - 1) * (q - 1);
        long long int d = calcular_chave_privada(e, cop);
        long long int frase_criptografada[MAX_FRASE], tamanho_frase = 0, new_frase_enumerada[MAX_FRASE];
        char nova_frase[MAX_FRASE];
        while (fscanf(crip, "%lld", &frase_criptografada[tamanho_frase]) != EOF) {
            tamanho_frase++;
        }
        reenumerar_frase(frase_criptografada, tamanho_frase, new_frase_enumerada, e, d, n);
        decifrar(letras, numero_no_alfabeto, new_frase_enumerada, nova_frase, tamanho_frase, 0);
        fclose(crip);
    }
}

void gerarChavePublica(long long int *num1, long long int *num2, long long int *phi) {
    printf("\nDigite dois numeros primos para a geracao da chave publica:\n");
    printf("P: ");
    scanf("%lld", num1);
    printf("Q: ");
    scanf("%lld", num2);

    while (!ehPrimo(*num1) || !ehPrimo(*num2)) {
        printf("\nUm dos numeros digitados nao eh primo. Digite novamente:\n");
        printf("P: ");
        scanf("%lld", num1);
        printf("Q: ");
        scanf("%lld", num2);
    }

    long long int cop = (*num1 - 1) * (*num2 - 1);

    printf("\nDigite um numero Co-primo (numero E) de (P - 1)*(Q - 1): ");
    scanf("%lld", phi);

    while (!mdc(cop, *phi)) {
        printf("\nEste numero nao pode ser usado para gerar a chave publica. Digite novamente:\n");
        printf("E: ");
        scanf("%lld", phi);
    }
}


/*RESPONSÁVEL PELA ENTRADA DA MENSAGEM A SER CRIPTOGRAFADA, FAZ A CRIPTOGRAFIA E ARMAZENA A MENSAGEM CRIPTOGRAFADA EM UM ARQUIVO TXT*/

void encriptarMensagem() {
    FILE *crip;
    crip = fopen("grifado.txt", "w");

    if (crip == NULL) {
        printf("Erro ao criar ou abrir o arquivo 'grifado.txt'!\n");
        return;
    }

    long long int n = 0, e = 0;

    printf("Digite a chave pública (n, e):\n");
    printf("n: ");
    scanf("%lld", &n);
    printf("e: ");
    scanf("%lld", &e);

    char frase[MAX_FRASE];
    printf("Digite sua frase: ");
    scanf(" %[^\n]", frase);

    int tamanho_frase = strlen(frase);

    long long int frase_enumerada[MAX_FRASE];
    long long int frase_criptografada[MAX_FRASE];

    enumerar(letras, numero_no_alfabeto, frase, frase_enumerada, tamanho_frase, 0);
    criptografar_mensagem(frase_enumerada, tamanho_frase, frase_criptografada, e, n);

    for (int i = 0; i < tamanho_frase; i++) {
        fprintf(crip, "%lld ", frase_criptografada[i]);
    }

    printf("Texto criptografado com sucesso!\n");

    fclose(crip);
}


/*IMPLEMENTA A EXPONENCIAÇÃO MODULAR RÁPIDA, USADA PARA ENCRIPTAR E DESENCRIPTAR*/

long long int exponenciacao_modular_rapida(long long int base, long long int expoente, long long int mod) {
    long long int n = base, k = expoente, d = mod;
    long long int resultado, pot;

    pot = n % d;
    resultado = 1;

    for (; k > 0; k /= 2) {
        if (k % 2 == 1) {
            resultado = (resultado * pot) % d;
        }
        pot = (pot * pot) % d;
    }

    return resultado;
}


// Função para manipular o botão "Gerar Chaves"
void on_button_generate_keys_clicked(GtkWidget *widget, gpointer data) {
    FILE *keys;
            keys = fopen("chaves.txt", "w");

            long long int chave1 = 0, chave2 = 0, phi = 0;
            gerarChavePublica(&chave1, &chave2, &phi);

            fprintf(keys, "n = %lld e = %lld", chave1 * chave2, phi);
            fclose(keys);
            gtk_label_set_text(GTK_LABEL(data), "Chaves públicas geradas com sucesso!");
}

// Função para manipular o botão "Criptografar"
void on_button_encrypt_clicked(GtkWidget *widget, gpointer data) {
    encriptarMensagem();
    gtk_label_set_text(GTK_LABEL(data), "Mensagem criptografada com sucesso!");
}

// Função para manipular o botão "Descriptografar"
void on_button_decrypt_clicked(GtkWidget *widget, gpointer data) {
    desencriptarMensagem();
    gtk_label_set_text(GTK_LABEL(data), "Mensagem descriptografada com sucesso!");
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Criptografia GUI");
    gtk_container_set_border_width(GTK_CONTAINER(window), 10);
    gtk_widget_set_size_request(window, 400, 200);

    GtkWidget *grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(window), grid);

    GtkWidget *label1 = gtk_label_new("1. Gerar Chaves Públicas");
    GtkWidget *label2 = gtk_label_new("2. Criptografar Mensagem");
    GtkWidget *label3 = gtk_label_new("3. Descriptografar Mensagem");

    GtkWidget *buttonGenerateKeys = gtk_button_new_with_label("Gerar Chaves");
    GtkWidget *buttonEncrypt = gtk_button_new_with_label("Criptografar");
    GtkWidget *buttonDecrypt = gtk_button_new_with_label("Descriptografar");

    GtkWidget *statusLabel = gtk_label_new("");

    g_signal_connect(buttonGenerateKeys, "clicked", G_CALLBACK(on_button_generate_keys_clicked), statusLabel);
    g_signal_connect(buttonEncrypt, "clicked", G_CALLBACK(on_button_encrypt_clicked), statusLabel);
    g_signal_connect(buttonDecrypt, "clicked", G_CALLBACK(on_button_decrypt_clicked), statusLabel);

    gtk_grid_attach(GTK_GRID(grid), label1, 0, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttonGenerateKeys, 1, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label2, 0, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttonEncrypt, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label3, 0, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), buttonDecrypt, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), statusLabel, 0, 3, 2, 1);

    g_signal_connect(window, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    gtk_widget_show_all(window);

    gtk_main();

    return 0;
}
