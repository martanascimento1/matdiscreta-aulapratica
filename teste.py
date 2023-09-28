from tkinter import*

janela = Tk ()
janela.title ("Criptografia RSA - Matematica Discreta")
janela.geometry('700x400')


#label = Label (janela, text = "Primeiro entry")
#label.grid (column = 0, row = 0, padx=15, pady=15)

#entrada = Entry(janela,width=10)
#entrada.grid(column=1, row=0, padx=5, pady=15)

def ola():
    resultado = entrada.get()
    label.configure(text= resultado)
texto_one = Label(janela, text="Escolha uma das opcoes a seguir:", bg='green', font='times')
texto_one.grid(column=10, row=0)
botao = Button(janela, text="Gerar Chave Publica",command = ola)
botao.grid(column=10, row=1, padx=10, pady=15)
botao = Button(janela, text="Encriptar",command = ola)
botao.grid(column=10, row=2, padx=10, pady=15)
botao = Button(janela, text="Desencriptar",command = ola)
botao.grid(column=10, row=3, padx=10, pady=15)

janela.mainloop ()