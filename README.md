# Matemática Discreta

## Grupo🧑‍🤝‍🧑

*Antônio Maria Cardoso Wagner*

*Giovanna Alves Barbosa de Oliveira*

*Marta Mirely Nascimento dos Santos*

*Matheus Henrique Gomes de Oliveira*

*Paulo Sérgio Veras Carvalho*

*Vitória Maria Santana Bigi*

*Yasmin Antonela Nascimento Oliveira*


**Matemática Discreta**

**UFAL - Universidade Federal de Alagoas**:

**Professor: Bruno Pimentel**

### Descrição do Projeto📰  

* Este projeto utiliza como base o método de criptografia RSA e a tabela ASCII para encriptar e desencriptar mensagens fornecidas pelo usuário através de operações matemáticas como aritmética modular, algoritmo de Euclides, etc. 

**O funcionamento do programa possibilita que o usuário escolha entre 5 opções:**

**1 - Gerar Chave Pública🔑**

* Nesta opção o programa solicita que o usuário insira dois numeros primos (p,q) e um outro inteiro positivo "e" que seja relativamente primo a (p-1)*(q-1). A partir disso é criado um arquivo .txt contendo uma chave pública, a qual é representada pelo par (n, e), onde n = p * q. 

**2 - Encriptar🔐**

* Nesta opção o programa solicita a chave pública que foi gerada anteriormente e logo após a frase a ser encriptada deve ser inserida. A mensagem encriptada será salva em um arquivo .txt gerado pelo programa.

**3 - Desencriptar🔓**

* Nesta opção o programa solicita os valores "p", "q" e "e" que já foram usados anteriormente para a criação da chave pública. A mensagem desencriptada é salva num arquivo .txt.

**4 - Ver Mensagem Desencriptada👀**

* Ao selecionar esta opção a mensagem desencriptada é retornada para o usuário na CLI.

**5 - Sair🚪**

* Ao selecionar esta opção a execução do programa é encerrada.

## Conceitos matemáticos utilizados:

* Aritmética modular com base na tabela ASCII;
* Algoritmo de Euclides;
* Números primos;

### Ferramentas utilizadas⚙️

* Visual Studio Code
* C
* GTK

